/*
 Δοκιμαστικό πρόγραμμα για το φως LED
 αναβοσβήνει το φως κάθε δευτερόλεπτο
*/

#define pinL 29             //Ονομάζω pinL το pin 29 στο οποίο είναι συνδεδεμένο το ηχείο

void setup() {
  pinMode(pinL,OUTPUT);     //Ορίζουμε το pin από το φως ως έξοδος
}

void loop() {               //Ανάβουμε και σβήνουμε το φως κάθε δευτερόλεπτο
  digitalWrite(pinL,HIGH);  //Ενεργοποιώ το φως
  delay(1000);              //Περιμένω ένα δευτερόλεπτο
  digitalWrite(pinL,LOW);   //Απενεργοποιώ το φως 
  delay(1000);              //Περιμένω ένα δευτερόλεπτο
}
