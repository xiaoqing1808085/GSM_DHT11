#ifndef __GSM_H__
#define __GSM_H__

#include "main.h"
#include "usart.h"
#include "dht.h"

extern void gsm_init(void);
extern int gsm_send(void);
extern int gsm_resv(void);


#endif
