#include "Characters.h"

#define INIT_PAGE 0
#define GAME_PAGE 1

Image orocaboy = Image(orocaboy_copyData);
uint16_t ball_x = 0;
  
void setup() 
{
  beginGameBuino();
  beginOrocaboy(INDEX_WHITE, 0);
}

void loop() 
{
  static int sys_cnt = 0;
  static int page = INIT_PAGE;
  
  if (updateGameBuino())
  {
    clearDisplay();

    switch(page)
    {
      case INIT_PAGE:
        if (grabButton(Button::home))
        {
          page = GAME_PAGE;
          sys_cnt = 0;
        }
        else
        { 
          setColor(BLACK);
          drawRect(0, 0, gb.display.width(), gb.display.height());

          setCursor(gb.display.width()/2 - 200, gb.display.height()/2-50);
          setColor(WHITE);
          gbPrint(3, "Arduino Character test\n");

          setCursor(gb.display.width()/2 - 120, gb.display.height()/2+30);
          setColor(WHITE);
          gbPrint(2, "Please Insert Coin...\n");
        }      
       break;
      
      case GAME_PAGE:
        if (grabButton(Button::home))
        {
          page = INIT_PAGE;
          sys_cnt = 0;
        }
        else
        { 
          drawGameBackgroundImage();
          drawGrid();

          sysCount(sys_cnt);

          drawButton(BLUE, 40, -35, 10);
          getBtnSignal(40, -35);

          moveOrocaboy();
        }
       break;
    }

    sys_cnt++;
  }  
}

void drawGameBackgroundImage()
{
  setColor(WHITE);
  drawRect(0, 30, gb.display.width(), gb.display.height()-95);
}

void drawGrid()
{
  setColor(BLACK);
  for (int row = 1; row < gb.display.height()/50; row++)
  {
    drawLine(0, (50*row)-20, gb.display.width(), (50*row)-20);
  }

  for (int col = 1; col < gb.display.width()/50; col++)
  {
    drawLine(50*col, 30, 50*col, gb.display.height());
  }    
}

void sysCount(int cnt)
{
  setColor(WHITE);
  setCursor(0, 0);
  gbPrint("Cnt : ");
  gbPrint(cnt++);
  gbPrint("\n");
}

void beginGameBuino()
{
  gb.begin();
  gb.display.clear();
}

void clearDisplay()
{
  gb.display.clear();
}

bool updateGameBuino()
{
  return gb.update();
}

void setCursor(int16_t x, int16_t y)
{
  gb.display.setCursor(x, y);
}

void setColor(Color color)
{
  gb.display.setColor(color);
}

void gbPrint(uint8_t size, const String &s)
{
  gb.display.setFontSize(size);
  gb.display.print(s);
}

void gbPrint(uint8_t size, long num)
{
  gb.display.setFontSize(size);
  gb.display.print(num);
}

void gbPrint(const String &s)
{
  gb.display.print(s);
}

void gbPrint(long num)
{
  gb.display.print(num);
}

void drawRect(int16_t x, int16_t y, int16_t w, int16_t h)
{
  gb.display.fillRect(x, y, w, h);
}

void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
  gb.display.drawLine(x0, y0, x1, y1);
}

void drawImg(uint16_t frame_num, int16_t x, int16_t y, Image& img, int16_t w, int16_t h)
{
  gb.display.drawImage(x, y, img, w, h);
  orocaboy.setFrame(frame_num%4);
}

void drawButton(Color color, int16_t x, int16_t y, int16_t size)
{
  gb.display.setColor(color);

  gb.display.drawCircle(gb.display.width()/2/2-5  + x,    gb.display.height()    + y,    size);   // left
  gb.display.drawCircle(gb.display.width()/2/2+25 + x,    gb.display.height()    + y,    size);   // right
  gb.display.drawCircle(gb.display.width()/2/2+10 + x,    gb.display.height()-15 + y,    size);   // up
  gb.display.drawCircle(gb.display.width()/2/2+10 + x,    gb.display.height()+15 + y,    size);   // down

  gb.display.drawCircle(gb.display.width()/2    - 40 + x, gb.display.height()    + y,    size);   // MENU
  gb.display.drawCircle(gb.display.width()/2+20 - 40 + x, gb.display.height()    + y,    size);   // HOME

  gb.display.drawCircle(gb.display.width()/2    + 10 + x, gb.display.height()    + y,    size);   // A
  gb.display.drawCircle(gb.display.width()/2+20 + 10 + x, gb.display.height()    + y,    size);   // B
}

void getBtnSignal(int16_t x, int16_t y)
{
  if (gb.buttons.repeat(Button::a,     1))
  {
    gb.display.println("Key : A");
    gb.display.setColor(RED);
    gb.display.fillCircle(gb.display.width()/2 + 10 + x, gb.display.height() + y, 10);
  }
  if (gb.buttons.repeat(Button::b,     1))
  {
    gb.display.println("Key : B");
    gb.display.setColor(GREEN);
    gb.display.fillCircle(gb.display.width()/2+20 + 10 + x, gb.display.height() + y, 10);
  }
  if (gb.buttons.repeat(Button::menu,  1))
  {
    gb.display.println("Key : MENU");
    gb.display.setColor(GRAY);
    gb.display.fillCircle(gb.display.width()/2    - 40 + x, gb.display.height() + y, 10);
  }
  if (gb.buttons.repeat(Button::home,  1))
  {
    gb.display.println("Key : HOME");
    gb.display.setColor(GRAY);
    gb.display.fillCircle(gb.display.width()/2+20 - 40 + x, gb.display.height() + y, 10);
  }
  if (gb.buttons.repeat(Button::left,  1))
  {
    gb.display.println("Key : LEFT");
    gb.display.setColor(WHITE);
    gb.display.fillCircle(gb.display.width()/2/2-5  + x, gb.display.height() + y, 10);   
  }
  if (gb.buttons.repeat(Button::right, 1))
  {
    gb.display.println("Key : RIGHT");
    gb.display.setColor(WHITE);
    gb.display.fillCircle(gb.display.width()/2/2+25 + x, gb.display.height() + y, 10);
  }
  if (gb.buttons.repeat(Button::up,    1))
  {
    gb.display.println("Key : UP");
    gb.display.setColor(WHITE);
    gb.display.fillCircle(gb.display.width()/2/2+10 + x, gb.display.height()-15 + y, 10);
  }
  if (gb.buttons.repeat(Button::down,  1))
  {
    gb.display.println("Key : DOWN");
    gb.display.setColor(WHITE);
    gb.display.fillCircle(gb.display.width()/2/2+10 + x, gb.display.height()+15 + y, 10);
  }
}

bool grabButton(Button button)
{
  return gb.buttons.repeat(button,  1);
}

void beginOrocaboy(ColorIndex background_color, uint16_t first_frame_num)
{
  orocaboy.setTransparentColor(background_color);
  orocaboy.setFrame(first_frame_num);  
}

void moveOrocaboy()
{
  const int16_t MIN_X = 0;
  const int16_t MAX_X = 50 * (gb.display.width()/50 - 1);

  const int16_t MIN_Y = 30;
  const int16_t MAX_Y = 50 * (gb.display.height()/50 - 1) - 20;

  static uint16_t frame_num = 0; 
  static int16_t boy_x = 0;
  static int16_t boy_y = 30;

  static uint16_t frame_delay_cnt = 0;

  if (grabButton(Button::right))
  {
    boy_x += 50;
  }
  if (grabButton(Button::left))
  {
    boy_x -= 50;
  }
  if (grabButton(Button::up))
  {
    boy_y -= 50;
  }
  if (grabButton(Button::down))
  {
    boy_y += 50;
  }

  if (grabButton(Button::a))
  {
    boy_x = 0;
    boy_y = 30;
  }

  boy_x = constrain(boy_x, MIN_X, MAX_X);
  boy_y = constrain(boy_y, MIN_Y, MAX_Y);

  drawImg(frame_num, boy_x, boy_y, orocaboy, 50, 50);

  if (frame_delay_cnt%5 == 0)
  {
    frame_num = (frame_num + 1);
  }

  frame_delay_cnt++;
}


