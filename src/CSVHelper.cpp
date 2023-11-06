//
// Created by chira on 06-11-2023.
//

#include <string>
#include<bits/stdc++.h>
#include<vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/CSVHelper.h"
using namespace std;

CSVHelper::CSVHelper(const string& filename) : filename(filename) {

}

bool CSVHelper::ReadCSV(vector<vector<string>>& data) {
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Failed to open CSV file" << endl;
        return false;
    }
    string line;
    while(getline(file,line)) {
        vector<string> row;
        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    file.close();
    return true;
}


bool CSVHelper::WriteCSV(vector<vector<std::string>> &data){
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open CSV file for writing." << std::endl;
        return false;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
    return true;
}
