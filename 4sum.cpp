#include <bits/stdc++.h>
using namespace std; 

vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        //pehle sort kr denge given vector ko
        sort(nums.begin(), nums.end());

        // abhi bhi 3 pointer approach lenge par loop i and j ka chalyenge aur aage wale array par (do pointer saath mai chlaenge)
        for(int i = 0; i< n; i++)
        {
            long long  target_3 = target - nums[i]; //yha target mai sai v[i] minus kr denge
            //aur ab target change ho gya hai
            
            
            for(int j = i+1; j<n; j++)
            {
                long long target_2 = target_3 - nums[j];// yha changed target mai sai v[j] minus kr denge

                //ab two pinter approach lenge left from right 
                int left = j+1; //yeh left index hoga j index kain baad wala
                int right = n-1; //yeh right index hoga end of array index
                
                while(left<right)//ab jab tak dono cross nhi karte
                {
                    int two_sum = nums[left] + nums[right];// ham dono index ko add karenge
                    
                    if(two_sum < target_2)// agr dono ka sum target sai kam hai toh left ko badhyenge
                    left++;

                    else if(two_sum > target_2)// agr dono ka sum target sai zada hai toh right ko kam karenge
                    right--;

                    else// ab jab two_sum  target kai brabar hai tab saare index naye vector mai daal denge
                    {
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        ans.push_back(quad); // abpoore vector ko quad vector mai daal do
                        
                        //ab agr left index ka duplicate hai toh skip krdo
                        while(left<right && nums[left] == quad[2])
                            ++left;

                        //ab agr right index ka duplicate hai toh skip krdo
                        while(left<right && nums[right] == quad[3])
                            --right;
                        
                    }
    
                }

               //ab agr j index ka duplicate hai toh skip krdo
                while(j+1 < n && nums[j+1] == nums[j])
                        ++j;
                
            }

            //ab agr i index ka duplicate hai toh skip krdo
            while(i+1 < n && nums[i+1] == nums[i])
                        ++i;
        }

        return ans;
        
    }


int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    
  

    vector<vector<int>> ans = fourSum(nums, target );

    for(int i =0 ;i < ans.size(); i++)
    {
        for( int j = 0; j< ans[0].size(); j++)
        {
                cout<< ans[i][j] << " ";
        }
        cout <<endl;
    }


    return 0;
}
