#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <SimpleTimer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

SimpleTimer timer;

WidgetLCD lcd(V1);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);

  while (Blynk.connect() == false) {
    // Wait until connected
  }
}
void notifyOnButtonPress()
{
  // Invert state, since button is "Active LOW"
  int isButtonPressed = !digitalRead(2);
  if (isButtonPressed) {
    BLYNK_LOG("Button is pressed.");

    Blynk.notify("Please open up! Somebody is on the door!");
     lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(4, 0, "Open"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(4, 1, "The Door!");
  }
}

void emailOnButtonPress()
{

  int isButtonPressed = !digitalRead(2); // Invert state, since button is "Active LOW"

  if (isButtonPressed) // You can write any condition to trigger e-mail sending
  {
    BLYNK_LOG("Button is pressed."); // This can be seen in the Serial Monitor
    Blynk.email("kaustubhagarwal18@gmail.com", "Subject: Doorbell", "Please open up! Somebody is on the door!");
     lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(4, 0, "Open"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(4, 1, "The Door!");

  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}