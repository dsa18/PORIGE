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

/* [] END OF FILE */
#include "DSP.h"

    
    //n текущее значение АЦП
//k номер канала (фазы)
      static  int sumn = 0;
void Sk (int16 NewValue, uint8 k)
{
 
    sumn-=Nk[k];
    Nk[k]=NewValue;
    sumn+=Nk[k];
    int rez=NewValue-(sumn>>3);
     BIX_X[k]=(rez);
    
}

int XCos()
{
    return (BIX_X[0]*NCos[0]+BIX_X[1]*NCos[1]+BIX_X[2]*NCos[2]+BIX_X[3]*NCos[3]+
           BIX_X[4]*NCos[4]+BIX_X[5]*NCos[5]+BIX_X[6]*NCos[6]+BIX_X[7]*NCos[7])/8;
}

int YSin()
{
    return (BIX_X[0]*NSin[0]+BIX_X[1]*NSin[1]+BIX_X[2]*NSin[2]+BIX_X[3]*NSin[3]+
           BIX_X[4]*NSin[4]+BIX_X[5]*NSin[5]+BIX_X[6]*NSin[6]+BIX_X[7]*NSin[7])/8;
        
}

#define a0 1
#define a1 1
#define a2 1

#define b0 1
#define b1 1
#define b2 1

void BIX_Fiter(uint8 coun)
{
    // y[n] = (b0*x[n] + b1*x[n-1] + b2*x[n-2] - a1*y[n-1] - a2*y[n-2])/a0 
    switch (coun  ) 
    {
    case 0:
    BIX_Y[coun]=b0*BIX_X[coun]/a0;
        break;
    case 1:
    BIX_Y[coun]=(b0*BIX_X[coun]+b1*BIX_X[coun-1]-a1*BIX_Y[coun-1])/a0;
        break;
    default:
    BIX_Y[coun]=(b0*BIX_X[coun]+b1*BIX_X[coun-1]+b2*BIX_X[coun-2]-a1*BIX_Y[coun-1]-a1*BIX_Y[coun-2])/a0;
        break;
    }
}




#define N (4)
int filter(int a)
  {
  static int m[N];
  static int n;
  m[n]=a;
  n=(n+1)%N;
  a=0;
  for(int j=0;j<N;j++){a=a+m[j];}
  return a/N;
  }






/*
void RRSZ()
{
        if (couSZ>100)
    {
      couSZ=0;    
   // USBUART_1_PutData((uint8*)SZ,100 );
    }

}
#define N (2)
uint8 filter(uint8 a)
  {
  static int m[N];
  static int n;
  m[n]=a;
  n=(n+1)%N;
  a=0;
  for(int j=0;j<N;j++){a=a+m[j];}
  return a/N;
  }
uint8 filter_1(uint8 x)
  {
  static uint8 n;
  static uint8 m[N];
  static uint8 y;
  y=y+(x-m[n]);
  m[n]=x;
  n=(n+1)%N;
  return y/N;
  }

uint8 filter_2(uint8 x, uint8 Nb, uint8 k)
{
  static uint8 y = 0;
 // static int z = 0;
  y =y+ ((Nb*(x - y))>> k);
 
  return y ;
};

//---------------------------------------------------------------------------------
uint8 filter_3(uint8 x)
{
  static int8 y = 0;
 // static int z = 0;
  y =(x-0x80);
    if(y<0)y =abs(y);
    
    
    lin[cnt_line].x[2] = lin[cnt_line].x[1];            // Коэффициенты x переписать
    lin[cnt_line].x[1] = lin[cnt_line].x[0];            // Коэффициенты x переписать
    lin[cnt_line].x[0] = y;                            // Прочитать АЦП
    fir2_16((uint8_t *)&lin[cnt_line].x[0],(uint8_t *)fltr_c1);// Первое звено фильтра
    fir2_16((uint8_t *)&lin[cnt_line].y[0],(uint8_t *)fltr_c2);// Второе звено фильтра
    cnt_line++;
    if (cnt_line>9)cnt_line=0;
  return filter_1( lin[cnt_line].z[0]) ;
};
//---------------------------------------------------------------------------

void fir2_16(uint8_t * data, uint8_t * coef)
{
  struct data_s    *d_s;
  struct coef_s    *c_s;
  int32_t        acc;
  
  d_s = (struct data_s *) data;
  c_s = (struct coef_s *) coef;
  acc = (int32_t)(d_s->x[0] + d_s->x[2]) * (int32_t)c_s->a0;
  acc += (int32_t)d_s->x[1] * (int32_t)c_s->a1;
  acc += (int32_t)d_s->y[0] * (int32_t)c_s->b1;
  acc += (int32_t)d_s->y[1] * (int32_t)c_s->b2;
  acc >>= 15;
  acc += d_s->y[0] * c_s->c1;
  d_s->y[2] = d_s->y[1];
  d_s->y[1] = d_s->y[0];
  d_s->y[0] = acc;
}
*/