const int sensorPins[6] = {A0, A1, A2, A3, A4, A5};




int threshold = 0;

#define ENA 11
#define ENB 3
#define IN1 10
#define IN2 9
#define IN3 7
#define IN4 6

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  for(int i=0; i <= 5; i++){
    pinMode(sensorPins[i] , INPUT);

  }
  
}

void loop() {

int minvalue = 1023;
int maxvalue = 0;



for(int i = 0; i <= 5; i++)
{
  int reading =analogRead(sensorPins[i]);   
  Serial.print(reading);
  Serial.print(" ");

  if(reading < minvalue){
    minvalue = reading;
  }
  if(reading > maxvalue){
    maxvalue = reading;
  }    

}

  threshold = (minvalue + maxvalue) / 2 ;
  
  
 
  Serial.println(" ");

  
  byte sensors = 0;
 
 for(int i = 0; i <6; i++)
 {
    int value =analogRead(sensorPins[i]);
  
  if(value <= threshold){
    sensors |= (1<<i);
  }
  

Serial.println(sensors, BIN);
 }
  if((sensors & 0b001100)== 0b001100){
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
 }
  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
 }

Serial.println(sensors, BIN);

}