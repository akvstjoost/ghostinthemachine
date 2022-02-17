void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  digitalWrite(8,HIGH);
  
}

void loop() {
  analogWrite(9,255);
  digitalWrite(10,LOW);
  delay(1000);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(1000);
  
  digitalWrite(9,LOW);
  analogWrite(10,100);
  delay(1000);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(1000);
}
