int LEDR = 2;

void setup()
{
  analogReference(DEFAULT); // set to 5V reference
  pinMode(LEDR, OUTPUT);
}

void loop()
{
  int value;
  value = analogRead(2); // read signal from analog input 2
  
  // if the potentialmeter is more than halfway, turn the LED on
  if(value > 512) {
    digitalWrite(LEDR, HIGH);
  } else {
    digitalWrite(LEDR, LOW);
  }
  delay(1000); // give the user a chance to read the values coming out
}