# No-Snow
Ένα αυτόνομο εκχιονιστικό όχημα για τον καθαρισμό των αυλών στα σχολεία της Φλώρινας.
![](https://lh3.googleusercontent.com/xO7sTSYgVaHP3CewTKH7Cif9RfCc6hG_EpvHSLslNRIoFkOp1THHu7uWFASRAP4SzOY6zCx56El4OVzGu1Sz-iZWRYOYOWNuBQ8KCTcxCPi_N1hTWm2V-zk4BNUXDjUctixh7Ff76tcwklzNIrovwudYP6oPeZs7QBbuOLyxxbIowp-XWw0vQy6znL-_HHEAIcOaKQGCJbpXBTTVEArTaR4xi7VC6nAXZgl0V6F9BTlGQeLP23Puqq5umpnfMxNAgwkhzOH3pEqQt5TtVSXFQGeL0y_DqNeoFuT-bpq6ZJEAQjXcZLInghX4NAOkEd4t8Dw9IbH2Weck4GYPBTHWY3mUhBim6sUNyPDIlB3ibWItVrp1PQSsk-zFtFPIUurNYnsZYOgNwYWUZnTjsNlGQeVcANxGxJfumC9cXQghwqGLlnZ6lJ7XqUqnnU5vUI3QrZVHA-PjOQdFBKk0WUqWw9ao5WDyh6ZzW9Ey4LkanIhy-_cVkFZai_h2dXG99UCUzZ1XuAim7MH4zQf1_uT-bNx31FmgOJM0UItI1kcDTbiNLhmlZ1TTwthaP23JerkyDTLvbZlj-mOD4yu_9__72Gh17km5YSbe9MNmMHO4WwlDfNt3iVao5ZIYPPdkxNQG80vw0LZesGc-ze4aWTts9oXZWxMimRYnw17M0CiMIOPLjyL3T02Lvgmx6szSUAuWRGn_o5x2smzW8b-WVa0pVmM8=w1448-h969-no)
Μια από τις δημοφιλείς ιδέες ήταν ένα αυτόνομο εκχιονιστικό όχημα. Στην πόλη μας (Φλώρινα) κατά τους χειμερινούς μήνες έχουμε συχνά χιονοπτώσεις οι οποίες συνοδεύονται από χαμηλές θερμοκρασίες, με αποτέλεσμα προβλήματα στις μετακινήσεις, καθώς και στην λειτουργία των σχολείων. Ύστερα από κάθε ισχυρή χιονόπτωση, τα εκχιονιστικά μηχανήματα του Δήμου δουλεύουν συνεχώς για να καθαρίσουν τους δρόμους της πόλης και των γύρω χωριών, καθώς και τις αυλές των σχολείων πριν προλάβει να παγώσει το χιόνι. Αρκετές φορές τα σχολεία παραμένουν κλειστά γιατί δεν έχουν προλάβει να καθαριστεί οι αυλές, καθώς δίνεται προτεραιότητα τους δρόμους.

Επιλέξαμε λοιπόν να κατασκευάσουμε ένα αυτόνομο αποχιονιστικό μηχάνημα, το οποίο θα αναλαμβάνει να καθαρίσει το χιόνι από έναν συγκεκριμένο χώρο (για παράδειγμα την αυλή ενός σχολείου) χωρίς να χρειάζεται οδηγό.

#### Οι βασικές λειτουργίες που έχει το σύστημα μας είναι οι εξής:
- Μπορεί να κινηθεί σε ευθεία διαδρομή καθαρίζονας το χιόνι με το μαχαίρι και αντιλαμβάνεται τυχόν αποκλίσεις τις οποίες διορθώνει, με την βοήθεια γυροσκόπιου.
- Αντιλαμβάνεται πότε φτάνει στα όρια της αυλής με τον αισθητήρα απόστασης υπέρηχων και μπορεί να συνεχίσει την πορεία του προς την αντίθετη πλευρά με ακρίβεια αξιοποιώντας το γυροσκόπιο.
- Αντιλαμβάνεται την κίνηση ανθρώπων στον χώρο της αυλής (αισθητήρας PIR) και σταματάει εκπέμποντας προειδοποιητικά μηνύματα και φώτα.
- Αντιλαμβάνεται αν υπάρχουν συνθήκες δημιουργίας πάγου (αισθητήρας θερμοκρασίας και βροχόπτωσης) και να ρίχνει αλάτι στην αυλή.
#### Μελλοντικά σχέδια
- Υπολογισμός της θέσης του μέσα στην αυλή του σχολείου αξιοποιώντας τα δεδομένα από το γυροσκόπιο και τον αισθητήρα απόστασης.
- Επικοινωνία με έξυπνα κινητά τηλέφωνα ώστε να στέλνει και να δέχεται δεδομένα για την κατάσταση αποχιονισμού.

**Μπορείτε να διαβάσετε αναλυτικά για την υλοποίηση του έργου [στην ιστοσελίδα του ομίλου μας.](http://ppf.edu.gr/hackers/archives/604 "στην ιστοσελίδα του ομίλου μας.")**
