# StreetLight_Project
This project was built on arduino ide and uses an LDR sensor to detect ambient light levels and an I2C LCD to display real-time readings. If the light level is below 700, it indicates daytime with a happy message, and if above 700, it signals nighttime with a sad message. Additionally, an RGB LED cycles through colors at night and turns off during the day.

Required Libraries
  -Wire.h – Enables I2C communication.
  -LiquidCrystal_I2C.h – Controls the I2C LCD.
