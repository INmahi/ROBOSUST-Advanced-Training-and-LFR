#define ldr A1

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
}

void loop() {
  
  int value = analogRead(ldr);


  Serial.println(value);

  delay(10);

}
