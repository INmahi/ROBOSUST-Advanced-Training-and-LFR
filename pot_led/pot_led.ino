
#define POT  A1
#define Led 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(POT);

    //convert
  int brightness = map(val,0,1023,0,255);

  analogWrite(Led, brightness);

  Serial.println(val);
  delay(100);

}
