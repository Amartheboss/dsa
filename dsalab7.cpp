//DSA flight question
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class flight {
public:
    int am[10][10];
    char city_index[10][10];
    flight();
    int create();
    void display(int city_count);
};

flight::flight() {
    for (int i = 0; i < 10; i++) {
        strcpy(city_index[i], "xx");
        for (int j = 0; j < 10; j++) {
            am[i][j] = 0;
        }
    }
}

int flight::create() {
    int city_count = 0, j, si, di, wt;
    char s[10], d[10], c;
    do {
        cout << "Enter source city: ";
        cin >> s;
        cout << "Enter destination city: ";
        cin >> d;
        for (j = 0; j < 10; j++) {
            if (strcmp(city_index[j], s) == 0)
                break;
        }
        if (j == 10) {
            strcpy(city_index[city_count], s);
            city_count++;
        }
        for (j = 0; j < 10; j++) {
            if (strcmp(city_index[j], d) == 0)
                break;
        }
        if (j == 10) {
            strcpy(city_index[city_count], d);
            city_count++;
        }
        cout << "\n\tEnter distance from " << s << " and " << d << ": ";
        cin >> wt;
        for (j = 0; j < 10; j++) {
            if (strcmp(city_index[j], s) == 0)
                si = j;
            if (strcmp(city_index[j], d) == 0)
                di = j;
        }
        am[si][di] = wt;
        cout << "\n\tDo you want to add more cities...(y/n): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return city_count;
}

void flight::display(int city_count) {
    int i, j;
    cout << "\n\tDisplaying Adjacency Matrix: ";
    for (i = 0; i < city_count; i++)
        cout << "\t" << city_index[i] << "\n";
        for (j = 0; j < city_count; j++) {
            cout << "\t" << city_index[j];
            for (int k = 0; k < city_count; k++) {
                cout << "\t" << am[j][k];
            }
            cout << "\n";
        }
    
}

int main() {
    flight f;
    int n, city_count;
    char c;
    do{
        cout<<"\n\t1. Create \n\t2. Adjacency Matrix \n\t3. Exit";
        cout<<"\n\tEnter your choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
            city_count=f.create();
            break;
            
            case 2:
            f.display(city_count);
            break;
            
            case 3:
            return 0;
        }
        cout<<"\n\tDo you want to continuee..(y/n): ";
        cin>>c;
    }while(c=='y'||c=='Y');
        
    
    

    return 0;
}