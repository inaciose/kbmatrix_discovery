#include <Arduino.h>

#define serialSpeed 115200

int line_num[] = {1,2,3,5,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

int top_pin[]  = {0,1,0,0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};

int line_pin[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 46, 45};

int scan_line(int line, int pullon) {
  int res = 0;
  for(int f=0; f<24; f++) {
    pinMode(line_pin[f], OUTPUT); 
  }

  for(int f=0; f<24; f++) {
    digitalWrite(line_pin[f], LOW); 
  }

  digitalWrite(line_pin[pullon], HIGH); 

  digitalWrite(line_pin[line], LOW); 
  pinMode(line_pin[line], INPUT);

  if(digitalRead(line_pin[line])) {
    res = line;

    Serial.print(line_num[line]);
    Serial.print(" on ");
    Serial.print(line_num[pullon]);
    Serial.println("");

    delay(250);
  }

  return res;

}

void check_lines() {
  int line = 0;
  for(int f=0; f < 24; f++) {
    for(int j=0; j < 24; j++) {
      if(j == f) continue;
      line = scan_line(f, j);
    }
  }
}

void setup()
{
  Serial.begin(serialSpeed);
}

void loop()
{

  check_lines();

}