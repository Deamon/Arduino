const int switchPin = 8;
unsigned long previousTime;
int switchState = 0;
int previousSwitchState = 0;

int led = 2;
//10 minutes
long interval = 5000;

void setup() {
  // put your setup code here, to run once:
  for(int x = 2; x <= 8; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    
    if(digitalRead(led) == HIGH){
      digitalWrite(led, LOW);  
    }
    else{
      digitalWrite(led, HIGH);
    }
    led++ ;
    if(led > 7){
      led = 2;
    }
  }
  
  
  switchState = digitalRead(switchPin);
 
  if(switchState != previousSwitchState){
    for(int x = 2; x <= 8; x++){
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  previousSwitchState = switchState;
}
