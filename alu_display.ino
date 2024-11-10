int EstadoA = 0;
  int EstadoB = 0;

  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;

void setup() {
  //Pines de entrada para A, B, w, x, y, z
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT); 
  pinMode(7, INPUT);
  //Pines de salida para cada operación

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);


}

void loop() {

  EstadoA = digitalRead(2); // Leer valor de A
  EstadoB = digitalRead(3); // Leer valor de B
  w = digitalRead(4);
  x = digitalRead(5);
  y = digitalRead(6);
  z = digitalRead(7);

  // SUMA
  if ((EstadoA ^ EstadoB)&&(!z && !y && !x && w)) {
     UNO ();
    // SALIDA DE SUMA
  }
  // ACARREO
  if ((EstadoA && EstadoB)&&(!z && !y && !x && w)) {
    ACARREO (); 
  }

  //RESTA
  if ((EstadoA ^ EstadoB)&&(!z && !y && x && !w)) {
    UNO ();
  }
  // (!A AND B) SIGNO NEGATIVO DE LA RESTA
  if ((!EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    NEGATIVO (); //SALIDA DEL SIGNO NEGATIVO
  }

  //MULTIPLICACION
  if ((EstadoA && EstadoB)&&(!z && !y && x && w)) {
    UNO (); // SALIDA DE LA MULTIPLICACIÓN
  }

  //DIVISION
  if ((EstadoA && EstadoB)&&(!z && y && !x && !w)) {
   UNO (); // SALIDA DE LA DIVISIÓN
  }
  // (!A AND !B) INDEFINIDO
  if ((!EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
   INDEFINIDO (); // SALIDA DEL INDEFINIDO
  }
  // (A AND !B) INFINITO
  if ((EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    INFINITO(); // SALIDA DEL INFINITO
  }

   // PARA QUE LOS LED VUELVAN A SU ESTADO OFF
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

}
void UNO (){
    digitalWrite(12, HIGH); 
    digitalWrite(13, HIGH);
}
void ACARREO (){
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
}
void NEGATIVO (){
    digitalWrite(12, HIGH); 
    digitalWrite(13, HIGH);
    digitalWrite(10, HIGH);
}
void INFINITO (){
    digitalWrite(10, HIGH); 
    digitalWrite(8, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(9, HIGH);
}
void INDEFINIDO (){
    digitalWrite(12, HIGH); 
    digitalWrite(10, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
}