/*
 Δοκιμαστικό πρόγραμμα για τον αισθητήρα θερμοκρασίας
 Διαβάζει τις τιμές που παίρνει ο αισθητήρας 
 και τις εμφανίζει στο serial monitor.
*/

#include <dht.h>  //Εισάγουμε την βιβλιοθήκη του αισθητήρα θερμοκρασίας

#define pinT A14  //Ονομάζω pinT το αναλογικό Pin 14 στο οποίο είναι συνδεδεμένος ο αισθητήρας

dht DHT;          //Δημιουργώ ένα θερμόμετρο από την βιβλιοθήκη DHT

float temp;       //Δημιουργώ μια μεταβλητή στην οποία θα αποθηκεύω την θερμοκρασία

void setup() {
Serial.begin(9600);   //Ξεκινάμε την σειριακή επικοινωνία
}

void loop() {
  DHT.read11(pinT);        //Διαβάζουμε τις τιμές από τον αισθητήρα
  temp = DHT.temperature;  //Παίρνουμε την θερμοκρασία
  Serial.println(temp);    //την εμφανίζουμε στην σειριακή οθόνη
}
