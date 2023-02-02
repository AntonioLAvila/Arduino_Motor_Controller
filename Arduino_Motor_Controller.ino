#include <string.h>
#include "Motor.cpp"

float powers[4] = {0,0,0,0};
Motor motor1(1,2,3);
Motor motor2(4,5,6);
Motor motor3(7,8,9);
Motor motor4(10,11,12);

Motor* base[4] = {&motor1, &motor2, &motor3, &motor4};

void setup() {
  Serial.begin(9600);
  setMotors();
}

void loop() {
  if(Serial.available()){
    String command = Serial.readStringUntil('\0');
    char buffer[21];
    command.toCharArray(buffer, 21);  //is null terminated

    if(buffer[0] == 'H'){
      char* split = strtok(buffer + 1, ",");
      int i = 0;
      while(split != NULL){
        powers[i] = atof(split);
        split = strtok(NULL, ",");
        i++;
      }
    }    
  }
  setMotors();
}

void setMotors(){
  for(int i = 0; i < 4; i++){
    base[i]->setMotor(powers[i]);
  }
}