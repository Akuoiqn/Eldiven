#if USING_FORCE_FEEDBACK

#if defined(ESP32)
  #include "ESP32Servo.h"
#else
  #include "Servo.h"
#endif

//Servo pinkyServo;
//Servo ringServo;
//Servo middleServo;
//Servo indexServo;
//Servo thumbServo;
int lowCheck = 0;
int highCheck = 0;
bool grabButton = 13;
void setupServoHaptics(){
pinMode(PIN_PINKY_MOTOR,OUTPUT);
pinMode(PIN_RING_MOTOR,OUTPUT);
pinMode(PIN_MIDDLE_MOTOR,OUTPUT);
pinMode(PIN_INDEX_MOTOR,OUTPUT);
pinMode(PIN_THUMB_MOTOR,OUTPUT);
}

//static scaling, maps to entire range of servo
void scaleLimits(int* hapticLimits, float* scaledLimits){
  for (int i = 0; i < 5; i++){
    scaledLimits[i] = 180.0f - hapticLimits[i] / 1000.0f * 180.0f;
  }
}

//dynamic scaling, maps to the limits calibrated from your finger
void dynScaleLimits(int* hapticLimits, float* scaledLimits){
  //will be refactored to take min and max as an argument

  /* this implementation of dynamic scaling relies on the assumption 
   * that the servo reaches 2/3 of the potentiometer's range, 
   * and that 0 degrees is geared to the start of the potentiometer.
   * Different hardware types may need to handle dynamic scaling differently.
   */
  for (int i = 0; i < sizeof(hapticLimits); i++){
    scaledLimits[i] = hapticLimits[i] / 1000.0f * 180.0f;
  }
}

void writeServoHaptics(){
  //int* hapticLimits^^
//  float scaledLimits[5];
//  scaleLimits(hapticLimits, scaledLimits);

//while (analogRead(PIN_JOY_BTN)>=512){
//  if (PIN_PINKY_MOTOR == LOW){
//    continue;}
//    else{
//      digitalWrite(PIN_PINKY_MOTOR, LOW);
//      }
//  }
//
//  while (analogRead(PIN_JOY_BTN)<=511){
//  if (PIN_PINKY_MOTOR == HIGH){
//    continue;}
//    else{
//      digitalWrite(PIN_PINKY_MOTOR, HIGH);
//      }
//  }
  
}
//  if(grabButton == true){
//    if(fingerPos[0]>=511){
//    digitalWrite(PIN_PINKY_MOTOR, LOW);}
//    else{
//    digitalWrite(PIN_PINKY_MOTOR, HIGH);}
//
//  if(fingerPos[1]>=511){
//    digitalWrite(PIN_RING_MOTOR, LOW);}
//    else{
//    digitalWrite(PIN_RING_MOTOR, HIGH);}
//
//  if(fingerPos[2]>=511){
//    digitalWrite(PIN_MIDDLE_MOTOR, LOW);}
//    else{
//    digitalWrite(PIN_MIDDLE_MOTOR, HIGH);}
//
//  if(fingerPos[3]>=511){
//    digitalWrite(PIN_INDEX_MOTOR, LOW);}
//    else{
//    digitalWrite(PIN_INDEX_MOTOR, HIGH);}
//
//  if(fingerPos[4]>=511){
//    digitalWrite(PIN_THUMB_MOTOR, LOW);}
//    else{
//    digitalWrite(PIN_THUMB_MOTOR, HIGH);}}
//    else{
//      digitalWrite(PIN_PINKY_MOTOR, HIGH);
//      digitalWrite(PIN_RING_MOTOR, HIGH);
//      digitalWrite(PIN_MIDDLE_MOTOR, HIGH);
//      digitalWrite(PIN_INDEX_MOTOR, HIGH);
//      digitalWrite(PIN_THUMB_MOTOR, HIGH);
//      }
//    }
//  if(hapticLimits[0] >= 0) {
//    thumbServo.write(scaledLimits[0]);
////    if(PIN_THUMB_MOTOR == LOW){
////    digitalWrite(PIN_THUMB_MOTOR, HIGH);}
//    };
//  if(hapticLimits[1] >= 0) {
//    indexServo.write(scaledLimits[1]);
////    if(PIN_INDEX_MOTOR == LOW){
////  digitalWrite(PIN_INDEX_MOTOR, HIGH);}
//  };
//  if(hapticLimits[2] >= 0) {
//    middleServo.write(scaledLimits[2]);
////    if(PIN_MIDDLE_MOTOR == LOW){
////    digitalWrite(PIN_MIDDLE_MOTOR, HIGH);}
//};
//  if(hapticLimits[3] >= 0) {
//    ringServo.write(scaledLimits[3]);
////    if(PIN_RING_MOTOR == LOW){
////    digitalWrite(PIN_RING_MOTOR, HIGH);}
//    };
//  if(hapticLimits[4] >= 0) {
//    pinkyServo.write(scaledLimits[4]);
////    if(PIN_PINKY_MOTOR == LOW){
////    digitalWrite(PIN_PINKY_MOTOR, HIGH);}
//    };
//}
void stateMagnet(int* fingerPos) {

  if (fingerPos[2]>=600){
    if(PIN_THUMB_MOTOR == LOW) return;
   if(lowCheck < 10){
    lowCheck = lowCheck + 1;
    }else{
   digitalWrite(PIN_THUMB_MOTOR, LOW);
   digitalWrite(PIN_INDEX_MOTOR, LOW);
   digitalWrite(PIN_MIDDLE_MOTOR, LOW);
   digitalWrite(PIN_RING_MOTOR, LOW);
   digitalWrite(PIN_PINKY_MOTOR, LOW);
   lowCheck = 0;
   }}
   else{
    if (PIN_THUMB_MOTOR == HIGH) return; 
     if(highCheck < 10){
    highCheck = highCheck + 1;
    }else{
     digitalWrite(PIN_THUMB_MOTOR, HIGH);
    digitalWrite(PIN_INDEX_MOTOR, HIGH);
   digitalWrite(PIN_MIDDLE_MOTOR, HIGH);
   digitalWrite(PIN_RING_MOTOR, HIGH);
   digitalWrite(PIN_PINKY_MOTOR, HIGH);
  highCheck = 0;
   }}}
#endif
