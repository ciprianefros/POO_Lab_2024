#include "Colleague.h"

Colleague::Colleague(std::string name, long long int phoneNumber, std::string company, std::string address)
    : Contact(name, ContactType::Colleague), phoneNumber(phoneNumber), company(company), address(address) {}