#include <string.h>

float powers[4];
char* intermidiate[4];


void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    String command = Serial.readStringUntil('\n');

    char* charCommand[]
    
  }
}