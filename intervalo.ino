// Intervalometer 
// 3-way switch to control delay
// 7.1.2013 Visa Ritvola

int optoPin = 5;      // Optocoupler pin
int delaySwitch1 = 6;  // Delayswitch in position 1
int delaySwitch2 = 7; // in position 2
int ledPin = 8;

int delayTime1 = 5000; // five second delay
int delayTime2 = 20000;  // twenty second delay
int delayTime3 = 60000;  // one minute delay

void setup()
{
  pinMode(optoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(delaySwitch1, INPUT);
  pinMode(delaySwitch2, INPUT);
  
  digitalWrite(delaySwitch1, HIGH);
  digitalWrite(delaySwitch2, HIGH);
  
  digitalWrite(optoPin, LOW);
  digitalWrite(ledPin, LOW);
  
}

void loop()
{
  digitalWrite(optoPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(optoPin, LOW);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(determineDelay());  
}

int determineDelay()
{
  if (digitalRead(delaySwitch1) == LOW) {
    return delayTime1; // Switch in UP position
  } else if (digitalRead(delaySwitch2) == LOW) {
    return delayTime3; // Switch in DOWN position
  } else {
    return delayTime2; // Switch in MIDDLE position
  } 
}
