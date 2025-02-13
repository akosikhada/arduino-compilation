int LEDR = 13;
int LEDG = 8;

void setup()
{
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void loop()
{
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDR, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}