#include <SoftwareSerial.h> //Include softwareserial library
SoftwareSerial BLUETOOTH(0,1);

String voice;
int shelf_motor=6;
int shelf_motor1=7;
int draw_motor=11;
int draw_motor1=12;



void shelfmotoron()
{

digitalWrite(shelf_motor, HIGH);

digitalWrite(shelf_motor1, LOW);
delay(1000);
digitalWrite(shelf_motor, LOW);

digitalWrite(shelf_motor1, LOW);

}
void drawmotoron()
{
digitalWrite(draw_motor, LOW);

digitalWrite(draw_motor1, HIGH);
delay(2000);
digitalWrite(draw_motor, LOW);

digitalWrite(draw_motor1, LOW);

}

void shelfmotoroff()
{
digitalWrite(shelf_motor, LOW);

digitalWrite(shelf_motor1, LOW);
}

void drawmotoroff()
{

digitalWrite(draw_motor, LOW);

digitalWrite(draw_motor1, LOW);
delay(2000);
}

void shelfmotordown()
{

digitalWrite(shelf_motor, LOW);

digitalWrite(shelf_motor1, HIGH);
delay(1000);
digitalWrite(shelf_motor, LOW);

digitalWrite(shelf_motor1, LOW);


}

void drawmotor()
{

digitalWrite(draw_motor,  HIGH);

digitalWrite(draw_motor1, LOW);
delay(2000);
digitalWrite(draw_motor, LOW);

digitalWrite(draw_motor1, LOW);

}


void setup() 
{

Serial.begin(9600);
BLUETOOTH.begin(9600);

pinMode(shelf_motor,OUTPUT);
pinMode(shelf_motor1,OUTPUT);


pinMode(draw_motor,OUTPUT);
pinMode(draw_motor1,OUTPUT);


}

void loop()
{
  
while (Serial.available()) 

{ delay(10); 

char c = Serial.read(); 

if (c =='#')

{

break; 
}

voice += c;

}

if (voice.length() > 0)

{

if(voice == "*lift")

{

shelfmotoron();

}
if (voice=="*down")
 
{
shelfmotordown();
}

else if(voice == "*wait")

{

shelfmotoroff();
}
{
  
while (Serial.available()) 

{ delay(10); 

char c = Serial.read(); 

if (c =='#')

{

break; 
}

voice += c;

}


if (voice.length() > 0)

{

if(voice =="*open")

{

drawmotoron();

}

if (voice== "*close") 

{
drawmotor();
}

else if(voice == "*standby")

{

drawmotoroff();

}
}

{
  voice="";
}

 }

 } 
}

 
