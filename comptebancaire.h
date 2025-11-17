#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <string>

class CompteBancaire {
private:
    std::string numeroCompte;
    double solde;

public:
    CompteBancaire(std::string numero);

    void crediter(double montant);
    bool retirer(double montant);
    void afficherInfos() const;

    double getSolde() const;
    std::string getNumero() const;
};

#endif