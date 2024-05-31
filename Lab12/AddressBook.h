#pragma once
#include <vector>
#include <string>
#include "Contact.h"
#include "Friend.h"

class AddressBook {
private:
    std::vector<Contact*> contacts;

public:
    AddressBook();

    void addContact(Contact* contact);
    bool searchContact(const std::string& name);
    std::vector<Friend*> searchFriends();
    void deleteContact(const std::string& name);
};


