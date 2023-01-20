#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

//Variant 6
// A5
// t = 5
// T=10
// B13
// t = 2
// T=10


void delay(int millis) {
	for(int i=0;i< millis*0x010000;i++);
}

int main(void)
{  
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	GPIO_SetBits(GPIOB, GPIO_Pin_13);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);

	while (1) {
				  
		  GPIOB->ODR |= GPIO_Pin_13;  		  
		  GPIOA->ODR |= GPIO_Pin_5;  
		  
		  delay(2);		
		  GPIOB->ODR &= ~GPIO_Pin_13;		  
		  delay(3);		
		  GPIOA->ODR &= ~GPIO_Pin_5;     
		
		  delay(5);
  }
		
}