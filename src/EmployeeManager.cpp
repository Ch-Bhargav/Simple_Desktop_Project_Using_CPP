//
// Created by chira on 06-11-2023.
//

#include <iostream>
#include "../include/Employee.h"
#include "../include/CSVHelper.h"
#include "../include/EmployeeManager.h"

using namespace std;

EmployeeManager::EmployeeManager(){

}

void EmployeeManager::addEmployee(int emp_id, const std::string &emp_name, double emp_salary) {
    Employee newEmployee(emp_id,emp_name,emp_salary);
    employees.push_back(newEmployee);
}
bool EmployeeManager::removeEmployee(int id) {
    for(auto i = employees.begin();i != employees.end();i++){
        if(i->getId() == id) {
            employees.erase(i);
            return true;
        }
    }
    return false;
}
Employee* EmployeeManager::findEmployee(int id) {
    for(auto& employee : employees){
        if(employee.getId() == id)
            return &employee;
    }
    return nullptr;
}

void EmployeeManager::displayAllEmployees() const {
    for(const auto& employee : employees){
        cout << "Employee id:" << employee.getId() << endl;
        cout << "Employee Name:" << employee.getName() << endl;
        cout << "Employee Salary:" << employee.getSalary() << endl;
        cout << "-------------------------------------------" << endl;
    }
}

void EmployeeManager::saveDataToCSV(const std::string &filename) const {

}

void EmployeeManager::loadDataFromCSV(const std::string &filename) {

}
