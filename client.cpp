#include "Client.h"

Client::Client(std::string u, std::string p, bool isAgent)
    : username(u), password(p), agent(isAgent), compte(CompteBancaire(u)) {}

std::string Client::getUsername() const {
    return username;
}

bool Client::checkPassword(std::string p) const {
    return p == password;
}

bool Client::isAgent() const {
    return agent;
}

CompteBancaire& Client::getAccount() {
    return compte;
}