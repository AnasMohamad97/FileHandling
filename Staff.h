//
// Created by Anas Mohamad Sobhi on 5/18/20.
//

#ifndef FILE_RESEARCH_STAFF_H
#define FILE_RESEARCH_STAFF_H

#include <iostream>
#include <fstream>

using namespace std;

class Staff {

public:

    char name[200];
    char id[100];
    char degree[100];
    char staff_dep_id[100];
    const static int maxRecordSize  = 700;

    void write_staff_record(fstream& stream)
    {
        char record[maxRecordSize];
        strcpy(record , this->id);
        strcat(record,"|");
        strcat(record , this->name);
        strcat(record,"|");
        strcat(record , this->degree);
        strcat(record,"|");
        strcat(record,this->staff_dep_id);
        strcat(record , "\n");
        short len = strlen(record);
        stream.write((char*)&len , sizeof(len));
        stream.write(record , len);
    }




};


#endif //FILE_RESEARCH_STAFF_H
