#include <stdint.h>

int main(void)
{
	//Registro de Direcciones RCC:
	//dir Base: 0x4002 3800

	//Offset de los registros:		Dir_Base+Offset:
	//>RCC_AHB1ENR: 0X30			>> 0x4002 3830
	//>RCC_APB1ENR: 0X40			>> 0x4002 3840
	//>RCC_APB2ENR: 0X44			>> 0x4002 3844

//CREACION DE PUNTEROS:
	uint32_t* clock_reg_AHB1 = (uint32_t*) 0x40023830;//Puntero para RCC_AHB1ENR
	uint32_t* clock_reg_APB1 = (uint32_t*) 0x40023840;//Puntero para RCC_APB1ENR
	uint32_t* clock_reg_APB2 = (uint32_t*) 0x40023844;//Puntero para RCC_APB2ENR

//BITS EN ALTA:
	//a) RCC_AHB1ENR:			0000 0000 0000 0000 0000 0000 0110 0000
	//i. GPIOG_EN >> bit 6		>>0x0000 0060 >> habilita bit 5 y 6
	//ii. GPIOF_EN >> bit 5
	*clock_reg_AHB1 |= 0x00000060;
	//b) RCC_APB1ENR:			0000 0000 0001 1000 0000 0000 0000 0000
	//i. UART5_EN >> bit 20		>>0x0018 0000 >> habilita bit 19 y 20
	//ii. UART4_EN >> bit 19
	*clock_reg_APB1 |= 0x00180000;
	//c) RCC_APB2ENR:			0000 0000 0000 0010 0000 0001 0000 0000
	//i. ADC1_EN >> bit 8		>>0x0002 0100 >> habilita bit 19 y 20
	//ii. TIM10_EN >> bit 17
	*clock_reg_APB2 |= 0x00020100;
//BITS EN BAJA:
	//a) RCC_AHB1ENR:			1111 1111 1111 1111 1111 1111 1111 1100
	//i. GPIOA_EN >> bit 0		>>0xFFFF FFFC >> desabilita bit 0 y 1
	//ii. GPIOB_EN >> bit 1
	*clock_reg_AHB1 &= 0xFFFFFFFC;
	//b) RCC_APB1ENR:			1111 1111 1111 1111 1111 1111 1110 0101
	//i. TIM6_EN >> bit 4		>>0xFFFF FFE5 >> desabilita bit 1, 3 y 4
	//ii. TIM5_EN >> bit 3
	//iii. TIM3_EN >> bit 1
	*clock_reg_APB1 &= 0xFFFFFFE5;
	//c) RCC_APB2ENR:			1111 1111 1111 1001 1111 1111 1111 1111
	//i. TIM11_EN >> bit 18		>>0XFFF9 FFFF >> desabilita bit 19 y 20
	//ii. TIM10_EN >> bit 17
	*clock_reg_APB2 &= 0XFFF9FFFF;
}
