#pragma once
#include <string>
#include "ContactType.h"

class Contact {
public:
    std::string name;
    ContactType type;

    Contact(std::string name, ContactType type);
    virtual ~Contact() = 0;
};

