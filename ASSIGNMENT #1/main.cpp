// CREATE A PROGRAM THAT WILL SIMULATE HOW TRAFFIC SIGNAL WORKS.

int redLight = 13;      // Red LED for vehicle traffic
int yellowLight = 12;   // Yellow LED for vehicle traffic
int greenLight = 11;    // Green LED for vehicle traffic
int pedRedLight = 5;    // Red LED for pedestrian traffic
int pedGreenLight = 4;  // Green LED for pedestrian traffic

void setup() {
  // Initialize the digital pins as outputs
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(pedRedLight, OUTPUT);
  pinMode(pedGreenLight, OUTPUT);
}

void loop() {
  // Initial State: Traffic light is red, and pedestrian light is green
  digitalWrite(redLight, HIGH);
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight, LOW);
  digitalWrite(pedRedLight, LOW);
  digitalWrite(pedGreenLight, HIGH);
  delay(10000); // Pedestrian Green: 10 seconds

  // Pedestrian light starts flashing yellow
  for (int i = 0; i < 3; i++) {
    digitalWrite(pedGreenLight, LOW);
    delay(500); // 0.5 seconds off
    digitalWrite(pedGreenLight, HIGH);
    delay(500); // 0.5 seconds on
  }
  digitalWrite(pedGreenLight, LOW);
  digitalWrite(pedRedLight, HIGH);
  delay(3000); // Pedestrian Yellow: 3 seconds

  // Traffic light turns green
  digitalWrite(redLight, LOW);
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight, HIGH);
  delay(20000); // Traffic Green: 20 seconds

  // Traffic light turns yellow
  digitalWrite(greenLight, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(5000); // Traffic Yellow: 5 seconds

  // Traffic light turns red, restarting the process
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight, HIGH);
  digitalWrite(pedRedLight, LOW);
  digitalWrite(pedGreenLight, HIGH);
  delay(10000); // Pedestrian Green: 10 seconds
}