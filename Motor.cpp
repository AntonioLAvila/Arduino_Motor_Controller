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
            if(percentPower < 0){
                if(isFwd) isFwd = false;
                digitalWrite(fwd, LOW);
                digitalWrite(reverse, HIGH);
                float out = map(percentPower, -1, 1, 0, 255);
                analogWrite(pwm, out);
            }else{
                if(!isFwd) isFwd = true;
                digitalWrite(fwd, HIGH);
                digitalWrite(reverse, LOW);
                float out = map(percentPower, -1, 1, 0, 255);
                analogWrite(pwm, out);
            }
        }
};
