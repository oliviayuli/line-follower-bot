//Name: Olivia Chan
//Date: June 9, 2023

//Declaration Section
//Photoresistors
int ldr1; //Value from photoresistor 1(left ldr)
int ldr2; //Value from photoresistor 2(middle ldr)

//Motor Driver
const int speedLeft = 3; //Pin for left wheel speed
const int directionLeft = 12; //Pin for left wheel direction
const int speedRight = 11; //Pin for right wheel speed
const int directionRight = 13; //Pin for right wheel direction

//Motor pins
void setup() {
  pinMode(speedLeft, OUTPUT);
  pinMode(directionLeft, OUTPUT);
  pinMode(speedRight, OUTPUT);
  pinMode(directionRight, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  photoresistor();
  //when the left ldr is black and the middle is white, go straight
  if (ldr1 < 250 && ldr2 > 250)
  {
    moveForward();
  }
  //when the left ldr is black and the middle is black, go right
  else if (ldr1 < 250 && ldr2 < 250)
  {
    rotateRight();
  }
  //when the left ldr is white and the middle is white, go left
  else if (ldr1 > 250 && ldr2 > 250)
  {
    rotateLeft();
  }
  //go straight if none of the other conditions are met
  else {
    moveForward();
  }
}

//function moveForward
void moveForward()
{
  digitalWrite(directionLeft, HIGH);
  digitalWrite(directionRight, HIGH);
  analogWrite(speedLeft, 35);
  analogWrite(speedRight, 35);
}

//function rotateLeft
void rotateLeft()
{
  digitalWrite(directionLeft, LOW);
  digitalWrite(directionRight, HIGH);
  analogWrite(speedLeft, 55);
  analogWrite(speedRight, 50);

}

//function rotateRight
void rotateRight()
{
  digitalWrite(directionLeft, HIGH);
  digitalWrite(directionRight, LOW);
  analogWrite(speedLeft, 50);
  analogWrite(speedRight, 55);
}

//function photoresistor
void photoresistor()
{
  ldr1 = analogRead(A5);
  ldr2 = analogRead(A4);
}
