#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

class OBST {
public:
    Node *obst_root;
    int key[10];
    int success[10]; 
    int failure[11];  
    int cost[11][11];
    int weight[11][11];
    int root[11][11];
    int number_of_keys;

    OBST() {
        cout << "Enter Number of Keys: ";
        cin >> number_of_keys;

        cout << "Enter keys (sorted):\n";
        for (int i = 0; i < number_of_keys; i++) {
            cout << "Key[" << i << "]: ";
            cin >> key[i];
        }

        cout << "Enter success probabilities P[i] (for each key):\n";
        for (int i = 0; i < number_of_keys; i++) {
            cout << "P[" << i << "]: ";
            cin >> success[i];
        }

        cout << "Enter failure probabilities Q[i] (n+1 values):\n";
        for (int i = 0; i <= number_of_keys; i++) {
            cout << "Q[" << i << "]: ";
            cin >> failure[i];
        }

        for (int i = 0; i <= number_of_keys; i++) {
            for (int j = 0; j <= number_of_keys; j++) {
                cost[i][j] = 0;
                weight[i][j] = 0;
                root[i][j] = 0;
            }
        }

        obst_root = nullptr;
    }

    void calculate_weight() {
        for (int i = 0; i <= number_of_keys; i++) {
            weight[i][i] = failure[i];
            for (int j = i + 1; j <= number_of_keys; j++) {
                weight[i][j] = weight[i][j - 1] + success[j - 1] + failure[j];
            }
        }
    }

    void calculate_cost() {
        for (int i = 0; i <= number_of_keys; i++) {
            cost[i][i] = failure[i];
        }

        for (int length = 1; length <= number_of_keys; length++) {
            for (int i = 0; i <= number_of_keys - length; i++) {
                int j = i + length;
                cost[i][j] = INT_MAX;

                for (int r = i + 1; r <= j; r++) {
                    int temp = cost[i][r - 1] + cost[r][j] + weight[i][j];
                    if (temp < cost[i][j]) {
                        cost[i][j] = temp;
                        root[i][j] = r;
                    }
                }
            }
        }
    }

    Node* maketree(int i, int j) {
        if (i == j)
            return nullptr;

        int r = root[i][j];
        Node* newNode = new Node(key[r - 1]);
        newNode->left = maketree(i, r - 1);
        newNode->right = maketree(r, j);
        return newNode;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void display_tables() {
        cout << "\nWeight Table:\n";
        for (int i = 0; i <= number_of_keys; i++) {
            for (int j = 0; j <= number_of_keys; j++) {
                cout << setw(5) << weight[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nCost Table:\n";
        for (int i = 0; i <= number_of_keys; i++) {
            for (int j = 0; j <= number_of_keys; j++) {
                if (cost[i][j] == INT_MAX)
                    cout << setw(5) << "INF" << " ";
                else
                    cout << setw(5) << cost[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nRoot Table:\n";
        for (int i = 0; i <= number_of_keys; i++) {
            for (int j = 0; j <= number_of_keys; j++) {
                cout << setw(5) << root[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    OBST tree;
    tree.calculate_weight();
    tree.calculate_cost();
    tree.display_tables();

    tree.obst_root = tree.maketree(0, tree.number_of_keys);

    cout << "\nInorder Traversal of OBST: ";
    tree.inorder(tree.obst_root);
    cout << endl;

    return 0;
}
