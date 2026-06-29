// push btn
int led = 9;
int btnIn = 2;
int state;
//potmeter
int potPin = A0;
int potValue;
float volt;
int ledR = 12;
//start
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(btnIn,INPUT);
  pinMode(potPin,INPUT);
  pinMode(ledR,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  state = digitalRead(btnIn);
  if(state)
  {
  	Serial.println("Button PRESSED! Led ON.");
  	digitalWrite(led,state);
  }
  else
  {
  	Serial.println("Button Released! Led OFF.");
  	digitalWrite(led,state);
  }

  potValue = analogRead(potPin);
  volt = potValue*(5.0/1023.0);
  
  if(volt>=2.5)
  {
    digitalWrite(ledR,HIGH);
  }
  else{
    digitalWrite(ledR,LOW);
  }
  Serial.print("Current Voltage(V) : ");
  Serial.println(volt);
  delay(500);
}




