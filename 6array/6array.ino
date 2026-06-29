#define ldr1 A0
#define ldr2 A1
#define ldr3 A2
#define ldr4 A3
#define ldr5 A4
#define ldr6 A5

void setup() {
  Serial.begin(9600);


  for(int i = 0; i<=5; i++){

    pinMode(A0+i,INPUT);
  }

  // pinMode(ldr1, INPUT);
  // pinMode(ldr2, INPUT);
  // pinMode(ldr3, INPUT);
  // pinMode(ldr4, INPUT);
  // pinMode(ldr5, INPUT);
  // pinMode(ldr6, INPUT);
}

void loop() {


  for(int i = 0; i<6; i++){

    Serial.print(analogRead(A0+i));
    Serial.print(" ");
  }

  Serial.println("");
  
  // int value1 = analogRead(ldr1);
  // int value2 = analogRead(ldr2);
  // int value3 = analogRead(ldr3);
  // int value4 = analogRead(ldr4);
  // int value5 = analogRead(ldr5);
  // int value6 = analogRead(ldr6);


  // Serial.println(value1);
  // Serial.println(value2);
  // Serial.println(value3);
  // Serial.println(value4);
  // Serial.println(value5);
  // Serial.println(value6);

  delay(220);

}
