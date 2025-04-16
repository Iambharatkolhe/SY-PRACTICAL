#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int size=0;
class prims 
{
public:
int minwt=0;
    int mat[20][20];  
    int v, e;         
         
    vector<int> Final;
    vector<pair<int,int>> edge;
    vector<int> weight;


    prims() 
    {
        for (int i = 0; i < 20; i++) 
        {
            for (int j = 0; j < 20; j++) 
            {
                mat[i][j] = 0;
            }
        }
    }
            

    void addEdge(int u, int v, int w) 
    {
        mat[u][v] = w;   
        mat[v][u] = w;
    }

  
    void prim() 
    { 
       
        for (int i = 0; i < v; i++) 
        {
             
            Final.push_back(-1); 
        }

        Final[0] = 1;   
         
        
       
        for (int count = 0; count < size - 1; count++) 
        {
            int min = INT_MAX;
            int u = -1, v = -1;

          
            for (int i = 0; i < size; i++) 
            {
                if (Final[i] == 1) 
                {
                    for (int j = 0; j < size; j++) 
                    {
                        if (Final[j] == -1 && mat[i][j] != 0 && mat[i][j] < min) 
                        {
                            min = mat[i][j];
                            u = i;
                            v = j;                            
                        }
                    }
                }
            }

            if (u != -1 && v != -1) 
            {   minwt+=min;
               
                Final[v] = 1;   
                 
                edge.push_back({u,v});  
                weight.push_back(min);  
            }
        }
    }
    void display() 
    {
        int total = 0;
        cout << "PATH in the Minimum KM:" << endl;
        for (int i = 0; i < edge.size(); i++) 
        {
            cout << "PATH: " << edge[i].first << " - " << edge[i].second 
                 << " KM: " << weight[i] << endl;
            total += weight[i];
        }
        cout << "Total KM is " << minwt<< endl;
    }
};

int main() 
{
    int v, e;
    cout << "Enter the no. of city: ";
    cin >> v;
    size=v;
    cout << "Enter the no. of path: ";
    cin >> e;

    prims p;
    p.v = v;
    p.e = e;

    for (int i = 0; i < e; i++) 
    {
        int u, v, w;
        cout << "Enter PATH " << i + 1 << " (SOURCE DESTINATION KM): ";
        cin >> u >> v >> w;
        p.addEdge(u, v, w);
    }

    p.prim();  
    p.display();  

    return 0;
}

/*Enter the no. of vertices: 4
Enter the no. of edges: 5
Enter edge 1 (u v w): 0 1 10
Enter edge 2 (u v w): 0 2 6
Enter edge 3 (u v w): 0 3 5
Enter edge 4 (u v w): 1 3 15
Enter edge 5 (u v w): 2 3 4


You are a job seeker preparing for interviews in different locations. You have
a list of cities where interviews are scheduled, and you want to find the shortest
path to visit all the interview locations, starting from your current location. The
objective is to minimize the total travel distance and time while ensuring you reach
each interview location on time. Use appropriate data structure and algorithm to
implement it

*/
   
    