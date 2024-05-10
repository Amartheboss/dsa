// DSA Exp 5

#include <iostream>
#include<unistd.h>   
using namespace std;

class Node{
    int lbit, rbit;
    int value;
    Node *left, *right;

    public:
        Node(){
            lbit = rbit = 0;
            value = 0;
            left = right = NULL;
        }
        friend class DTBT;
};

class DTBT{
    Node *head;

    public:
        DTBT(){
            head = new Node();
            head->value = 9999;
            head->rbit = 1;
            head->lbit = 0;
            head->left = head;
            head->right = head;
        }


        void insert(int data){
            if (head->left == head && head->right == head){
                Node *root = new Node();
                root->value = data;
                root->left = head->left;
                root->lbit = head->lbit;
                root->rbit = 0;
                root->right = head->right;
                head->left = root;
                head->lbit = 1;
                return;
            }

            Node *cur = new Node;
            cur = head->left;
            while (1){
                if (cur->value < data){
                    Node *root = new Node();
                    root->value = data;
                    if (cur->rbit == 0){
                        root->right = cur->right;
                        root->rbit = cur->rbit;
                        root->lbit = 0;
                        root->left = cur;
                        cur->rbit = 1;
                        cur->right = root;
                        return;
                    }
                    else{
                        cur = cur->right;
                    }
                }
                if (cur->value > data){
                    Node *root = new Node();
                    root->value = data;
                    if (cur->lbit == 0){
                        root->left = cur->left;
                        root->lbit = cur->lbit;
                        root->rbit = 0;
                        root->right = cur;
                        cur->lbit = 1;
                        cur->left = root;
                        return;
                    }
                    else{
                        cur = cur->left;
                    }
                }
            }
            sleep(5);
        }

        void inorder(){
            Node *c;
            c = head->left;
            while (c->lbit == 1){
                c = c->left;
            }
            while (c != head){
                cout << " " << c->value;
                c = inorderSuccessor(c);
            }
            cout << endl;
            sleep(2);
        }

        Node *inorderSuccessor(Node *c){
            if (c->rbit == 0)
                return c->right;
            else
                c = c->right;
            while (c->lbit == 1){
                c = c->left;
            }
            return c;
        }
};

int main(){
    DTBT t1;
    int choice;
    while (true){
        cout << "...Threaded Binary Tree..." << endl;
        cout << "========== Menu ==========" << endl;
        cout << "   1. Insert Nodes." << endl;
        cout << "   2. Inorder Traversal." << endl;
        cout << "   0. Exit." << endl;
        cout << "     ---> ";
        cin >> choice;
        switch(choice){
            case 1:
                int count;
                cout << "Enter the Number of Nodes to be Inserted: ";
                cin >> count;
                for (int i = 0; i < count; i++){
                    int num;
                    cin >> num;
                    t1.insert(num);
                }
                cout << "Node Added..." << endl;
                sleep(2);
                system("cls");
                break;
            case 2:
                cout << "Inorder Traversal of DTBST...\n";
                t1.inorder();
                system("cls");
                break;
            case 0:
                exit(0);
            default:
                cout << "Please Enter Valid Input..." << endl;
                sleep(1);
                system("cls");
                break;
        }
    }
    return 0;
}