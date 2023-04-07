//Pines de conexión del driver
int Pin_Motor_Der_A = 8;
int Pin_Motor_Der_B = 9;
int Pin_Rele = 10;
int estado=0;

#include <Servo.h> // Se incluye la Libreria del Servo 1
Servo servo1; //Se declara la variable del Servo 1

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  servo1.attach(11); //Iniciamos el servo para que empiece a trabajar en el pin 10
  
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Rele, OUTPUT);

}

void loop() {

  if (Serial.available()) {
     estado = Serial.read();
  
}
/*ADELANTE*/
 if (estado =='a'){ //ADELANTE
  digitalWrite (Pin_Motor_Der_A, HIGH);//D8
  digitalWrite (Pin_Motor_Der_B, LOW);//D9
   }
 /*FUNCION STOP*/  
if(estado=='S'){
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  servo1.write(86); //Equivalente a desplazarse al angulo 90°
   }

/*RETROCESO*/
if (estado =='b'){ 
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, HIGH);
/*FUNCION STOP*/ 
   }
if(estado=='S'){
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  servo1.write(86); //Equivalente a desplazarse al angulo 90°
   }
/*EFECTOS*/
if (estado =='1'){ //EFECTOS ON
 digitalWrite (Pin_Rele, HIGH);
 }
 if (estado =='0'){ //EFECTOS OFF
 digitalWrite (Pin_Rele, LOW);
 }

/*DERECHA*/
  if (estado =='d'){ //DERECHA
  servo1.write(135);//Equivalente a desplazarse al angulo 135° 
  delay(50); //Espera de 1 Segundo
  digitalWrite (Pin_Motor_Der_A, HIGH);//D8
  digitalWrite (Pin_Motor_Der_B, LOW);//D9
  }
/*FUNCION STOP*/ 
  if(estado=='S'){
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  servo1.write(86); //Equivalente a desplazarse al angulo 90°
   }
   
/*IZQUIERDA*/
  if (estado =='i'){ //IZQUIERDA
  servo1.write(45);//Equivalente a desplazarse al angulo 45° 
  delay(50); //Espera de 1 Segundo
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
}
/*FUNCION STOP*/ 
 if(estado=='S'){
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  servo1.write(86); //Equivalente a desplazarse al angulo 90°
   }
    }
