int i = 0;
int pin = digitalRead(4);
int prevPin = pin; 
unsigned long int rollTime = 0;
unsigned long int actualRollTime = 0;
int flag = 0;
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
  int pinHigh = pin ? 2 : 5;
  int pinLow = !pin ? 2 : 5;
  if(rollTime - actualRollTime > blinkTime){
    digitalWrite(pinHigh, HIGH); 
    digitalWrite(pinLow, LOW); 
  }else{
    digitalWrite(pinHigh, LOW);
    digitalWrite(pinLow, LOW);
  }
  if ( rollTime - actualRollTime > blinkTime * 2){
    actualRollTime = rollTime; 
  }  
}
int onOutButton(int* flag){  
  int buttonPinState = digitalRead(4);  
  if(buttonPinState == 1 && *flag == 1){
    *flag = 0;       
    return 1;
  }
  if(*flag == 0 && buttonPinState == 0){
    *flag = 1;   
  }
  return 0;
}
void loop() {  
  blink(pin);
  Serial.println(pin);
  int isButtonOutPressed = onOutButton(&flag); 
  if(isButtonOutPressed){
     pin = !pin;
  } 
  rollTime = millis(); 
}