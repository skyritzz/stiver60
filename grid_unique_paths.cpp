#include <bits/stdc++.h>
using namespace std; 

// this question has three approach 
// 1. recursion // this has exponential time compexitiy 
// 2. DP (enhanced recursion) // this works fine
// 3. combinations // this also works

int unique_path(int i , int j, int m , int n , vector<vector<int>> &dp)
{
    if(i > m || j > n ) return 0; // agar row or col out of bound ho rahe hai toh zero return krdo
    if(i == m-1 && j == n-1) return 1; // return wahi sai krna jha sai row or col dono dono end ho 

    if(dp[i][j] = -1) return dp[i][j];// to remove repetitive recursion calls

    else // nhi toh ek call down kai lie (i+1, j) //dusri call right kai lie (i, j+1) 
    return dp[i][j] = unique_path(i+1, j, m, n, dp) + unique_path(i, j+1, m,n , dp);
}


int main()
{
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    int i=0, j = 0;
    int ans = unique_path(i,j, m, n, dp);
    if(m==1 && n== 1)
    cout << ans;

    cout << dp[0][0];


    return 0;

}