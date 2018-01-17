

#include <DHT.h>
#define DHTPIN 45
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const int pinTIE = A10;  //tierra

const int pinUV  = A12;
const int pinCO2 = A13;
const int pinGAS = A14;
const int pinLUZ = A15;
                       
float valTIE= 0;

int valUV  = 0;
int valCO2 = 0;
int valGAS = 0;
int valLUZ = 0;        

void setup()
{
  Serial.begin(9600);
  dht.begin();
  
  pinMode(pinUV,  INPUT );
  pinMode(pinCO2, INPUT );
  pinMode(pinGAS, INPUT );
  pinMode(pinLUZ, INPUT );        
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Falla sensor temperatura/humedad");
  } else {
    Serial.print("Humedad:     "); 
    Serial.print(h);
    Serial.println(" %\t");
    Serial.print("Temperatura: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  
  valTIE  = analogRead(pinTIE);
  valLUZ = analogRead(pinLUZ);
  valUV  = analogRead(pinUV);
  valCO2 = analogRead(pinCO2);
  valGAS = analogRead(pinGAS);

  Serial.print("TIE ");
  Serial.println(valTIE);
  Serial.print("UV  ");
  Serial.println(valUV);
  Serial.print("CO2 ");
  Serial.println(valCO2);
  Serial.print("GAS ");
  Serial.println(valGAS);
  Serial.print("LUZ ");
  Serial.println(valLUZ);   
  Serial.println();
  delay(3000);     
}
