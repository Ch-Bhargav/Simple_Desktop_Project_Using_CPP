//
// Created by chira on 06-11-2023.
//
#include "../include/Employee.h"
Employee::Employee(): emp_id(0), emp_name(""), emp_salary(0.0){

}

Employee::Employee(int emp_id, const string& emp_name, double emp_salary)
    :emp_id(emp_id), emp_name(emp_name), emp_salary(emp_salary){
}

int Employee::getId() const{
    return this->emp_id;
}
string Employee::getName() const {
    return this->emp_name;
}
double Employee::getSalary() const {
    return this->emp_salary;
}

void Employee::setId(int emp_id) {
    this->emp_id = emp_id;
}

void Employee::setName(std::string emp_name) {
    this->emp_name = emp_name;
}

void Employee::setSalary(double emp_salary) {
    this->emp_salary = emp_salary;
}

