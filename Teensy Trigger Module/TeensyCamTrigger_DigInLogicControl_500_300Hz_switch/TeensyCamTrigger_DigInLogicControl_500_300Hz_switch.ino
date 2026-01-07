// High-speed camera trigger generator for Teensy 3.2.
// syncTrigPin gates output on/off; selector pins choose frequency.
// selectorPin1 HIGH & selectorPin2 LOW -> 500 Hz output.
// selectorPin1 LOW & selectorPin2 HIGH -> 300 Hz output.
// Any other selector combination disables output.

const int syncPin = 0;
const int syncTrigPin = 1;
const int selectorPin1 = 11;
const int selectorPin2 = 12;
// const int debugLedPin = 13;
const unsigned int interval500HzUs = 2000;
const unsigned int interval300HzUs = 3333;
// const unsigned long ledToggleIntervalSyncOff500mHzUs = 1000000;
// const unsigned long ledToggleIntervalSyncOff300mHzUs = 1666667;
elapsedMicros sinceOnsetTest;
elapsedMicros pulseDuration;
// elapsedMicros sinceLedToggle;
bool syncOn = false; //true
// unsigned long lastLedIntervalUs = 0;
// bool lastLedEnabled = false;
// int lastSelectorState = -1;

void setup() {
  pinMode(syncPin, OUTPUT);
  pinMode(syncTrigPin, INPUT);
  pinMode(selectorPin1, INPUT);
  pinMode(selectorPin2, INPUT);
  // pinMode(debugLedPin, OUTPUT);
  digitalWrite(syncPin, LOW);
  // digitalWrite(debugLedPin, LOW);
}

void loop() {
  bool selector1High = digitalReadFast(selectorPin1) == HIGH;
  bool selector2High = digitalReadFast(selectorPin2) == HIGH;
  // int selectorState = 0;
  unsigned int outputIntervalUs = 0;

  if (selector1High && !selector2High) {
    // selectorState = 1;
    outputIntervalUs = interval500HzUs;
  } else if (!selector1High && selector2High) {
    // selectorState = 2;
    outputIntervalUs = interval300HzUs;
  }

  // unsigned long ledIntervalUs = 0;
  // if (syncOn == true) {
  //   if (selectorState != 0 && outputIntervalUs > 0) {
  //     ledIntervalUs = (unsigned long)outputIntervalUs * 50;
  //   }
  // } else {
  //   if (selectorState == 1) {
  //     ledIntervalUs = ledToggleIntervalSyncOff500mHzUs;
  //   } else if (selectorState == 2) {
  //     ledIntervalUs = ledToggleIntervalSyncOff300mHzUs;
  //   }
  // }

  // bool ledEnabled = ledIntervalUs > 0;
  // if (selectorState != lastSelectorState || ledEnabled != lastLedEnabled || ledIntervalUs != lastLedIntervalUs) {
  //   sinceLedToggle = 0;
  //   digitalWriteFast(debugLedPin, LOW);
  //   lastLedEnabled = ledEnabled;
  //   lastLedIntervalUs = ledIntervalUs;
  //   lastSelectorState = selectorState;
  // }

  // if (ledEnabled && sinceLedToggle >= ledIntervalUs) {
  //   sinceLedToggle = 0;
  //   digitalWriteFast(debugLedPin, !digitalReadFast(debugLedPin));
  // } else if (!ledEnabled) {
  //   digitalWriteFast(debugLedPin, LOW);
  // }

  if (syncOn == true) {
    if (outputIntervalUs > 0 && sinceOnsetTest >= outputIntervalUs) {
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
