#include<iostream>
#include<bits/stdc++.h>
 
 
#define print_array(x,n) for(int i=0; i<n; i++) cout << x[i] << " ";
#define line() cout << endl;
 
using namespace std;
 
void make_groups(int arr[], int n)
{
    if(n%3)
    {
        cout << "-1" << endl;
        return;
    } 
 
    int count[7] = { 0 };
    vector<string> ans;
 
    for(int i=0; i<n; i++)
        count[arr[i]]++;
 
    if(count[5] != 0 || count[0] != 0)
    {
        cout << "-1" << endl;
        return;
    }
    
    //print_array(count,7)
    //line()
 
    // print c = 4
    while(count[4])
    {
        if(count[2] > 0 && count[1] > 0)
        {
            ans.push_back("1 2 4");
            count[2]--;
            count[1]--;
            count[4]--;
        }
        else
        {
            cout << "-1" << endl;
            return ;
        }
    }
 
    // print c = 6
    while(count[6])
    {
        if(count[2] > 0 && count[1] > 0)
        {
            ans.push_back("1 2 6");
            count[2]--;
            count[1]--;
            count[6]--;
            
        }
        else if(count[3] > 0 && count[1] > 0)
        {
            ans.push_back("1 3 6");
            count[3]--;
            count[1]--;
            count[6]--;
        }
        else 
        {
            cout << "-1" << endl;
            return ;
        }
    }
 
    if( ans.size() != n/3 )
    {
            cout << "-1" << endl;
            return ;
    }
 
    for(int i=0; i<n/3; i++)
    {
        cout << ans[i] << endl;
    }
 
    return ;
}
 
 
int main()
{
    int n;
    cin >> n;
 
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    make_groups(arr, n);
 
    return 0;
}