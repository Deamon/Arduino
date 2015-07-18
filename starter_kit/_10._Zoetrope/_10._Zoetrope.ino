const int potPin = A0;

const int onOffSwitchStateSwitchPin = 5;
const int directionSwitchPin = 4;

const int enablePin = 9;
const int controlPin1 = 2;
const int controlPin2 = 3;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(directionSwitchPin, INPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  
  digitalWrite(enablePin, LOW);

}

void loop() {
  //get inputs
  
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;
  
  // If we have a difference between current switch state and previous then
  // change the power of the motor
  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }
  
  // If we have a difference between current switch state and previous, then
  // change motor direction
  if(directionSwitchState != previousDirectionSwitchState){
    if(directionSwitchState == HIGH){
      motorDirection = !motorDirection;
    }
  }
  
  // Control motor direction
  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else{
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  // Control motor power
  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }
  
  //Saving state to compare on next loop
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
  
}
