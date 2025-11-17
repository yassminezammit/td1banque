#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

int main() {
    Bank bank;

    
    bank.addClient("wael", "wael");
    bank.addClient("yasmine", "yasmine1");
    bank.addClient("agent", "admin", true);

    int choice;

    while (true) {
        cout << "\n==== SYSTEME BANCAIRE ====\n";
        cout << "1. Login\n";
        cout << "2. Quitter\n";
        cout << "Choix : ";
        cin >> choice;

        if (choice == 2) break;

        string username, password;
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        Client* user = bank.login(username, password);

        if (!user) {
            cout << " Login invalide.\n";
            continue;
        }

        if (user->isAgent()) {
            int c;
            do {
                cout << "\n--- MENU AGENT ---\n";
                cout << "1. Créer un client\n";
                cout << "2. Afficher tous les comptes\n";
                cout << "3. Supprimer un client\n";
                cout << "4. Logout\n";
                cout << "Choix : ";
                cin >> c;

                if (c == 1) {
                    string u, p;
                    cout << "Nom utilisateur : "; cin >> u;
                    cout << "Mot de passe : "; cin >> p;
                    bank.addClient(u, p);
                }
                else if (c == 2) bank.showAllAccounts();
                else if (c == 3) {
                    string u;
                    cout << "Client à supprimer : "; cin >> u;
                    bank.removeClient(u);
                }

            } while (c != 4);
        }
        else {
            int c;
            do {
                cout << "\n--- MENU CLIENT ---\n";
                cout << "1. Afficher solde\n";
                cout << "2. Créditer\n";
                cout << "3. Retirer\n";
                cout << "4. Transférer\n";
                cout << "5. Logout\n";
                cout << "Choix : ";
                cin >> c;

                if (c == 1) user->getAccount().afficherInfos();
                else if (c == 2) {
                    double s; cout << "Somme : "; cin >> s;
                    user->getAccount().crediter(s);
                }
                else if (c == 3) {
                    double s; cout << "Somme : "; cin >> s;
                    user->getAccount().retirer(s);
                }
                else if (c == 4) {
                    string dest;
                    double s;
                    cout << "Destinataire : "; cin >> dest;
                    cout << "Somme : "; cin >> s;
                    bank.transfer(username, dest, s);
                }

            } while (c != 5);
        }
    }

    cout << "Au revoir !\n";
    return 0;
}