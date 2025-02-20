#include <LiquidCrystal_I2C.h>  // Library to Run I2C LCD

// Define the size of filter array
#define FILTER_SIZE 20
#define LOWER_THRESHOLD 0
#define UPPER_THRESHOLD 610
#define RED_PIN 10
#define YELLOW_PIN 9
#define GREEN_PIN 8
#define BUZZER_PIN 2

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the Analog pin for the water sensor
const int WaterSensorPin = A0;

// Analog Value filter
int Filter(int sensorValue);

// Convert fill percentage to mm (example conversion, adjust based on your container)
int convertToMm(int fillPercent) {
  const int maxMm = 100; // Maximum height in mm
  return (fillPercent * maxMm) / 100;
}

// Adjustable sensitivity and delay values
int sensitivity = 10; // Adjust sensitivity value as needed
int delayValue = 1000; // Adjust delay value in milliseconds as needed

void setup() {
  // Initialize the LCD
  lcd.init();
  // Turn on the Backlight
  lcd.backlight();
  // Clear the display buffer
  lcd.clear();
  // Initialize Serial Monitor
  Serial.begin(57600);
  // Make LED pins and Buzzer pin as output
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  // Turn Off all the pins
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  // Variable to store sensor values
  int sensorValue;
  // Variable to store filtered Value
  int filteredValue;
  // Variable to store fill percentage
  int fillPercent;
  // Variable to store water level in mm
  int waterLevelMm;

  // Read the value from the water sensor
  sensorValue = analogRead(WaterSensorPin);
  filteredValue = Filter(sensorValue);
  fillPercent = map(filteredValue, LOWER_THRESHOLD, UPPER_THRESHOLD, 0, 100);
  waterLevelMm = convertToMm(fillPercent);

  // Clear the second line of the LCD
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the line

  // Change the color of LED, buzzer, and display message as per water level
  if (fillPercent >= 99 - sensitivity && fillPercent < 100) { // High level
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Level High");
  } else if (fillPercent >= 30 && fillPercent < 80) { // Medium level
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Level Mid ");
  } else if (fillPercent < 30 + sensitivity) { // Low level
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Level Low ");
  }

  // Display water level percentage and mm on the second line of the LCD
  lcd.setCursor(0, 1);
  lcd.print(fillPercent);
  lcd.print("% ");
  lcd.print(waterLevelMm);
  lcd.print("mm");

  // Print raw sensor value to Serial Monitor for troubleshooting
  Serial.print("Raw Sensor Value: ");
  Serial.println(sensorValue);
  
  // Print real-time water level percentage and mm to Serial Monitor
  Serial.print("Water Level: ");
  Serial.print(fillPercent);
  Serial.print("%, ");
  Serial.print(waterLevelMm);
  Serial.println("mm");

  // Adjustable delay before the next loop
  delay(delayValue);
}

// Averaging filter to filter Analog Values
int Filter(int sensorValue) {
  static int analogArray[FILTER_SIZE] = { 0 };
  int filteredValue = 0;
  int i;
  // Shift the Element removing the oldest value stored at index 0
  for (i = 0; i < (FILTER_SIZE - 1); i++) {
    analogArray[i] = analogArray[i + 1];
  }
  // Put the current value in the last element of Array i.e. at index FILTER_SIZE-1
  analogArray[FILTER_SIZE - 1] = sensorValue;
  for (i = 0; i < FILTER_SIZE; i++) {
    filteredValue += analogArray[i];
  }
  // Return Filtered Analog Value
  return (filteredValue / FILTER_SIZE);
}
