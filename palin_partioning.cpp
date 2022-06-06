#include<bits/stdc++.h>
using namespace std;

//palindrome code 
bool isPal(string s, int start, int end)
{
    while(start<=end)
    {
        if(s[start++] != s[end--])
        {
            return false;
        }
        return true;
    }
}

//In C++, std::substr() is a predefined function used for string handling. 
//string.h is the header file required for string functions. 
//This function takes two values pos and len
void solve(int index, string s, vector<string>&v, vector<vector<string>>&ans)
{
    if(index == s.size())//when we reach end of string
    {
        ans.push_back(v);
        return;
    }

    for(int i = index; i<s.size(); i++)
    {
        if(isPal(s, index, i))//decision is olny taken for planidromic substring
        {
            v.push_back(s.substr(index, i-index+1));
            solve(i+1, s, v, ans);
            v.pop_back();// when going back we need to pop the last element
        }
    }
}


void printAns(vector < vector < string >> & ans) {
   cout<<"The palindromes are "<<endl;
   cout << "[ ";
   for (int i = 0; i < ans.size(); i++) {
      cout << "[ ";
      for (int j = 0; j < ans[i].size(); j++)
         cout << ans[i][j] << " ";
         
      cout << "]";
   }
   cout << " ]";
}

int main()
{
    string s = "geeks";
    vector<string> v;
    vector<vector<string>> ans;
    solve(0, s, v, ans);
    printAns(ans);


    return 0;
}