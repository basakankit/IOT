//In this code LED blinks on while in built LED switches off and so on
int High=1;
int Low=0;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(13, High);
  digitalWrite(8, Low);
  delay(2000);
  digitalWrite(13, Low);
  digitalWrite(8, High);
  delay(2000);
  Serial.println(9600);
}
