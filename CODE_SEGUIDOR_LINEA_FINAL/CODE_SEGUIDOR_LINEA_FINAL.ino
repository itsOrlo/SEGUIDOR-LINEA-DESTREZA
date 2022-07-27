/* Seguidor de Linea */

#define Motor11 7 //-> Atrás derecho
#define Motor12 6 //-> Adelante derecho
#define Motor21 9 //-> Delantero izquierdo
#define Motor22 8// -> Atrás izquierdo
#define PWMmotor1 5 // Motor derecho
#define PWMmotor2 10 // Motor izquierdo
int valuePWM1 = 91; // Velocidad Motor Derecho.
int valuePWM2 = 81; // Velocidad Motor Izquierdo.

void setup() {
  
      pinMode(Motor11, OUTPUT);
      pinMode(Motor12, OUTPUT);
      pinMode(Motor21, OUTPUT);
      pinMode(Motor22, OUTPUT);
      pinMode(PWMmotor1, OUTPUT);
      pinMode(PWMmotor2, OUTPUT);
      pinMode(A0, INPUT); // Entrada Sensor Derecho.
      pinMode(A1, INPUT); // Entrada Sensor Izquierdo.
      
}
void loop() {
  
    int izq_SENSOR = analogRead(A0); // Lectura Valores Sensor Izquierdo.
    int der_SENSOR = analogRead(A1); // Lectura Valores Sensor Derecho
    
if (der_SENSOR < 50 && izq_SENSOR < 50) // Auto al frente.
{
    digitalWrite(Motor11, LOW);
    digitalWrite(Motor12, HIGH); // -> adelante derecho
    digitalWrite(Motor21, HIGH); // -> adelante izquierdo
    digitalWrite(Motor22, LOW);
    analogWrite(PWMmotor1, valuePWM1);
    analogWrite(PWMmotor2, valuePWM2);
}

else if (der_SENSOR < 50 && izq_SENSOR > 60) // Auto a la Izquierda.
{
  
    digitalWrite(Motor11, LOW); //->atras derecho
    digitalWrite(Motor12, LOW);
    digitalWrite(Motor21, HIGH); //->delante izq
    digitalWrite(Motor22, LOW);
    //analogWrite(PWMmotor1, valuePWM1);
    analogWrite(PWMmotor2, valuePWM2 + 50);
    
}

else if (der_SENSOR > 50 && izq_SENSOR < 60) // Auto a la Derecha.
{
  
    digitalWrite(Motor11, LOW);
    digitalWrite(Motor12, HIGH);//->delante derecha
    digitalWrite(Motor21, LOW);
    digitalWrite(Motor22, LOW);// -> atras izquierdo
    analogWrite(PWMmotor1, valuePWM1 + 50);
    // analogWrite(PWMmotor2, valuePWM2);

}
else if (der_SENSOR > 50 && izq_SENSOR > 50) //BACK
{
    digitalWrite(Motor11, HIGH); // -> atrás derecha
    digitalWrite(Motor12, LOW);
    digitalWrite(Motor21, LOW);
    digitalWrite(Motor22, HIGH); //-> atrás izq
    analogWrite(PWMmotor1, valuePWM1 + 40);
    analogWrite(PWMmotor2, valuePWM2 + 30);
}
}
