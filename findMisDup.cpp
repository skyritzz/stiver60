#include <bits/stdc++.h>
using namespace std; 


int main()
{
    vector<int> arr = {4, 5, 2, 9, 8, 1, 1, 7, 10, 3};
    int i = 0;
    int n = arr.size();

    int missing, repeating;

    while(i<n)
    {
        if(arr[i] == arr[arr[i]-1])//agar ele correct position par hai toh ham index inc krenge
        {
            i++;
        }
        else//agar ele sahi pos par nhi hai toh swap kr kr kai usse sahi pos par lae ayenge
        {
            swap(arr[i], arr[arr[i]-1]);
        }
    }
    
    for(int i = 0; i< n;i++)
    {
        if(arr[i] != i+1)// ab agr ele wrong hai apni sahi position par nhi hai 
        {
            missing = i+1; // toh wha jo ele hona tha b=vo missing hai 
            repeating = arr[i]; // aur jo wha par iss waqt hai woh repeating hai
            break;
        }
    }

    cout << "MISSING NO IS " << missing << endl;
    cout << "REPEATING NO IS " << repeating << endl;

    return 0;
}

//ref : aditya verma
//this approach does not work is=f array provided is "const" vector<int> &arr ->maths and bit manipulation can be used