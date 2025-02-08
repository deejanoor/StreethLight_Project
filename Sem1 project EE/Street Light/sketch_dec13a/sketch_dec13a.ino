
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (I2C Address: 0x27, 20 columns, 4 rows)
LiquidCrystal_I2C lcd(0x27, 20, 4);


// RGB LED Pins
const int PIN_RED = 5;
const int PIN_GREEN = 3;
const int PIN_BLUE = 6;

// LDR Sensor
const int LDR_PIN = A0;
int Threshold = 700;

void setup() {
  Serial.begin(9600);
  lcd.init();       // Initialize the LCD
  lcd.backlight();  // Turn on backlight


  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void setColor(int R, int G, int B) {
  // Invert values because it's a Common Anode RGB LED
  analogWrite(PIN_RED, 255 - R);
  analogWrite(PIN_GREEN, 255 - G);
  analogWrite(PIN_BLUE, 255 - B);
}

void loop() {
  int LDR_Value = analogRead(LDR_PIN);


  Serial.print("LDR Value: ");
  Serial.println(LDR_Value);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LDR: ");
  lcd.print(LDR_Value);

  if (LDR_Value > Threshold) { 
    lcd.setCursor(0, 1);
    lcd.print("It's night time :(");


    setColor(255, 0, 0); // Red
    delay(500);
    setColor(0, 255, 0); // Green
    delay(500);
    setColor(0, 0, 255); // Blue
    delay(500);
  } else { 
   
    lcd.setCursor(0, 1);
    lcd.print("It is day time :D");
    setColor(0, 0, 0);
    delay(1000);
  }
}
