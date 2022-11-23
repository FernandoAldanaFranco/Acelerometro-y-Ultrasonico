//sensor ultrasónico
//Adaptación del código: Dr. Fernando Aldana Franco
const int tiempo_espera=1000; //1 segundo

int trig=4; //Trigger pin
int echo=3; //Echo pin

long distancia; //Distancia medida

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT); //Salida
  pinMode(echo,INPUT); //Entrada
  digitalWrite(trig,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura_US(); //Función de sensor
  Serial.print("Lectura del sensor: ");
  Serial.print(distancia);
  Serial.print("  cm");
  Serial.println();
  delay(tiempo_espera);
}

void lectura_US(void){
  
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long tiempo=pulseIn(echo,HIGH);
  distancia=tiempo/59;
}

