int valor=0;
int led=3;
int potencia=0;
void setup()
{
	pinMode(led,OUTPUT);
}

void loop()
{
  valor=analogRead(A0);
  potencia=map(valor,0,1024,0,255);
  analogWrite(led,valor);
}