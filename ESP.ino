// #define BLYNK_TEMPLATE_ID "TMPL3B-XJ-Ipm"
// #define BLYNK_TEMPLATE_NAME "Car Parking"
// #define BLYNK_AUTH_TOKEN "sgFats22vn4lfDmzDwCi7P5bJ6gvoa_j"
#define BLYNK_TEMPLATE_ID "TMPL3ZEizXoWh"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "nmRz_eA3YBnB7x0tH8uA_QCAZq-LxLXM"
#define BLYNK_PRINT Serial

#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "realme";
char pass[] = "87654321";



SoftwareSerial mySerial(D1, D2);  //Rx, Tx pins

// BLYNK_WRITE(V5)
// {
//   String slot = mySerial.readStringUntil('\r');
//   Serial.println(slot);
//   // String a="Slot";

// }


void setup() {
  mySerial.begin(9600);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  String str = mySerial.readStringUntil('\r');
  
  // Check which parking slot is available
  if (str == "1") {
    Blynk.virtualWrite(V0, "1");
    Blynk.virtualWrite(V1, "3");

  }
  else if (str == "2") {
    Blynk.virtualWrite(V0, "2");
    Blynk.virtualWrite(V1, "2");
  }
  else if (str == "3") {
    Blynk.virtualWrite(V0, "3");
    Blynk.virtualWrite(V1, "1");
  }
  else if (str == "4") {
    Blynk.virtualWrite(V0, "4");
    Blynk.virtualWrite(V1, "0");
  }
  else if (str == "0") {
    Blynk.virtualWrite(V0, "Parking Is Full");
    Blynk.virtualWrite(V1, "4");
    
  }

  // // Check availability of slot 1
  // if (str == "s1") {
  //   Blynk.virtualWrite(V1, "Filled");
  // }
  // else if (str == "n1") {
  //   Blynk.virtualWrite(V1, "____");
  // }

  // // Check availability of slot 2
  // if (str == "s2") {
  //   Blynk.virtualWrite(V2, "Filled");
  // }
  // else if (str == "n2") {
  //   Blynk.virtualWrite(V2, "____");
  // }

  // // Check availability of slot 3
  // if (str == "s3") {
  //   Blynk.virtualWrite(V3, "Filled");
  // }
  // else if (str == "n3") {
  //   Blynk.virtualWrite(V3, "____");
  // }

  // // Check availability of slot 4
  // if (str == "s4") {
  //   Blynk.virtualWrite(V4, "Filled");
  // }
  // else if (str == "n4") {
  //   Blynk.virtualWrite(V4, "____");
  // }

  Blynk.run();
}
