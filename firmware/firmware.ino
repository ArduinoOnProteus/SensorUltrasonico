void createUltrasound(){
  #define ultraTrigPin 13
  #define ultraEchoPin 12
  pinMode(ultraTrigPin, OUTPUT);
  pinMode(ultraEchoPin, INPUT);  
}

float getUltrasound(){
  //Protocol Ultrasound. usando formula -> d = (Vsom*T)/2 onde Vsom=340m/s
  digitalWrite(ultraTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraTrigPin, LOW);
  unsigned long auxtime = pulseIn(ultraEchoPin, HIGH);
  float distance = (auxtime/29.4)/2; //resultado em cm
  return distance;
}

void setup() {
  //alocate pins
  Serial.begin(9600);
  createUltrasound();
}

void loop() {
  Serial.println(getUltrasound());
}
