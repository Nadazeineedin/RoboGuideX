#include <Servo.h> 
Servo Myservo; 
//ultra sonic
#define trigPin 11 // Trig Pin Of HC-SR04 
#define echoPin 12 // Echo Pin Of HC-SR04 
//motors on PWM pins
#define MLa 9 // Right motor 1st pin 
#define MLb 6 // Right motor 2nd pin 
#define MRa 3 // Left motor 1st pin 
#define MRb 5 // Left motor 2nd pin
//color sensor
#define S0 A0 
#define S1 A1
#define S2 A5
#define S3 A4
#define sensorOut A2
long duration, distance; 
int sp = 0.5*255; //speed in terms of PWM
//initialize color sensor readings
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
void setup() { 
// Color sensor pins
 pinMode(sensorOut, INPUT);
 pinMode(S0, OUTPUT); 
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
// Setting frequency scaling to 20%
 digitalWrite(S0,1);
 digitalWrite(S1,0);
// Motor pins
 pinMode(MLa, OUTPUT); 
 pinMode(MLb, OUTPUT); 
 pinMode(MRa, OUTPUT); 
 pinMode(MRb, OUTPUT); 
//ulta-sonic pins
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
//servo motor signal pin
 Myservo.attach(10); 
 Serial.begin(9600); 

} 
void loop() {
 // Setting RED (R) filtered photodiodes to be read
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redFrequency = pulseIn(sensorOut, LOW);
 // Setting GREEN (G) filtered photodiodes to be read
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenFrequency = pulseIn(sensorOut, LOW);
 // Setting BLUE (B) filtered photodiodes to be read
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueFrequency = pulseIn(sensorOut, LOW);
 // Convert frequency to color intensity
 int redIntensity = redFrequency * 100 * 1.234;
 int greenIntensity = greenFrequency * 90 * 0.99;
 int blueIntensity = blueFrequency * 100;
 // Print color intensities
 Serial.print("R = ");
 Serial.print(redIntensity);
 Serial.print(" G = ");
 Serial.print(greenIntensity);
 Serial.print(" B = ");
 Serial.println(blueIntensity);
 // Check if red color is dominant
 if (redIntensity < greenIntensity && redIntensity < blueIntensity) {
 Serial.println(" - RED detected!");
 // Stop the robot
 digitalWrite(MRb, LOW);
 digitalWrite(MRa, LOW);
 digitalWrite(MLb, LOW);
 digitalWrite(MLa, LOW);
 Serial.println("Stop");
 delay(1000);
 } else {
 // Proceed with obstacle avoidance
//measuring the distance
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); // Transmit Waves For 10us 
 delayMicroseconds(10); 
 duration = pulseIn(echoPin, HIGH); // Receive Reflected Waves 
 distance = duration / 58.2; // Get Distance 
 Serial.println(distance); 
 delay(10); 
 // Obstacle avoidance logic...
 if (distance > 25) // Condition For Absence Of Obstacle 
 { 
 Myservo.write(90); 
 analogWrite(MRb, sp); // Move Forward 
 digitalWrite(MRa, LOW); 
 analogWrite(MLb, sp); 

 digitalWrite(MLa, LOW); 
 } 
 else if ((distance < 25 )&&(distance > 0)){ 
// Condition For Presence Of Obstacle 
 digitalWrite(MRb, LOW); //Stop 
 digitalWrite(MRa, LOW); 
 digitalWrite(MLb, LOW); 
 digitalWrite(MLa, LOW); 
 delay(100); 
// measure right side distance
 Myservo.write(0); //move Ultrasonnic to the Right
 delay(500); 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); // Transmit Waves For 10us 
 delayMicroseconds(10); 
 duration = pulseIn(echoPin, HIGH); // Receive Reflected Waves 
 distance = duration / 58.2; // Get Distance 
 Serial.println(distance); 
 delay(10); 
 if (distance > 25) //Right road is clear
 { 
 Myservo.write(0); 
 delay(500); 
 digitalWrite(MRb, LOW); // Move Backward 
 analogWrite(MRa, sp); 
 digitalWrite(MLb, LOW);
 analogWrite(MLa, sp); 
 delay(100); 
 digitalWrite(MRb, LOW); //Stop 
 digitalWrite(MRa, LOW); 
 digitalWrite(MLb, LOW); 
 digitalWrite(MLa, LOW); 
 delay(100); 
 digitalWrite(MRb, LOW); // Move Right 
 digitalWrite(MRa, HIGH); 
 digitalWrite(MLa, LOW); 
 digitalWrite(MLb, LOW); 
 delay(300); 
 } 
 else if ((distance < 25)&&(distance > 0)){
// right and forward roads are blocked 
//check for the left road distance
 Myservo.write(90); //move ultrasonic to the Left
 delay(500); 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); // Transmit Waves For 10us 
 delayMicroseconds(10); 
 duration = pulseIn(echoPin, HIGH); // Receive Reflected Waves 
 distance = duration / 58.2; // Get Distance 
 Serial.println(distance); 
 delay(10); 
 if (distance > 25) //Left road is clear
 {

 Myservo.write(45); 
 delay(500); 
 digitalWrite(MRb, LOW); // Move Backward 
 analogWrite(MRa, sp); 
 digitalWrite(MLb, LOW); 
 analogWrite(MLa, sp); 
 delay(100); 
 digitalWrite(MRb, LOW); //Stop 
 digitalWrite(MRa, LOW); 
 digitalWrite(MLb, LOW); 
 digitalWrite(MLa, LOW); 
 delay(100); 
 digitalWrite(MRb, LOW); // Move Left 
 digitalWrite(MRa, LOW); 
 digitalWrite(MLa, HIGH); 
 digitalWrite(MLb, LOW); 
 delay(300); 
 }
 }
 }
 
 }
}
