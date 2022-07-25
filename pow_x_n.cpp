#include <bits/stdc++.h>
using namespace std; 

int main()
{
    double x = 2.00000;
     int n=10;
     double ans = 1.0;
        long long nn = n;
        if(nn<0) //making -ve number +ve
            nn = (-1)*(nn);
        
        while(nn)
        {
            if(nn%2)
            {
                ans = ans*x;
                nn = nn-1;
            }
            else
            {
                x = x*x;
                nn = nn/2;
            }
        }
        
        if(n<0) //x^(-n) ===>  1/(x^n)
            ans = double(1.0)/double(ans);
        cout << "ans is " << ans ;        
    return 0;
}