#include "Bank.h"
#include <iostream>

Client* Bank::login(std::string u, std::string p) {
    for (auto& c : clients) {
        if (c.getUsername() == u && c.checkPassword(p))
            return &c;
    }
    return nullptr;
}

void Bank::addClient(std::string u, std::string p, bool agent) {
    clients.emplace_back(u, p, agent);
    std::cout << " Client " << u << " ajouté.\n";
}

Client* Bank::findClient(std::string username) {
    for (auto& c : clients)
        if (c.getUsername() == username)
            return &c;
    return nullptr;
}

void Bank::removeClient(std::string username) {
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->getUsername() == username) {
            clients.erase(it);
            std::cout << "Client supprimé.\n";
            return;
        }
    }
    std::cout << "Client introuvable.\n";
}

void Bank::showAllAccounts() const {
    std::cout << "\n==== LISTE DES COMPTES ====\n";
    for (const auto& c : clients) {
        std::cout << "- " << c.getUsername();
        if (c.isAgent()) std::cout << " (agent)";
        std::cout << "\n";
    }
}

bool Bank::transfer(std::string from, std::string to, double amount) {
    Client* c1 = findClient(from);
    Client* c2 = findClient(to);

    if (!c1 || !c2) {
        std::cout << "Un des comptes est introuvable.\n";
        return false;
    }

    if (!c1->getAccount().retirer(amount))
        return false;

    c2->getAccount().crediter(amount);

    std::cout << " Transfert réussi.\n";
    return true;
}