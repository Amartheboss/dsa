#include <iostream>
#define size 10

using namespace std;

class node
{
    string name;
    int id;
    long int tele;
    friend class hashing;

public:
    node()
    {
        id = 0;
        tele = 0;
    }
};
class hashing
{
    node data[size];
    int index = 0;

public:
    void create_record(string n, int i, long int t)
    {
        index = i % size;
        for (int j = 0; j < size; j++)
        {
            if (data[index].id == 0)
            {
                data[index].id = i;
                data[index].name = n;
                data[index].tele = t;
                break;
            }
            else
            {
                index = (index + 1) % size;
            }
        }
    }
    void display_record()
    {
        cout << "\nNAME\tID\tTELEPHONE\t\n";
        for (int i = 0; i < size; i++)
        {
            if (data[i].id != 0)
            {
                cout << "\n"
                     << data[i].name << "\t" << data[i].id << "\t" << data[i].tele << endl;
            }
        }
        cout << "\n";
    }
    void delete_record(int id)
    {
        int flag = 0;
        for (int j = 0; j < size; j++)
        {
            if (data[index].id == id)
            {
                data[index].id = 0;
                data[index].name = "";
                data[index].tele = 0;
                flag = 1;
                break;
            }
            else
            {
                index = (index + 1) % size;
                flag = 0;
            }
        }
        if (flag == 0)
        {
            cout << "Record not found" << endl;
        }
    }
    void modified_record(int id)
    {
        int new_id;
        long int new_tel;
        string new_name;

        cout << "Enter a Name : ";
        cin >> new_name;
        cout << "Enter a ID : ";
        cin >> new_id;
        cout << "Enter a Telephone no.: ";
        cin >> new_tel;

        index = id % size;
        int new_index = new_id % size;
        for (int j = 0; j < size; j++)
        {
            if (index == new_index)
            {
                data[index].id = new_id;
                data[index].name = new_name;
                data[index].tele = new_tel;
                break;
            }
            else
            {
                delete_record(id);
                create_record(new_name, new_id, new_tel);
                cout << "Record Modified\n"
                     << endl;
                break;
            }
        }
    }
};

int main()
{
    hashing h;
    while (1)
    {
        cout << "========= Menu =========\n";
        cout << "1.Create Record \t\n";
        cout << "2.Display Record \t\n";
        cout << "3.Delete Record \t\n";
        cout << "4.Modify Record \t\n";
        cout << "5.Exit\n";
        cout << "========================\n";
        cout << endl;

        int choice;
        cout << "Enter a choice : ";
        cin >> choice;

        int stid;
        string stname;
        long int sttele;

        switch (choice)
        {
        case 1:
            cout << "Enter a Name : ";
            cin >> stname;
            cout << "Enter a ID : ";
            cin >> stid;
            cout << "Enter a Telephone no.: ";
            cin >> sttele;

            h.create_record(stname, stid, sttele);
            cout << "Record Inserted!!!\n\n";
            break;
        case 2:
            h.display_record();
            break;
        case 3:
            cout << "Enter a ID : ";
            cin >> stid;

            h.delete_record(stid);
            cout << "Record deleted\n"
                 << endl;
            break;
        case 4:
            cout << "Enter a ID : ";
            cin >> stid;

            h.modified_record(stid);
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}