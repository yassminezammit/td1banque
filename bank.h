#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Client.h"

class Bank {
private:
    std::vector<Client> clients;

public:
    Client* login(std::string u, std::string p);

    void addClient(std::string u, std::string p, bool agent = false);
    void removeClient(std::string username);

    void showAllAccounts() const;

    bool transfer(std::string from, std::string to, double amount);

    Client* findClient(std::string username);
};

#endif