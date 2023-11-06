//
// Created by chira on 06-11-2023.
//

#ifndef DESKTOPPROJECT_CSVHELPER_H
#define DESKTOPPROJECT_CSVHELPER_H
#include<bits/stdc++.h>
using namespace std;
 class CSVHelper{
 public:
     CSVHelper(const string& filename);
     bool ReadCSV(vector<vector<string>>& data);
     bool WriteCSV(vector<vector<string>>& data);
 private:
     string filename;

 };

#endif //DESKTOPPROJECT_CSVHELPER_H
