#include "mbed.h"

#include "uLCD_4DGL.h"

InterruptIn up(D3);
InterruptIn down(D8);
InterruptIn sel(D5);

//DigitalIn up(D3);
//DigitalIn down(D8);
//DigitalIn sel(D5);
AnalogOut sig(PA_4);
AnalogIn sig_fil(D11);
DigitalOut flash(LED2);

uLCD_4DGL uLCD(D1, D0, D2);



/*void up_button()
{
   if(slew_rate < 1){
        slew_rate *= 2;
        uLCD.locate(0,0);
        uLCD.printf("%f", slew_rate);
    }
    else{
        slew_rate = 1;
        uLCD.locate(0,0);
        uLCD.printf("%f", slew_rate);
    }
}
void down_button()
{
    if(slew_rate > 0.125){
        slew_rate /= 2;
        uLCD.locate(0,0);
        uLCD.printf("%f", slew_rate);
    }
    else{
        slew_rate = 0.125;
        uLCD.locate(0,0);
        uLCD.printf("%f", slew_rate);
    }
}
void flip()
{


}*/
int main(){
    float slew_rate = 0.125;

    while(1){
        if (up){
            if(slew_rate < 1){
                slew_rate *= 2;
                uLCD.locate(0,0);
                uLCD.printf("%f", slew_rate);
            }
            else{
                slew_rate = 1;
                uLCD.locate(0,0);
                uLCD.printf("%f", slew_rate);
            }
        }
        if (down){
           if(slew_rate > 0.125){
                slew_rate /= 2;
                uLCD.locate(0,0);
                uLCD.printf("%f", slew_rate);
            }
            else{
                slew_rate = 0.125;
                uLCD.locate(0,0);
                uLCD.printf("%f", slew_rate);
            }
        }
        if (sel){
            uLCD.locate(0,0);
            uLCD.printf("%f", slew_rate);
            break;
        }
    }
    while(1){
        if(slew_rate == 1){
            for (float i = 0.0f; i < 1.0f; i += 0.01f) {
                sig = (i / 1.1);
                wait_us(800);
            }
            for (float i = 0.0f; i < 1.0f; i += 0.01f) {
                sig = (1 / 1.1);
                wait_us(800);
            }
            for (float i = 1.0f; i > 0.0f; i -= 0.01f) {
                sig = (i / 1.1);
                wait_us(800);
            }
        }
        if(slew_rate == 0.5){
            for (float i = 0.0f; i < 1.0f; i += 0.01f) {
                sig = (i / 1.1);
                wait_us(400);
            }
            for (float i = 0.0f; i < 4.0f; i += 0.01f) {
                sig = (1 / 1.1);
                wait_us(400);
            }
            for (float i = 1.0f; i > 0.0f; i -= 0.01f) {
                sig = (i / 1.1);
                wait_us(400);
            }
        }
        if(slew_rate == 0.25){
            for (float i = 0.0f; i < 1.0f; i += 0.01f) {
                sig = (i / 1.1);
                wait_us(200);
            }
            for (float i = 0.0f; i < 10.0f; i += 0.01f) {
                sig = (1 / 1.1);
                wait_us(200);
            }
            for (float i = 1.0f; i > 0.0f; i -= 0.01f) {
                sig = (i / 1.1);
                wait_us(200);
            }
        }
        if(slew_rate == 0.125){
            for (float i = 0.0f; i < 1.0f; i += 0.01f) {
                sig = (i / 1.1);
                wait_us(100);
            }
            for (float i = 0.0f; i < 22.0f; i += 0.01f) {
                sig = (1 / 1.1);
                wait_us(100);
            }
            for (float i = 1.0f; i > 0.0f; i -= 0.01f) {
                sig = (i / 1.1);
                wait_us(100);
            }
        }
    }
    
    
}