#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    int hund = 0;
    int two_hund = 0;
 
    for(int i=0; i<n; i++)
    {
        int data;
        cin >> data;
 
        if(data == 100)
            hund++;
        else
            two_hund++;
    }
 
    if(two_hund%2 == 0)
    {
        if(hund%2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        if((hund-2)%2 == 0 && hund-2>=0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}