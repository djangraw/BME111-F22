/*
  AnalogInToSerial_500Hz

  Reads 1 analog input pin and prints the time and results to the Serial Monitor.

  Created 1/15/21 by DJ based on AnalogInToSerial.
  Updated 3/6/21 by DJ - make sampling rate more constant
  Updated 6/8/21 by DJ - renamed from AnalogInToSerial_Time3Chan_v2
  Updated 7/28/22 by DJ - switched to 1 channel, renamed to AnalogInToSerial_500Hz
*/

// Declare Constants & Initialize Variables
const int inputPin = A0;                        // Analog input pin
unsigned long currentTime = 0;                  // time
unsigned long nextTime = 0;                     // time to record sample
int sensorValue = 0;                            // value read from the analog input pin
const unsigned int fs = 500;                    // sampling rate in Hz (max should be 500)
const unsigned int delayTimeMs = (1000/fs);     // ms to wait between samples


// Run once on startup
void setup() {
  // initialize serial communications at 500000 bps:
  Serial.begin(500000);
  currentTime = millis(); 
}


// Run repeatedly
void loop() {

  // get the current time
  while (currentTime<nextTime) {
    currentTime = millis(); 
  }

  // print the time to the Serial Monitor
  //Serial.print(currentTime);
  //Serial.print(" ");

  // read the analog input value
  sensorValue = analogRead(inputPin);
  // print the results to the Serial Monitor:
  Serial.println(sensorValue);
  
  // wait to keep the sampling rate constant:
  nextTime = nextTime+delayTimeMs;
}
