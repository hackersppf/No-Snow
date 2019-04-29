/*
 Δοκιμαστικό πρόγραμμα για το ηχείο
 Το ενεργοποιεί κάθε δευτερόλεπτο
*/

//Σταθερές
#define pinSound 27    // Το ηχείο είναι συνδεδεμένο στο pin 27

void setup() {
  pinMode(pinSound,OUTPUT); //Ορίζουμε το pin του ηχείου ως OUTPUT
}

void loop() {
  digitalWrite(pinSound,HIGH);
  delay(1000);
  digitalWrite(pinSound,LOW);
  delay(1000);
}
