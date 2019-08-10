//// Signature Question ////////////////
#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
 
string k_string(int k, string str)
{
    if(k == 1)
        return str;
    
    int alpha[26];
    for(int i=0; i<26; i++)
        alpha[i] = 0;
    
    int n = str.length();
    
    for(int i=0; i<n; i++)
    {
        int index = str[i] - 'a';
        alpha[index]++;
    }
 
    if( n%k != 0)
        return "-1";
 
    for(int i=0; i<26; i++)
    {
        if( alpha[i]%k != 0 )
            return "-1";
    }
 
    string s = "";
 
    for(int i=0; i<26; i++)
    {
        int count = alpha[i]/k;
        for(int j=0; j<count; j++)
            s = s + char('a' + i);
    }
 
    string ans = "";
    for(int i=0; i<k; i++)
        ans = ans + s;
    
    return ans;
}
 
int main()
{
    int k;
    cin >> k;
 
    string s;
    cin >> s;
 
    cout << k_string(k, s) << endl;
 
    return 0;
}