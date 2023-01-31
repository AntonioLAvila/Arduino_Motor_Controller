//"FL%+4.fFR%+4.fBR%+4.fBL%+4.f\n"
//"FL+0.2233FR-0.3456BR-0.3454BL+0.9820"

void setup() {
  Serial.begin(9600);
}

void loop() {
  
}

void int_extractor(char* data_array, int* output_values, char delimiter){
    if(data_array[0] == 0) return;
    char* split = strtok(data_array, &delimiter);
    int idx = 0;
    while(split != NULL){
        output_values[idx] = atoi(split);
        split = strtok(NULL, &delimiter);
        idx++;
    }
}