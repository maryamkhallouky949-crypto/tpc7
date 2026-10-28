
#include <iostream>
using namespace std;

class CompteBancaire {
private:
    double solde;
    int codeSecurite;

public:
  
    CompteBancaire() {
        solde = 0;
        codeSecurite = 1234;
    }


    CompteBancaire(double s, int code) {
        if (s >= 0) {
            solde = s;
        } else {
            solde = 0;
            cout << "Solde initial invalide. Solde fixe a 0." << endl;
        }

        codeSecurite = code;
    }

  
    void afficherSolde() {
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Erreur : montant invalide." << endl;
        } else if (montant > solde) {
            cout << "Erreur : solde insuffisant." << endl;
        } else {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        }
    }

    void retrait(double montant, int code) {
        if (code != codeSecurite) {
            cout << "Erreur : code de securite incorrect." << endl;
        } else if (montant <= 0) {
            cout << "Erreur : montant invalide." << endl;
        } else if (montant > solde) {
            cout << "Erreur : solde insuffisant." << endl;
        } else {
            solde -= montant;
            cout << "Retrait securise effectue avec succes." << endl;
        }
    }
};

int main() {
    CompteBancaire c1;

    CompteBancaire c2(1000, 4567);

    cout << "Compte 1 " << endl;
    c1.afficherSolde();

    cout << "Compte 2" << endl;
    c2.afficherSolde();

    cout << " Retrait simple de 200 DH" << endl;
    c2.retrait(200);
    c2.afficherSolde();

    cout << "Retrait securise de 300 DH" << endl;
    c2.retrait(300, 4567);
    c2.afficherSolde();

    cout << "Test avec un mauvais code " << endl;
    c2.retrait(100, 1111);
    c2.afficherSolde();

    cout << "Test avec un montant trop eleve" << endl;
    c2.retrait(2000, 4567);
    c2.afficherSolde();

    return 0;
}
