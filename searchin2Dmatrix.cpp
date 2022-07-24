#include <bits/stdc++.h>
using namespace std; 

int main()
{
    vector<vector<int>>  matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    int target = 13;
    int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0; 
        int hi = (n*m-1); 
        
        while(lo <= hi)
        {
            int mid = (lo+(hi-lo)/2);
            if(matrix[mid/m][mid%m] == target)
            //TO fin d actual index from the matrix we do mat[a][b] =>  a = mid/m , b = mid%m
            {
                cout <<   "true" ; 
                break;
            }
            else if (matrix[mid/m][mid%m] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid-1;
            }
        }
        cout << "false";

    return 0;
}