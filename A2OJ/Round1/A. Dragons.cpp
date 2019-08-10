#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector< pair<int,int> > dragons;

    for(int i=0; i<n; i++)
    {
        int strength, bonus;
        cin >> strength >>  bonus;
        
        pair<int,int> dragon_i = make_pair(strength, bonus);
        dragons.push_back(dragon_i); 
    }

    sort(dragons.begin(), dragons.end());

    string res = "YES";

    for(int i=0; i<n; i++)
    {
        if( s > dragons[i].first)
            s += dragons[i].second;
        else
        {
            res = "NO";
            break;   
        }
        
    }

    cout << res << endl;
    return 0;
    
}