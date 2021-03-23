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

  if (liesWert > 1000) {
    digitalWrite(9,LOW);          // turn off the first LED
    digitalWrite(10,LOW);         // turn off the second LED
    digitalWrite(11,LOW);         // turn off the third LED
    delay(250);                   // wait 1/4 of a second
    digitalWrite(11,HIGH);        // turn on the third LED
    digitalWrite(10,HIGH);        // turn on the second LED
    digitalWrite(9,HIGH);         // turn on the first LED
    delay(250);                   // wait 1/4 of a second
    }

  else {
    analogWrite(11, schreibWert);
    analogWrite(10, schreibWert);
    analogWrite(9, schreibWert);    
    }  

  Serial.print(liesWert);
  Serial.print(" : ");
  Serial.println(schreibWert);
  delay(100);

}
