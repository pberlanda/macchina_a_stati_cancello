const bool PREMUTO = LOW;
const bool RILASCIATO = HIGH;

const unsigned int APERTO = 1;
const unsigned int APERTURA = 2;
const unsigned int CHIUSO = 3;
const unsigned int CHIUSURA = 4;

const bool SPENTO = LOW;
const bool ACCESO = HIGH;

bool p0, p1;
bool p0_old, p1_old;
unsigned int stato;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  p0_old = RILASCIATO;
  p1_old = RILASCIATO;

  //stato = 1; // inizializza lo stato.
  stato = CHIUSO;

}

void loop() {

  // leggi il valore corrente del pulsante
  p0 = digitalRead(A0);
  p1 = digitalRead(A1);

  delay(50);

  switch (stato){
    case APERTURA:{
      // se il pulsante è stato prenuto e prima era rilasciato cambia stato
      if ((p0 == PREMUTO) && (p0_old == RILASCIATO)){
        stato = APERTO;
        Serial.print("cancello APERTO");
        Serial.println(stato);
        break;
      } 
    }
    case CHIUSO:{
      // se il pulsante è stato prenuto e prima era rilasciato cambia stato
      if ((p0 == PREMUTO) && (p0_old == RILASCIATO)){
        stato = APERTURA;
        Serial.print("Stato APERTURA");
        Serial.println(stato);
        break;
      }
    }
    case APERTO:{
      // se il pulsante è stato prenuto e prima era rilasciato cambia stato
      if ((p0 == PREMUTO) && (p0_old == RILASCIATO)){
        stato = APERTO;
        Serial.print("Stato aggiornato ");
        Serial.println(stato);
        break;
      }
    }
    case CHIUSURA:{
      // se il pulsante è stato prenuto e prima era rilasciato cambia stato
      if ((p0 == PREMUTO) && (p0_old == RILASCIATO)){
        stato = CHIUSO;
        Serial.print("Stato aggiornato ");
        Serial.println(stato);
        break;
      }
    }
    default:{
      Serial.println("Stato non previsto, invio comando di CHIUSRUA");
      stato = CHIUSURA;
      break;
    }
  }

  // aggiorna stato
  p0_old = p0;
  p1_old = p1;

}
