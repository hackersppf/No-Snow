/*
  Πρόγραμμα δοκιμής βηματικού κινητήρα
*/

//Βιβλιοθήκες
#include <Stepper.h>

//Μεταβλητές
Stepper stepper(2038, 35, 37, 39, 41);

void setup() {
  
}

void loop() {
  stepper.setSpeed(6); // Ορίζω την ταχύτητα σε 6 rpm
  stepper.step(2038); // Περιστρέφω τον κινητήρα για 2038 βήματα (1 περιστροφή)
}
