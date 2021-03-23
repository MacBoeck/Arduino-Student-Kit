int liesWert = 0;
int schreibWert = 0;

void setup() {
  // LEDs als OUTPUT deklarieren 
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  // A0 analog pin (für den Pontentiometer) ist immer automatisch INPUT und muss nicht deklariert werden

  Serial.begin(9600); 

}

void loop() {

  liesWert = analogRead(A0);
  schreibWert = liesWert / 4;

  analogWrite(11, schreibWert);
  analogWrite(10, schreibWert);
  analogWrite(9, schreibWert);

  Serial.print(liesWert);
  Serial.print(" : ");
  Serial.println(schreibWert);
  delay(100);

}
