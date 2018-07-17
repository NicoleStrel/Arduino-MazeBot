//Angelina + Nicole 
//Final project 
#include <Servo.h>

//declare Variables 
Servo pingServo; 
Servo servoLeft;
Servo servoRight;
const int pingPinT =3;
const int pingPinE = 2;
const int usTocm = 29;
long duration;
int cm;
int cmL;
int cmR;
int speaker= 9;
int redLED= 4;
int yellowLED= 5;
int greenLED=6;
int blueLED= 7;
int numTurn=1;

//Setup function
void setup() {
Serial.begin(9600);
pinMode (pingPinT, OUTPUT);
pinMode (pingPinE, INPUT);
tone (9, 3000, 2000);
pingServo.attach(11);
servoLeft.attach(12);
servoRight.attach(13);
}

//Loop function
void loop() { 
digitalWrite (greenLED, HIGH);
//Detect Middle(forward)
pingServo.writeMicroseconds(1450);
delay(100);
cm = ultraSound();
Serial.println(cm);

//Move forward
forward(1);
delay(1);

//If distance is less than 14cm stop
if (cm <=14 ){
  digitalWrite (greenLED, LOW);
  digitalWrite (redLED, HIGH);
  stopIt(20);
  //Right
  delay(1000);

  //detect right side
  pingServo.writeMicroseconds (-1000);
  delay (1000);
  cmR = ultraSound();
  Serial.println("right: ");
  Serial.println(cmR);
  delay(1000);
 
  //turn back forward
  pingServo.writeMicroseconds(1450);
  delay(1000);
  cm = ultraSound();
  
  //detect Left side
  pingServo.writeMicroseconds(3300);
  delay(1000);
  cmL = ultraSound();
  Serial.println("left: ");
  Serial.println(cmL);
  delay(1000);
  digitalWrite (redLED, LOW);
  
  //decide which way to go
   if (cm > 14 ){
   pingServo.writeMicroseconds(1450);
   delay(100);
   cm = ultraSound();
   Serial.println(cm);
   forward(1);
   }
   
   //adjust for the fourth turn
    if (numTurn ==4){
    turnRight(29);
    pingServo.writeMicroseconds(1450);
    stopIt(100);
    delay(100);
    numTurn ++;
   //turn left if left side is bigger
   }else if(cmL>cmR){
    Serial.println("TUrning Left!");
    turnLeft(28);
    pingServo.writeMicroseconds(1450);
    stopIt(100);
    delay(100);   
    numTurn ++;
    //turning right if right side is bigger
   }else if(cmR>cmL){
    turnRight(28);
    pingServo.writeMicroseconds(1450);
    stopIt(100);
    delay(100);
    numTurn ++;
   }
}else {
  //moving forward
forward(1);
digitalWrite (greenLED, HIGH);
pingServo.writeMicroseconds(1450);
delay(100);
cm = ultraSound();
Serial.println(cm);
delay(1);

} 
//detect forward
pingServo.writeMicroseconds(1450);
delay(100);
cm = ultraSound();
Serial.println(cm);

//play song after last turn
if (numTurn==9){
    pingServo.writeMicroseconds(1450);
    forward(220);
    stopIt(10);
    playSong();
    stopIt(10000);
   } 
}

//measuring function
int ultraSound(){
digitalWrite(pingPinT, LOW);
delayMicroseconds(2);
digitalWrite(pingPinT, HIGH);
delayMicroseconds(5);
digitalWrite(pingPinT, LOW);
duration = pulseIn (pingPinE, HIGH, 25000);
cm = duration/usTocm/2;
if (cm==0){
  cm = 5000;
}

return cm;

}

//Moving forward function
void forward(int loops){
  for (int i =1; i<=loops; i++){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }
}

//turning Left function 
void turnLeft(int loops){
  for (int i = 1; i<=loops; i++){
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }
}

//turning Right function
void turnRight(int loops){
  for (int i= 1; i<=loops; i++){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1700);
    delay(20);
  }
}

//moving backwards function  
void backward(int loops){
  for(int i =1; i<=loops; i++){
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1700);
    delay(20);
  }
}
//stopping function
void stopIt (int loops){
    for(int i =1; i<=loops; i++){
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
    delay(20);
  }
}
void playSong(){
//Chorus
 noteC5(500);
 digitalWrite (redLED, HIGH);
 delay (500);
 digitalWrite(redLED, LOW);

 noteF5 (500);
 digitalWrite (yellowLED, HIGH);
 delay (500);
 digitalWrite(yellowLED, LOW);

 noteC5(500);
 digitalWrite (greenLED, HIGH);
 delay (500);
 digitalWrite(greenLED, LOW);

 noteF4 (500);
 digitalWrite (blueLED, HIGH);
 delay (500);
 digitalWrite(blueLED, LOW);

 noteC5(500);
 digitalWrite (redLED, HIGH);
 delay (500);
 digitalWrite(redLED, LOW);

 noteF5 (500);
 digitalWrite (yellowLED, HIGH);
 delay (500);
 digitalWrite(yellowLED, LOW);

 noteC5(1000);
 digitalWrite (greenLED, HIGH);
 delay (1000);
 digitalWrite(greenLED, LOW);
 
 //Verse 1
 noteC5(500);
 digitalWrite (blueLED, HIGH);
 delay (500);
 digitalWrite(blueLED, LOW);

 noteF5 (500);
 digitalWrite (redLED, HIGH);
 delay (500);
 digitalWrite(redLED, LOW);

 noteC5(500);
 digitalWrite (yellowLED, HIGH);
 delay (500);
 digitalWrite(yellowLED, LOW);

 noteF5 (500);
 digitalWrite (greenLED, HIGH);
 delay (500);
 digitalWrite(greenLED, LOW);

 noteA5 (750);
 digitalWrite (blueLED, HIGH);
 delay (750);
 digitalWrite(blueLED, LOW);

 noteG5 (250);
 digitalWrite (redLED, HIGH);
 delay (250);
 digitalWrite(redLED, LOW);

 noteF5 (250);
 digitalWrite (yellowLED, HIGH);
 delay (250);
 digitalWrite(yellowLED, LOW);

 noteE5 (250);
 digitalWrite (greenLED, HIGH);
 delay (250);
 digitalWrite(greenLED, LOW);

 noteD5 (250);
 digitalWrite (blueLED, HIGH);
 delay (250);
 digitalWrite(blueLED, LOW);

 noteCsharp5 (250);
 digitalWrite (redLED, HIGH);
 delay (250);
 digitalWrite(redLED, LOW);

 //Chrous
 noteC5(500);
 digitalWrite (yellowLED, HIGH);
 delay (500);
 digitalWrite(yellowLED, LOW);

 noteF5 (500);
 digitalWrite (greenLED, HIGH);
 delay (500);
 digitalWrite(greenLED, LOW);

 noteC5(500);
 digitalWrite (blueLED, HIGH);
 delay (500);
 digitalWrite(blueLED, LOW);

 noteF4 (500);
 digitalWrite (redLED, HIGH);
 delay (500);
 digitalWrite(redLED, LOW);

 noteC5(500);
 digitalWrite (yellowLED, HIGH);
 delay (500);
 digitalWrite(yellowLED, LOW);

 noteF5 (500);
 digitalWrite (greenLED, HIGH);
 delay (500);
 digitalWrite(greenLED, LOW);

 noteC5(1000);
 digitalWrite (blueLED, HIGH);
 delay (1000);
 digitalWrite(blueLED, LOW);

 //Verse 2
 noteF5 (750);
 digitalWrite (redLED, HIGH);
 delay (750);
 digitalWrite(redLED, LOW);
 
 noteD5 (250);
 digitalWrite (yellowLED, HIGH);
 delay (250);
 digitalWrite(yellowLED, LOW);

 noteC5 (500);
 digitalWrite (greenLED, HIGH);
 delay (500);
 digitalWrite(greenLED, LOW);

 noteCsharp4 (500);
 digitalWrite (blueLED, HIGH);
 delay (500);
 digitalWrite(blueLED, LOW);

 noteA4 (500);
 digitalWrite (redLED, HIGH);
 delay (500);
 digitalWrite(redLED, LOW);

 noteG4(500);
 digitalWrite (yellowLED, HIGH);
 delay (500);
 digitalWrite(yellowLED, LOW);

 noteF4 (500);
 digitalWrite (greenLED, HIGH);
 delay (500);
 digitalWrite(greenLED, LOW);

 //rest 1/2 sec
 delay (500);
 
}
//------------------------Notes--------------------
void noteC5 (int duration){
  tone (speaker, 523, duration);
}
void noteF5 (int duration){
  tone (speaker, 698, duration);
}
void noteF4  (int duration){
  tone (speaker, 349, duration);
}
void noteA5 (int duration){
  tone (speaker, 880, duration);
}
void noteG5 (int duration){
   tone (speaker, 784, duration);
}
void noteE5 (int duration){
  tone (speaker, 659, duration);
}
void noteD5 (int duration){
  tone (speaker, 587, duration);
}
void noteCsharp5 (int duration){
  tone (speaker, 554, duration);
}
void noteCsharp4 (int duration){
 tone (speaker, 277, duration);
}
void noteA4 (int duration){
   tone (speaker, 440, duration);
}
void noteG4 (int duration){
   tone (speaker, 392, duration);
}
void chorus(){
  
}




