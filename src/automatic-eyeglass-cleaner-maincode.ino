#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

/* PINS */

const int pump = 23; //relay_channel_1
const int blower = 52; //relay_channel_2
const int inValve = 24; //relay_channel_3
const int outValve = 25; //relay_channel_4
const int us_cleaner = 26; //relay_channel_5

const int main_ls_dir = 5; //cytron_motor_drive
const int main_ls_pwm = 6; //cytron_motor_drive
const int rnsr_ls_dir = 7; //cytron_motor_drive
const int rnsr_ls_pwm = 8; //cytron_motor_drive

const int wipr_dir = 9; //cytron_motor_drive
const int wipr_pwm = 10; //cytron_motor_drive

const int enc_A = 3; //encoder_pin_A
const int enc_B = 2; //encoder_pin_B

const int main_ls_hall = 11;

const int vsl_LOW = A0; //vessel_water_level_BOTTOM
const int vsl_HIGH = A1; //vessel_water_level_TOP
const int tank_LOW = A2; //tank_water_level_BOTTOM
const int tank_HIGH = A3; //tank_water_level_TOP

int servoPin = 4;

/* VARIABLES */

double z = 0.0; // vertical_coordinate
long counter = 0; // encoder revolution counter

  
/* VALUES */

const int main_ls_val = 50;
const int rnsr_ls_val = 100;
const int wipr_lft_val = 35;
const int wipr_rgt_val = 30;
const int cyt_stop_val = 0;
const int wipr_stop_val = 0;

const int vsl_lvl_ref = 1111;
const int tank_lvl_ref = 1111;

const int main_ls_up = HIGH;
const int main_ls_down = LOW;
const int rnsr_ls_left = HIGH;
const int rnsr_ls_right = LOW;
const int wipr_lft = HIGH;
const int wipr_rgt = LOW;

const int wipe_time = 2475;
const int rnsr_right_time = 3500;
const int rnsr_left_time = 3500;
const int wipr_lft_time = 550;
const int wipr_rgt_time = 550;
const int blow_time = 10000;

const int wipr_open_ang = 45;

const double ultrasonic = -45.0;
const double rinser = 15.0;
const double wiper = 23.0;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
Servo Servo1;

void setup() {
  pinMode(pump,OUTPUT);
  pinMode(blower,OUTPUT);
  pinMode(inValve,OUTPUT);
  pinMode(outValve,OUTPUT);
  pinMode(us_cleaner,OUTPUT);
  pinMode(main_ls_dir,OUTPUT);
  pinMode(main_ls_pwm,OUTPUT);
  pinMode(rnsr_ls_dir,OUTPUT);
  pinMode(rnsr_ls_pwm,OUTPUT);
  pinMode(wipr_dir,OUTPUT);
  pinMode(wipr_pwm,OUTPUT);
  pinMode(enc_A,INPUT_PULLUP);
  pinMode(enc_B,INPUT_PULLUP);
  pinMode(vsl_LOW,INPUT);
  pinMode(vsl_HIGH,INPUT);
  pinMode(tank_LOW,INPUT);
  pinMode(tank_HIGH,INPUT);
  pinMode(main_ls_hall,INPUT);

  digitalWrite(pump,HIGH);
  digitalWrite(blower,HIGH);
  digitalWrite(inValve,HIGH);
  digitalWrite(outValve,HIGH);
  digitalWrite(us_cleaner,HIGH);

  attachInterrupt(digitalPinToInterrupt(enc_A),enc,CHANGE);

  Servo1.attach(servoPin);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("LensKart");
  lcd.setCursor(0,1);
  lcd.print("Open the front door and place the spectacle");
  Serial.begin(9600);
  //vertical(33.0,1);
}

void loop() {
    vertical(ultrasonic,-1);
    delay(70000);
    vertical(rinser,1);
    rinse();
    analogWrite(rnsr_ls_pwm,0);
    Servo1.write(0);
    delay(500);
    vertical(wiper,1);
    blow();
    wipe();
    vertical(0,-1);
    delay(60000);

}
void vertical(double m, double x) // m - target coordinate || x=1 for moving up || x=-1 for moving down
{
  if(x == 1)
  { 
    digitalWrite(main_ls_dir,main_ls_up);
    while(z <= m)
     {
      analogWrite(main_ls_pwm,main_ls_val);
      Serial.println(z);
     }
  }
  if(x == -1)
  { 
    digitalWrite(main_ls_dir,main_ls_down);
    while(z >= m)
    {
     analogWrite(main_ls_pwm,main_ls_val);
      Serial.println(z);
    } 
  }
  analogWrite(main_ls_pwm,cyt_stop_val);
}

void enc()
{
  if(digitalRead(enc_A) != digitalRead(enc_B))
   counter++;
  else
   counter--;
  z=counter/600;
}

int waterlvl(int x) //x=1 for vessel || x=2 for tank || returns 2-full 1-not_full 0-empty
{ 
  int a,b,c;
  if(x == 1)
  {
    a= vsl_LOW;
    b= vsl_HIGH;
    c= vsl_lvl_ref;
  }
  if(x == 2)
  {
    a= tank_LOW;
    b= tank_HIGH;
    c= tank_lvl_ref;
  }
  if(analogRead(a) > c)
   if(analogRead(b) > c)
    return 2;
   return 1;
  return 0;
}

void rinse()
{
 digitalWrite(rnsr_ls_dir,rnsr_ls_right);
 analogWrite(rnsr_ls_pwm,rnsr_ls_val);
 delay(rnsr_right_time);
 digitalWrite(rnsr_ls_dir,rnsr_ls_left);
 delay(rnsr_left_time);
 analogWrite(rnsr_ls_val,cyt_stop_val); 
}

void wipe()
{ 
  Servo1.write(wipr_open_ang);  
  delay(1000);
  long t = millis();
  while((millis()-t)<=wipe_time)
  {
  digitalWrite(wipr_dir,wipr_lft);
  analogWrite(wipr_pwm,wipr_lft_val);
  delay(wipr_lft_time);
  digitalWrite(wipr_dir,wipr_rgt);
  analogWrite(wipr_pwm,wipr_rgt_val);
  delay(wipr_rgt_time);
  }
  analogWrite(wipr_pwm,cyt_stop_val);
  Servo1.write(0);
  delay(1000);
}
void blow()
{
  digitalWrite(blower,LOW);
  delay(blow_time);
  digitalWrite(blower,HIGH);
}
void homestate()
{
  while(digitalRead(main_ls_hall)!=LOW)
  {
    digitalWrite(main_ls_dir,main_ls_down);
    analogWrite(main_ls_pwm,main_ls_val);
  }
  analogWrite(main_ls_pwm,cyt_stop_val);
}
