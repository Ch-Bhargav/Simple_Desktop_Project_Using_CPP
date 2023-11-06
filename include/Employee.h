//
// Created by chira on 06-11-2023.
//

#ifndef DESKTOPPROJECT_EMPLOYEE_H
#define DESKTOPPROJECT_EMPLOYEE_H

#include <string>
using namespace std;

class Employee{
private:
    int emp_id;
    string emp_name;
    double emp_salary;
public:

    Employee();
    Employee(int emp_id, const string& emp_name, double emp_salary);
    int getId() const;
    string getName() const;
    double getSalary() const;

    void setId(int emp_id);
    void setName(string emp_name);
    void setSalary(double emp_salary);

};
#endif //DESKTOPPROJECT_EMPLOYEE_H
