#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>



using namespace std;


struct Student_prim_index
{
    string id ;
    short offset;
};
bool comp_PI(Student_prim_index i1, Student_prim_index i2)
{
    return (i1.id < i2.id);
}

struct Staff_prim_index
{
    string id ;
    short offset;
};

struct Dep_prim_index
{
    string id ;
    short offset;
};

struct Student_SI_GPA
{
    // secondry index of gpa and prim index;
    double gpa;
    string id; // primary index

};

struct Student_SI_DepID
{
    // secondry index of gpa and prim index;
    string Depid;
    string id; // primary index

};

bool comp_SI_GPA(Student_SI_GPA i1, Student_SI_GPA i2)
{
    return (i1.gpa > i2.gpa);
}


struct Staff_SI_DepID
{
    // secondry index of DepartmentId and prim index(Staff ID);

    string depID;
    string id; // primary index

};
struct Staff_SI_Name
{
    // secondry index of DepartmentId and prim index(Staff ID);

    string Name;
    string id; // primary index

};

bool comp_SI_Staffname(Staff_SI_Name i1, Staff_SI_Name i2)
{
    return (i1.Name < i2.Name);
}
vector<Student_prim_index>Student_PI;
vector<Staff_prim_index> Staff_PI;
vector<Dep_prim_index> Dep_PI;

class Student {

public:
    char name[200];
    char ID[100];
    char level[100];
    char gpa[100];
    char deptId[100];
    const static int maxRecordSize  = 700;
    short Len;
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
        this->Len = len;
        cout<<Len<<endl;
       // stream.write((char*)&len , sizeof(len));
        stream.write(record , len);
    }
};

class Department {

public:
    char dept_ID[100];
    char deptName[100];
    char HeadOfDept[100];
    const static int maxRecordSize  = 300;
    short Len ;

    void write_dept_record(ofstream& stream)
    {
        char record[maxRecordSize];
        strcpy(record , this->dept_ID);
        strcat(record,"|");
        strcat(record , this->deptName);
        strcat(record,"|");
        strcat(record , this->HeadOfDept);
        strcat(record , "\n");
        short len = strlen(record);
        this->Len = len;
        //stream.write((char*)&len , sizeof(len));
        stream.write(record , len);
    }

};

class Staff {

public:

    char name[200];
    char id[100];
    char degree[100];
    char staff_dep_id[100];
    const static int maxRecordSize  = 700;
    short Len ;
    void write_staff_record(ofstream& stream)
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
        this->Len = len;
        //stream.write((char*)&len , sizeof(len));
        stream.write(record , len);
    }
};

vector<Staff_SI_DepID> Read_Staff_SIndex_DepID()
{
    fstream file;
    file.open("StaffSI_DepID.txt",ios::out|ios::in);
    vector<Staff_SI_DepID>v;
    Staff_SI_DepID tmp;

    char DepId[100];  // secondry key
    char StaffId[100]; //Primary key

    while(true)
    {
        file.getline(DepId, sizeof(DepId) , '|');
        file.getline(StaffId , sizeof(StaffId) , '|');

        if(file.fail())break;
        if(file.eof())break;

        tmp.depID = DepId;
        tmp.id = StaffId;
        v.push_back(tmp);

    }

       return v ;

}

void write_Staff_SIndex_DepID(char StaffId[] , char DepId[] )
{

        fstream file;
        file.open("StaffSI_DepID.txt",ios::out|ios::in|ios::app);

        char del = '|';

        file.write(DepId, sizeof(DepId));
        file.write(&del , sizeof(del));
        file.write(StaffId, sizeof(StaffId));
        file.write(&del , sizeof(del));

}

void Read_Staff_prim_Index_file()
{

    fstream file;
    file.open("StaffPI.txt",ios::out|ios::in);
    char id[100];
    char ofset[100];
    Staff_prim_index spi;
    while(true)
    {
        file.getline(id, sizeof(id),'|');
        file.getline(ofset, sizeof(ofset),'|');
       // cout<<strlen(id)<<" "<<strlen(ofset)<<endl;

        if(file.fail())break;
        if(file.eof())break;


        spi.id = string(id);
        string str(ofset);
        str.erase(0,1);
        spi.offset = stoi(str);
        spi.id.erase(0,1);
        // cout<<spi.id<<" "<<spi.offset<<endl;
        Staff_PI.push_back(spi);

    }
    file.close();



}

void Write_Staff_prim_Index_file(int s)
{
fstream outfile;
outfile.open("StaffPI.txt", ios::in | ios::out |ios::app);
char del = '|';
for(int i = s ; i < Staff_PI.size() ; ++i)
{
    outfile.write((char*)&Staff_PI[i].id , sizeof(Student_PI[i].id));
    outfile.write(&del , sizeof(del));
    string ofset = to_string(Staff_PI[i].offset);
    outfile.write((char*)&ofset, sizeof(ofset));
    outfile.write(&del , sizeof(del));

}

}
void Add_Staff_Record()
{
ofstream file;
file.open("staff.txt");
Staff record;
Read_Staff_prim_Index_file();
int start = Staff_PI.size();

cout<<"Enter the number of the  records : ";
int n;
cin >> n;
cin.ignore();
while(n--)
{
    cout<<"Enter The Staff ID : ";
    cin.getline(record.id , sizeof(record.id));

    cout<<"Enter The Staff Name : ";
    cin.getline(record.name , sizeof(record.name));

    cout<<"Enter The Staff Degree : ";
    cin.getline(record.degree, sizeof(record.degree));

    cout<<"Enter The Staff Department ID : ";
    cin.getline( record.staff_dep_id , sizeof(record.staff_dep_id));

    record.write_staff_record(file);
    Staff_prim_index tmp;

    tmp.id = record.id;

    if(!Staff_PI.empty())
    {
        tmp.offset = record.Len + Staff_PI.back().offset;
    }
    else tmp.offset = record.Len;
    write_Staff_SIndex_DepID(record.id , record.staff_dep_id);
    Staff_PI.push_back(tmp);

}
Write_Staff_prim_Index_file(start);


}

void Read_Department_prim_Index_file()
{

    fstream file;

    file.open("DepartmentPI.txt",ios::out|ios::in);

    char id[100];
    char ofset[100];

    Dep_prim_index dpi;

    while(true)
    {
        file.getline(id, sizeof(id),'|');
        file.getline(ofset, sizeof(ofset),'|');

        if(file.fail())break;
        if(file.eof())break;

       // cout<<id<<" "<<ofset<<endl;
        dpi.id = string(id);
        string str(ofset);
        str.erase(0,1);
        dpi.offset = stoi(str);
        //cout<<dpi.id<<" "<<dpi.offset<<endl;
        Dep_PI.push_back(dpi);

    }
    file.close();


}

void Write_department_prim_Index_file(int s)
{
fstream outfile;
outfile.open("DepartmentPI.txt", ios::in | ios::out |ios::app);
char del = '|';

for(int i = s ; i < Dep_PI.size() ; ++i)
{
   // cout<<Dep_PI[i].id.size()<<endl;
    outfile.write((char*)&Dep_PI[i].id , sizeof(Dep_PI[i].id));
    outfile.write(&del , sizeof(del));
    string ofset = to_string(Dep_PI[i].offset);
    outfile.write((char*)&ofset, sizeof(ofset));
    outfile.write(&del , sizeof(del));

}

}


void Add_Department_Record()
{
ofstream file;
file.open("department.txt", ios::in | ios::out |ios::app);
Department record;

Read_Department_prim_Index_file();
int start = Dep_PI.size();

//cout<<start<<endl;
cout<<"Enter the number of the  records : ";
int n;
cin >> n;
cin.ignore();

while(n--)
{
    cout<<"Enter The Department ID : ";
    cin.getline(record.dept_ID , sizeof(record.dept_ID));

    cout<<"Enter The Department Name : ";
    cin.getline(record.deptName , sizeof(record.deptName));

    cout<<"Enter The Head Of The Department : ";
    cin.getline(record.HeadOfDept, sizeof(record.HeadOfDept));



    record.write_dept_record(file);
    Dep_prim_index tmp;

    tmp.id = record.dept_ID;

    if(!Dep_PI.empty())
    {
        tmp.offset = record.Len + Dep_PI.back().offset;
    }
    else tmp.offset = record.Len;

    Dep_PI.push_back(tmp);

}
//cout<<start<<endl;
Write_department_prim_Index_file(start);
file.close();


}
Department Read_Dep_Record(int i)
{
    fstream file;
    file.open("department.txt", ios::in | ios::out |ios::app);
    Department record;
    // Read_Student_prim_Index_file();

    if(i>=1)file.seekg(Dep_PI[i-1].offset,ios::beg);
    else  file.seekg(0,ios::beg);

    file.getline(record.dept_ID, sizeof(record.dept_ID),'|');
    file.getline(record.deptName, sizeof(record.deptName),'|');
    file.getline(record.HeadOfDept, sizeof(record.HeadOfDept),'\n');
    return  record;

}
void Find_Dep_With_Max_Staff()
{
    Read_Department_prim_Index_file();
    Read_Staff_prim_Index_file();
    vector<Staff_SI_DepID>secInd =  Read_Staff_SIndex_DepID();
    int mx = 0;
    int ind = 0;
    for(int i = 0  ; i < Dep_PI.size() ; ++i)
    {
        int count  = 0;
        for( int j = 0 ; j < secInd.size() ; ++j)
        {
          // cout<<Dep_PI[i].id<<" "<<secInd[i].depID<<" ";
            if(Dep_PI[i].id == secInd[j].depID)
                count++;
           // cout<<count<<endl;
        }

        if(count > mx )
        {
            mx = count;
            ind = i;
        }
    }
    Department out = Read_Dep_Record(ind);
    cout<<"The Department with maximum Number of Staff members is ->  "<<out.deptName<<" Department with Count of : "<<mx<<endl;

  /*  for( int j = 0 ; j < secInd.size() ; ++j)
        cout<<secInd[j].*/

   // cout<<mx<<" "<<Dep_PI[ind].id<<endl;


}
vector<Student_SI_GPA> Read_Student_SIndex_GPA()
{
    fstream file;
    file.open("StudentSI_GPA.txt",ios::out|ios::in);
    vector<Student_SI_GPA>v;
    Student_SI_GPA tmp;

    char id[100];
    char gpa[100];

    while(true)
    {
        file.getline(gpa, sizeof(gpa),'|');
        file.getline(id, sizeof(id),'|');

        if(file.eof())break;

        tmp.id = string(id);
        tmp.gpa = stod(gpa);
        //  cout<<tmp.id<<" "<<tmp.gpa<<endl;
        v.push_back(tmp);
    }
    return  v;

}
void Write_Student_SIndex_GPA(char gpa[] , char id[] )
{
    fstream file;
    file.open("StudentSI_GPA.txt",ios::out|ios::in|ios::app);
    char del = '|';
    // cout<<gpa<<" "<<id<<endl;
    file.write(gpa , sizeof(gpa));
    file.write(&del , sizeof(del));
    file.write(id , sizeof(id));
    file.write(&del , sizeof(del));

}

void Read_Student_prim_Index_file()
{

    fstream file;
    file.open("StudentPI.txt",ios::out|ios::in);
    char id[100];
    char ofset[100];
    Student_prim_index spi;
    while(true)
    {
        file.getline(id, sizeof(id),'|');
        file.getline(ofset, sizeof(ofset),'|');

        if(file.eof())break;


        spi.id = string(id);
        string str(ofset);
        str.erase(0,1);
        spi.offset = stoi(str);
        spi.id = spi.id.substr(1);
        // cout<<spi.id<<" "<<spi.offset<<endl;
        Student_PI.push_back(spi);

    }


}

void Write_Student_prim_Index_file(int s)
{
    ofstream outfile;
    outfile.open("StudentPI.txt");
    char del = '|';


    for(int i = s ; i < Student_PI.size() ; ++i)
    {
        outfile.write((char*)&Student_PI[i].id , sizeof(Student_PI[i].id));
        outfile.write(&del , sizeof(del));
        string ofset = to_string(Student_PI[i].offset);
        outfile.write((char*)&ofset, sizeof(ofset));
        outfile.write(&del , sizeof(del));
    }
}
void Add_Student_Record()
{



    fstream file;
    file.open("student.txt", ios::in | ios::out |ios::app);
    Student record;


    Read_Department_prim_Index_file();
    Read_Student_prim_Index_file();
    int start = Student_PI.size();


    cout<<"Enter the number of the  records : ";
    int n;
    cin >> n;
    while(n--)
    {
        cin.ignore();
        cout<<"Enter The Student ID : ";
        cin.getline(record.ID,20);

        cout<<"Enter The Student Name : ";
        cin.getline(record.name , 50);

        cout<<"Enter The Student Level : ";
        cin.getline(record.level,20);

        cout<<"Enter The Student GPA : ";
        cin.getline( record.gpa , 10);

       // cout<<"Enter The Student Department ID : ";
        //cin.getline(record.deptId,20);

        cout<<"Choose the Department ID :"<<endl;
        for(int i = 0 ; i <Dep_PI.size() ; ++i )
        {
            cout<<Dep_PI[i].id<<":"<<i+1<<" ";
        }cout<<endl;
        cout<<" -> :";

        int ind; cin >> ind;


        strcpy(record.deptId, Dep_PI[ind-1].id.c_str());

        record.write_student(file);
        Student_prim_index tmp;

        tmp.id = record.ID;

        if(!Student_PI.empty())
        {
            tmp.offset = record.Len + Student_PI.back().offset;
        } else tmp.offset = record.Len;
        Student_PI.push_back(tmp);
        Write_Student_SIndex_GPA(record.gpa,record.ID);


    }
    Write_Student_prim_Index_file(start);



}

void Read_Student_Record(int i)
{
    fstream file;
    file.open("student.txt", ios::in | ios::out |ios::app);
    Student record;
     //Read_Student_prim_Index_file();
      //cout<<i<<endl;
   //   cout<<Student_PI[i-1].offset<<endl;
    if(i>=1)file.seekg(Student_PI[i-1].offset-1,ios::beg);
    else  file.seekg(0,ios::beg);

    file.getline(record.ID, sizeof(record.ID),'|');
    file.getline(record.name, sizeof(record.name),'|');
    file.getline(record.gpa, sizeof(record.gpa),'|');
    file.getline(record.level, sizeof(record.level),'|');
    file.getline(record.deptId, sizeof(record.deptId),'\n');


    cout<<"Name: "<<record.name<<"\nID: "<<record.ID<<endl;//<<"\nGPA: "<<record.gpa<<"\nLevel: "<<record.level<<"\nDepartment ID: "<<record.deptId<<endl;
     //cout<<record.name<<" "<<record.ID<<endl;
     cout<<"----------------------"<<endl;

}

void Search_Student_Record(string id)
{
    vector<Student_prim_index>tmp = Student_PI;
    map<string,int>pos;

    for(int i = 0 ; i < Student_PI.size() ; ++i)
        pos[Student_PI[i].id] =  i;        // sort of a hashmap of the position of the record in the orginal file


    sort(tmp.begin(),tmp.end() , comp_PI); //intially

    int low = 0 , high = Student_PI.size()-1;
    //cout<<low<<" "<<high<<endl;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(id == tmp[mid].id)
        {
            Read_Student_Record(pos[id]);
            break;
        }
        else if(id > tmp[mid].id)
            low = mid + 1;
        else high = mid - 1;
    }

}
void Find_Student_By_GPA()
{
    double x  , y;
    cout<<"Enter The Interval's values "<<"\n"<<"the Lower Value : ";cin >> x;
    cout<<"The Upper Value : ";cin >> y;





    vector<Student_SI_GPA> v = Read_Student_SIndex_GPA();
    //sort(v.begin(),v.end(),comp_SI_GPA);
    //  cout<<v.size()<<endl;
    for(int i = 0 ; i < v.size() ; ++i)
    {
        if(x <= v[i].gpa && v[i].gpa <= y)
        {

            Search_Student_Record(v[i].id);
            cout<<"\n"<<"--------------------------------------"<<endl;
        }
    }


}

vector<Student_SI_DepID> creat_Student_SI_DepID()
{
    vector<Student_SI_DepID>v;
    Student_SI_DepID tmp;
    ifstream file;
    file.open("student.txt");
    Student record;

    while(true) {

        // cout<< sizeof(record.id)<<endl;
        //   string line;
        //getline(file , line);
        // cout<<line<<endl;
        file.getline(record.ID, sizeof(record.ID), '|');
        file.getline(record.name, sizeof(record.name), '|');
        file.getline(record.level, sizeof(record.level), '|');
        file.getline(record.gpa, sizeof(record.gpa), '|');
        file.getline(record.deptId, sizeof(record.deptId), '\n');
        // cout << strlen(record.deptId) << " " << record.deptId << endl;

        string t = record.deptId;
        if(t.size()> 6)
        {
            t = t.substr(1,6);
            //cout<<t<<endl;
        }

        if (file.eof())break;
        if (file.fail())break;

        tmp.Depid = t;
        tmp.id = record.ID;
        v.push_back(tmp);
    }

    return  v;
}
Staff Read_Staff_ith_Record(int i)
{
    ifstream file;
    file.open("staff.txt");
    Staff record;
    // Read_Student_prim_Index_file();
   // cout<<i<<endl;
    if(i>=1)file.seekg(Staff_PI[i-1].offset,ios::beg);
    else  file.seekg(0,ios::beg);
    file.getline(record.id , sizeof(record.id) , '|');
    file.getline(record.name , sizeof(record.id) , '|');
    file.getline(record.degree , sizeof(record.degree) , '|');
    file.getline(record.staff_dep_id , sizeof(record.staff_dep_id) , '\n');
    //cout<<record.name<<" "<<record.id<<" "<<record.degree<<" "<<record.staff_dep_id<<endl;
    return record;

    //cout<<"Name: "<<record.name<<"\nID: "<<record.ID<<"\nGPA: "<<record.gpa<<"\nLevel: "<<record.level<<"\nDepartment ID: "<<record.deptId<<endl;


}
vector<Staff_SI_Name> create_Staff_SI_Name()
{

    ifstream file;
    file.open("staff.txt");
    Staff record;
    vector<Staff_SI_Name>v;
    Staff_SI_Name tmp;

    while(true)
    {

       // cout<< sizeof(record.id)<<endl;
     //   string line;
        //getline(file , line);
       // cout<<line<<endl;
        file.getline(record.id , sizeof(record.id) , '|');
        file.getline(record.name , sizeof(record.id) , '|');
        file.getline(record.degree , sizeof(record.degree) , '|');
        file.getline(record.staff_dep_id , sizeof(record.staff_dep_id) , '\n');
      //  cout<<strlen(record.staff_dep_id)<<" "<<strlen(record.name)<<endl;
        if(file.eof())break;
        if(file.fail())break;

        tmp.Name = record.name;
        tmp.id = record.id;
        v.push_back(tmp);
    }
    return v;
}
Staff  search_Staff_member_by_name(string name)
{
    vector<Staff_SI_Name>v = create_Staff_SI_Name();
    sort(v.begin(),v.end(),comp_SI_Staffname);
     map<string,int>pos;
     Read_Staff_prim_Index_file();

    for(int i = 0 ; i < Staff_PI.size() ; ++i) {
       // cout<<Staff_PI[i].id<<" "<<i<<endl;
        pos[Staff_PI[i].id] = i;
    }

    int low = 0 , high = v.size()-1;
    while(low <= high)
    {

            int mid = (low+high)/2;
            //cout<<mid<<" "<<tmp[mid].id<<" ";
            //cout<<v[mid].Name.size()<<" "<<name.size()<<'\n';
          //  cout<<v[mid].Name<<" "<<name<<endl;
            if(name == v[mid].Name)
            {
               // cout<<v[mid].Name<<endl;
                //read staff record;
                //get his depid
              // cout<<mid<<" "<<v[mid].id.size()<<" "<<pos[v[mid].id]<<endl;
                Staff record = Read_Staff_ith_Record(pos[v[mid].id]);
                //cout<<record.name<<" "<<record.staff_dep_id<<endl;
                return record;
                break;
            }
            else if(name > v[mid].Name)
                low = mid + 1;
            else high = mid - 1;

    }
    cout<<"record Not found!!"<<endl;
    exit(0);

}
void Find_Student_In_Dep_By_Staff()
{

    cout<<"Enter the Staff Member Name :"<<"\n";
    string name;
    getline(cin , name);
    Read_Student_prim_Index_file();
   Staff target =  search_Staff_member_by_name(name);
   string depID = target.staff_dep_id;
   vector<Student_SI_DepID> v = creat_Student_SI_DepID();

   string str = target.staff_dep_id;
   cout<<"students joined  department managed by "<<target.name<<":"<<endl;
   for (int i = 0 ; i < v.size() ; ++i)
   {
      // cout<<str.size()<<" "<<v[i].Depid.size()<<endl;
       //cout<<str<<" "<<v[i].Depid<<endl;

       if( str == v[i].Depid)
       {
           //cout<<str<<" "<<v[i].Depid<<endl;
           //cout<<i<<endl;
           Read_Student_Record(i);

       }
   }







}


int main()
{

   // Read_Student_prim_Index_file();
    // Read_Student_Record(0);
  //  Find_Student_By_GPA();
    //Add_Student_Record();
   // Add_Department_Record();
   // Add_Staff_Record();
    //Find_Dep_With_Max_Staff();
   // vector<Staff_SI_Name>v = create_Staff_SI_Name();
 //  cout<< v.size()<<endl;
    //Find_Student_In_Dep_By_Staff();

}
