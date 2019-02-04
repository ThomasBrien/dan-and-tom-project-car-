#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define Pin 9
#define Pin 10
#define Pin 11
#define Pin 12

int maximumRange = 55; 
int minimumRange = 0; 
long duration, distance

int forward = 9; 
int front = 10; 
int reverse = 11; 
int back = 12; 


void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(forward, OUTPUT);
 pinMode(front, OUTPUT);
 pinMode(reverse, OUTPUT);
 pinMode(back, OUTPUT);
}

void go_forward()
{
digitalWrite(forward,HIGH); 
digitalWrite(front,HIGH); 
digitalWrite(reverse,LOW); 
digitalWrite(back,LOW); 
}
void go_rvrs()
{
digitalWrite(forward,LOW); 
digitalWrite(front,LOW); 
digitalWrite(reverse,HIGH); 
digitalWrite(back,HIGH); 
}

void stop_car()
{
digitalWrite(reverse,LOW);
digitalWrite(forward,LOW); 
digitalWrite(front,LOW);
digitalWrite(back,LOW);
}
void go_right()
{
digitalWrite(forward,HIGH); 
digitalWrite(back,HIGH); 
digitalWrite(reverse,LOW);   
digitalWrite(front,LOW); 
}






void loop() {
 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 
 distance = duration/58.2;
 
 

if (distance > maximumRange || distance < minimumRange){

 Serial.println("1");
 go_forward();


}
 else {
  go_rvrs();
  delay(250);
  go_right();
 delay(500);
 
 
 }

 delay(50);
COMMENTS
