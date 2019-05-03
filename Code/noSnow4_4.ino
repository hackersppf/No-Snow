/*
  Το προγραμμα για το αποχιονιστικό μηχάνημα που έχει συνδεδεμένους τους 4 κινητήρες σε διαφορετικές θέσεις στον οδηγό
*/

//Εισάγουμε όλες τις βιβλιοθήκες που θα χρειαστούμε. Μπορούμε να πάμε στα προγράμματα δοκιμών και να 
//αντιγράψουμε τις εντολές #include από εκεί
#include <dht.h>            //Αισθητήρας θερμοκρασίας DHT11
#include <NewPing.h>        //Αισθητήρας απόστασης υπέρηχων
#include <MPU6050_tockn.h>  //Μονάδα IMU (γυροσκόπιο)
#include <Wire.h>           //Βοηθητική για την μονάδα IMU
#include <AFMotor.h>        //Οδηγός των κινητήρων για τις ρόδες
#include <Servo.h>          //Servo κινητήρες για μαχαίρι και διασκορπιστή αλατιού
#include <Stepper.h>        //Βηματικός κινητήρας για μεταφορά αλατιού

//Ορίζουμε τα pin στα οποία έχουμε συνδέσει τις μονάδες σαν σταθερές με την εντολή define
//Έτσι αντί να χρησιμοποιούμε πλέον τους αριθμούς των pin στο πρόγραμμα μας θα χρησιμοποιούμε
//τα ονόματα που δίνουμε παρακάτω
#define pinT A14      //Αισθητήρας θερμοκρασίας DHT11 είναι στο pin Α14
#define pinR A15      //Αισθητήρας βροχής είναι στο pin Α15
#define pinD 23       //Αισθητήρας απόστασης είναι στο pin 23
#define pinP 25       //Αισθητήρας PIR είναι στο pin 25
#define pinS 27       //To ηχείο είναι στο pin 27
#define pinL 29       //To φως είναι στο pin 29
#define pinServoM 10  //To Servo του μαχαιριού είναι τοποθετημένο στην θέση SERVO2 του οδηγού που αντιστοιχεί στο digital pin 10
#define pinServoA 9   //To Servo της αλατιέρας είναι τοποθετημένο στην θέση SERVO1 του οδηγού που αντιστοιχεί στο digital pin 9

#define STEPPER_PIN_1 35
#define STEPPER_PIN_2 37
#define STEPPER_PIN_3 39
#define STEPPER_PIN_4 41
int step_number = 0;

//Δημιουργούμε αντικείμενα - μεταβλητές, τα οποία έχουν τις δικές τους συναρτήσεις
Servo front;                            //Κινητήρας servo που ελέγχει το μαχαίρι
Servo back;                             //Κινητήρας servo που ελέγχει τον διασκορπιστή αλατιού
//Stepper salt(1019, 35, 37, 39, 41);     //Κινητήρας βηματικός που ελέγχει τον κοχλία μεταφοράς αλατιού. Δηλώνουμε τα βήματα (1019) και σε ποια pin είναι συνδεδεμένος
dht DHT;                                //Μονάδα αισθητήρα θερμοκρασίας
MPU6050 imu(Wire);                      //Μονάδα IMU
NewPing sonar(pinD, pinD, 400);         //Μονάδα αισθητήρα απόστασης υπέρηχων. Δηλώνουμε σε ποιο pin είναι τα TRIG και ECHO (στο ίδιο pin) καθώς και το μέγιστο όριο απόστασης 

//Δηλώνουμε τους 4 κινητήρες του οχήματος σε ποιες θέσεις είναι τοποθετημένα
AF_DCMotor motorFR(1);   //Ονομάζουμε motorFR τον κινητήρα που είναι στην θέση 1 του οδηγού κινητήρων και είναι στο μπροστά δεξί μέρος
AF_DCMotor motorFL(2);   //Ονομάζουμε motorFL τον κινητήρα που είναι στην θέση 2 του οδηγού κινητήρων και είναι στο μπροστά αριστερό μέρος
AF_DCMotor motorBL(3);   //Ονομάζουμε motorΒL τον κινητήρα που είναι στην θέση 3 του οδηγού κινητήρων και είναι στο πίσω αριστερό μέρος
AF_DCMotor motorBR(4);   //Ονομάζουμε motorBR τον κινητήρα που είναι στην θέση 4 του οδηγού κινητήρων και είναι στο πίσω δεξί μέρος

//Μεταβλητές που θα χρειαστούμε
int pir;                //Εδώ θα διαβάζουμε την τωρινή τιμή από τον αισθητήρα PIR
float cm;               //Εδώ θα διαβάζουμε την τιμή από τον αισθητήρα απόστασης σε εκατοστά
float rain;             //Εδώ θα διαβάζουμε την τιμή του αισθητήρα βροχής/χιονιού
float temp;             //Εδώ θα διαβάζουμε την τιμή του αισθητήρα θερμοκρασίας
float mZ;               //Εδώ θα κρατάμε τις μοίρες περιστροφής γύρω από τον άξονα Ζ από την μονάδα IMU
boolean ice = false;    //Μεταβλητή θα παίρνει 2 τιμές, False αν δεν έχει πάγο και true αν έχει πάγο


//Η συνάρτηση start κάνει την αρχικοποίηση του οχήματος μας
//Θα πρέπει να ενεργοποιήσουμε το γυροσκόπιο και να σηκώσουμε το μαχαίρι
void start() {
  delay(5000);                  //Περιμένουμε 5 δευτερόλεπτα για να τοποθετήσουμε το όχημα
  digitalWrite(pinL,HIGH);      //Ανάβουμε το φως
  Wire.begin();                 //Ξεκινάμε τις βιβλιοθήκες της μονάδα imu
  imu.begin();                  //Ξεκινάμε τις βιβλιοθήκες της μονάδα imu 
  imu.calcGyroOffsets(true);    //Ζητάμε από την μονάδα να κάνει την αρχική ρύθμιση (θέλει 3 δευτερόλεπτα)
  digitalWrite(pinL,LOW);       //Μόλις η ρύθμιση τελειώσει σβήνουμε το φως.
  front.attach(pinServoM);      //Ενεργοποιώ τον κινητήρα servo του μαχαιριού
  front.write(100);              //Ανεβάζω το μαχαίρι ;
}

//Η συνάρτηση checkIce θα ελέγχει τις συνθήκες θερμοκρασίας και βροόπτωσης/χιονόπτωσης και
//αν αυτές είναι τέτοιες ώστε να υπάρχει πάγος θα κάνει την μεταβλητή ice true αλλιώς θα την κάνει false
void checkIce() {
  DHT.read11(pinT);                           //Διαβάζουμε τις τιμές από τον αισθητήρα θερμοκρασίας
  temp = DHT.temperature;                     //Παίρνουμε την θερμοκρασία στην μεταβλητή temp
  rain = map(analogRead(pinR),0,1023,100,0);  //Παίρνουμε την τιμή της βροχόπτωσης/χιονόπτωσης
  if (temp > 0 && rain < 90) {                //Αν η θερμοκρασίας είναι κάτω από 0 και υπάρχει βροόπτωση/χιονόπτωση πάνω από 20% τότε
    ice = true;                              //Κάνω την μεταβλητή του πάγου σε true  
  } else {                                    //Αλλιώς
    ice = false;                             //Κάνω την μεταβλητή του πάγου σε false  
  }
}

//Η συνάρτηση checkPir ελέγχει αν υπάρχει κίνηση ανθρώπων μπροστά από το όχημα και το σταματάει εκπέμποντας προειδοποιητικό ήχο και φως
void checkPir() {
  pir = digitalRead(pinP);      //Διαβάζω την τιμή του αισθητήρα PIR
  if (pir == HIGH) {            //Αν υπάρχει κίνηση
    motorFR.run(RELEASE);       //Απενεργοποιώ τους κινητήρες
    motorBR.run(RELEASE);       //Απενεργοποιώ τους κινητήρες
    motorFL.run(RELEASE);       //Απενεργοποιώ τους κινητήρες 
    motorBL.run(RELEASE);       //Απενεργοποιώ τους κινητήρες 
    digitalWrite(pinL,HIGH);    //Ανάβω το φως 
    //digitalWrite(pinS,HIGH);    //Ανοίγω το ηχείο 
  } else {                      //Αλλιώς αν δεν υπάρχει κίνηση 
    digitalWrite(pinL,LOW);     //Κλείνω το φως 
    //digitalWrite(pinS,LOW);   //Κλείνω το ηχείο 
    motorFR.run(FORWARD);       //Ενεργοποιώ τους κινητήρες
    motorBR.run(FORWARD);       //Ενεργοποιώ τους κινητήρες
    motorFL.run(FORWARD);       //Ενεργοποιώ τους κινητήρες
    motorBL.run(FORWARD);       //Ενεργοποιώ τους κινητήρες
  }
}

//Η συνάρτηση drive οδηγεί το όχημα σε ευθεία στις μοίρες m που θέλουμε 
//Έτσι αν το όχημα μας κινείται μπροστά θα την γράψουμε ως drive(0), ενώ αν επιστρέφει 
//θα την γράψουμε ως drive(180)
void drive(float m) {       
  front.write(150);              //Κατεβάζω το μαχαίρι 
  motorFR.run(FORWARD);         //Ενεργοποιώ τους κινητήρες
  motorBR.run(FORWARD);         //Ενεργοποιώ τους κινητήρες
  motorFL.run(FORWARD);         //Ενεργοποιώ τους κινητήρες
  motorBL.run(FORWARD);         //Ενεργοποιώ τους κινητήρες
  cm = sonar.ping_cm();         //Παίρνουμε την απόσταση του τοίχου από τον αισθητήρα υπερήχων
  while (cm > 20 || cm == 0) {  //Όσο η απόσταση από τον τοίχο είναι μεγαλύτερη από 20 εκατοστά ή είναι μηδενική (μπορεί να μας δίνει τέτοια τιμή ο αισθητήρας αν δεν υπάρχει εμπόδιο κοντά
    checkPir();                 //Καλούμε τη συνάρτηση που ελέγχει για ανθρώπους
    if (ice == true) {          //Αν υπάρχει πάγος τότε
      OneStep(false);
    }
    imu.update();               //Ανανεώνουμε τις τιμές του γυροσκόπιου
    mZ = imu.getAngleZ();       //Παίρνουμε τις μοίρες περιστροφής γύρω από τον άξονα Ζ
    if (mZ < m-2) {             //Αν η γωνία περιστροφής είναι μικρότερη από -1 μοίρα το όχημα έχει φύγει λίγο δεξιά οπότε
      motorFR.setSpeed(150);    //Δίνουμε ταχύτητα 150 στους 2 κινητήρες δεξιά  
      motorBR.setSpeed(150);    //Δίνουμε ταχύτητα 150 στους 2 κινητήρες δεξιά  
      motorFL.setSpeed(0);      //Σταματάμε τους δυο κινητήρες αριστερά
      motorBL.setSpeed(0);      //Σταματάμε τους δυο κινητήρες αριστερά
    } else if (mZ > m+2) {      //Αν η γωνία περιστροφής είναι μεγαλύτερη από 1 μοίρα το όχημα έχει φύγει λίγο αριστερά οπότε
      motorFL.setSpeed(150);    //Δίνουμε ταχύτητα 150 στους 2 κινητήρες αριστερά  
      motorBL.setSpeed(150);    //Δίνουμε ταχύτητα 150 στους 2 κινητήρες αριστερά  
      motorFR.setSpeed(0);      //Σταματάμε τους δυο κινητήρες δεξιά
      motorBR.setSpeed(0);      //Σταματάμε τους δυο κινητήρες δεξιά
    } else {                    //Αλλιώς αν δεν έχουμε ξεφύγει από την ευθεία
      motorFL.setSpeed(150);    //Ορίζουμε την ταχύτητα και δεξιά και αριστερά στο 150
      motorBL.setSpeed(150);    //Ορίζουμε την ταχύτητα και δεξιά και αριστερά στο 150
      motorFR.setSpeed(150);    //Ορίζουμε την ταχύτητα και δεξιά και αριστερά στο 150
      motorBR.setSpeed(150);    //Ορίζουμε την ταχύτητα και δεξιά και αριστερά στο 150
    }
    cm = sonar.ping_cm();       //Παίρνουμε ξανά την απόσταση του τοίχου από τον αισθητήρα υπερήχων   
  }                             
  motorFR.run(RELEASE);         //Όταν πλέον φτάσουμε στον τοίχο απενεργοποιούμε τους 4 κινητήρες
  motorBR.run(RELEASE);         //Aπενεργοποιούμε τους 4 κινητήρες
  motorFL.run(RELEASE);         //Απενεργοποιούμε τους 4 κινητήρες
  motorBL.run(RELEASE);         //Απενεργοποιούμε τους 4 κινητήρες
  front.write(100);              //Ανεβάζω το μαχαίρι 
}

//Η συνάρητση turnLeft στρίβει το όχημα μας αριστερά μέχρι να φτάσει τις m μοίρες
void turnLeft(float m) {    
  while (mZ < m) {          //Όσο ακόμα δεν έχει φτάσει το όχημα τις επιθυμητές μοίρες
    motorFL.run(BACKWARD);   //Βάζω τους αριστερά κινητήρες να κινηθούν ανάποδα
    motorBL.run(BACKWARD);   //Βάζω τους αριστερά κινητήρες να κινηθούν ανάποδα
    motorFR.run(FORWARD);    //Τους δεξιά κινητήρες να κινηθούν μπροστά
    motorBR.run(FORWARD);    //Τους δεξιά κινητήρες να κινηθούν μπροστά
    motorFL.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    motorBL.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    motorFR.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    motorBR.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    imu.update();           //Ενημερώνω τις τιμές του γυροσκόπιου
    mZ = imu.getAngleZ();   //Παίρνω τη νέα τιμής της γωνίας Z
  }
  motorFR.run(RELEASE);      //Όταν πλέον φτάσω τις επιθυμητές μοίρες απενεργοποιώ τους κινητήρες
  motorBR.run(RELEASE);      //Απενεργοποιώ τους κινητήρες
  motorFL.run(RELEASE);      //Απενεργοποιώ τους κινητήρες
  motorBL.run(RELEASE);      //Απενεργοποιώ τους κινητήρες
}

//Η συνάρητση turnRight στρίβει το όχημα μας αριστερά μέχρι να φτάσει τις m μοίρες
void turnRight(float m) {    
  while (mZ > m) {          //Όσο ακόμα δεν έχει φτάσει το όχημα τις επιθυμητές μοίρες
    motorFR.run(BACKWARD);   //Βάζω τους δεξιά κινητήρες να κινηθούν ανάποδα
    motorBR.run(BACKWARD);   //Βάζω τους δεξιά κινητήρες να κινηθούν ανάποδα
    motorFL.run(FORWARD);    //Τους αριστερά κινητήρες να κινηθούν μπροστά
    motorBL.run(FORWARD);    //Τους αριστερά κινητήρες να κινηθούν μπροστά
    motorFL.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    motorBL.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    motorFR.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    motorBR.setSpeed(200);   //Ορίζω την ταχύτητα των κινητήρων
    imu.update();           //Ενημερώνω τις τιμές του γυροσκόπιου
    mZ = imu.getAngleZ();   //Παίρνω τη νέα τιμής της γωνίας Z
  }
  motorFR.run(RELEASE);      //Όταν πλέον φτάσω τις επιθυμητές μοίρες απενεργοποιώ τους κινητήρες
  motorBR.run(RELEASE);      //Απενεργοποιώ τους κινητήρες
  motorFL.run(RELEASE);      //Απενεργοποιώ τους κινητήρες
  motorBL.run(RELEASE);      //Απενεργοποιώ τους κινητήρες
}

void setup() {
  //Ορίζω τα pin που χρειάζονται να δηλωθούν ως input και output
  pinMode(pinS,OUTPUT);   //Ορίζουμε το pin του ηχείου ως έξοδο
  pinMode(pinL,OUTPUT);   //Ορίζουμε το pin του φωτός ως έξοδο
  pinMode(pinP, INPUT);   //Ορίζουμε το pin του αισθητήρα PIR ως είσοδο
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  
  //Τώρα ξεκινάν οι οδηγίες μας
  start();        //Βήμα 1ο Αρχικοποιώ το όχημα
  checkIce();     //Βήμα 2ο Ελέγχω τις συνθήκες θερμοκρασίας - υγρασίας για το αν υπάρχει πάγος
  drive(0);
  
}


void OneStep(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}


void loop() {
}
