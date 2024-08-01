#include<18F4550.h> 
#use delay (clock=1000000)        
#fuses HS, NOWDT, PUT, BROWNOUT, NOLVP, CPUDIV1 
#define led0 pin_b1
int16 conta=0;
boolean estado_anterior = false;
int digito[10] =
               {0b00111111,    //D�gito 0
                0b00000110,    //D�gito 1
                0b01011011,    //D�gito 2
                0b01001111,    //D�gito 3
                0b01100110,    //D�gito 4
                0b01101101,    //D�gito 5
                0b01111101,    //D�gito 6
                0b00000111,    //D�gito 7
                0b01111111,    //D�gito 8
                0b01101111     //D�gito 9
               };
#int_timer0              
void trata_t0()           
{

static unsigned int32 tempo=0,num=0,num1=5,num2=9,num3=5;


if(input(pin_b0)==0){
   num=0;
   num1=0;
   num2=0;
   num3=0;
}
if(input(pin_b1)==0){
   num = num;
   num1=num1;
   num2=num2;
   num3=num3;
   estado_anterior= !estado_anterior;
}
   //SET_TIMER0(3036+get_timer0()); //set_timer
   SET_TIMER0(131+get_timer0()); //set_timer
conta++;
if (conta>4) conta = 1;
switch(conta)
          {
      case 1: OUTPUT_D(digito[num3]);
                       OUTPUT_A(0b11111011);
                       break; 
      case 2: OUTPUT_D(digito[num2]);
                       OUTPUT_A(0b11110111);
                       break; 
      case 3: OUTPUT_D(digito[num1]);
                       OUTPUT_A(0b11101111);
                       break; 
      case 4: OUTPUT_D(digito[num]);
                       OUTPUT_A(0b11011111);
                       break; 
          }
          

if(!estado_anterior){

tempo++;
if (tempo==32)
{
tempo=0;
num++;
if (num>9){
num=0;
num1++;
}
if(num1>5){
num1=0;
num2++;
}
if(num2>9){
num2=0;
num3++;
}
if(num3>5)num3=0;
}

}
}          
          
          
 
void main()
{
port_b_pullups(TRUE);
ENABLE_INTERRUPTS(GLOBAL|INT_TIMER0);  
//setup_timer_0 (RTCC_DIV_2|RTCC_INTERNAL); 
setup_timer_0 (RTCC_DIV_64|RTCC_INTERNAL | RTCC_8_BIT );//8 bits
while(true)
{}
}
