#include "mbed.h"

#include "uLCD_4DGL.h"

InterruptIn up(USER_BUTTON);
InterruptIn down(D8);
InterruptIn sel(D5);

//DigitalIn up(D3);
//DigitalIn down(D8);
//DigitalIn sel(D5);
AnalogOut sig(PA_4);
AnalogIn sig_fil(D11);
DigitalOut flash(LED2);

uLCD_4DGL uLCD(D1, D0, D2);

float slew_rate = 0.125;

void up_button()
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


}
int main(){
    
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
            
        }
    }
    
    while(1){
        up.rise(&up_button);
        //down.rise(&down_button);
        flash = !flash;

      ThisThread::sleep_for(250ms);

    }
    
}