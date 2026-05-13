#include <SoftwareSerial.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008, 7, 6, 5, 4, 3, 2, 1, HIGH);

const int led = 13;
int buz = 2;
int bu = 8;
int temp = A2;
int light = A3;
int pot = A1;

// --- FIX: Timer variables ---
unsigned long lastUpdate = 0;
const int interval = 500; // Update every 500ms (2 times per second)

void setup() {
  pinMode(buz, OUTPUT);
  pinMode(bu, INPUT);
  pinMode(temp, INPUT);
  pinMode(light, INPUT);
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // 1. Instant Serial Check (No lag for the LED)
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') digitalWrite(led, HIGH);
    else if (command == '0') digitalWrite(led, LOW);
  }

  // 2. Non-Blocking Update (Only run this every 500ms)
  if (millis() - lastUpdate >= 500) {
    lastUpdate = millis();

    // Read sensors
    float t = (analogRead(temp) * 0.125) - 22.0;
    float p = (analogRead(pot) / 1023.0) * 100.0;
    float l = (analogRead(light) / 1023.0) * 100.0;

    // SEND DATA: Efficiently without 'String' objects
    Serial.print(t);
    Serial.print(";");
    Serial.print(p);
    Serial.print(";");
    Serial.println(l); 

    // UPDATE LCD: Only once every 500ms to prevent bus lag
    lcd.setCursor(0, 0);
    lcd.print("P:"); lcd.print((int)p); lcd.print("%  "); 
    lcd.setCursor(8, 0);
    lcd.print("L:"); lcd.print((int)l); lcd.print("%  ");
    lcd.setCursor(0, 1);
    lcd.print("Temp: "); lcd.print(t, 1); lcd.print("C  ");
  }
}