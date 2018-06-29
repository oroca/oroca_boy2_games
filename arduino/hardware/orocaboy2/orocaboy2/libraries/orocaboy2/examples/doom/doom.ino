
extern "C" 
{
void D_DoomMain (void);
err_code_t audioSetVol(uint8_t volume);
}

  
void setup() {
  // put your setup code here, to run once:
  gb.begin();
  gb.display.clear();

  audioSetVol(80);
  D_DoomMain();
}

void loop() {
}
