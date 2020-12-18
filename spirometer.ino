#include<Wire.h>
#include<Adafruit_BMP085.h>
#include<LiquidCrystal.h>

Adafruit_BMP085 bmp;

const int rs =12, en =11, d4= 5, d5=4, d6 =3, d7 =2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
long pres=0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   lcd.begin(16, 1);
   if (!bmp.begin())
   {
      Serial.println("Could not find a valid bmp");
      while(1){}
   }


}

void loop() {
  // put your main code here, to run repeatedly:
  pres = bmp.readPressure();
  delay(3000);
  lcd.setCursor(0,0);
  if (pres < 99000)
  {
      Serial.println(pres);
      lcd.print(" ");
      lcd.print("OFF");
      Serial.println("OFF");
      delay(500);  
  }

  if (pres >99000 && pres < 105666)
  {

    Serial.println(pres);
    lcd.print(" ");
    lcd.print("Bad");
    Serial.println("Bad");
    delay(2000);
  }

  if (pres >105667 && pres < 112332)
  {

    Serial.println(pres);
    lcd.print(" ");
    lcd.print("Good");
    Serial.println("Good");
    delay(2000);
  }
  if (pres > 112333)
  {
      Serial.println(pres);
      lcd.print(" ");
      lcd.print("Excellent");
      Serial.println("Excellent");
      delay(500);  
  }


}
