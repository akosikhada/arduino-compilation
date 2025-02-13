const int potPin = A0;      // Potentiometer connected to Analog pin A0
const int ledPins[] = {2, 4, 6, 8}; // LEDs connected to digital pins 2, 4, 6, and 8
const int numLeds = 4;     // Number of LEDs

// Delay between readings (in milliseconds)
const int readDelay = 10;  // Adjust this value as needed

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(57600); // Initialize serial communication
}

void loop() {
  int potValue = analogRead(potPin);

  int ledsToTurnOn = map(potValue, 0, 1023, 0, numLeds);

  for (int i = 0; i < numLeds; i++) {
    if (i < ledsToTurnOn) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  Serial.println(potValue);

  delay(readDelay); // Introduce the delay
}