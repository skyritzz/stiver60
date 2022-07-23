#include <bits/stdc++.h>
using namespace std; 




int main()
{
    vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4 };
    int min = INT_MAX;
    int profit = 0;
    for(int i = 0; i< v.size(); i++)
    {
        if(v[i] < min)
        {
            min = v[i];
        }
        if(v[i] - min > profit)
        {
            profit = v[i] -  min;
        }
    }
    cout << profit;


    return 0;
}