#include <iostream>
using namespace std;

struct node {
    char label[10];
    int chcount;
    node* child[10];
};

class gt {
    private:
        node* root;

    public:
        gt() {
            root = NULL;
        }

    void create_tree() {
        int tchapters, tsections, tsubsections;
        
        root = new node;
        cout << "Enter the Name of the Book: ";
        cin >> root->label;
        cout << "Enter the Number of Chapters: ";
        cin >> tchapters;
        root->chcount = tchapters;

        for (int i = 0; i < tchapters; i++) {
            root->child[i] = new node;
            cout << "Enter the Name of the Chapter " << i+1 << ": ";
            cin >> root->child[i]->label;
            cout << "Enter the Number of Sections " << i+1 << ": ";
            cin >> tsections;
            root->child[i]->chcount = tsections;

            for (int j = 0; j < tsections; j++) {
                root->child[i]->child[j] = new node;
                cout << "Enter the Name of the Section " << j+1 << ": ";
                cin >> root->child[i]->child[j]->label;
                cout << "Enter the Number of Subsections " << j+1 << ": ";
                cin >> tsubsections;
                root->child[i]->child[j]->chcount = tsubsections;

                for (int k = 0; k < tsubsections; k++) {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Enter the Name of the Subsection " << k+1 << ": ";
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }

    void display(node* root) {
        if (root == NULL) {
            return;
        }
        cout << "\nDisplaying....." << endl;
        cout << "\nBook: " << root->label << endl;

        for (int i = 0; i < root->chcount; i++) {
            cout << endl;
            cout << "Name of the Chapter:" << i+1 << "> " << root->child[i]->label << endl;

            for (int j = 0; j < root->child[i]->chcount; j++) {
                cout << "Name of the Section "<< j+1 << ": " << root->child[i]->child[j]->label << endl;

                for (int k = 0; k < root->child[i]->child[j]->chcount; k++) {
                    cout << "Name of the Subsection " << k+1 << ": " << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }

    node* getRoot() {
        return root;
    }
};


int main() {
    gt myTree;
    myTree.create_tree();
    myTree.display(myTree.getRoot());
    return 0;
}