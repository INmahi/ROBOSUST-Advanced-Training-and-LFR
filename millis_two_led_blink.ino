/*
  millis_two_led_blink.ino
  -------------------------------------------------------------
  PURPOSE: Teach how to use millis() for NON-BLOCKING timing.

  WHAT IT DOES:
    - LED_B turns ON immediately after upload, stays on 2s, off 2s, repeat.
    - LED_A starts OFF, turns ON after 2s, stays on 2s, off 2s, repeat.
    => The two LEDs blink together on the same 2s/2s rhythm but in
       OPPOSITE phase: while one is ON the other is OFF, and they swap
       every 2 seconds.

  -------------------------------------------------------------
  WHY delay() WON'T WORK HERE:
    delay() is BLOCKING. When you call delay(2000) the Arduino does
    NOTHING else for those 2 full seconds: it cannot read a button,
    cannot drive a second LED on its own schedule, cannot talk over
    serial. The CPU just sits and counts.

    To make two LEDs follow their own timing with delay() you would
    have to interleave delays by hand, and the moment you add a third
    task (a sensor, a button, a motor) the math falls apart and the
    sketch becomes unresponsive.

    millis() solves this. It returns the number of milliseconds since
    the board was powered on, and it keeps counting on its own in the
    background. Instead of telling the CPU to "wait", we simply ask
    "has enough time passed yet?" every loop. The loop never stops, so
    the board stays free to do many things at once.

  -------------------------------------------------------------
  WIRING (two LEDs, each with a current-limiting resistor):

        Arduino D8 ----[ 220 ohm ]----|>|---- GND     (LED_A)
        Arduino D9 ----[ 220 ohm ]----|>|---- GND     (LED_B)

    - |>| is the LED. The long leg (anode, +) goes toward the resistor
      / Arduino pin; the short leg (cathode, -) goes to GND.
    - A 220 ohm (or 330 ohm) resistor protects each LED from too much
      current. One resistor per LED.
    - Both LED cathodes share the Arduino GND pin.
  -------------------------------------------------------------
*/

const int LED_A = 8;   // starts OFF (turns on after the first 2s)
const int LED_B = 9;   // starts ON  (lit immediately after upload)

const unsigned long interval = 2000;  // 2000 ms = 2 seconds on, 2 seconds off

// Remembers the last time we flipped the LEDs.
// unsigned long because millis() can grow large (it rolls over ~49 days).
unsigned long previousMillis = 0;

// Current state of each LED. They start in OPPOSITE states.
bool ledB_on = true;   // LED_B begins ON
bool ledA_on = false;  // LED_A begins OFF

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // Apply the starting states right away.
  digitalWrite(LED_A, ledA_on ? HIGH : LOW);
  digitalWrite(LED_B, ledB_on ? HIGH : LOW);
}

void loop() {
  // Grab the current "stopwatch" reading. The loop keeps spinning fast,
  // so this runs thousands of times per second without ever blocking.
  unsigned long currentMillis = millis();

  // Has a full 2-second interval passed since the last flip?
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   // remember "now" for the next check

    // Toggle both LEDs. They swap states, so they stay in opposite phase.
    ledA_on = !ledA_on;
    ledB_on = !ledB_on;

    digitalWrite(LED_A, ledA_on ? HIGH : LOW);
    digitalWrite(LED_B, ledB_on ? HIGH : LOW);
  }

  // <-- Notice: the loop is free here. You could read a sensor, check a
  //     button, or print to Serial without disturbing the LED timing.
}
