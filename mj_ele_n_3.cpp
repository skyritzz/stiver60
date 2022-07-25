#include <bits/stdc++.h>
using namespace std; 

int main()
{
    //MOORE VOTING ALGO
    vector<int> v = {1,1,1,3,3,2,2,2};
    int n1 = -1;
    int n2 = -1;
    int c1 = 0;
    int c2 = 0;
    
    for(int i = 0; i< v.size() ; i++)
    {
        if(v[i] == n1)
        c1++;

        else if(v[i] == n2)
        c2++;

        else if(c1 == 0)
        {
            n1 = v[i];
            c1 = 1;
        }

        else if(c2 == 0)
        {
            n2 = v[i];
            c2 = 1;
        }

        else{
            c1--;
            c2--;
        }
    }

    vector<int> ans;
    int count1 = 0;
    int count2 = 0;

    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == n1)
        {
            count1++;
        }
        else if(v[i] == n2)
        {
            count2++;
        }
    }

    if(count1>(v.size()/3))
    ans.push_back(n1);

    if(count2>(v.size()/3))
    ans.push_back(n2);

    for(int i = 0; i< ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}