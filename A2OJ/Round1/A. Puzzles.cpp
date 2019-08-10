#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    //cout << n << " " << m << endl;
    int min_diff = INT_MAX;

    int puzzles[m];
    for(int i=0; i<m; i++)
        cin >> puzzles[i];
    
    sort(puzzles, puzzles+m);
    
    for(int i=0; i<=m-n; i++)
    {
        min_diff = min(min_diff, puzzles[i+n-1] - puzzles[i]);
       // cout << min_diff << " " << i << " " << i+n-1 << endl;
    }
    
    cout << min_diff << endl;
    
    return 0;
}