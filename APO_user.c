/*
 * APO_user.c
 *
 *  Created on: Jan 11, 2020
 *      Author: poh
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "APO_user.h"
#include "Carmaker.h"
#include "Car/Car.h"

tIncoming_data Data_IN;


static void
query_server(int timeout_ms){
	ApocQueryServers(timeout_ms,NULL);
	while (!ApocQueryDone()) {
		if (ApocWaitIO(100) == 1)
		    ApocPoll();
	    }
}

static int
find_server(void){
	int i;
	int apo = -1;
	unsigned long starttime = 0;

	for (i=0; i<ApocGetServerCount(); i++) {
	 const tApoServerInfo *sinf = ApocGetServer(i);
	 if (strcmp(sinf->Identity, "ApoExample") == 0) {
		 if (starttime == 0 || starttime < sinf->StartTime) {
				starttime = sinf->StartTime;
				apo = i;
		 }
	 }

	}
	return apo;
}

static tApoSid
connect_to_app(int apo,  unsigned long channelmask)
{
	tApoSid sid = NULL;
	int res;
	sid = ApocOpenServer(apo);
	if ((res = ApocConnect(sid, channelmask)) == ApoErrOk) {
		do {
		    if (ApocWaitIO(100) == 1)
			ApocPoll();
		} while ((res = ApocGetStatus(sid, NULL)) == ApoConnPending);
	}
	if (!(ApocGetStatus(sid, NULL) & ApoConnUp)) {
		ApocCloseServer(sid);
		sid = NULL;
	}

	    return sid;
}


tApoSid APO_connect(unsigned long channelmask){
	tApoSid sid = NULL;
	int apo;

	query_server(1000);
	if ((apo = find_server()) >= 0){
		LogUsage("APO_connect");
		sid = connect_to_app(apo, channelmask);
	}
	return sid;
}

void APO_DeclQuants(void)
{

	tDDefault *df = DDefaultCreate("User_APO.");
		AposDefDouble("Time","s",ApoPropMono,&SimCore.Time);
		AposDefDouble("Velocity","kmph",Car.ConBdy1.v,DVA_None);
		DDefDouble(df,"Signal 1","",&Data_IN.Signal1,DVA_None);
		return;
}

void APO_Calc(void){
	tApoSid sid = NULL;
	int res;
	tApoSubscription Subs[1];

	Subs[0].Name = "Sine";
	res = ApocSubscribe(sid, 1, Subs, 100, 1, 10, 0);
	if (res != ApoErrOk)
		return ;
	ApocPoll();

	while (ApocGetData(sid) > 0) {
		 printf("%s = %g\n",
				 Subs[0].Name, *(float *)Subs[0].Ptr);
	 }
	 ApoSleep_ms(50);
	return;
}

void APO_finish(void){
	tApoSid sid = NULL;
	if (!(ApocGetStatus(sid, NULL) & ApoConnUp))
			LogUsage("APO_End: no connection");
	ApocCloseServer(sid);
	return ;
}

