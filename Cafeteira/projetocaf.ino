#include <Ultrasonic.h>
#include <Servo.h>
#include <Servo.h> 
HC_SR04 sensor1(4, 5);
HC_SR04 sensor2(2, 3);

Servo meuservo;     
Servo meuservo2;
char stateMenu;

void setup() {
  Serial.begin(9600);
  meuservo.attach(9);  
  meuservo2.attach(12);
}


void loop() {

  delay(2000);

  Serial.println(String("Distancia: ") + sensor1.distance() + String(" mm"));
  delay(2000);


  switch (stateMenu) {
    case 0:

      if (sensor1.distance() < 20 ) {
        stateMenu = 1;
        delay(1000);
        Serial.println("Ligado");
        meuservo.write(0);
      } else {
        Serial.println("Aproxime-se para ligar");
        Serial.println("");
        meuservo.write(90);
        meuservo2.write(90);
      }
      break;

    case 1:               
      if (sensor2.distance() > 30 ) {
        Serial.println("Café Longo selecionado");
        meuservo2.write(0);                 
        Serial.println("Café Longo em preparo");
        delay(6000);
        Serial.println("Café Longo pronto");
        Serial.println("");
        stateMenu = 0;
      } else {
        Serial.println("Café Curto selecionado");
        meuservo2.write(180);
        Serial.println("Café Curto em preparo");
        delay(3000);
        Serial.println("Café Curto pronto");
        Serial.println("");
        stateMenu = 0;
      }
      break;


      delay(3000);                        
  }
}