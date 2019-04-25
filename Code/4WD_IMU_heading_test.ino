/* Πρόγραμμα ελέγχου μονάδας IMU για το αποχιονιστικό 1
 * Σκοπός του προγράμματος είναι να κινήσουμε το όχημα μας ευθεία και αυτό να διατηρεί την πορεία του 
 * Η μονάδα IMU ελέγχει διαρκώς αν υπάρχουν αποκλίσεις στον άξονα Ζ και διορθώνει την πορεία αλλάζοντας την
 * ταχύτητα των κινητήρων κάθε πλευράς.
 */

//Προσθέτουμε τις βιβλιοθήκες για την μονάδα IMU (γυροσκόπιο και το επιταχυνσιόμετρο)
#include <MPU6050_tockn.h>
#include <Wire.h>

//Προσθέτουμε την βιβλιοθήκη για τον οδηγό των κινητήρων
#include <AFMotor.h>

//Δηλώνουμε την μονάδα IMU με το όνομα imu
MPU6050 imu(Wire);

//Δηλώνουμε τους 4 κινητήρες του οχήματος σε ποιες θέσεις είναι τοποθετημένα
AF_DCMotor motorFR(1); //Μπροστά δεξιά στην θέση 1
AF_DCMotor motorFL(2); //Μπροστά αριστερά στην θέση 2
AF_DCMotor motorBL(3); //Πίσω αριστερά στην θέση 3
AF_DCMotor motorBR(4); //Πίσω δεξιά στην θέση 4

void setup() {
  //Ξεκινάμε την μονάδα IMU
  Wire.begin();
  imu.begin();

  //Ζητάμε από την μονάδα να κάνει την αρχική ρύθμιση (θέλει 3 δευτερόλεπτα)
  imu.calcGyroOffsets(true);
 
  //Ενεργοποιούμε τους κινητήρες
  motorFR.run(FORWARD);
  motorBR.run(FORWARD);
  motorFL.run(FORWARD);
  motorBL.run(FORWARD);
}

void loop() {
  //Ζητάμε τις νέες τιμές από το γυροσκόπιο
  imu.update();

  //Αν η γωνία περιστροφής γύρω από τον άξονα Ζ είναι μικρότερη από -3 μοίρες στρίβουμε το όχημα αριστερά
  //Αλλιώς αν η γωνία είναι μεγαλύτερη από 3 μοίρες στρίβουμε το όχημα δεξιά
  //Αλλιώς αν η γωνία περιστροφής δεν είναι ούτε μικρότερη από -3 ούτε μεγαλύτερη από 3 προχωράμε ευθεία.
  if (imu.getAngleZ() < -3) {
    motorFR.setSpeed(200);
    motorBR.setSpeed(200);
    motorFL.setSpeed(0);
    motorBL.setSpeed(0);
  } else if (imu.getAngleZ() > 3) {
    motorFL.setSpeed(200);
    motorBL.setSpeed(200);
    motorFR.setSpeed(0);
    motorBR.setSpeed(0);
  } else {
    motorFL.setSpeed(200);
    motorBL.setSpeed(200);
    motorFR.setSpeed(200);
    motorBR.setSpeed(200);
  }
}
