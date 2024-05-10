#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student{
    typedef struct stud{
        int roll;
        char name[10];
        char div;
        char add[10];
    }stud;
    stud rec;
    public:
        void create();
        void display();
        int search();
        void Delete();
};

void student::create(){
    char ans;
    ofstream fout;
    fout.open("stud.txt",ios::out|ios::binary);
    do{
        cout<<"\n\tEnter Roll No. of Student : ";
        cin>>rec.roll;
        cout<<"\n\tEnter Name of the Student : ";
        cin>>rec.name;
        cout<<"\n\tEnter Div of the Student : ";
        cin>>rec.div;
        cout<<"\n\tEnter Address of the Student : ";
        cin>>rec.add;
        fout.write((char*)&rec,sizeof(stud))<<flush;
        cout<<"\n\t Do You want to add more records : ";
        cin>>ans;
    }while(ans == 'y'|| ans == 'Y');
    fout.close();
}

void student::display(){
    ifstream fin;
    fin.open("stud.txt",ios::in | ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tThe content of file are : \n";
    cout<<"\n\tRoll\tName\tDiv\taddress";
    while(fin.read((char *)&rec,sizeof(stud))){
        if(rec.roll!=-1){
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
        }
    }
    fin.close();
}

int student::search(){
    int r;
    bool found = false;
    ifstream fin;
    fin.open("stud.txt",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tEnter a roll no. : ";
    cin >> r;

    while(fin.read((char *)&rec,sizeof(stud))){
        if(rec.roll == r){
            cout<<"\n\tRecord Found: ";
            cout<<"\n\tRoll\tName\tDiv\taddress";
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
            found = true;
            break;
        }
    }

    fin.close();

    if(!found)
        cout << "\n\tRecord not found!";
    
    return found ? 1 : 0;
}

int main(){
    student s;
    int ch;
    do{
        cout<<"\n\t1. Create\n\t2. Display\n\t3. Search\n\t4. Delete\n\t5. Exit\n\tEnter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                s.create();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.search();
                break;
            case 4:
                s.Delete();
                break;
            case 5:
                cout<<"\n\tExiting....";
                break;
            default:
                cout<<"\n\tInvalid choice!";
        }
    }while(ch!=5);
    return 0;
}