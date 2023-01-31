#include <string.h>

float powers[4];

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    String command = Serial.readStringUntil('\0');
    char* buffer;
    command.toCharArray(buffer, 21);  //is null terminated

    if(buffer[0] == 'H'){
      buffer = buffer + 1;
      char* split = strtok(buffer, ",");
      int i = 0;
      while(split != NULL){
        powers[i] = atof(split);
        split = strtok(NULL, ",");
        i++;
      }
    }    
  }
}