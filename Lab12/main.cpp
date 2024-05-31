#include <iostream>
#include "AddressBook.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"

int main() {

    AddressBook addressBook;

    addressBook.addContact(new Friend("Ana", "01-01-1990", 0731234567, "Strada Victoriei, Bucuresti"));
    addressBook.addContact(new Acquaintance("Bogdan", 732345678));
    addressBook.addContact(new Colleague("Carmen", 733456789, "ABC Corp", "Strada Universitații, Cluj-Napoca"));
    addressBook.addContact(new Friend("Dan", "02-02-1992", 734567890, "Strada Republicii, Timisoara"));
    addressBook.addContact(new Acquaintance("Elena", 735678901));
    addressBook.addContact(new Colleague("Florin", 736789012, "XYZ Corp", "Strada Libertatii, Iași"));
    addressBook.addContact(new Friend("Gabriel", "03-03-1993", 737890123, "Strada Mihai Viteazu, Constanta"));
    addressBook.addContact(new Acquaintance("Horia", 738901234));
    addressBook.addContact(new Colleague("Irina", 739012345, "DEF Corp", "Strada Eroilor, Brasov"));

    std::string searchName = "Ana";
    if (addressBook.searchContact(searchName)) {
        std::cout << searchName << " is in the address book." << std::endl;
    }
    else {
        std::cout << searchName << " is not in the address book." << std::endl;
    }

    std::vector<Friend*> friends = addressBook.searchFriends();
    std::cout << "Friends in the address book:" << std::endl;
    for (auto friendContact : friends) {
        std::cout << "Name: " << friendContact->name << ", Birth Date: " << friendContact->birthDate
            << ", Phone Number: " << friendContact->phoneNumber << ", Address: " << friendContact->address << std::endl;
    }

    addressBook.deleteContact("Bogdan");

    searchName = "Bogdan";
    if (addressBook.searchContact(searchName)) {
        std::cout << searchName << " is still in the address book." << std::endl;
    }
    else {
        std::cout << searchName << " has been deleted from the address book." << std::endl;
    }

    return 0;
}