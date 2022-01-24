//..................librerias......................................................................................
#include <xc.h>

//....................conf_fusibles................................................................................
#pragma config OSC = XT         // Oscillator Selection bits (XT oscillator)
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bit (Brown-out Reset disabled)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config LVP = OFF        // Low Voltage ICSP Enable bit (Low Voltage ICSP disabled)

#define _XTAL_FREQ  4000000

//..............variables globales y prototipos de funcion.........................................................
unsigned char A=0;

void conf_puertos(void);
void conf_tmr0(void);
void conf_int(void);

//..............codigo principal................................................................
void main(void) {
    
    //.........................conf perifericos.................................................
    conf_puertos();
    conf_tmr0();
    conf_int();
    
    //.........................bucle.............................................................
    while(1)
    {
        PORTA=~PORTA;
        __delay_ms(150);
        __delay_ms(150);
        __delay_ms(100);
    }
    
 }

//......................funciones............................................................
void conf_puertos(void){
    
    TRISB=0x01;         // puerto B de entrada
    LATB=0;             // limpiar puerto B
    PORTB=0;            // limpiar puerto B
    
    TRISD=0x00;         // puerto D de salida
    LATD=0;             // limpia puerto D
    PORTD=0;            // limpia puerto D
    
    TRISA=0x00;         // puerto C de salida
    LATA=0;             // limpia puerto C
    PORTA=0;            // limpia puerto C
    ADCON1=0x06;        // Puerto A digital
      
}
void conf_tmr0(void)
{
    T0CON=0b10001000;  //on,16,tcy,no preescaler
}
void conf_int(void){
    INTCON=0b10010000;  //int habilitadas sin prioridad, int externa 0 RB0
    INTCON2=0b10000000; // flanco descenso RB0
}
void interrupt base(){              //0x08
    
    if(INTCONbits.INT0IF==1){
        INTCONbits.INT0IF = 0;
        PORTD=~PORTD;
    }    
}

//void interrupt low_priority LowIsr(void)  //0x18
//{
//	
//}
