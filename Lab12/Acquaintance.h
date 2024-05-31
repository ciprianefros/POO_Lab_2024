#pragma once
#include "Contact.h"

class Acquaintance : public Contact {
public:
    long long int phoneNumber;

    Acquaintance(std::string name, long long int phoneNumber);
};

