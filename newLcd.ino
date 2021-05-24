#include <IRremote.h>
#include <LiquidCrystal_I2C.h>

const int RECV_PIN = 7;
int RelayPin = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define onOff FFA25D

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.init(); 
  pinMode(RelayPin, OUTPUT);
  lcd.backlight();

}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        if ((results.value) == 0xFFA25D || (results.value) == 0xFD9A65)
        {
          if (digitalRead(RelayPin) == HIGH)
          {
            digitalWrite(RelayPin, LOW);
          }
          else
          {
            digitalWrite(RelayPin, HIGH);
          }
        
        }
   irrecv.resume();
  }
}
