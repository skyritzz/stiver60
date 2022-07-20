#include<bits/stdc++.h>
#define vi vector<int> 

 using namespace std;

 void nextPermutation(vector<int>& arr) {
    
        int n = arr.size()-1;
        int peakIdx = 0;
        for(int i = n; i>0; i--)//find peak index
        {
            if(arr[i] > arr[i-1])
            {
                peakIdx = i;//when found break out of loop
                break;
            }
        }
        
        if(peakIdx==0)
        {
            sort(arr.begin(), arr.end());// if no next permutation exist then sort the arr
        }
        else
        {
            int virus = arr[peakIdx-1];
            for(int j = peakIdx ; j<=n; j++)//from peak index till end
            {
                int nxtGr = arr[j] - virus;
                if( nxtGr > 0 )// swap till we get nextgreater 
                {
                    int temp = arr[j];
                    arr[j] = arr[peakIdx-1];
                    arr[peakIdx-1] = temp;
                }
            }
            sort(arr.begin() + peakIdx , arr.end());//if ele not sorted from peak index till end
        }
        
    }

 int main()
 {
    vector<int> v = {1,2,3};
    nextPermutation(v);
    for(int i = 0 ; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
 }