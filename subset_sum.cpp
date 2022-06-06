#include <bits/stdc++.h>
using namespace std;

  void solve(vector<int> arr, int N, int sum , int idx,  vector<int> &ans)
    {
        if(idx == arr.size())
        {
           ans.push_back(sum);
           return;
            
        }
        
        //wheter picked or not we have toinc indx+1 
        
        //when picked idx+1 and sum is added to the ele of that index 
        solve(arr, N, sum + arr[idx], idx+1, ans )  ;
        
        //when not picked index is increased and sum remains same 
        solve(arr, N, sum, idx+1, ans )  ;
        
        
       
    }



int main()
{
    vector<int> num;
    int N = num.size();
    int sum = 0;
    vector<int> ans;
        solve(num, N, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;

    return 0;
}