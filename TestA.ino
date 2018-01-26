#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Pantalla 128x32 bits posibles coordenadas de impresiòn 127x31

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 OLED(OLED_RESET);

//Global variables
int surveyStatus=0;
//

// Button pin definitions

#define BUTTON_A D6
#define BUTTON_B D5
#define BUTTON_C D4
#define BUTTON_D D3
int CHOICE_NONE= 0;
#define CHOICE_A 1
#define CHOICE_B 2
#define CHOICE_C 3
#define CHOICE_D 4
 
void setup()   {
  OLED.begin();
  OLED.clearDisplay();
 
  //Add stuff into the 'display buffer'
  OLED.setTextWrap(false);
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
 //OLED.startscrollleft(0x00, 0x0F); //make display scroll 

  pinMode(D6, INPUT_PULLUP);
  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);

}

 
 
void loop() {

 /*OLED.setCursor(0,0);
   OLED.println("Existe prueba");
   OLED.display(); //output 'display buffer' to screen  
   delay(1000);
   OLED.clearDisplay();*/
 attractMode(); // Blink lights while waiting for user to press a button
 whiteBlackScreen(); //Puts the screen white and black
 if (surveyStatus==1){
   OLED.setCursor(0,0);
   OLED.println("Existe prueba");
   OLED.display(); //output 'display buffer' to screen  
   delay(3000);
   OLED.clearDisplay();
 }
 else{
   OLED.setCursor(0,0);
   OLED.println("No existe prueba");
   OLED.display(); //output 'display buffer' to screen  
   delay(3000);
   OLED.clearDisplay();
 }


  
}

void printPluscleanScreen (String msg)
 {
   OLED.setCursor(0,0);
   OLED.println(msg);
   OLED.display(); //output 'display buffer' to screen  
   delay(500);
   OLED.clearDisplay();
 }

 int checkButton(void)
{
 if (digitalRead(D6) == 0) return(1); 
 else if (digitalRead(D5) == 0) return(2); 
 else if (digitalRead(D4) == 0) return(3); 
 else if (digitalRead(D3) == 0) return(4);

 return(CHOICE_NONE); // If no button is pressed, return none
}

void whiteBlackScreen(void)
{
  OLED.setTextColor(WHITE);
  OLED.display(); //output 'display buffer' to screen  
  delay(1000);
  OLED.clearDisplay();
}

 void attractMode(void)
{
 while(1) 
 {
   printPluscleanScreen("Presione");
   if (checkButton() != CHOICE_NONE) return;

   printPluscleanScreen("Presione un");
   if (checkButton() != CHOICE_NONE) return;

   printPluscleanScreen("Presione un boton");
   if (checkButton() != CHOICE_NONE) return;

   printPluscleanScreen("Presione un boton!");
   if (checkButton() != CHOICE_NONE) return;
 }
}
