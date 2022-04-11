// Motor A, Left Side
const uint8_t pwmLeft = 6;      // ENA - Enable and PWM
const uint8_t leftForward = 5;  // IN1 - Forward Drive
const uint8_t leftReverse = 4;  // IN2 - Reverse Drive
 
// Motor B, Right Side
const uint8_t pwmRight = 10;     // ENB - Enable and PWM
const uint8_t rightForward = 9; // IN3 - Forward Drive
const uint8_t rightReverse = 8; // IN4 - Reverse Drive

//Left Sensor A1
//Right Sensor A0


int threshVal = 200;
//int threshVal3 = 40;

 
//////////////// Start Functions //////////////////
 
// All Stop
void allStop() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
}
 
void allForward(int dutyON, int dutyOFF) {
  digitalWrite(leftForward, LOW); // Switched NOW SHOULD BE HIGH/LOW same for allReverse(flipped)
  digitalWrite(leftReverse, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, HIGH);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
  delay(dutyON);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
  delay(dutyOFF);
}
 
void allReverse(int dutyON, int dutyOFF) {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
  delay(dutyON);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
  delay(dutyOFF);
}
 
void skidsteerRight(int dutyON, int dutyOFF) {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
  delay(dutyON);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
  delay(dutyOFF);
}
 
void skidsteerLeft(int dutyON, int dutyOFF) {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, HIGH);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
  delay(dutyON);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
  delay(dutyOFF);
}
 
//////////////// End Functions //////////////////

 
void setup() {

  Serial.begin(9600);
  // Set pins to motor driver (L298) to outputs
  pinMode(pwmLeft, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftReverse, OUTPUT);
  pinMode(pwmRight, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightReverse, OUTPUT);
  
  delay(1000);
  
}
 
void loop() {

  int val1=analogRead(A0);//purp right
  int val2=analogRead(A1);//white left
//  Serial.print("Sensor1:  "); Serial.println(val1,DEC); 
//  Serial.print("Sensor2:  "); Serial.println(val2,DEC);
  
  if(analogRead(A1)<threshVal && analogRead(A0)<threshVal){
    allForward(13,30);
    
  }else if(analogRead(A1)>threshVal && analogRead(A0)>threshVal){    
    allForward(13,30);
    
  }else if(analogRead(A1)>threshVal && analogRead(A0)<threshVal){ 
    skidsteerLeft(7,30);
    
  }else if(analogRead(A1)<threshVal && analogRead(A0)>threshVal){    
    skidsteerRight(7,30);
  }

}
