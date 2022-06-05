#include <bits/stdc++.h>
using namespace std;

void solve(int index, int target, vector<int> arr, vector<vector<int>> &ans, vector<int> &op)
{
    if(index == arr.size() || target == 0)
    {
        if(target == 0)
        {
            ans.push_back(op);
        }
        return;
    }

    //if decision is taken i.e. element is picked up
    if(arr[index] <= target){
        op.push_back(arr[index]);
        solve(index, target-arr[index], arr, ans, op);
        op.pop_back();// if target not achieved we have to remove the last elememt pushed
    }
    //not picked
    solve(index+1, target, arr, ans, op);
    return;
}

void printAns(vector < vector < int >> & ans) {
   cout<<"The combinations are "<<endl;
   cout << "[ ";
   for (int i = 0; i < ans.size(); i++) {
      cout << "[ ";
      for (int j = 0; j < ans[i].size(); j++)
         cout << ans[i][j] << " ";
         
      cout << "]";
   }
   cout << " ]";
}

int main()
{
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> ans;
    int index;
    int target = 7;
    vector<int> op;
    solve(0, target, arr, ans, op );
    printAns(ans);
    return 0;
}