void setup(){
  pinMode(3, OUTPUT); // Green
  pinMode(4, OUTPUT); // Yellow
  pinMode(5, OUTPUT); // Red
  pinMode(2, INPUT);  // Switch
}

void loop(){
  int switchState = digitalRead(2);
  if(switchState == LOW){
    // Switch not pressed
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(500);
    digitalWrite(4, HIGH);
    
    delay(500);
    digitalWrite(3, HIGH);
    
    delay(1000);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  }
}
