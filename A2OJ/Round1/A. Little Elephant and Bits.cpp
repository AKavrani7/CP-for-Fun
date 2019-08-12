#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string no;
    cin >> no;

    int zero_index = -1;
    string ans = "";

    for(int i=0; no[i]; i++)
    {
        if(no[i] == '0' && zero_index == -1)
        {
            zero_index = i;
            continue;
        }

        ans += no[i];     
    }

    if(zero_index == -1)
        ans.pop_back();
    
    cout << ans << endl;
    return 0;
}