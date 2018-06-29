#include "hamster.h"


Hamster hamster;


#define SPEED   20

uint32_t rx_count = 0;
int robot_speed_l = 0;
int robot_speed_r = 0;


void updateRobot(void);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  

  hamster.begin("");
  
  gb.begin();
  gb.display.clear();  
}

void loop() {
  // put your main code here, to run repeatedly:
  int r_x;
  int r_y;
  int r_w = 50;
  int r_h = 50;
  int l_s = 0;
  int r_s = 0;
  int s_length = 80;

  if (hamster.update() == true)
  {
    rx_count++;
  }

  if (gb.update())
  {      
    gb.display.clear();  
    gb.display.setColor(WHITE);
    gb.display.print("RX Cnt : ");    
    gb.display.println(rx_count);        

    gb.display.print("L : ");    
    gb.display.println(hamster.leftProximity());        
    gb.display.print("R : ");    
    gb.display.println(hamster.rightProximity());        


    r_x = gb.display.width()/2 - r_w/2;
    r_y = gb.display.height()/2 - r_h/2;

    l_s = constrain(hamster.leftProximity(), 0, s_length);
    r_s = constrain(hamster.rightProximity(), 0, s_length);


    gb.display.setColor(BLUE);
    gb.display.fillRect(r_x, r_y, r_w, r_h);
    
    gb.display.setColor(YELLOW);
    gb.display.fillRect(r_x       , r_y - s_length + l_s, 10, s_length-l_s);
    gb.display.fillRect(r_x+r_w-10, r_y - s_length + r_s, 10, s_length-r_s);


    updateRobot();
  }
}

void updateRobot(void)
{
  robot_speed_l = 0;
  robot_speed_r = 0;

  if (gb.buttons.repeat(Button::up, 1))
  {
    robot_speed_l = SPEED;
    robot_speed_r = SPEED;
  }
  if (gb.buttons.repeat(Button::down, 1))
  {
    robot_speed_l = -SPEED;
    robot_speed_r = -SPEED;      
  }
  if (gb.buttons.repeat(Button::left, 1))
  {
    robot_speed_l = -SPEED;
    robot_speed_r =  SPEED;      
  }
  if (gb.buttons.repeat(Button::right, 1))
  {
    robot_speed_l =  SPEED;
    robot_speed_r = -SPEED;      
  }
  if (gb.buttons.repeat(Button::up, 1) && gb.buttons.repeat(Button::left, 1))
  {
    robot_speed_l = 0;
    robot_speed_r = SPEED;
  }
  if (gb.buttons.repeat(Button::up, 1) && gb.buttons.repeat(Button::right, 1))
  {
    robot_speed_l = SPEED;
    robot_speed_r = 0;
  }
  if (gb.buttons.repeat(Button::down, 1) && gb.buttons.repeat(Button::left, 1))
  {
    robot_speed_l = 0;
    robot_speed_r = -SPEED;
  }
  if (gb.buttons.repeat(Button::down, 1) && gb.buttons.repeat(Button::right, 1))
  {
    robot_speed_l = -SPEED;
    robot_speed_r = 0;
  }

  hamster.wheels(robot_speed_l, robot_speed_r);
}