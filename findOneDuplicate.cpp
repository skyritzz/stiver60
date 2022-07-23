#include <bits/stdc++.h>
using namespace std; 
 
int main()
{
    vector<int>nums = {3,1,3,4,2};

    //LINKED LIST CYCLE DETECTION CONCEPT IS USED
    //FLOYD CYCLE DETECTION

    //PHASE 1
    //slow fast ko same index par rakha
        int slow = nums[0];
        int fast = nums[0];
        
        //slow ko ek step badhaya
        // fast ko two step badhaya
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!= fast);//jab tak dono ek jagah nhi mil jaate tab tak badhate raho
        
        //2nd PHASE
        
        //isme fast ko first index pat lae gaye
        fast = nums[0];
        
        //aur phir dono slow or fast ko ek ek step aage badhaya
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        //ab jab dono same index par point karenge toh yeh ele duplicate ele hoga
        
        cout << "DUPLICATE ELEMENT IS " << slow;
        
        
    return 0;
}