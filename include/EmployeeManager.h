//
// Created by chira on 06-11-2023.
//

#ifndef DESKTOPPROJECT_EMPLOYEEMANAGER_H
#define DESKTOPPROJECT_EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>
using namespace std;
class EmployeeManager{
public:
    EmployeeManager();
    void addEmployee(int emp_id,const string& name, double emp_salary);
    bool removeEmployee(int id);
    Employee* findEmployee(int id);
    void displayAllEmployees() const;
    void saveDataToCSV(const string& filename) const;
    void loadDataFromCSV(const string& filename);

private:
    vector<Employee> employees;
};

#endif //DESKTOPPROJECT_EMPLOYEEMANAGER_H
