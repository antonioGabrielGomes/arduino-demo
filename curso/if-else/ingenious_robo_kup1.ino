int pinVermelho = 10;
int pinAmarelo = 9;
int pinVerde = 8;
int pinBotao = 7;
int pinPedresteVermelho = 3;
int pinPedestreVerde = 2;

int faseSemafaro;

int estadoBotao;
int estadoAnteriorBotao;

int tempoPisca;
int estadoPisca;

void setup() {
  // put your setup code here, to run once:

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinPedresteVermelho, OUTPUT);
  pinMode(pinPedestreVerde, OUTPUT);

  faseSemafaro = 1;

  estadoAnteriorBotao = digitalRead(pinBotao);

  tempoPisca = 0;
  estadoPisca = HIGH;
}

void loop() {
  
  estadoBotao = digitalRead(pinBotao);

  if ((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)) {
    if (faseSemafaro < 4) {
      faseSemafaro = faseSemafaro + 1;
    } else {
      faseSemafaro = 1;
    }
  }

  estadoAnteriorBotao = estadoBotao;

  if (faseSemafaro == 1) { // ABERTO PARA O CARRO, FECHADO PARA PEDESTRE
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedresteVermelho, HIGH);
  }

  if (faseSemafaro == 2) {  // AMARELO - ATENÇÃO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedresteVermelho, HIGH);
  }

  if (faseSemafaro == 3) {  // FECHADO PARA CARRO, ABERTO PARA PEDESTRE
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);

    digitalWrite(pinPedestreVerde, HIGH);
    digitalWrite(pinPedresteVermelho, LOW);
  }

  if (faseSemafaro == 4) {  // PEDESTRE PISCANDO
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);

    tempoPisca = tempoPisca + 1;

    if (tempoPisca == 400) {
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    }

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedresteVermelho, estadoPisca);
  }

  delay(1);
}
