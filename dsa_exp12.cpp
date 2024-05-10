#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Student{
    typedef struct{
        int roll;
        char name[10];
        char div;
        char add[10];
    }Record;
    const char*filename="stud.dat";
    Record rec;

public:
    void create();
    void dispaly();
    int search();
    void Delete();
};

void Student::create(){
    char ans;
    ofstream fout;
    fout.open(filename,ios::in|ios::out|ios::binary);

    do{
        cout<<"\n\tEnter Roll no of Student:";
        cin>>rec.roll;
        cout<<"\n\tEnter a Name of Student :";
        cin>>rec.name;
        cout<<"\n\tEnter a Division of Student:";
        cin>>rec.div;
        cout<<"\n\tEnter a Address of Student:";
        cin>>rec.add;

        fout.seekp((rec.roll-1)*sizeof(Record));//Move the write pointer to the desired position
        fout.write((char*)&rec,sizeof(Record));

        cout<<"\n\tDo you want to Add more Records: ";
        cin>>ans;
    }while(ans='y'||ans=='Y')
}
void Student::Delete(){
    int pos=search();

    if (pos==-1){
        cout<<"\n\tRecord Not Found";
        return;
    }  

fstream f;
f.open(filename,ios::in|ios::out|ios::binary);

fseekp((pos-1)* size of(Record));
rec.roll=-1;
strcpy(rec.name,"NULL");
rec.div='N';
strcpy(rec.add,"NULL");
f.write((char*)&rec,sizeof(Record));

f.close();
cout<<"\n\tRecord Deleted";
}

int main(){
    Student obj;
    int ch;
    char ans;
    do{
        cout<<"\n\t***Student Information****";
        cout<<"\n\t1. Create \n\t2.Display\n\t3.Delete\n\t4.Search\n\t5.Exit";
        cout<<"\n\t......Enter Your Choice:";
        cin>>ch;

        switch(ch){
            case 1: obj.create();break;
            case 2: obj.display();break;
            case 3: obj.Delete();break;
            case 4: obj.search();break;
            case 5: break;
        }

        cout<<"\n\t......Do You Want to Continue in Main Menu:";
        cin>>ans;
    }while(ans=='y'|| ans=='Y');
    return 0;
}