#include <iostream>
#include "CompteBancaire.h"

CompteBancaire::CompteBancaire(std::string numero)
    : numeroCompte(numero), solde(0.0) {}

void CompteBancaire::crediter(double montant) {
    solde += montant;
    std::cout << " Crédit effectué. Nouveau solde : " << solde << "euro\n";
}

bool CompteBancaire::retirer(double montant) {
    if (montant > solde) {
        std::cout << "Solde insuffisant.\n";
        return false;
    }
    solde -= montant;
    std::cout << " Retrait effectué. Nouveau solde : " << solde << "euro\n";
    return true;
}

void CompteBancaire::afficherInfos() const {
    std::cout << "Compte : " << numeroCompte
        << " | Solde : " << solde << "euro\n";
}

double CompteBancaire::getSolde() const {
    return solde;
}

std::string CompteBancaire::getNumero() const {
    return numeroCompte;
}