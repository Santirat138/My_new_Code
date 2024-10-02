// C++ program to demonstrate Adjacency Matrix
// representation of undirected and unweighted graph
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{

    int V, E;
    cin>>V>>E;
    // ***TASK 1 input number of vertices(v).
    vector<vector<int>> mat(V, vector<int>(V, 0));
    // ***TASK 2 loop for reading E edge.

    for(int i=0;i<E;i++){
        int I, J;
        cin>>I;
        cin>>J;
        addEdge(mat, I, J);
    }

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}
