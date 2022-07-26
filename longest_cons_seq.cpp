#include <bits/stdc++.h>
using namespace std; 

int solve(vector<int> &v)
{
    set<int> st;
    for(int i = 0; i< v.size(); i++)
    {
        st.insert(v[i]);
    }
    

    int streak = 0;
    for(int i = 0; i< v.size(); i++)
    {
        if(!st.count(v[i]-1))//agr num - 1 nhi hai array mai toh ham proceed karenge
        {
            int currNum = v[i];
            int currStreak = 1;

            while(st.count(currNum+1))// jab tak hame num+1 mil rha hai ham proceed karenge
            {
                currNum += 1;
                currStreak += 1;
            }

            streak = max(streak, currStreak);

        }
    }
    return streak;
}


int main()
{
    vector<int> v = {0,3,7,2,5,8,4,6,0,1};

    

    int ans = solve(v);
    

    cout << "LONGEST CONSECUTIVE SEQUENCE IS " << ans << endl;

    return 0;
}