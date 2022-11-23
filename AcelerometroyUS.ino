//sensor ultrasónico y acelerómetro
//Adaptación Dr. Fernando Aldana Franco
#include <math.h>
const int x_pin = A1; // connect x_out of module to A1
const int y_pin = A2; // connect y_out of module to A2 
const int z_pin = A3; // connect z_out of module to A3
const int tiempo_lectura=1000; // 1 segundo

int trig=4; //Trigger pin
int echo=3; //Echo pin
void setup() {
  pinMode(trig,OUTPUT); //Salida
  pinMode(echo,INPUT); //Entrada
  digitalWrite(trig,LOW);
  Serial.begin(9600); 
  
}

void loop() {
  Serial.println();
  lectura_US(); //Función de sensor
  Serial.println();
  lectura_Acelerometro(); 
  delay(tiempo_lectura);
}

void lectura_US(void){
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long tiempo=pulseIn(echo,HIGH);
  long distancia=tiempo/59;

  Serial.print("Lectura del sensor: ");
  Serial.print(distancia);
  Serial.print("  cm");
  Serial.println();
}

void lectura_Acelerometro(void){
  int x_adc, y_adc, z_adc; 
  double x_g, y_g, z_g;
  double roll, pitch, yaw;
  x_adc = analogRead(x_pin); /* Digital value of voltage on x_out pin */ 
  y_adc = analogRead(y_pin); /* Digital value of voltage on y_out pin */ 
  z_adc = analogRead(z_pin); /* Digital value of voltage on z_out pin */ 
  Serial.print("x (valor ADC) = ");
  Serial.print(x_adc);
  Serial.print("\t\t");
  Serial.print("y (valor ADC) = ");
  Serial.print(y_adc);
  Serial.print("\t\t");
  Serial.print("z (valor ADC) = ");
  Serial.print(z_adc);
  Serial.println();
  //delay(100);
  
  x_g = ( ( ( (double)(x_adc * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in x-direction in g units */ 
  y_g = ( ( ( (double)(y_adc * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in y-direction in g units */ 
  z_g = ( ( ( (double)(z_adc * 5)/1024) - 1.80 ) / 0.330 ); /* Acceleration in z-direction in g units */ 
  Serial.print("X en G = ");
  Serial.print(x_g);
  Serial.print("\t");
  Serial.print("Y en G = ");
  Serial.print(y_g);
  Serial.print("\t");
  Serial.print("Z en G = ");
  Serial.print(z_g);
  Serial.print("\n");
  roll = ( ( (atan2(y_g,z_g) * 180) / 3.14 ) + 180 ); /* Formula for roll */
  pitch = ( ( (atan2(z_g,x_g) * 180) / 3.14 ) + 180 ); /* Formula for pitch */
  //yaw = ( ( (atan2(x_g,y_g) * 180) / 3.14 ) + 180 ); /* Formula for yaw */
  /* Not possible to measure yaw using accelerometer. Gyroscope must be used if yaw is also required */

  Serial.print("Roll = ");
  Serial.print(roll);
  Serial.print("\t");
  Serial.print("Pitch = ");
  Serial.print(pitch);
  Serial.print("\n");
}

