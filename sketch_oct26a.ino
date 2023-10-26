#include <SoftwareSerial.h>


int LDR=A0; // select the input pin for the LDR&Temperature Sensor
int Temp=A5;

int sensorLDR=0;// variable to store the value coming from the sensor
int sensorTemp=0;
int led=3;
int fan=2;




void setup() 
{ 

	pinMode(led, OUTPUT);
	pinMode(fan, OUTPUT);  
 	pinMode(LDR, INPUT);
  	pinMode(Temp,INPUT);
	Serial.begin(9600);
}

void loop()

{


    sensorLDR = analogRead(LDR);
	sensorTemp = map(((analogRead(A5)-20)*3.04),0,1023,-40,125);//0,1023 are minima and maxima of sensor and -40 to 125 are mapped values...
    Serial.println(sensorTemp);
  	
	
  	//for led
   	if (sensorLDR < 700)

      {
      digitalWrite(led,HIGH);
      }
    else
      {
      digitalWrite(led,LOW);  
      }
	
  	//for fan
  	if (sensorTemp>40)//given if temp>40...turn on the fan

      {
      digitalWrite(fan,HIGH);
      }
    else if(sensorTemp<40 && sensorTemp>35)//second condition
      {
      digitalWrite(fan,LOW);  
      }
  	else
      {
      digitalWrite(fan,HIGH);
      }
}