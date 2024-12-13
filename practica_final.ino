
// Definimos los pines
const int sensorPin = A0;   // Pin analógico para el sensor de agua
const int motorPin = 9;     // Pin digital para el control del motor

// Valores de referencia (ajustar según tu sensor)
const int waterDetected = 500;  // Umbral para detectar agua

// Variables de control
unsigned long lastTurnOffTime = 0;   // Tiempo del último apagado
const int delayAfterFull = 15000; // Tiempo de espera (10 segundos)

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Para depuración
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Leer el valor del sensor
  Serial.println(sensorValue);            // Mostrar el valor en el monitor serial

  // Comprobamos el nivel del sensor
  if (sensorValue >= waterDetected) {
    digitalWrite(motorPin, LOW); // Apagar el motor
    lastTurnOffTime = millis(); // Actualizar el tiempo del último apagado
    Serial.println("Motor apagado: nivel alto de agua.");
  } else if (millis() - lastTurnOffTime >= delayAfterFull) {
    digitalWrite(motorPin, HIGH); // Encender el motor después del retraso
    Serial.println("Motor encendido: nivel bajo de agua y tiempo de espera cumplido.");
  }

  delay(500); // Espera para estabilidad
}
