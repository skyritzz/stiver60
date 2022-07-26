#include <bits/stdc++.h>
using namespace std; 

int main()
{
    vector<int> v = {15,-2,2,-8,1,7,10,23};
    int sum = 0;
    int maxm = 0;
    unordered_map<int, int> m;
    for(int i = 0; i< v.size(); i++)
    {
        sum += v[i];// sum krna shuru kro array ele ko
        if(sum == 0) // agr zero ho jata hai toh wha tak kai index ka length maxm m daal do
        maxm = i+1;

        else{// age sum zero nhi hota hai toh
            if(m.find(sum) != m.end())// agr voh sum hame map mai mil jata hai toh usse 
            //cuurent index jha par vo ruka hai toh map mai jis index par voh same sum mila hai subtract krdo// maxm update krdo
            {
                maxm = max(maxm , i - m[sum]);
            }
            else{// agar vo sum map mai nhi hai toh usse map mai with index daal do
                m[sum] = i;
            }
        }
        
    }
    cout << maxm << endl;

    return 0;
}