#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "CompteBancaire.h"

class Client {
private:
    std::string username;
    std::string password;
    bool agent;
    CompteBancaire compte;

public:
    Client(std::string u, std::string p, bool isAgent = false);

    std::string getUsername() const;
    bool checkPassword(std::string p) const;

    bool isAgent() const;
    CompteBancaire& getAccount();
};

#endif