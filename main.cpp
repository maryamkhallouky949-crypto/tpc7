
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
   
    Contact(string n) {
        nom = n;
        telephone = "Non renseigne";
        email = "Non renseigne";
    }


    Contact(string n, string t) {
        nom = n;
        telephone = t;
        email = "Non renseigne";
    }


    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
       
    }
};

int main() {
   
    Contact c1("maryam");
    Contact c2("adam", "0612345678");
    Contact c3("reda", "0623406788", "reda@gmail.com");

    // Affichage
    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
