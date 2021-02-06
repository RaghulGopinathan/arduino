
/*ANDROID ARDUINO BLUETOOTH RC CAR  */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial BT(0,1); //RX, TX respetively
int led = 3;        //led

int outPin1 = 5;     //motor1
int outPin2 = 6;    //motor1

int outPin4 = 11;   //motor2
int outPin3 = 12;   //motor2

char bt = 0;  
int value=0;//BT 
/*-----------------------------------------------------------------------------------------------------*/
String voice;
String store;
int RED = 9;
int tim=0;// Red LED at pin 9
void RedOn(){
// Red LED on, others off

lcd.begin();
lcd.backlight();
digitalWrite (RED, HIGH);
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print(" ******RC******"); //You can write 16 Characters per line .
delay(2000);//Delay used to give a dynamic effect
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("  Team NOVUS");
delay(1000); 
lcd.clear();//Clean the screen
lcd.setCursor(0,0); 
lcd.print(" Ready to move ");

/*lcd.setCursor(0,1);
lcd.print(" TEAM NOVUS ");*/
value=1;
}
void buzzer()
{
  tone(10,4000,750);
  delay(1000);
   tim=1;
}
void RedOff(){ // Red LED off, others on
lcd.backlight();
digitalWrite (RED, LOW);
value=0;
lcd.clear();
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("RC TURNING OFF...");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Shutting down...");
delay(1000);
lcd.clear();
}
void setup()
{
//Initializing display
//lcd.backlight();//To Power ON the back light
//lcd.backlight();// To Power OFF the back light
BT.begin(9600);
Serial.begin(9600);
pinMode(RED, OUTPUT);
  pinMode(outPin1,OUTPUT);
  pinMode(outPin2,OUTPUT);
  pinMode(outPin3,OUTPUT);
  pinMode(outPin4,OUTPUT);
  
 // pinMode(led,OUTPUT);
}
void loop()
{
while(BT.available()) {
delay(10);
char c=BT.read();
if(c=='#')
{break; }
voice += c;
}
if (voice.length() > 0) {
Serial.println(voice);
if(voice =="engine start" || voice =="engines." || voice=="engine stock" || voice=="indian stock" || voice =="engines start"&& tim==0)
{
RedOn();
buzzer();
}
else if(voice =="engine of" || voice=="enginesoff" || voice=="engine off" || voice=="engine stop" || voice=="indian stop"){
RedOff();
buzzer();
}
voice="";
}
 if(value==1)
 {
 if(Serial.available() > 0)
  {
   // BT.begin(9600);
     bt = Serial.read();
    //digitalWrite(led, 1);
    /*_________________________________________________________________________________________________*/
    
    if(bt == 'F')        //move forwards
    {
      digitalWrite(outPin1,HIGH);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,HIGH);
      digitalWrite(outPin4,LOW);
    }
    else if (bt == 'B')       //move backwards
    {
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,HIGH);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,HIGH);
    }
    else if (bt == 'S')     //stop!!
    {   
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,LOW);
    }
    else if (bt == 'R')    //right
    {
      digitalWrite(outPin1,HIGH);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,LOW);
    }
    else if (bt == 'L')     //left
    {
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,HIGH);
      digitalWrite(outPin4,LOW);
    }
    else if (bt == 'I')    //forward right
    {
      digitalWrite(outPin1,HIGH);
      digitalWrite(outPin2,LOW);
      digitalWrite(outPin3,LOW);
      digitalWrite(outPin4,HIGH);
    }
    else if (bt== 'G')    //forward left
    {
      digitalWrite(outPin1,LOW);
      digitalWrite(outPin2,HIGH);
      digitalWrite(outPin3,HIGH);
      digitalWrite(outPin4,LOW);
    }   
    } 
 }
}
  /*THE---------------- E N  D -----------------------------------------------------------------------*/
