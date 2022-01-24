//..................librerias......................................................................................
#include <xc.h>

//....................conf_fusibles................................................................................
#pragma config OSC = XT         // Oscillator Selection bits (XT oscillator)
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bit (Brown-out Reset disabled)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config LVP = OFF        // Low Voltage ICSP Enable bit (Low Voltage ICSP disabled)

#define _XTAL_FREQ	4000000		// Definici�n del valor del cristal

//..............variables globales y prototipos de funcion.........................................................
unsigned char A=0,B=0,S=0,PB=0;
void conf_puertos(void);

//..............codigo principal................................................................
void main(void) {
    //.........................conf perifericos.................................................
    conf_puertos();
    //.........................bucle.............................................................
    while(1)
    {
        PB=PORTB;
        A=PB>>4;
        B=PB&0x0F;
        S=PORTA&0x0F;
        
        switch(S){
            case 0:
                LATD=A+B;
                break;
                
            case 2:
                LATD=A*B;
                break;
                
            default:
                LATD=0;
                break;
        }
        
    }
    
 }

//......................funciones............................................................
void conf_puertos(void){
    
    TRISB=0xFF;         // puerto B de entrada
    LATB=0;             // limpiar puerto B
    PORTB=0;            // limpiar puerto B
    
    TRISD=0x00;         // puerto D de salida
    LATD=0;             // limpia puerto D
    PORTD=0;            // limpia puerto D
    
    TRISA=0xFF;         //Puerto A de entrada
    LATA=0;             //Limpiar puerto
    PORTA=0;            //Limpiar puerto
    ADCON1=0x06;        //Puerto A digital
}