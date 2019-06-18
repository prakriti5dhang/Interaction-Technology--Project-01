int motorPin1 = 11; //motor connected to pin 11
int motorPin2 = 10; //motor connected to pin 10
int IRsensorPin1 = 2;  // IR sensor 1 is connected to the 2 pin of the arduino
int IRsensorPin2 =  4; // IR sensor 2 is connected to the 4 pin of the arduino
const int trigPin =12; //Trigger pin of the ultrasonic is connected to 12 pin of the arduino
const int echoPin =8; //Echo pin of the ultrasonic is connected to 8 pin of the arduino

int ledRpin =13; // Led is connected to 13 pin of the arduino


int IRsensorValue1;        
int IRsensorValue2;
long duration, distancecm;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
 // pinMode(out, OUTPUT);
   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   pinMode(ledRpin, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
                                                                                                                                                                                               
  
}

void loop() {
  digitalWrite(trigPin, LOW);
 delayMicroseconds(4);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(8);
 digitalWrite(trigPin,LOW);
 duration = pulseIn(echoPin, HIGH);
 distancecm =(duration/2)/29.1;
 Serial.print(distancecm);
 Serial.println("cm");
 
 /* Ultrasonic sensor code starts */

 //https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 //https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm
 
  IRsensorValue1 = digitalRead(IRsensorPin1); //reads the digital value of IR sensor 1
  IRsensorValue2 = digitalRead(IRsensorPin2); //reads the digital value of IR sensor 2

  Serial.print(" IR sensor 1 = " ); 
  Serial.println(IRsensorValue1); // prints the IR sensor 1  value
  Serial.print("IR sensor 2 = " );
  Serial.println(IRsensorValue2); // prints the IR sensor 2  value
 if(distancecm <=20)
 {
  digitalWrite(ledRpin,LOW);
  //robo car stops
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
 }
 
 
 /* Ultrasonic sensor code ends */
 
     
/* IR sensor code starts */
  
 
  

 /* IR sensor 1  and IR sensor 2*/

 
  
  if((IRsensorValue1 == 1) && (IRsensorValue2 == 1))
{
  digitalWrite(ledRpin,HIGH);
 //robo car moves forward
analogWrite(motorPin1, 100); //rotate motor 1
analogWrite(motorPin2, 100); //rotate motor 2
}

if ((IRsensorValue1 == 1) && (IRsensorValue2 == 0))
 {
  
 digitalWrite(ledRpin,HIGH);
  // robo car turns left
  analogWrite(motorPin1, 0); //rotate motor 1
  analogWrite(motorPin2, 60);  //stops the motor 2
  
  delay(30);
  analogWrite(motorPin1, 100); //rotate motor 1
 analogWrite(motorPin2, 100); //rotate motor 2

 }
 
 if ((IRsensorValue1 == 0) && (IRsensorValue2 == 1))
 {
  digitalWrite(ledRpin,HIGH);
 //robo car turns right
  analogWrite(motorPin2, 0); //rotate motor 2
  analogWrite(motorPin1, 60); //stops the motor 1
  delay(30);
  analogWrite(motorPin1, 100); //rotate motor 1
 analogWrite(motorPin2, 100); //rotate motor 2

 }
 
if((IRsensorValue1 == 0) && (IRsensorValue2 == 0))
  {
  //robo car stops
  digitalWrite(ledRpin,LOW);
  analogWrite(motorPin1, 0); //stops motor 1
  analogWrite(motorPin2, 0); //stops motor 2
    //robo car stops
  }

  
 
 
/* IR sensor code ends */


 
}
