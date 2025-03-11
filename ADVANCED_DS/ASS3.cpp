#include <iostream>
using namespace std;

#define MAX 10 
class Node {
public:
    int vertex;    
    Node* next;    

  
    Node(int val) {
        vertex = val;
        next = NULL;
    }
};

class GraphList {
public:
    int vertices;       
    Node* adjList[MAX];   

    GraphList(int v) {
        vertices = v;
        for (int i = 0; i < v; i++) {
            adjList[i] = NULL;
        }
    }

    
    void addEdge(int src, int dest) {
        
        Node* newNode = new Node(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        Node* newNode2 = new Node(src);
        newNode2->next = adjList[dest];
        adjList[dest] = newNode2;
    }

    void displayGraph() {
        cout << "\n Flight Network (Adjacency List Representation)\n";
        for (int i = 0; i < vertices; i++) {
            cout << "City " << i << " -> ";
            Node* temp = adjList[i];
            while (temp) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


class GraphMatrix {
public:
    int matrix[MAX][MAX];
    int vertices;

    GraphMatrix(int v) {
        vertices = v;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                matrix[i][j] = 0; 
            }
        }
    }

  
    void addEdge(int src, int dest) {
        matrix[src][dest] = 1;
        matrix[dest][src] = 1; 
    }


    void displayMatrix() {
        cout << "\n Flight Network (Adjacency Matrix Representation)\n";
        for (int i = 0; i < vertices; i++) {
            cout << "City " << i << " -> ";
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    int vertices = 5; 
    GraphList listGraph(vertices);
    GraphMatrix matrixGraph(vertices); 


    listGraph.addEdge(0, 1);
    listGraph.addEdge(0, 4);
    listGraph.addEdge(1, 2);
    listGraph.addEdge(1, 3);
    listGraph.addEdge(1, 4);
    listGraph.addEdge(2, 3);
    listGraph.addEdge(3, 4);

    matrixGraph.addEdge(0, 1);
    matrixGraph.addEdge(0, 4);
    matrixGraph.addEdge(1, 2);
    matrixGraph.addEdge(1, 3);
    matrixGraph.addEdge(1, 4);
    matrixGraph.addEdge(2, 3);
    matrixGraph.addEdge(3, 4);

    listGraph.displayGraph();
    matrixGraph.displayMatrix();

    return 0;
}
