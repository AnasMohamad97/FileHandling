//
// Created by Anas Mohamad Sobhi on 5/18/20.
//

#ifndef FILE_RESEARCH_STUDENT_H
#define FILE_RESEARCH_STUDENT_H

#include <iostream>
#include <fstream>

using namespace std;

class Student {

public:
    char name[200];
    char ID[100];
    char level[100];
    char gpa[100];
    char deptId[100];
    const static int maxRecordSize  = 700;

    void write_student(fstream& stream)
    {
        char record[maxRecordSize];
        strcpy(record , this->ID);
        strcat(record,"|");
        strcat(record , this->name);
        strcat(record,"|");
        strcat(record,this->level);
        strcat(record,"|");
        strcat(record , this->gpa);
        strcat(record,"|");
        strcat(record , this->deptId);
        strcat(record , "\n");
        short len = strlen(record);
        stream.write((char*)&len , sizeof(len));
        stream.write(record , len);
    }

};


#endif //FILE_RESEARCH_STUDENT_H
