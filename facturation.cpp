
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Article {
    string nom;
    double prixUnitaire;
    int quantite;
    double tauxTVA;
};

class Facture {
private:
    vector<Article> articles;

public:
    
    void ajouterArticle(string nom, double prix) {
        articles.push_back({nom, prix, 1, 20.0});
    }

    void ajouterArticle(string nom, double prix, int quantite) {
        articles.push_back({nom, prix, quantite, 20.0});
    }

    void ajouterArticle(string nom, double prix,
                        int quantite, double tva) {
        articles.push_back({nom, prix, quantite, tva});
    }

  
    void afficherTotal() {
        double total = 0;

        cout << "FACTURE" << endl;

        for (const Article& a : articles) {
            double sousTotal = a.prixUnitaire * a.quantite;
            double montantTVA = sousTotal * a.tauxTVA / 100.0;
            double totalArticle = sousTotal + montantTVA;

            cout << "Article : " << a.nom << endl;
            cout << "Prix unitaire : " << a.prixUnitaire << " DH" << endl;
            cout << "Quantite : " << a.quantite << endl;
            cout << "TVA : " << a.tauxTVA << "%" << endl;
            cout << "Total article : " << totalArticle << " DH" << endl;

            total += totalArticle;
        }

        cout << "Total de la facture : " << total << " DH" << endl;
    }
};

int main() {
    Facture f;

   
    f.ajouterArticle("crayon", 5.0);

   
    f.ajouterArticle("Cahier", 20.0, 3);

    f.ajouterArticle("Sac", 200.0, 2, 10.0);

    f.afficherTotal();

    return 0;
}
