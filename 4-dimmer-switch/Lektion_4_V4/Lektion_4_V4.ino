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

  if (liesWert < 300) {          // if the value from the potentiometer is less than 300 then:
    digitalWrite(9,LOW);          // turn off the first LED
    digitalWrite(10,LOW);         // turn off the second LED
    digitalWrite(11,LOW);         // turn off the third LED
  }
  else if (liesWert < 600) {     //if the value from the potentiometer is less than 600 then:
    analogWrite(9, schreibWert);   // turn on the first LED
    digitalWrite(10,LOW);         // turn off the second LED
    digitalWrite(11,LOW);         // turn off the third LED
  }
  else if (liesWert < 900) {     //if the value from the potentiometer is less than 900 then:
    analogWrite(9, schreibWert);   // turn on the first LED
    analogWrite(10, schreibWert);  // turn on the second LED
    digitalWrite(11,LOW);         // turn off the third LED
  }
  else if (liesWert < 999) {
    analogWrite(9, schreibWert);   // turn on the first LED
    analogWrite(10, schreibWert);  // turn on the second LED
    analogWrite(11, schreibWert);  // turn on the third LED
  }
  else {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    delay(100);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    delay(100);    
    }


  Serial.print(liesWert);
  Serial.print(" : ");
  Serial.println(schreibWert);
  delay(100);

}
