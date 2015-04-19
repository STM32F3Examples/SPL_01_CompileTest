#include "stm32f30x.h"                  // Device header
/*Led PB13, Button PC13*/

void delay_ms(int delay_time);

void led_init(void);
void button_init(void);

int main(){
	led_init();
	button_init();
	while(1){
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)){
			GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		} else{
			GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_SET);
			delay_ms(0xFFFFF);
			GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
			delay_ms(0xFFFFF);
		}
	}
}

void led_init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin=GPIO_Pin_13;
	myGPIO.GPIO_Mode=GPIO_Mode_OUT;
	myGPIO.GPIO_OType=GPIO_OType_PP;
	myGPIO.GPIO_PuPd=GPIO_PuPd_NOPULL;
	myGPIO.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOB,&myGPIO);
}

void button_init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOCEN ,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Mode=GPIO_Mode_IN;
	myGPIO.GPIO_Pin=GPIO_Pin_13;
	GPIO_Init(GPIOC,&myGPIO);
}

void delay_ms(int delay_time){
	for(int i=0; i<delay_time; i++);
}
