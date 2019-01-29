# No-Snow
Ένα αυτόνομο εκχιονιστικό όχημα για τον καθαρισμό των αυλών στα σχολεία της Φλώρινας.
# Πως επιλέξαμε το θέμα
- Αρχικά μέσα από μια δίωρη ιδεοθύελλα (brainstorming) δημιουργήσαμε τον [εννοιολογικό χάρτη](http://ppf.edu.gr/hackers/archives/153 "εννοιολογικό χάρτη") με τα γενικά θέματα τα οποία μας απασχολούν.
- Στην [επόμενη συνάντηση μας](http://ppf.edu.gr/hackers/archives/247 "επόμενη συνάντηση μας"), αφού μελετήσαμε τον εννοιολογικό χάρτη και τις πληροφορίες που είχαμε συλλέξει για τα θέματα που είχαν αποτυπωθεί σε αυτόν, ξεκινήσαμε να γράφουμε [ιδέες και προτάσεις](http://ppf.edu.gr/hackers/archives/category/%CE%B9%CE%B4%CE%AD%CE%B5%CF%82-%CE%B3%CE%B9%CE%B1-%CE%BA%CE%B1%CF%84%CE%B1%CF%83%CE%BA%CE%B5%CF%85%CE%AD%CF%82 "ιδέες και προτάσεις").
- Η συγγραφή και ο σχολιασμός ιδεών και προτάσεων διήρκησε τρεις εβδομάδες. Μια από τις δημοφιλείς ιδέες ήταν ένα [αυτόνομο εκχιονιστικό όχημα](http://ppf.edu.gr/hackers/archives/510 "αυτόνομο εκχιονιστικό όχημα").
# Αναλυτική περιγραφή
## Τι θέλουμε να πετύχουμε
Στην πόλη μας (Φλώρινα) κατά τους χειμερινούς μήνες έχουμε συχνά χιονοπτώσεις οι οποίες συνοδεύονται από χαμηλές θερμοκρασίες, με αποτέλεσμα προβλήματα στις μετακινήσεις, καθώς και στην λειτουργία των σχολείων. Ύστερα από κάθε ισχυρή χιονόπτωση, τα εκχιονιστικά μηχανήματα του δήμου δουλεύουν συνεχώς για να καθαρίσουν τους δρόμους της πόλης και των γύρω χωριών, καθώς και τις αυλές των σχολείων πριν προλάβει να παγώσει το χιόνι. Αρκετές φορές τα σχολεία παραμένουν κλειστά γιατί δεν έχουν προλάβει να καθαριστεί οι αυλές, καθώς δίνεται προτεραιότητα τους δρόμους. Θα θέλαμε να κατασκευάσουμε ένα αυτόνομο εκχιονιστικό μηχάνημα, το οποίο θα αναλαμβάνει να καθαρίσει το χιόνι από έναν συγκεκριμένο χώρο (για παράδειγμα την αυλή ενός σχολείου) χωρίς να χρειάζεται οδηγό.
## Οι βασικές λειτουργίες που θέλουμε να έχει το σύστημα μας είναι οι εξής:
- Να τοποθετούμε το όχημα μας στην αρχική του θέση και με δεδομένες τις διαστάσεις τις αυλής να την καθαρίζει από το χιόνι.
- Να αντιλαμβάνεται την σχετική του θέση από την αφετηρία και με αυτόν τον τρόπο να υπολογίζει την θέση του στον χώρο της αυλής.
- Να αντιλαμβάνεται τυχόν στατικά εμπόδια που υπάρχουν στον χώρο και να τα αποφεύγει.
- Να αντιλαμβάνεται την κίνηση ανθρώπων στον χώρο της αυλής και να σταματάει εκπέμποντας προειδοποιητικά μηνύματα και φώτα.
- Να αντιλαμβάνεται αν το χιόνι έχει καθαριστεί από την διαδρομή που περνάει, ή θα πρέπει να ξαναπεράσει.
## Πως σκοπεύουμε να υλοποιήσουμε το σύστημα μας
- Σκεφτόμαστε να κατασκευάσουμε ένα τετρακίνητο όχημα, με 4 κινητήρες gear dc, αξιοποιώντας κάποιο από τα συναρμολογούμενα kit που υπάρχουν διαθέσιμα στην αγορά.
- Το μηχανισμό για την απώθηση του χιονιού θα τον κατασκευάσουμε αξιοποιώντας τον τρισδιάστατο εκτυπωτή του Ομίλου μας, βασισμένοι σε σχέδια που υπάρχουν διαθέσιμα στο διαδίκτυο με ελεύθερες άδειες χρήσης.
- Η κεντρική μονάδα του οχήματος μας θα αποτελείται από ένα Arduino uno
- Οι 4 κινητήρες θα συνδέονται στην κεντρική μονάδα με την χρήση ενός motor driver.
- Για την αλλαγή θέσης (σηκωμένος ή κατεβασμένος) του μηχανισμού απώθησης του χιονιού θα χρησιμοποιήσουμε έναν κινητήρα servo.
- Για τον έλεγχο του χιονιού στο έδαφος θα χρησιμοποιήσουμε αισθητήρα RGB υπέρυθρων. 
- Για την αποφυγή εμποδίων θα χρησιμοποιήσουμε τρεις αισθητήρες υπερήχων.
- Για την αναγνώριση της κίνησης ανθρώπων θα χρησιμοποιήσουμε τέσσερις αισθητήρες PIR.
- Για την ειδοποίηση των ανθρώπων που κινούνται κοντά στο όχημα μας, θα χρησιμοποιήσουμε ένα buzzer και φώτα led.
- Για το υπολογισμό της θέσης του οχήματος μας μέσα στην αυλή θα χρησιμοποιήσουμε ένα γυροσκόπιο, το οποίο θα μας δίνει την σχετική θέση του οχήματος από το σημείο εκκίνησης.
## Λίστα βασικού εξοπλισμού
- 1 x [Arduino UNO R3 ATmega328P Board](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/microcontrollers/compatible-boards/arduino-uno-r3-atmega328p-board-usb-cable/ "Arduino UNO R3 ATmega328P Board") - 7,48 ευρώ.
- 1 x [L293D Motor Driver Shield](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/motors/drivers/l293d-motor-driver-shield-expansion-board-for-arduino/ "L293D Motor Driver Shield") - 4,87 ευρώ
- 1 x [4WD Smart Robot Car Chassis Kit for Arduino](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/kit/4wd-smart-robot-car-chassis-kit-for-arduino-with-speed-encoder-for-arduino/ "4WD Smart Robot Car Chassis Kit for Arduino") - 18,49 ευρώ
- 2 x [MG90S Micro Metal Gear 9g Servo](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/motors/servo/mg90s-micro-metal-gear-9g-servo-for-arduino-rc-180-degrees/ "MG90S Micro Metal Gear 9g Servo") - 10 ευρώ
- 1 x [APDS-9960 RGB Sensor](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/sensors/distance/apds-9960-rgb-gesture-sensor-for-arduino/ "APDS-9960 RGB Sensor") - 6,20 ευρώ
- 3 x [HC-SR04 Ultrasonic Module](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/sensors/sound/hc-sr04-ultrasonic-module-distance-measuring-transducer-sensor-for-arduino/ "HC-SR04 Ultrasonic Module") - 6 ευρώ
- 4 [PIR Motion Detector Module HC-SR501](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/sensors/distance/pir-motion-detector-module-hc-sr501-for-arduino/ "PIR Motion Detector Module HC-SR501") - 8,76 ευρώ
- 1 x [Active Buzzer Alarm Module](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/outputs/active-buzzer-alarm-module-for-arduino/ "Active Buzzer Alarm Module") - 2,19 ευρώ
- 1 x [3W High-Power LED Module](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/outputs/keyes-3w-high-power-led-module-for-arduino/ "3W High-Power LED Module") - 2,59 ευρώ
- 1 x [MPU9250+BMP280 10DOF Acceleration/Gyroscope/Compass Sensor Module - GY-91](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/sensors/tilt/mpu9250bmp280-10dof-acceleration-gyroscope-compass-sensor-module-gy-91/ "MPU9250+BMP280 10DOF Acceleration/Gyroscope/Compass Sensor Module - GY-91") - 12,19 ευρώ
- 1 x [1Kg Filament PM Fluorescent Yellow PLA 1.75mm](https://www.cableworks.gr/3d-printers/filaments/filament-pm/pla/1kg-filament-pm-fluorescent-yellow-pla-1.75mm/ "1Kg Filament PM Fluorescent Yellow PLA 1.75mm") - 21,01 ευρώ
**Συνολικό κόστος: 99,78 ευρώ**
## Πρόχειρο σχέδιο κατασκευής
![](https://github.com/hackersppf/No-Snow/blob/master/no%20snow%20%CF%80%CF%81%CE%BF%CF%83%CF%87%CE%AD%CE%B4%CE%B9%CE%BF.png)
