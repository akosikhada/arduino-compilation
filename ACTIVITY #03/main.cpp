const int potPin = A0;      // Potentiometer connected to Analog pin A0
const int ledPins[] = {1, 2, 3, 4}; // LEDs connected to digital pins 7, 8, 9, and 10
const int numLeds = 4;     // Number of LEDs

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read the potentiometer value (0-1024)
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the number of LEDs to turn on (0-4)
  int ledsToTurnOn = map(potValue, 0, 1024, 0, numLeds);

  // Turn on the appropriate number of LEDs
  for (int i = 0; i < numLeds; i++) {
    if (i < ledsToTurnOn) {
      digitalWrite(ledPins[i], HIGH); // Turn LED on
    } else {
      digitalWrite(ledPins[i], LOW);  // Turn LED off
    }
  }
}