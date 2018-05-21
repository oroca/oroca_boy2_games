
extern "C" 
{
void D_DoomMain (void);
}

  
void setup() {
  // put your setup code here, to run once:
  gb.begin();
  gb.display.clear();

  D_DoomMain();
}

void loop() {
}
