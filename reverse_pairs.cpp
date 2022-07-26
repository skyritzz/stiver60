#include <bits/stdc++.h>
using namespace std; 

 int ans = 0;
    void merge(vector<int> &a, int l , int m , int r)
    {
        int leftsize = m-l+1;
        int rightsize = r-m;
        vector<int> left(leftsize), right(rightsize);
        
        for(int i = 0;  i< leftsize; i++)
            left[i] = a[l+i];
        for(int i = 0; i< rightsize; i ++)
            right[i] = a[m+1+i];
        
        //the process before merging
        int i, j = 0;
        int cnt = 0;
        for(int i = 0; i<leftsize; i++)// i kai bhar aate hi main ans mai count ko inc kar denge
        {
            while(j<rightsize && left[i] > (long) 2*right[j]) // if condition true // inc j++;
            {
                j++;
            }
            cnt += j;// count mai j sai pehle jitne element hai unko count karenge
        }
        ans += cnt;
        
        //phir jab process khtm ho jayega tab ham merge karege two sorted arrays ko
        i=0,j=0;
        int k = l;
        while(i<leftsize && j<rightsize)
        {
            if(left[i] > right[j])
                a[k++] = right[j++];
            else
                a[k++] = left[i++];
        }
        
        while(i<leftsize)
        {
            a[k++] = left[i++];
        }
        
         while(j<rightsize)
        {
            a[k++] = right[j++];
        }
    }
        
    
    void mergeSort(vector<int> &a, int l , int r)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            mergeSort(a, l, m);
            mergeSort(a, m+1, r);
            merge(a, l, m, r);// merge mai actual merge karne sai pehle ham ek chota sa process karenge //phir merge karenge
        }
    }



int main()
{
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};
    int n = nums.size()-1;
    mergeSort(nums, 0, n);
    cout << "no of reverse pairs are " << ans;
    return 0;
}