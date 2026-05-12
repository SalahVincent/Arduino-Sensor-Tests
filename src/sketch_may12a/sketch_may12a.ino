#include <SoftwareSerial.h> // Library for serial communication on other digital pins
#include <Wire.h>           // Library for I2C communication
#include <hd44780.h>        // Main LCD library
#include <hd44780ioClass/hd44780_I2Cexp.h> // I2C expander class for the LCD

// Initialize LCD with I2C address 0x20 and MCP23008 expander configuration
hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008,7,6,5,4,3,2,1,HIGH);

// Pin definitions for peripherals
int led = 13;   // Status LED pin
int buz= 2;     // Buzzer pin
int bu= 8;      // Input button pin
int temp = A2;  // Analog input for temperature sensor
int light = A3; // Analog input for light sensor
int pot = A1;   // Analog input for potentiometer

void setup() {
  // Configure pin modes for digital and analog I/O
  pinMode(led,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(bu,INPUT);
  pinMode(temp,INPUT);
  pinMode(light,INPUT);
  pinMode(pot,INPUT);

  // Initialize Serial communication at 9600 baud and setup LCD dimensions
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // Read the current state of the digital button
  int b = digitalRead(bu);

  // Read analog temperature and convert to Celsius using linear scaling
  float t = analogRead(temp);
  t = ((t*0.125)-22.0);

  // Read potentiometer value and convert to a 0-100 percentage
  float p = analogRead(pot);
  p = ((p/1023.0)*100.0);

  // Map the percentage to an 8-bit PWM value (0-255)
  float p1 = map(p,0,100,0,255);

  // Ensure buzzer is set to LOW at the start of each cycle
  digitalWrite(buz,LOW);

  // Read light sensor value and convert to a 0-100 percentage
  float l = analogRead(light);
  l = ((l/1023.0)*100.0);

  // Concatenate sensor values into a semicolon-separated string for Serial output
  String data = String (String(t)+";"+String(p)+";"+String(l) );
  Serial.println(data);

  // Clear display and update LCD with Potentiometer (R), Light (L), and Temperature (T)
  lcd.clear();
  lcd.print("R: "); lcd.print(p); lcd.print("%");
  lcd.setCursor(8, 0); // Move cursor to the middle of the top row
  lcd.print("L: "); lcd.print(l); lcd.print("%");
  lcd.setCursor(0, 1); // Move cursor to the start of the bottom row
  lcd.print("T: "); lcd.print(t); lcd.print((char)223); lcd.print("C"); // (char)223 is the degree symbol
}