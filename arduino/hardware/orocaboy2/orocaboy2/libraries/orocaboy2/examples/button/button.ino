
uint16_t ball_x = 0;
uint16_t ball_y = 130;
int8_t face_dir = 1;
int8_t speed = 1;
int test_cnt = 0;

  
void setup() {
  // put your setup code here, to run once:
  gb.begin();
  gb.display.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  static int cnt;
  
    if (gb.update())
    {
      gb.display.clear();

      gb.display.setColor(BLUE);

      gb.display.setCursor(0, 0);
      gb.display.setColor(WHITE);
      gb.display.println("Arduino Games Buttons");
      gb.display.println();
      gb.display.print("Cnt : ");
      gb.display.println(test_cnt++);

      

      gb.display.setColor(BLUE);
      gb.display.drawCircle(gb.display.width()/2    + 10, gb.display.height()/2, 10);        // A
      gb.display.drawCircle(gb.display.width()/2+20 + 10, gb.display.height()/2, 10);        // B

      gb.display.drawCircle(gb.display.width()/2    - 40, gb.display.height()/2, 10);   // MENU
      gb.display.drawCircle(gb.display.width()/2+20 - 40, gb.display.height()/2, 10);   // HOME

      gb.display.drawCircle(gb.display.width()/2/2-5 , gb.display.height()/2, 10);      // left
      gb.display.drawCircle(gb.display.width()/2/2+25, gb.display.height()/2, 10);      // right
      gb.display.drawCircle(gb.display.width()/2/2+10, gb.display.height()/2-15, 10);   // up
      gb.display.drawCircle(gb.display.width()/2/2+10, gb.display.height()/2+15, 10);   // down


      speed = 1;

      if (gb.buttons.repeat(Button::a,     1))
      {
        gb.display.println("Key : A");
        gb.display.fillCircle(gb.display.width()/2 + 10, gb.display.height()/2, 10);
        speed = 3;
      }
      if (gb.buttons.repeat(Button::b,     1))
      {
        gb.display.println("Key : B");
        gb.display.fillCircle(gb.display.width()/2+20 + 10, gb.display.height()/2, 10);
        speed = 5;
      }
      if (gb.buttons.repeat(Button::menu,  1))
      {
        gb.display.println("Key : MENU");
        gb.display.fillCircle(gb.display.width()/2    - 40, gb.display.height()/2, 10);
      }
      if (gb.buttons.repeat(Button::home,  1))
      {
        gb.display.println("Key : HOME");
        gb.display.fillCircle(gb.display.width()/2+20 - 40, gb.display.height()/2, 10);
      }
      if (gb.buttons.repeat(Button::left,  1))
      {
        gb.display.println("Key : LEFT");
        gb.display.fillCircle(gb.display.width()/2/2-5 , gb.display.height()/2, 10);
        face_dir = -1;
        ball_x = (ball_x - speed) % gb.display.width();
      }
      if (gb.buttons.repeat(Button::right, 1))
      {
        gb.display.println("Key : RIGHT");
        gb.display.fillCircle(gb.display.width()/2/2+25, gb.display.height()/2, 10);
        face_dir = 1;
        ball_x = (ball_x + speed) % gb.display.width();
      }
      if (gb.buttons.repeat(Button::up,    1))
      {
        gb.display.println("Key : UP");
        gb.display.fillCircle(gb.display.width()/2/2+10, gb.display.height()/2-15, 10);
        ball_y = (ball_y - speed) % gb.display.height();
      }
      if (gb.buttons.repeat(Button::down,  1))
      {
        gb.display.println("Key : DOWN");
        gb.display.fillCircle(gb.display.width()/2/2+10, gb.display.height()/2+15, 10);
        ball_y = (ball_y + speed) % gb.display.height();
      }
    }  
}
