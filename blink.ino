int i = 0;
int pin = digitalRead(4) == 1 ? 2 : 5;
int prevPin = pin; 
int rollTime = 0;
int actualRollTime = 0;


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
  pinMode(4, INPUT_PULLUP);  // Habilita resistor pull-up interno
}
void blink(int pin){
  int blinkTime = 250;
  actualRollTime + blinkTime >= rollTime ?  digitalWrite(pin, HIGH) :  digitalWrite(pin, LOW);  
  if (actualRollTime + blinkTime * 2 >= rollTime){
    actualRollTime = rollTime; 
  }
}
void loop() {  
  blink(pin);
  if (pin != prevPin){
    digitalWrite(prevPin, LOW);
    prevPin = pin; 
  }
  if(digitalRead(4) == LOW){
    pin = pin == 2 ? 5 : 2;
  }
  rollTime = millis();
}