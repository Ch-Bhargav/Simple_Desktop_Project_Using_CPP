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
    CSVHelper csvHelper(filename);

    std::vector<std::vector<std::string>> data;

    for (const auto& employee : employees) {
        std::vector<std::string> rowData;
        rowData.push_back(std::to_string(employee.getId()));
        rowData.push_back(employee.getName());
        rowData.push_back(std::to_string(employee.getSalary()));
        data.push_back(rowData);
    }

    if (csvHelper.WriteCSV(data)) {
        std::cout << "Data saved to CSV file: " << filename << std::endl;
    } else {
        std::cerr << "Failed to save data to CSV." << std::endl;
    }
}

void EmployeeManager::loadDataFromCSV(const std::string &filename) {
    CSVHelper csvHelper(filename);
    std::vector<std::vector<std::string>> data;

    if (csvHelper.ReadCSV(data)) {
        employees.clear(); // Clear existing employee data

        for (const auto& row : data) {
            if (row.size() == 3) {
                int id = std::stoi(row[0]);
                std::string name = row[1];
                double salary = std::stod(row[2]);
                addEmployee(id, name, salary);
            }
        }

        std::cout << "Data loaded from CSV file: " << filename << std::endl;
    } else {
        std::cerr << "Failed to load data from CSV." << std::endl;
    }
}
