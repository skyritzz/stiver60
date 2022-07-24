#include <bits/stdc++.h>
using namespace std; 

//GAP METHOD
//this takes constant space O(1)


int main()
{
    vector<int> nums1 = {1,4,7,8,10};
    vector<int> nums2 = {2,3,9};
    int m = nums1.size();
    int n = nums2.size();

    int gap = ceil((float)(m+n)/2);
       
        while(gap>0)//jab tak gap zero nhi ho jata
        {
            int i = 0;
            int j = gap;
            while(j<(m+n))// jab tak j index out of index nh iho jata
            {
                //working only on first array as i in 1st arr and j also in 1st arr
                if(j<m && nums1[i]>nums1[j])
                {
                    swap(nums1[i], nums1[j]);
                }

                //working on both arrays as i in 1st arr and j in 2nd arr
                else if(j>=m && i<m && nums1[i] > nums2[j-m])
                {
                    swap(nums1[i], nums2[j-m]);
                }

                //working on both arrays as i in 2nd arr and j also in 2nd arr
                else if(i >= m && j>= m && nums2[i-m] > nums2[j-m])
                {
                    swap(nums2[i-m],nums2[j-m]);
                }
                j++;
                i++;
            }
            if(gap == 1)//agar gap 1 ho jata hai toh kaam khtm bhar niaklo
                gap = 0;
            else // gap greater tham 1 so gap ko reduce krdo by half
                gap = gap/2;
        }

        //printing both arrays
        for(int i= 0; i<m; i++)
        {
            cout<< nums1[i] <<" ";
        }
        cout<<endl;
        for(int i= 0; i<n; i++)
        {
            cout<< nums2[i] <<" ";
        }
        
   


    return 0;
}