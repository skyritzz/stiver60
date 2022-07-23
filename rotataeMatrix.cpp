#include <bits/stdc++.h>
using namespace std; 

int main()
{
    
    vector<vector<int>> v ={{1,2,3}, {4,5,6} , {7,8,9}};
    int n = v.size();

    //simple fanda
    //do transpose  of a matrix
    //then reverse earch row of a matrix

    //in transpose we 
    // we only consider diagonally separated matrix
    // tranpose can be done of same row ans same col matrix
    

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< i; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    for(int i = 0; i<n; i++)
    {
        reverse(v[i].begin(), v[i].end());
    }

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

  

    return 0;
}
