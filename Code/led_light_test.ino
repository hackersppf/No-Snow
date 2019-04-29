/*
 Δοκιμαστικό πρόγραμμα για το φως LED
 αναβοσβήνει το φως κάθε δευτερόλεπτο
*/

//Σταθερές
#define pinLight 29    // Το φως είναι συνδεδεμένο στο pin 29

void setup() {
  pinMode(pinLight,OUTPUT); //Ορίζουμε το pin από το φως ως OUTPUT
}

void loop() {
  //Ανάβουμε και σβήνουμε το φως κάθε δευτερόλεπτο
  digitalWrite(pinLight,HIGH);
  delay(1000);
  digitalWrite(pinLight,LOW);
  delay(1000);
}
