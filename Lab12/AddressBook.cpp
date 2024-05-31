#include "AddressBook.h"
#include <algorithm>

AddressBook::AddressBook() {}

void AddressBook::addContact(Contact* contact) {
    contacts.push_back(contact);
}

bool AddressBook::searchContact(const std::string& name) {
    for (auto contact : contacts) {
        if (contact->name == name) {
            return true;
        }
    }
    return false;
}

std::vector<Friend*> AddressBook::searchFriends() {
    std::vector<Friend*> friends;
    for (auto contact : contacts) {
        if (contact->type == ContactType::Friend) {
            friends.push_back(static_cast<Friend*>(contact));
        }
    }
    return friends;
}

void AddressBook::deleteContact(const std::string& name) {
    auto it = std::remove_if(contacts.begin(), contacts.end(), [&](Contact* contact) {
        return contact->name == name;
        });

    if (it != contacts.end()) {
        delete* it;
        contacts.erase(it, contacts.end());
    }
}