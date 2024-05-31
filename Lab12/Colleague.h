#pragma once
#include "Contact.h"

class Colleague : public Contact {
public:
    long long int phoneNumber;
    std::string company;
    std::string address;

    Colleague(std::string name, long long int phoneNumber, std::string company, std::string address);
};

