#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <cstring>

class Manager : public Employee {
public:
    Manager() {
        setEmpID(101); // Default admin ID
        setPassword("robin"); // Default admin password
        setRole("Admin");
    }
};

#endif