#pragma once
#include "Contact.h"

#include <vector>
#include <string>

class Friend : public Contact {
public:
    std::string birthDate;
    long long int phoneNumber;
    std::string address;

    Friend(std::string name, std::string birthDate, long long int phoneNumber, std::string address);

};

