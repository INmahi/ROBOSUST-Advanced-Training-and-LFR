
//FADE LED WITH PWM

const int ledPin1 = 9;  // PWM pin
const int ledPin2 = 10;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  analogWrite(ledPin1,0);
  analogWrite(ledPin2,255);
  
  // Fade from 0% to 100%
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin1, brightness);
    analogWrite(ledPin2,255-brightness);
    delay(10);
  }
  // for (int brightness = 255; brightness >= 0; brightness--) {
  //   analogWrite(ledPin, brightness);
  //   delay(10);
  // }

  // Fade from 100% to 0%
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin1, brightness);
    analogWrite(ledPin2,255-brightness);
    delay(10);
  }

}