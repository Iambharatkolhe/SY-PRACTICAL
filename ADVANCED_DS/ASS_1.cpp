#include<iostream>
using namespace std;

class BT {
public:
    int data;
    BT *left;
    BT *right;

    BT(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
BT* insert(BT* root, int value) {
    if (root == NULL) {
        return new BT(value);
    }
    string direction;
    cout << "Enter left or right for " << root->data << ": ";
    cin >> direction;
    if (direction == "left") {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder(BT* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BT* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(BT* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int countNodes(BT* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(BT* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void Ancestors(BT* root) {
    if (root == NULL){
        cout<<"Tree Is MT";
        return ;
    } 
   else{
    cout<<root->data;
   }
    return ;
}

int treeHeight(BT* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    BT* root = NULL;
    int choice, value;
    do {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Count Nodes\n6. Count Leaf Nodes\n7. Print Ancestors\n8. Height\n9. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                preorder(root);
                cout << endl;
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Total Nodes: " << countNodes(root) << endl;
                break;
            case 6:
                cout << "Leaf Nodes: " << countLeafNodes(root) << endl;
                break;
            case 7:
                Ancestors(root);
                cout << endl;
                break;
            
            case 8:
                cout << "Tree Height: " << treeHeight(root) << endl;
                break;
        }
    } while (choice != 9);
    
    return 0;
}
