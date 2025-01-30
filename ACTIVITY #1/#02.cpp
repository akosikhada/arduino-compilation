int LEDR = 13;

void setup()
{
  pinMode(LEDR, OUTPUT);
}

void loop()
{
  digitalWrite(LEDR, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDR, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}