//
// Created by Anas Mohamad Sobhi on 5/18/20.
//

#ifndef FILE_RESEARCH_DEPARTMENT_H
#define FILE_RESEARCH_DEPARTMENT_H

#include <iostream>
#include <fstream>

using namespace std;


class Department {

public:
    char dept_ID[100];
    char deptName[200];
    char HeadOfDept[200];
    const static int maxRecordSize  = 600;

    void write_dept_record(fstream& stream)
    {
        char record[maxRecordSize];
        strcpy(record , this->dept_ID);
        strcat(record,"|");
        strcat(record , this->deptName);
        strcat(record,"|");
        strcat(record , this->HeadOfDept);
        strcat(record , "\n");
        short len = strlen(record);
        stream.write((char*)&len , sizeof(len));
        stream.write(record , len);
    }

};


#endif //FILE_RESEARCH_DEPARTMENT_H
