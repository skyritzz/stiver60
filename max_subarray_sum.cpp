#include<bits/stdc++.h>
 using namespace std;


int solve(int arr[], int n)
{
     int sum = 0;
    int msum = 0;
    for(int i = 0; i< n; i++){
        if(sum >= 0)
        sum += arr[i];

        else
        sum = arr[i];

        if(sum > msum )
        msum = sum;
    }
    return msum ;
}

 int main()
 {
     int n;
     cout<< "enter n " ;
     cin >> n ;
     int arr[n];
     cout<< "enter n elements " ;
     for(int i = 0; i< n; i++)
     {
         cin>> arr[i];
     }

    cout<< solve(arr, n) << endl;

     return 0;
 }