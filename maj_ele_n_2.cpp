#include <bits/stdc++.h>
using namespace std; 

int main()
{
    //MOORES VOTING ALGO
    vector<int> v = {2,2,1,1,1,2,2};
    int count =0;
    int candidate = 0;
    for(auto num : v) //TRAVERSEING EACH ELE OF VECTOR V
    {
        if(count == 0)//AS SOON AS COUNT BECOMES ZERO WE UPDATE CANDIDATE WITH CURRENT NUM
        candidate = num; 

        if(candidate == num)//IF NUM IS EQUAL TO SAM CANDIDATE THEN INC COUNT BY 1
        count++;

        else// IF CANDIDATE IS NOT EQUAL TO NUM THEN DEC COUNT BY 1
        count--;
    }

    cout << "MAJORITY ELEMENT IS "<< candidate;

    return 0;
}