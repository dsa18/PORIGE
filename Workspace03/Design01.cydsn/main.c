/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "DSP.h"
#include <stdlib.h>
#include "res.h"
#include <stdlib.h>
#include <math.h>  
 uint16 Dacc;
void init_usb_my();
void init_Gen();
//void USB_NeWk();

uint8 count;
uint8 buffer[128];
uint8 buffer_out[128];
uint8 buffer_out1[1280];
uint8 SZ[1000];


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    init_usb_my();
    init_Gen();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
      //USB_NeWk();
        /* Place your application code here. */
    }
}
void init_usb_my()
{
    USBUART_1_Start(0, USBUART_1_3V_OPERATION);//!!NOTE!! Make sure this matches your board voltage!
  
    
    while(!USBUART_1_GetConfiguration());
    USBUART_1_CDC_Init();
    
}
CY_ISR (Tim_ISR1)
{
    
 VDAC8_1_SetValue(0);
//USAR_();
    
 Stop_ADC_Write(0xff);
}
CY_ISR (USB_NeWk)
{
   
    
    if(USBUART_1_DataIsReady() != 0u)               /* Check for input data from PC */
        {   
            count = USBUART_1_GetAll(buffer);           /* Read received data and re-enable OUT endpoint */
            if(count >= 2)
            {
                while(USBUART_1_CDCIsReady() == 0u);    /* Wait till component is ready to send more data to the PC */ 
                switch (buffer[0]) 
                {
                 case 0:


                    break;
                 case 1:

                    
                    buffer_out[0]='O';
                    buffer_out[1]='1';
                    USBUART_1_PutData(buffer_out, 2); 
                    break;
                 case 2:
                    PGA_Inv_1_SetGain(buffer[1]);
                    buffer_out[0]='O';
                    buffer_out[1]='2';
                    USBUART_1_PutData(buffer_out, 2); 

                    break;
                  case 3:
                    ADC_SAR_1_SetOffset(buffer[1]);
                    buffer_out[0]='O';
                    buffer_out[1]='3';
                    USBUART_1_PutData(buffer_out, 2); 
                    break;
                  case 4:
//                    Sel_Gen_Write(buffer[1]);
                    buffer_out[0]='O';
                    buffer_out[1]='4';
                    USBUART_1_PutData(buffer_out, 2); 
                    break;
                   case 5:

                   // WORD=buffer[1];
                    //buffer_out[2]=WORD;
                    buffer_out[0]='O';
                    buffer_out[1]='5';
                    USBUART_1_PutData(buffer_out, 3); 
                    break;
                case 7:
                    Upr1_Write(buffer[1]);
                    buffer_out[0]='O';
                    buffer_out[1]='6';
                    USBUART_1_PutData(buffer_out, 2); 
                    break;
                  default:
                    buffer_out[0]='E';
                    buffer_out[1]='R';
                    buffer_out[2]='R';
                    buffer_out[3]='O';
                    buffer_out[4]='R';
                    USBUART_1_PutData(buffer_out, 5); 

                    break;
                }

            }
        }
}

void init_Gen()
{

    Upr1_Write(0xFF);
    Upr1_Write(0xFF);
    ADC_SAR_1_Start();
    ADC_SAR_1_Init();
    VDAC8_1_Start();
    VDAC8_1_Init();
    ADC_SAR_1_IRQ_Enable();
    PGA_Inv_1_Init();
    PGA_Inv_1_Start();

    USB_isr_Start();
    USB_isr_SetVector (USB_NeWk) ;
SW_isr_1_Start ();
SW_isr_1_SetVector(Tim_ISR1);
//con=7;
    Sel_Gen_Write(0x7);
    Stop_ADC_Write(0xFF);


}


CY_ISR (ADC_SAR_1_ISR)
{
uint8 con= Sel_Gen_Read();

// int Din = ADC_SAR_1_GetResult16();
//ADC_SAR_1_IRQ_Disable();
   NeWk[con]=ADC_SAR_1_GetResult16();
   // BIX_X[con]= Sk(NeWk[con], con);//удаление постоянной состовляющей
    
//ADC_SAR_1_IsEndConversion();
     Sk(filter(NeWk[con]), con);
 //BIX_X[con]=);
    VDAC8_1_SetValue((NeWk[con]>>4)&0xFF);
    if (con==0)
    {
        // Stop_ADC_Write(0);
         con=8;
         USAR_();
    }
    
 Sel_Gen_Write(con-1);
    
  //ADC_SAR_1_IRQ_Enable();
  
}
void USAR_()
{

   uint16 coun=0;
    uint8 a=0;
   buffer_out1[coun++]=' ';
//for (uint8 i=0; i<8;i++)
{
  // itoa(NeWk[i],&buffer_out1[coun++],16);
  //coun=strlen(buffer_out1);
    int X=XCos();
    int Y=YSin();
    double amp=sqrt((X/1000)^2+(Y/1000)^2);
   buffer_out1[coun++]='X';
   itoa(X,&buffer_out1[coun++],10);
   coun=strlen(buffer_out1);
   buffer_out1[coun++]=' ';
   buffer_out1[coun++]='Y';
   itoa(Y,&buffer_out1[coun++],10);
   coun=strlen(buffer_out1);
   buffer_out1[coun++]=' ';
   buffer_out1[coun++]='A';
   itoa((int)amp,&buffer_out1[coun++],10);
   coun=strlen(buffer_out1);
   buffer_out1[coun++]=' ';
}
    

    ///конец строки
buffer_out1[coun++]=0x0d;
USBUART_1_PutData(buffer_out1,coun);


//aa++;

     /*USBUART_1_PutData(buffer_out1,2);*/
 
    
    
    
}



