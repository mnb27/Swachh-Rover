int MOTOR_A1 = 7; 
int MOTOR_B1 = 5; 
int stop_distance=14;
const int trigPin = 11;
  const int echoPin = 12;
  const int motorBspeed  =5;
  long duration;
  int distance;

int RIGHT = A0; 
int LEFT = A1;
int a,b;
void setup() {
  
pinMode(MOTOR_A1, OUTPUT); 
//pinMode(MOTOR_A2, OUTPUT); 
pinMode(MOTOR_B1, OUTPUT); 
//pinMode(MOTOR_B2, OUTPUT); 
pinMode(RIGHT, INPUT); 
pinMode(LEFT, INPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
Serial.begin(9600);
}
void loop() {
  Serial.print(" \n");
  a=analogRead(LEFT);
   b=analogRead(RIGHT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print(distance);
   if(distance < stop_distance)
   {
     digitalWrite(MOTOR_A1, LOW);
 // digitalWrite(MOTOR_A2, LOW);
  //stop left motors
  digitalWrite(MOTOR_B1, LOW);
 // digitalWrite(MOTOR_B2, LOW);
    Serial.print("stop\n");

  
  digitalWrite (MOTOR_A1,HIGH);                       
  digitalWrite (MOTOR_B1,LOW);
  delay(250);
  delay(500);
  digitalWrite (MOTOR_A1,HIGH);                       
  digitalWrite (MOTOR_B1,HIGH);
  delay(900);
  digitalWrite (MOTOR_A1,LOW);                       
  digitalWrite (MOTOR_B1,HIGH);
  delay(800);
  digitalWrite (MOTOR_A1,LOW);                       
  digitalWrite (MOTOR_B1,LOW);
  delay(900);
  digitalWrite (MOTOR_A1,LOW);                       
  digitalWrite (MOTOR_B1,HIGH);

  delay(700);

   digitalWrite (MOTOR_A1,LOW);                       
  digitalWrite (MOTOR_B1,LOW);
  delay(650);
  digitalWrite (MOTOR_A1,LOW);                       
  digitalWrite (MOTOR_B1,HIGH);
  }
if (analogRead(RIGHT)<=50 && analogRead(LEFT)<=50) //compare the both sensor to decide the direction
{
  //MOVE FORWARD//
  
  Serial.print("yes forward\n");
  //run right motors clockwise
  digitalWrite(MOTOR_A1, HIGH);
  //digitalWrite(MOTOR_A2, HIGH);
  //run left motors clockwise
  digitalWrite(MOTOR_B1, HIGH);
 // digitalWrite(MOTOR_B2, LOW);
}
else if (analogRead(RIGHT)<=50 && analogRead(LEFT)>=900) //compare the both sensor to decide the direction
{
  //MOVE RIGHT//
  
  Serial.print("yes right\n");  
  //run right motors clockwise
  digitalWrite(MOTOR_A1, HIGH);
 // digitalWrite(MOTOR_A2, HIGH);
  //run left motors anti-clockwise
  digitalWrite(MOTOR_B1, LOW);
 // digitalWrite(MOTOR_B2, HIGH);
}
else if (analogRead(RIGHT)>=900 && analogRead(LEFT)<=50) //compare the both sensor to decide the direction
{ 
  //MOVE-LEFT//
  Serial.print("yes Left\n");
  //run right motors anti-clockwise
  digitalWrite(MOTOR_A1, LOW);
 // digitalWrite(MOTOR_A2, LOW);
  //run left motors clockwise
  digitalWrite(MOTOR_B1, HIGH);
 // digitalWrite(MOTOR_B2, LOW);
}
else if(analogRead(RIGHT)>=900 && analogRead(LEFT)>=900) //compare the both sensor to decide the direction
{ 
  //STOP//
Serial.print("yes stop\n");

  //stop right motors
  digitalWrite(MOTOR_A1, LOW);
 // digitalWrite(MOTOR_A2, LOW);
  //stop left motors
  digitalWrite(MOTOR_B1, LOW);
 // digitalWrite(MOTOR_B2, LOW);
  }
}