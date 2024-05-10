// DSA Exp 4

# include <iostream>
# include <cstdlib>
using namespace std;

class node {
    public:
    int info;
    struct node *left;
    struct node *right;
}*root;

class BST {
    public:
        node *root;

        BST ()
        {
            root = NULL;
        }

        void insert(node *tree, node *newnode) {
            if (root == NULL){
                root = new node;
                root -> info = newnode -> info;
                root -> left = NULL;
                root -> right = NULL;
                cout<<"Root Node is Added"<<endl;
                return;
            }

            if (tree -> info == newnode -> info){
                cout<<"Element already in the tree"<<endl;
                return;
            }
            if (tree -> info > newnode -> info){
                if (tree -> left != NULL)
                {
                    insert(tree -> left, newnode);
                }
                else
                {
                    tree -> left = newnode;
                    (tree -> left) -> left = NULL;
                    (tree -> left) ->right = NULL;
                    cout<<"Node Added To Left"<<endl;
                    return;
                }
            } else {
                if (tree -> right != NULL)
                {
                    insert(tree -> right, newnode);
                }
                else
                {
                    tree -> right = newnode;
                    (tree -> right) -> left = NULL;
                    (tree -> right) -> right = NULL;
                    cout<<"Node Added To Right"<<endl;
                    return;
                }
            }
        }

        void display(node *ptr, int level){
            int i;
            if (ptr!= NULL){
                display(ptr->right, level+1);
                cout << endl;
                if (ptr == root)
                    cout << "Root->:";
                else{
                    for (i=0; i < level; i++)
                        cout << "       ";
                }
                cout << ptr->info;
                display(ptr->left, level+1); 
            }
        }

        void min(node *root){
            node *temp;
            if (root == NULL)
                cout << "Tree is Empty";
            else{
                temp = root;
                while (temp->left != NULL){
                    temp = temp->left;
                }
                cout << temp->info;
            }
        }

        int height(node *root){
            int hleft, hright;
            if (root == NULL){
                return 0;
            }
            else if (root->left == NULL && root->right == NULL){
                return 1;
            }
            hleft = height(root->left);
            hright = height(root->right);
            if (hright>=hleft){
                return(hright + 1);
            } else {
                return (hleft + 1);
            }
        }

        void mirror(node *root){
            node *temp;
            if (root != NULL){
                temp = root->left;
                root->left = root->right;
                root->right = temp;
                mirror(root->left);
                mirror(root->right);
            }
        }

        void search(node *ptr, int searchdata){
            if (ptr->info == searchdata){
                cout << "Element Found" << endl;
            }
            else if (ptr->info < searchdata && ptr->right != NULL){
                search(ptr->right, searchdata);
            }
            else if (ptr->info > searchdata && ptr->left != NULL){
                search(ptr->left, searchdata);
            }
            else{
                cout << "Element Not Found" << endl;
            }
        }
};

int main ()
{
    int choice, num;
    BST bst;
    node *temp;

    temp = new node ();
    temp->info = 60;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 68;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 24;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 48;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 52;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 21;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 72;
    bst.insert(bst.root, temp);
    temp = new node ();
    temp->info = 70;
    bst.insert(bst.root, temp);

    while (1)
    {
        cout<<"\n-------------------------------";
        cout<<"\n       Operations on BST       ";
        cout<<"\n-------------------------------\n";
        cout<<"1. Insert Element into Tree"<<endl;
        cout<<"2. Display Tree"<<endl;
        cout<<"3. Min value of Tree"<<endl;
        cout<<"4. Height of Tree"<<endl;
        cout<<"5. Mirror of node"<<endl;
        cout<<"6. Preorder of Tree"<<endl;
        cout<<"7. Inorder of Tree"<<endl;
        cout<<"8. Postorder of Tree"<<endl;
        cout<<"9. No. of Nodes in Longest Path"<<endl;
        cout<<"10. Search of Element"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"   ---> ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                temp = new node ();
                cout<<"Enter the number to be inserted : ";
                cin>>temp ->info;
                bst.insert(bst.root, temp);
                break;

            case 2:
                cout<<"Display BST : "<<endl;
                bst.display(bst.root,1);
                cout<<endl;
                break;

            case 3:
                cout<<"Min Value of Tree: ";
                bst.min(bst.root);
                cout<<endl;
                break;

            case 4:
                int h; 
                h = bst.height(bst.root);
                cout<<"Height of tree = "<<h;
                cout<<endl;
                break;

            case 5:
                bst.mirror(bst.root);
                bst.display(bst.root,1);
                break;

            // case 6:
                // cout<<"\n Display preorder Binary tree = ";
                // bst.preorder(bst.root);
                // cout<<endl;
                // break;

            // case 7:
                // cout<<"\n Display inorder Binary tree = ";
                // bst.inorder(bst.root);
                // break;

            // case 8:
                // cout<<"\n Display postorder Binary tree = ";
                // bst.postorder(bst.root);
                // cout<<endl;
                // break;

            // case 9:
                // int nodes;
                // nodes=bst.height(bst.root);
                // cout<<"No. of roots in longest path from root is "<<nodes;
                // cout<<endl;
                // break;

            case 10:
                int searchdata;
                cout << "Enter the element to be searched : ";
                cin >> searchdata;
                bst.search(bst.root, searchdata);
                cout<<endl;
                break;

            case 11:
                exit(1);

            default:
                cout<<"Wrong choice"<<endl;
        }
    }
};