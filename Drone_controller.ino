#include <Wire.h>
#include <SoftWire.h>
#include <Wire_slave.h>

#include <U8glib.h>

U8GLIB_SSD1306_128X64 display(U8G_I2C_OPT_NONE);

#define RX_bt PB6
#define TX_bt PB7
#define SCL_led PB8
#define SDA_led PB9
#define B1_TurnRight PA15
#define B2_TurnLeft PB3
#define B3 PA11
#define B4 PA10
#define B5 PA9
#define MOSI_mk1 PB15
#define CSN_mk1 PB11
#define CE_mk1 PB10
#define SCK_mk1 PB13
#define MISO_mk1 PB14
#define Y_power PA4
#define Y_move PA6
#define X_move PA7

boolean turnRight = false;
boolean turnLeft = false;
uint8_t power;
int8_t x_fly;
int8_t y_fly;
uint8_t drone_bat;//map values from 0 to 99
uint8_t controller_bat;//map values from 0 to 99

void setup() {
  // put your setup code here, to run once:
  pinMode(Y_power, INPUT);
  pinMode(Y_move, INPUT);
  pinMode(X_move, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  MoveInput();

}

void DisplayWrite(){
  display.setFont(u8g_font_6x13);
  display.setPrintPos(0,20);
  display.print("Drone bat: " + drone_bat + "%");
  display.setPrintPos(0,40);
  display.print("Controller bat: " + controller_bat + "%");
}

void DisplayPrint(){
  display.firstPage();
  do{
    DisplayWrite();
  }while(display.nextPage());
}

void MoveInput(){
  power = analogRead(Y_power);
  x_fly = analogRead(X_move-512);
  y_fly = analogRead(Y_move-512);
  if(digitalRead(B1_TurnRight) == HIGH){
    turnRight = true;
  }else{
    turnRight = false;
  }
  if(digitalRead(B2_TurnLeft) == HIGH){
    turnLeft = true;
  }else{
    turnLeft = false;  
  }
}
