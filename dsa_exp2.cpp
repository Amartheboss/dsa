#include <iostream>
using namespace std;
const static int hash_size = 10;

class node{
    public:
        string name;
        int id;
        node *next;
        node(string data, int key){
            name = data;
            id = key;
            next = NULL;
        }
};

void insert_into_hashtable(node *hash[]){
    int index, id;
    string name;
    cout << "Enter the id no : ";
    cin >> id;
    cout << "Enter the name : ";
    cin >> name; 
    node *np = new node(name, id);
    node *temp;
    index = id % hash_size;

    if (hash[index] == NULL){
        hash[index] = np;
    } else {
        np->next = hash[index];
        hash[index] = np;
    }
}

void display(node *hash[]){
    for (int i = 0; i < hash_size; i++){
        node *temp = hash[i];
        cout << "index " << i << " : ";
        while (temp != NULL){
            cout << "(" << temp->name << ", " << temp->id << ")" << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void search(node *hash[]){
    int key, index;
    string name;

    cout << "Enter the key to be search: ";
    cin >> key;
    index = key % hash_size;
    node *temp = hash[index];

    if (temp == NULL)
        cout << "Search element not found..." << endl;
    else{
        while (temp != NULL){
            if (temp->id == key){
                cout << temp->name << ", " << temp->id << endl;
                return;
            }else
                temp = temp->next;
        }
        cout << "Search element not found..." << endl;
    }
}

void deletekey(node *hash[]){
    int key, index;
    string name;

    cout << "Enter the key to be delete: ";
    cin >> key;
    index = key % hash_size;
    node *temp = hash[index];
    node *prev_temp = hash[index];

    if (temp == NULL)
        cout << "Element not found...";
    else{
        if (temp->id == key){
            hash[index] = temp->next;
            cout << "Element Deleted..." << endl;
            return;
        } else {
        while (temp != NULL){
            if (temp->next->id == key){
                temp->next = temp->next->next;
                cout << "Element Deleted..." << endl;
                return;
            } else
                temp = temp->next;
        }
        cout << "Element not found..." << endl;
        }
    }
}

int main(){
    node *hash[hash_size];
    string name;
    int id, n, choice;
    while (1)
    {
        cout << "\n========= Menu =========\n";
        cout << "1.Insert into HashTable\n";
        cout << "2.Display HashTable\n";
        cout << "3.Search in HashTable\n";
        cout << "4.Deletion in HashTable\n";
        cout << "5.Exit\n";
        cout << "========================\n\n";
        
        cout << "Enter a choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the no of entries : ";
            cin >> n;

            for (int k = 0; k < n; k++){
                
                insert_into_hashtable(hash);
            }

            break;
        case 2:
            display(hash);
            break;
        case 3:
            search(hash);
            break;
        case 4:
            deletekey(hash);
            break;
        case 5:
            return 0;
        }
    }
}