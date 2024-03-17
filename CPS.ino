
#include <Servo.h>  //includes the servo library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ir_enter 4
#define ir_back 3

#define ir_car1 13
#define ir_car2 10
#define ir_car3 9
#define ir_car4 8

int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
int s1=0,s2=0,s3=0,s4=0;
int slot = 4;
int flag1 = 0, flag2 = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {

  Serial.begin(9600);
  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);
  myservo.attach(2);
  myservo.write(90);



  lcd.backlight();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  CAR PARKING  ");
  lcd.setCursor(0, 1);
  lcd.print("    SYSTEM  ");

  delay(2000);

  lcd.clear();

  Read_Sensor();
  int total = S1 + S2 + S3 + S4;
  
  slot = slot - total;
}

void loop() {

  Read_Sensor();
  lcd.setCursor(0, 0);
  lcd.print("  Have Slot: ");
  lcd.print(slot);
  Serial.println(slot);
  delay(1000);
  lcd.print("    ");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  if (S1 == 1) {
    lcd.print("S1:Fill ");
    s1=1;
  } else {
    lcd.print("S1:----");
  s1=0;
  }

  lcd.setCursor(8, 0);
  if (S2 == 1) {
    lcd.print("S2:Fill ");
s2=1;
  } else {
    lcd.print("S2:----");
    s2=0;
  }

  lcd.setCursor(0, 1);
  if (S3 == 1) {
    lcd.print("S3:Fill ");
s3=1;                 
  } else {
    lcd.print("S3:----");
    s3=0;
  }

  lcd.setCursor(8, 1);
  if (S4 == 1) {
    lcd.print("S4:Fill ");
    s4=1;
  } else {
    lcd.print("S4:----");
    s4=0;
    
  }
  delay(1000);
  lcd.clear();

  if (digitalRead(ir_enter) == 0 && flag1 == 0) {
    if (slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(180);
        slot = slot - 1;
      }
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Parking Full ");
      delay(1000);
    }
  }

  if (digitalRead(ir_back) == 0 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(180);
      if (slot != 4) {
        slot = slot + 1;
      }
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo.write(90);
    flag1 = 0, flag2 = 0;
  }

  // if(s1==1){
  //   Serial.println("s1");
  //   delay(1000);
  // }else{
  //   Serial.println("n1");
  //   delay(1000);
  // }
  // if(s2==1){
  //   Serial.println("s2");
  //   delay(1000);
  // }else{
  //   Serial.println("n2");
  //   delay(1000);
  // }
  // if(s3==1){
  //   Serial.println("s3");
  //   delay(1000);
  // }else{
  //   Serial.println("n3");
  //   delay(1000);
  // }
  // if(s4==1){
  //   Serial.println("s4");
  //   delay(1000);
  // }else{
  //   Serial.println("n4");
  //   delay(1000);
  // }
}

void Read_Sensor() {
  S1 = 0, S2 = 0, S3 = 0, S4 = 0;

  if (digitalRead(ir_car1) == 0) { S1 = 1; }
  if (digitalRead(ir_car2) == 0) { S2 = 1; }
  if (digitalRead(ir_car3) == 0) { S3 = 1; }
  if (digitalRead(ir_car4) == 0) { S4 = 1; }
}
