//Haddel Balahmar,Deema AHmidah,Shumokh Abdullah,Wejdan Alshateri
// Define pins for the ultrasonic sensors
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 5; 
const int echoPin2 = 6; 
const int trigPin3 = 7; 
const int echoPin3 = 8; 

// Define pins for the buzzer and motor
const int buzzer = 11;
const int motorPin = 12;

// Define the pin for the water sensor
const int waterLevelPin = A0;

// Variables to store the duration and distance
long duration1, duration2, duration3;
int distance1, distance2, distance3;
int safetyDistance;

// Variable to store the water level
int waterLevel;

// Threshold for water level to detect water
const int waterThreshold = 300; // Adjust this value based on your calibration

// Melody for water detection - notes in the melody:
int melodyWater[] = {262, 294, 330, 349, 392, 440, 494, 523};
int waterNoteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4}; // Duration for each note

// Melody for obstacle detection - notes in the melody:
int melodyObstacle[] = {523, 494, 440, 392, 349, 330, 294, 262};
int obstacleNoteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4}; // Duration for each note

// Function to play melody
void playMelody(int melody[], int noteDurations[], int size) {
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

void setup() {
  // Initialize the ultrasonic sensors
  pinMode(trigPin1, OUTPUT); pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT); pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); pinMode(echoPin3, INPUT);
  
  // Initialize the buzzer and motor pin as output
  pinMode(buzzer, OUTPUT); pinMode(motorPin, OUTPUT);
  
  // Initialize the water sensor pin as input
  pinMode(waterLevelPin, INPUT);

  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Measure distance from each ultrasonic sensor
  distance1 = calculateDistance(trigPin1, echoPin1);
  distance2 = calculateDistance(trigPin2, echoPin2);
  distance3 = calculateDistance(trigPin3, echoPin3);

  // Find the smallest distance
  safetyDistance = min(distance1, min(distance2, distance3));

  // Read the water level from the sensor
  waterLevel = analogRead(waterLevelPin);  // Change this line to match your actual pin assignment

// Check if the water level is above the threshold
if (waterLevel > waterThreshold) {  // Change this line to match your calibration
  playMelody(melodyWater, waterNoteDurations, 8); // Play water detection melody
  digitalWrite(motorPin, HIGH); // Activate the motor

  delay(300);  // 7 seconds in milliseconds

  noTone(buzzer); // Stop the buzzer sound
  digitalWrite(motorPin, LOW); // Deactivate the motor
} 
// Else, if an obstacle is detected within the safety distance
else if (safetyDistance <= 30) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(motorPin, HIGH); // Activate if an object is close
} 
// If no water or obstacle is detected
else {
  digitalWrite(buzzer, LOW);
  digitalWrite(motorPin, LOW); // Deactivate if no object is close
}

  // Print distance values to serial monitor
  Serial.print("Distance1: "); Serial.println(distance1);
  Serial.print("Distance2: "); Serial.println(distance2);
  Serial.print("Distance3: "); Serial.println(distance3);
  // Print moisture level to serial monitor
  Serial.print("Water Level: "); Serial.println(waterLevel);
  
  // Short delay to avoid tone overlap
  delay(100);
}


// Function to calculate distance based on ultrasonic sensor readings
int calculateDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);  // Declare the local variable 'duration' here
    int distance = duration * 0.034 / 2;
    return distance;
} // <-- Added missing closing brace here