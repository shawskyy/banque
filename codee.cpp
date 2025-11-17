#include <iostream>
#include <string>
using namespace std;
class Compte {
private:
    string nom;
    double solde;

public:
    
    Compte(string n, double s = 0) {
        nom = n;
        solde = s;
    }

    
    void afficherSolde() {
        cout << nom << " a " << solde << " € sur son compte." << endl;
    }

    
    void credit(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << nom << " a reçu " << montant << " €." << endl;
        } else {
            cout << "Montant invalide." << endl;
        }
    }

    
    void debit(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << nom << " a dépensé " << montant << " €." << endl;
        } else {
            cout << "Solde insuffisant ou montant invalide." << endl;
        }
    }

    
    void transfert(Compte &autre, double montant) {
        if (montant > 0 && montant <= solde) {
            debit(montant);
            autre.credit(montant);
            cout << "Transfert de " << montant << " € vers " << autre.nom << " effectué." << endl;
        } else {
            cout << "Transfert impossible." << endl;
        }
    }
};
int main() {
    Compte compte1("Alice", 100);
    Compte compte2("Bob", 50);

    compte1.afficherSolde();
    compte2.afficherSolde();

    compte1.transfert(compte2, 30);

    compte1.afficherSolde();
    compte2.afficherSolde();

    return 0;
}
