// -----------------------------------------------------
//  Piaget PRO Emotional Mode
//  El sensor construye su realidad: asimilación,
//  acomodación y equilibrio sensorial.
// -----------------------------------------------------

int pinLDR = A0;

int pinR = 9;
int pinG = 6;
int pinB = 5;

// Función para LED RGB ANODO COMUN (lógica invertida)
void setColor(int r, int g, int b) {
  analogWrite(pinR, 255 - r);
  analogWrite(pinG, 255 - g);
  analogWrite(pinB, 255 - b);
}

void setup() {
  Serial.begin(9600);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {

  int valor = analogRead(pinLDR);

  // Zonas sensoriales según Piaget
  if (valor < 250) {
    // Poca luz → introspección → Acomodación lenta
    setColor(0, 0, 255);   
    Serial.println("Acomodación: El entorno desafía mis esquemas.");
  }
  else if (valor < 600) {
    // Equilibrio entre estímulo y experiencia
    setColor(0, 255, 0);  
    Serial.println("Equilibrio: Integro y mantengo mis estructuras.");
  }
  else {
    // Mucha luz → perturbación → Ajuste cognitivo
    setColor(255, 0, 0);  
    Serial.println("Asimilación: El entorno confirma mis esquemas previos.");
  }

  delay(200);
}
