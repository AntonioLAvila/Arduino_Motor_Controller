#include <string.h>

#define motor1 3;
#define motor2 5;
#define motor3 6;
#define motor4 9;

float powers[4];

void setup() {
  Serial.begin(9600);
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
}