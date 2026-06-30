const int sensorPins[6] = {A0, A1, A2, A3, A4, A5};

#define ENA 3
#define ENB 9
#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8

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

for(int i = 0; i <= 5; i++)
{
  
  Serial.print(analogRead(sensorPins[i]));
  Serial.print(" ");
  


}
  delay(1000);
  Serial.println(" ");


  long left = analogRead(A2);
  long right = analogRead(A3);
  long left_speed = map(left, 0, 1023, 255 ,0);
  long right_speed = map(right, 0, 1023, 255,0 );
  
  
  if(left < 500 && right < 500){

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    analogWrite(ENA, left_speed);
    analogWrite(ENB, right_speed);
  }  

  else{

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

  }





}