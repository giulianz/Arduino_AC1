// variaveis da led
const  int vermelho = 5 ;
const  int verde = 6 ;
const  int azul = 7;

bool estadoLedVermelho = false ; 
bool estadoLedVerde = false;
bool estadoLedAzul = false;

const  int botao1 = 2 ;
unsigned  long lastDebounceTime1 = 0 ;
const  int botaoDelay = 100 ;

void  setup()
{
  pinMode (A0, INPUT); 
  pinMode (A1, INPUT);

  pinMode (vermelho, OUTPUT);
  pinMode (verde, OUTPUT);
  pinMode (azul,OUTPUT);
  
 
  Serial.begin ( 9600 ); //começar o Sereal
  
  Serial.println ("começar"); 
  Serial.println ( " AC1 - Meu Primeiro Projeto 2021 " );
  Serial.println ( "                            V1.0 " );
  Serial.println ( " Grupo: Lion Eye              " );
}

void  loop()
{
  if (( millis () - lastDebounceTime1)> botaoDelay && digitalRead (botao1)) {
  	Serial. println ( " botao 1 apertado " );
    ledVermelho (true);
  	lastDebounceTime1 = millis ();
  }
  
  if ( getTemperatura ()> 15 ) {
    ledAzul ( true );
  } else {
  	ledAzul (false);
  }
  	
  delay( 10 );
}
 
 void  ledVermelho (bool estado) { 
estadoLedVermelho =!estadoLedVermelho;
  digitalWrite (vermelho, estadoLedVermelho);
}

void  ledVerde (bool estado) {
  estadoLedVerde =!estadoLedVerde;
  digitalWrite (verde, estadoLedVerde);
}
 void  ledAzul (bool estado) {
  estadoLedAzul =!estadoLedAzul;
  digitalWrite (azul, estadoLedAzul);
}
int  getTemperatura () {
  	int temperaturaC;
	temperaturaC = map ((( analogRead (A0) - 20 ) * 3,04 ), 0 , 1023 , - 40 , 125 );
  	return temperaturaC;
} 

int  getLuminosidade () {
  	int luminosidade;
	luminosidade = map ( analogRead (A1), 6 , 619 , - 3 , 10 );
  	return luminosidade;
}mpe
