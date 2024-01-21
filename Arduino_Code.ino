#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 8, 7, 4, 2);

int sensorPin = A0;
int buzzerPin = 13;
int Count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  digitalWrite(buzzerPin, LOW);
  lcd.print("Welcome");
  lcd.setCursor(0, 1);
  lcd.print("Students");
  delay(4000);
  lcd.clear();
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  int buzzerValue = digitalRead(buzzerPin);
  digitalWrite(buzzerPin, LOW);

  if (sensorValue == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Student at work");
    delay(2000);
    if (sensorValue == LOW) {
      lcd.print("No contact");
      lcd.setCursor(0, 1);
      lcd.print("with table");
      delay(2000);
    }
    unsigned long startTime = millis();
    unsigned long delayDuration = 30000;  // 30 seconds

    while (millis() - startTime < delayDuration) {
      if (sensorValue == HIGH) {
        digitalWrite(buzzerPin, LOW);
        
      }
      // Additional conditions and actions here if needed
    }
    Count = Count+1;
    lcd.setCursor(0, 1);
    lcd.print("Beeps: ");
    lcd.print(Count);
    delay(1000);
    lcd.clear();
    
    lcd.clear();
  } else if (sensorValue == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("No contact ");
    lcd.setCursor(0, 1);
    lcd.print("with table");
    delay(2000);
    if (sensorValue == HIGH) {
      lcd.print("Student at work");
      delay(2000);
    }
    
    unsigned long startTime = millis();
    unsigned long delayDuration = 30000;  // 30 seconds

    while (millis() - startTime < delayDuration) {
      if (sensorValue == LOW) {
        digitalWrite(buzzerPin, LOW);
      }
      // Additional conditions and actions here if needed
    }
    Count = Count+1;
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Beeps: ");
    lcd.print(Count);
    delay(1000);
    lcd.clear();
  }
}
