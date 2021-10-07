
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk nya
#include <Servo.h>

char auth[] = "4o_B_l5gs8CSFFnkWTIeXRjBpwlIet-A"; // token yang dikirim dari blynk ke email masing masing

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo 1724";
char pass[] = "20042004";

Servo muter;

BLYNK_WRITE(V1)
{
  muter.write(param.asInt());
  // fungsi blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  
  Blynk.begin(auth, ssid, pass); // memulai program kode autentikasi, ssid, dan password

  muter.attach(2); //setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run();
}
