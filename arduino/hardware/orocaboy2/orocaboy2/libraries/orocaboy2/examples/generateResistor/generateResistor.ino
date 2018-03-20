#define RESISTOR_COLOR_MAX   8
#define RESISTOR_SELECT_MAX  3
#define RESISTOR_DRAW_MAX    8

typedef struct {
  uint8_t  value;
  Color    color;
  uint16_t x_axis;
  uint16_t y_axis;
} resistor_part_part_t;

const Color part_color[RESISTOR_COLOR_MAX] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
bool flag_draw = false;
int test_cnt = 0;
uint8_t i;
uint32_t resistor_value;

resistor_part_part_t resistor_part[RESISTOR_DRAW_MAX];


void setup() {
  // put your setup code here, to run once:
  uint16_t div_x_pixel = gb.display.width()/RESISTOR_DRAW_MAX;

  for (i = 0; i < RESISTOR_DRAW_MAX; i++)
  {
    resistor_part[i].x_axis = div_x_pixel + i*div_x_pixel;
    resistor_part[i].y_axis = gb.display.height() / 2 ;
  }
  
  gb.begin();
  gb.display.clear(WHITE);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int cnt;

  if (gb.update())
  {
    gb.display.clear(WHITE);

    gb.display.setCursor(0, 0);
    gb.display.setColor(BLUE);
    gb.display.println();
    gb.display.println("  Arduino Resistor Random Test");
    gb.display.println();
    gb.display.print("  Cnt : ");
    gb.display.println(test_cnt++);

    if (flag_draw == true)
    {
      gb.display.print("                    Goal : ");
      
      if((resistor_value >= 0)&&(resistor_value < 1000))
      {
        gb.display.println(resistor_value);
      }
      else if((resistor_value >= 1000)&&(resistor_value < 1000000))
      {
        gb.display.print(resistor_value/1000);
        if(resistor_value%1000 > 0)
        {
          gb.display.print(".");
          gb.display.print(resistor_value%1000/100);  
        }
        gb.display.println("K");
      }
      else
      {
        gb.display.print(resistor_value/1000000);
        if(resistor_value%1000000 > 0)
        {
          gb.display.print(".");
          gb.display.print(resistor_value%1000000/100000);  
        }
        gb.display.println("M");        
      }

      /* Display selected all resistor_parts */
      for (i = 0; i < RESISTOR_DRAW_MAX; i++)
      {
        gb.display.setColor(resistor_part[i].color);
        gb.display.fillRoundRect(resistor_part[i].x_axis, resistor_part[i].y_axis, 10, 30, 5);
      }

      for (i = 0; i < RESISTOR_SELECT_MAX; i++)
      {
        gb.display.setColor(resistor_part[i].color);
        gb.display.fillRoundRect(gb.display.width()/2 + 110 + (i * 20), gb.display.height() - 60, 10, 30, 5);
      }
    }

    /* Check button for operation */
    if (gb.buttons.repeat(Button::a,     1))
    {
      gb.display.println("Key : DRAW");
      flag_draw = true;
    }
    if (gb.buttons.repeat(Button::b,     1))
    {
      gb.display.println("Key : ERASE");
      flag_draw = false;
    }
    if (gb.buttons.repeat(Button::menu,  1))
    {
      gb.display.println("Key : GENERATE");

      /* Select random color  */
      srand(millis());
      for (i = 0; i < RESISTOR_DRAW_MAX; i++)
      {
        resistor_part[i].value = rand()%RESISTOR_COLOR_MAX;
        resistor_part[i].color = part_color[resistor_part[i].value];
      }

      /* Calculate selected resistor_parts */
      resistor_value = (resistor_part[0].value*10 + resistor_part[1].value);
      resistor_value *= pow(10, resistor_part[2].value);
    }
    if (gb.buttons.repeat(Button::home,  1))
    {
      gb.display.println("Key : home");
    }
    if (gb.buttons.repeat(Button::left,  1))
    {
      gb.display.println("Key : LEFT");
    }
    if (gb.buttons.repeat(Button::right, 1))
    {
      gb.display.println("Key : RIGHT");
    }
    if (gb.buttons.repeat(Button::up,    1))
    {
      gb.display.println("Key : UP");
    }
    if (gb.buttons.repeat(Button::down,  1))
    {
      gb.display.println("Key : DOWN");
    }
  }
}
