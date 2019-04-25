/* Πρόγραμμα για τον έλεγχο λειτουργίας των κινητήρων στο αποχιονιστικό 1 
 * Το πρόγραμμα λειτουργεί όλους του κινητήρες μπροστά για 3 δευτερόλεπτα και 
 * μετά τους απενεργοποιεί για άλλα 3 δευτερόλεπτα. Η διαδικασία αυτή επαναλαμβάνεται
 * διαρκώς. Αν κάποιος κινητήρας κινείται ανάποδα μπορούμε να αντιστρέψουμε τα καλώδια του
 * στο Motor Driver Shield
 */ 
 
//Προσθέτουμε την βιβλιοθήκη για τον οδηγό των κινητήρων
#include <AFMotor.h>

//Δηλώνουμε τους 4 κινητήρες του οχήματος σε ποιες θέσεις είναι τοποθετημένα
AF_DCMotor motorFR(1); //Μπροστά δεξιά στην θέση 1
AF_DCMotor motorFL(2); //Μπροστά αριστερά στην θέση 2
AF_DCMotor motorBL(3); //Πίσω αριστερά στην θέση 3
AF_DCMotor motorBR(4); //Πίσω δεξιά στην θέση 4


//Στο setup γράφουμε τις εντολές που θα εκτελεστούν μια φορά στην αρχή
void setup() {
  //Ορίζουμε την ταχύτητα των κινητήρων
  motorFR.setSpeed(200);
  motorFL.setSpeed(200);
  motorBL.setSpeed(200);
  motorBR.setSpeed(200);
  
  //Απενεργοποιούμε τους κινητήρες
  motorFR.run(RELEASE);
  motorFL.run(RELEASE);
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
}

//Στο loop γράφουμε τις εντολές που θα εκτελούνται συνεχώς
void loop() {
  //Ενεργοποιούμε τους κινητήρες προς τα μπροστά για 3 δευτερόλεπτα
  motorFR.run(FORWARD);
  motorFL.run(FORWARD); 
  motorBL.run(FORWARD);  
  motorBR.run(FORWARD);  
  delay(3000);
  
  //Απενεργοποιούμε τους κινητήρες για 3 δευτερόλεπτα
  motorFR.run(RELEASE);
  motorFL.run(RELEASE); 
  motorBL.run(RELEASE);  
  motorBR.run(RELEASE);  
  delay(3000);
}
