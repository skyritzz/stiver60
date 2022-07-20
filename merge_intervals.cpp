#include <bits/stdc++.h>
using namespace std; 
 
 
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];//start tab hi update hoga jab kisi ka end usse chota hoga
        int end = intervals[0][1]; // end tab update hoga jab kisi ka end usse bada hoga
        
        for(auto i: intervals)
        {
            //no overlap
            if(i[0]>end)//jab interval ka start end sai bada hai tab overlap nhi hoga
            {
                ans.push_back({start, end});//naye interval par kaam karne sai pehle ham current                        //start aur end ko result mai daal denge phir unke update kar denge
                start = i[0];
                end = i[1];
            }
            //overlap 
            else
                end = max(end, i[1]);// overlap hai toh ham bas bade sai bada end search karenge
        }
        ans.push_back({start, end});// jo akhiri  interval bachega usme ham curr start aur end daal                                         //denge
       return ans;
        
    }

int main()
{
    vector<vector<int>> v = {{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> op = merge(v);

    for(auto i: op)
    {
       cout << i[0] << " " << i[1] <<endl;
    }

    return 0;
}