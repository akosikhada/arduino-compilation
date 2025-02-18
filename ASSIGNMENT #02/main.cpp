int button1 = 2;
int button2 = 3;
int button3 = 4;
int redLED = 8;
int greenLED = 9;
int yellowLED = 10;

void setup() {
  // Set button pins as inputs with internal pull-up resistors
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  // Set LED pins as outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() {
  // Check if Button 1 is pressed
  if (digitalRead(button1) == LOW) { 
    digitalWrite(redLED, HIGH); 
  } else {
    digitalWrite(redLED, LOW); 
  }

  // Check if Button 2 is pressed
  if (digitalRead(button2) == LOW) {  
    digitalWrite(greenLED, HIGH); 
  } else {
    digitalWrite(greenLED, LOW); 
  }

  // Check if Button 3 is pressed
  if (digitalRead(button3) == LOW) {  
    digitalWrite(yellowLED, HIGH); 
  } else {
    digitalWrite(yellowLED, LOW); 
  }
}