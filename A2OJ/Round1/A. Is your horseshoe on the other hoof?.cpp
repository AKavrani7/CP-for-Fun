#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int main()
{    
    unordered_set<int> count;
    for(int i=0; i<4; i++)
    {
        int data;
        cin >> data;
        count.insert(data);
    }

    int ans = 4 - count.size();   
    
    cout << ans;
    return 0;
}
