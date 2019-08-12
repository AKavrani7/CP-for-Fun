#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    int min_sol = INT_MAX;
    int max_sol = INT_MIN;

    for(int i=0; i<n; i++)
    {
        int data;
        cin >> data;

        if(data < min_sol)
            min_sol = data;
        
        if(data > max_sol)
            max_sol = data;
    }

    int min_fail = INT_MAX;
    for(int i=0; i<m; i++)
    {
        int data;
        cin >> data;

        if(data < min_fail)
            min_fail = data;
    }

    int val = max(2*min_sol, max_sol);
    if(val < min_fail)
        cout << val << endl;
    else
        cout << "-1" << endl;
    
    return 0;
}