#include <stdint.h>

int main(void)
{
    //Direccion base RCC: 0x4002 1000
    //(RCC_APB2ENR) offset: 0x18
    uint32_t* Clock_Reg = (uint32_t*) 0x40021018;
    //Direccion base GPIO Port A: 0x4001 0800
    //(GPIOx_CRL) offset: 0x00
    //(GPIOx_IDR) offset: 0x08
    uint32_t* PortA_Mod_Reg = (uint32_t*) 0x040010800;
    uint32_t* PortA_Input_Reg = (uint32_t*) 0x040010808;
    //Direccion base GPIO Port B: 0x4001 0C00
    //(GPIOx_CRL) offset: 0x00
    //(GPIOx_ODR) offset: 0x0C
    uint32_t* PortB_Mod_Reg = (uint32_t*) 0x040010C00;
    uint32_t* PortB_Output_Reg = (uint32_t*) 0x040010C0C;
    
    //Habilitamos señal de reloj PuertoA(bit 2), PuertoB(bit 3)
    *Clock_Reg |= (1 << 2);
    *Clock_Reg |= (1 << 3);
    //Configuracion del puerto PA4 y PA5 como inputs
    *PortA_Mod_Reg &= 0xFF00FFFF;//reiniciamos el puerto
    *PortA_Mod_Reg |= 0x00440000;//CNF(01) MODE(00) para ambos
    //Configuracion del puerto PB2 Y PB3 como outputs
    *PortB_Mod_Reg &= 0xFFFF00FF;//reiniciamos el puerto
    *PortB_Mod_Reg |= 0x000022FF;//CNF(00) MODE(10) para ambos
    //Puerto PB2 y PB3 en 0 bits
    *PortB_Output_Reg &= 0XFFFFFFF0;

    /*loop forever*/
    while (1)
    {   
        //Contador de pulsos S1
        uint8_t val_pul1 = 0;
        while (val_pul1 < 21)
        {
            while ((*PortA_Input_Reg & 0x10) == 0x00);
            
            while ((*PortA_Input_Reg & 0x10) == 0x10);
            val_pul1 = val_pul1 + 1;
        }
        //Contador de pulsos S2
        uint8_t val_pul2 = 0;
        while((*PortA_Input_Reg & 0x20) == 0x00);

        while((*PortA_Input_Reg & 0x20) == 0x20);
        val_pul2 = val_pul2 +1;
        //Muestra parpadeos cuando hay un pulso en S2 en D3
        if (val_pul2 = 1)
        {
            for (int i = 0; i < val_pul1; i++)
            {
                for(int i = 0; i < 200000;i++);
		        *PortB_Output_Reg |= 0x00000004;
		        for(int i = 0; i < 200000;i++);
		        *PortB_Output_Reg &= 0xFFFFFFFB;
            }
            //Si el numero de parpadeos es par enciende D4
            if (val_pul1 % 2 == 0)
            {
            for(int i = 0; i < 200000;i++);
            *PortB_Output_Reg |= 0x00000008;
            }
            //Si no es par permanece apagado
            else
            {
            for(int i = 0; i < 200000;i++);
            *PortB_Output_Reg &= 0xFFFFFFF7;
            }
        }
        //Espera a que se vuelva a presionar S2, para reiniciar
        if (val_pul2 = 2)
        {
            return(0);
        } 
    }
    
}