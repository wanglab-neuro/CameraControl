// High-speed camera trigger generator for Teensy 3.2 at fixed 500 Hz.
// syncTrigPin gates output on/off; when high, syncPin emits 500 Hz pulses.

const int syncPin = 0;
const int syncTrigPin = 1;
elapsedMicros sinceOnsetTest;
elapsedMicros pulseDuration;
bool syncOn = false; //true

void setup() {
  pinMode(syncPin, OUTPUT);
  pinMode(syncTrigPin, INPUT);
  digitalWrite(syncPin, LOW);
}

void loop() {
  if (syncOn == true) {
    // trigger at 500Hz
    if (sinceOnsetTest >= 2000){
      sinceOnsetTest = 0;
      SendPulse();
    } else {
      TestSync();
    }
  } else {
    TestSync();
  }
}

void SendPulse() {
  pulseDuration=0;
  while (pulseDuration < 500) {
    digitalWriteFast(syncPin, HIGH);
  }
  digitalWriteFast(syncPin, LOW);
}

void TestSync() {
if (digitalReadFast(syncTrigPin) == HIGH) {
      syncOn = true;
    } else {
      syncOn = false;
    }
}
