#include "Friend.h"

Friend::Friend(std::string name, std::string birthDate, long long int phoneNumber, std::string address)
    : Contact(name, ContactType::Friend), birthDate(birthDate), phoneNumber(phoneNumber), address(address) {};
