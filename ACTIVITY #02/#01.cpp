int LEDR = 2;
int LEDG = 3; // Green LED connected to pin 3
int POT = A2;  // Potentiometer connected to analog pin A2

void setup() {
  analogReference(DEFAULT); // set to 5V reference (optional, usually the default)
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(POT, INPUT); // Potentiometer is an input
}

void loop() {
  int value;
  value = analogRead(POT); // read signal from the potentiometer

  // if the potentiometer is more than halfway, turn the RED LED on, GREEN LED off
  if (value > 512) {
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
  } else { // Otherwise, turn the GREEN LED on, RED LED off
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
  }
  // delay(100);  // Optional delay.  1 second is a long time for LED control.
}