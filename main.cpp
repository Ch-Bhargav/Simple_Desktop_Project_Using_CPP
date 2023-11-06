#include <iostream>
#include<bits/stdc++.h>
#include "include/EmployeeManager.h"
#include "include/Employee.h"
using namespace std;

int main() {
    EmployeeManager employeeManager;
    int choice;
    while(true) {
        cout << "Employee Managemnet System" << endl;
        cout << "Select your Option" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Remove Employee" << endl;
        cout << "3. find Employee" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Save Data to CSV" << endl;
        cout << "6. Load Data From CSV" << endl;
        cout << "7. To exit the program" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter Employee Id:";
                int emp_id;
                cin >> emp_id;
                cout << "Enter Employee Name:";
                string emp_name;
                cin.ignore();
                getline(cin, emp_name);
                cout << "Enter Employee Salary:";
                double emp_salary;
                cin >> emp_salary;
                employeeManager.addEmployee(emp_id, emp_name, emp_salary);
                break;
            }
            case 2: {
                cout << "Enter employee Id to be removed:";
                int id;
                cin >> id;
                if (employeeManager.removeEmployee(id))
                    cout << "Employee with id:" << id << "Removed Succesfully" << endl;
                else cout << "No Employee with such id Found" << endl;
                break;
            }
            case 3: {
                cout << "Enter Employee to find:";
                int id;
                cin >> id;
                Employee *findEmployee = employeeManager.findEmployee(id);
                if (findEmployee) {
                    cout << "Employee Name:" << findEmployee->getName() << endl;
                    cout << "Employee Id:" << findEmployee->getId() << endl;
                    cout << "Employee Salary:" << findEmployee->getSalary() << endl;
                }
                break;
            }
            case 4: {
                employeeManager.displayAllEmployees();
                break;
            }
            case 5: {
                cout << "Enter the file name:";
                string filename;
                cin >> filename;
                employeeManager.saveDataToCSV(filename);
                cout << "Data saved to " << filename << endl;
                break;
            }
            case 6: {
                string filename;
                cout << "Enter CSV filename to load data: ";
                cin >> filename;
                employeeManager.loadDataFromCSV(filename);
                cout << "Data loaded from " << filename << endl;
                break;
            }
            case 7: {
                cout << "Exiting the Employee Management System." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }

        }
    }
}
