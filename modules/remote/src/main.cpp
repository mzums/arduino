#include <IRremote.h>

const byte IR_RECEIVE_PIN = 7;

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receive test");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
  if (IrReceiver.decode())
  {
    // Serial.println(IrReceiver.decodedIRData.decodedRawData);
    switch(IrReceiver.decodedIRData.decodedRawData) {
      case 3125149440:
        Serial.println("CH-");
        break;
      case 3108437760:
        Serial.println("CH");
        break;
      case 3091726080:
        Serial.println("CH+");
        break;
      case 3141861120:
        Serial.println("|<<");
        break;
      case 3208707840:
        Serial.println(">>|");
        break;
      case 3158572800:
        Serial.println(">||");
        break;
      case 4161273600:
        Serial.println("-");
        break;
      case 3927310080:
        Serial.println("+");
        break;
      case 4127850240:
        Serial.println("EQ");
        break;
      case 3910598400:
        Serial.println("0");
        break;
      case 3860463360:
        Serial.println("100+");
        break;
      case 4061003520:
        Serial.println("200+");
        break;
      case 4077715200:
        Serial.println("1");
        break;
      case 3877175040:
        Serial.println("2");
        break;
      case 2707357440:
        Serial.println("3");
        break;
      case 4144561920:
        Serial.println("4");
        break;
      case 3810328320:
        Serial.println("5");
        break;
      case 2774204160:
        Serial.println("6");
        break;
      case 3175284480:
        Serial.println("7");
        break;
      case 2907897600:
        Serial.println("8");
        break;
      case 3041591040:
        Serial.println("9");
        break;
    }
     IrReceiver.resume();
     delay(500);
  }
}
