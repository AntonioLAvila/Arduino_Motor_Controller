#define Motor_cpp
#include "Arduino.h"

class Motor{
    private:
        int pwm, fwd, reverse;
        bool isFwd;
    public:
        Motor(int pwmPin, int fwdPin, int reversePin){
            pwm = pwmPin;
            fwd = fwdPin;
            reverse = reversePin;
            isFwd = true;

            pinMode(pwm, OUTPUT);
            pinMode(fwd, OUTPUT);
            pinMode(reverse, OUTPUT);
        }

        void setMotor(float percentPower){
            if(percentPower>1) percentPower = 1;
            if(percentPower<-1) percentPower = -1;
            float out;
            if(percentPower < 0){
                if(isFwd){
                    isFwd = false;
                    digitalWrite(fwd, LOW);
                    digitalWrite(reverse, HIGH);
                }
                out = map(percentPower, -1.0, 0.0, 240.0, 0.0);
            }else{
                if(!isFwd){
                    isFwd = true;
                    digitalWrite(fwd, HIGH);
                    digitalWrite(reverse, LOW);
                }
                out = map(percentPower, 0, 1.0, 0.0, 240.0);
            }
            analogWrite(pwm, out);
        }
};
