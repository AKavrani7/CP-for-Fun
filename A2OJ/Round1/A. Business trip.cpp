#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int min_no_days(int k, int arr[])
{
    if(k<0)
        return -1;
    if(k==0)
        return 0;
    
    int min_days = 12;
    int sum_so_far = 0;
    int count = 0;

    for(int i = 11; i>=0; i--)
    {
        if(sum_so_far >= k)
        {
            min_days = count;
            return min_days;
        }
        else
        {
            sum_so_far += arr[i];
            count++;
        }
    }
    
    if(sum_so_far >= k)
    {
        min_days = count;
        return count;
    }

    return -1;
}


int main()
{
    int k;
    cin >> k;

    int arr[12];
    for(int i=0; i<12; i++)
        cin >> arr[i];

    sort(arr, arr+12);
    
    cout << min_no_days(k, arr) << endl;
    
    return 0;
}