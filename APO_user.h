/*
 * APO_user.h
 *
 *  Created on: Jan 7, 2020
 *      Author: poh
 */

#ifndef APO_USER_H_
#define APO_USER_H_

#include <apo.h>

typedef struct tIncoming_data {
	double Signal1;
}tIncoming_data;



extern tIncoming_data Data_IN;

tApoSid APO_connect(unsigned long channelmask);
void APO_DeclQuants(void);
void APO_Calc(void);
void APO_finish(void);

#endif /* APO_USER_H_ */
