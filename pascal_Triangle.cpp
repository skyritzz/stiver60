#include<bits/stdc++.h>
 using namespace std;

void solve(int n)
{
    vector<vector<int>> v(n);
    for(int line = 0 ; line < n; line++)
    {
        v[line].resize(line+1);//initialize empty row 
            //where no. of columns will always be equal to number of column
        for(int i = 0 ; i<= line; i++)
        {
            if(line == i || i == 0)
            {
                v[line][i] = 1;
            }
            else{
                v[line][i] = v[line-1][i-1] + v[line-1][i];
            }

            cout << v[line][i] << " ";
        }
        cout<< endl;
    }

}


 int main()
 {

     int n ; // rows
     cout << "enter rows " << endl;
     cin >> n;
     
     solve(n);

     return 0;
 }