#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2); 

long baselineReading = 0;
const int midiNoteLow = 21;  
const int midiNoteHigh = 127; 
long minExpectedReading = 0; 
long maxExpectedReading = 17000; 
int threshold = 50; 
const int debounceTime = 100; 
const int ledPin = 13; 
const int potPin = A0; 
static long lastReading = 0;
static int lastNote = -1; 
unsigned long lastNoteTime = 0; 
unsigned long lastNoteOnTime = 0; 
const unsigned long noteOffTimeout = 2000; 

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  Serial.begin(31250); 
  pinMode(ledPin, OUTPUT); 
  pinMode(potPin, INPUT); 
  baselineReading = cs_4_2.capacitiveSensor(1000);
}

void loop() {
  long total = cs_4_2.capacitiveSensor(1000);
  long normalizedReading = total - baselineReading;
  unsigned long currentTime = millis();

  int potValue = analogRead(potPin);
  threshold = map(potValue, 0, 1023, 5, 500); 

  if (normalizedReading < minExpectedReading) minExpectedReading = normalizedReading;
  if (normalizedReading > maxExpectedReading) maxExpectedReading = normalizedReading;

  bool isNoteActive = abs(normalizedReading - lastReading) > threshold;

  if (isNoteActive && (currentTime - lastNoteTime) > debounceTime) {
    normalizedReading = constrain(normalizedReading, minExpectedReading, maxExpectedReading);
    int mappedNote = map(normalizedReading, minExpectedReading, maxExpectedReading, midiNoteLow, midiNoteHigh);
    mappedNote = constrain(mappedNote, midiNoteLow, midiNoteHigh);
    mappedNote = mapToCMajor(mappedNote); 

    if (mappedNote != lastNote) {
      if (lastNote != -1) midiNoteOff(lastNote, 127); 
      midiNoteOn(mappedNote, 127);
      lastNote = mappedNote;
      lastNoteOnTime = currentTime; 
    }

    lastReading = normalizedReading;
    lastNoteTime = currentTime; 
  } else if (!isNoteActive && lastNote != -1 && (currentTime - lastNoteOnTime) > debounceTime) {
    midiNoteOff(lastNote, 127);
    lastNote = -1; 
    lastNoteOnTime = 0;
  }
}

void midiNoteOn(int note, int velocity) {
  digitalWrite(ledPin, HIGH); 
  delay(10); 
  digitalWrite(ledPin, LOW);
  Serial.write(0x90); 
  Serial.write(note); 
  Serial.write(velocity); 
}

void midiNoteOff(int note, int velocity) {
  digitalWrite(ledPin, LOW);
  Serial.write(0x80); 
  Serial.write(note); 
  Serial.write(0); 
}

int mapToCMajor(int note) {
  int noteInScale;
  int noteDistance = note % 12; 

  if (noteDistance <= 1) noteInScale = 0; 
  else if (noteDistance <= 3) noteInScale = 2; 
  else if (noteDistance <= 5) noteInScale = 4; 
  else if (noteDistance <= 6) noteInScale = 5; 
  else if (noteDistance <= 8) noteInScale = 7; 
  else if (noteDistance <= 10) noteInScale = 9; 
  else noteInScale = 11; 

  return (note / 12) * 12 + noteInScale;
}
