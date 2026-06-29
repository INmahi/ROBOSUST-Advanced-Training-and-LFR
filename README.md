# ROBOSUST Advanced Training & LFR

Arduino practice sketches from the ROBOSUST advanced training, building up toward a
Line Following Robot (LFR). Each folder is a self-contained Arduino sketch covering one
concept — analog reading, PWM, digital I/O, and non-blocking timing.

## Sketches

| Sketch | Purpose |
|--------|---------|
| [millis_two_led_blink.ino](millis_two_led_blink.ino) | Teaches **non-blocking timing** with `millis()`. Two LEDs blink on a 2s-on / 2s-off rhythm in opposite phase, and the comments explain why `delay()` can't do concurrent timing. Includes a simple two-LED + resistor wiring diagram. |
| [6array/](6array/6array.ino) | Reads a **6-channel LDR sensor array** on analog pins A0–A5 and streams all six values over serial — the sensing front-end for an LFR. |
| [tcrt5000/](tcrt5000/tcrt5000.ino) | Reads a single **TCRT5000** reflectance sensor on an analog pin and prints the value over serial. |
| [pot_led/](pot_led/pot_led.ino) | **Potentiometer-controlled LED brightness** — reads a pot with `analogRead()` and maps it to a PWM output via `analogWrite()`. |
| [led_fade_pwm/](led_fade_pwm/led_fed_pwm.ino) | **PWM fade demo** — two LEDs (pins 9 & 10) cross-fade in opposite directions using `analogWrite()`. |
| [sketch_mar14a/](sketch_mar14a/sketch_mar14a.ino) | **Digital + analog I/O combo** — a push button toggles one LED while a potentiometer's voltage crossing a 2.5V threshold drives a second LED. |

## Libraries

| Folder | Purpose |
|--------|---------|
| [libraries/](libraries/) | Bundled third-party Arduino libraries used across the training (Adafruit GFX / SSD1306 / SH110X / Motor Shield, AccelStepper, Servo, DHT, DallasTemperature, OneWire, NewPing, ESPAsyncTCP / ESPAsyncWebServer, and more). |

## Usage

Each sketch follows the standard Arduino layout (a `.ino` inside a folder of the same name).
Open the desired folder's `.ino` in the Arduino IDE, select your board and port, then upload.

> Note: [millis_two_led_blink.ino](millis_two_led_blink.ino) lives in the repo root. To open it
> directly in the Arduino IDE, move it into a `millis_two_led_blink/` folder of the same name.
