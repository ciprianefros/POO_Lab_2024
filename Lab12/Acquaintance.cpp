#include "Acquaintance.h"

Acquaintance::Acquaintance(std::string name, long long int phoneNumber)
    : Contact(name, ContactType::Acquaintance), phoneNumber(phoneNumber) {}