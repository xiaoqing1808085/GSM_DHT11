#include "gsm.h"



void gsm_init(void)
{
	HAL_Delay(10000);
	printf("ATE0\r\n");
	HAL_Delay(500);
	printf("AT+CMGF=1\r\n");
	HAL_Delay(500);
	printf("AT+CSCS=\"GSM\"\r\n");
	HAL_Delay(500);
}

int gsm_send(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
	DHT11_Read_Data(&temp,&humi);
	
	/******************ÐÞ¸Äµç»°ºÅÂë******************/
	printf("AT+CMGS=\"18394063991\"\r\n");
	
	
	HAL_Delay(500);
	printf("temp: %d , humi: %d\r\n",temp,humi);
	HAL_Delay(500);
	putchar('!'-7);
	HAL_Delay(3000);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
	return 0;
}

int gsm_resv(void)
{
	  if(getchar() == 'I')
	  {
		gsm_send();
	  }	
	  return 0;
}
