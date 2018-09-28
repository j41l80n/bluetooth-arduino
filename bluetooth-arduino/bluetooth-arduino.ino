#include <Bluetooth_HC05.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 9); // RX, TX

int data = 0;

void setup()
{
  Serial.begin(9600);
  Bluetooth.begin(9600);

  Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
}

void loop()
{
  Bluetooth.println("teste");

  if (Bluetooth.available()) { //wait for data received
    data = Bluetooth.read();
    if (data == '1') {
      Serial.println("LED On!");
    }
    else if (data == '0') {
      // digitalWrite(LED, 0);
      Serial.println("LED Off!");
      // Bluetooth.println("LED  On D13 Off ! ");
    }
  }
  else
  {
    Serial.println("not availSable");
  }
  delay(100);
}
