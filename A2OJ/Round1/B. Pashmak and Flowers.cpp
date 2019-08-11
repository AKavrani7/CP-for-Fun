#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
 
    long long unsigned int count_min = 0;
    long long unsigned int count_max = 0;
    int max_element = INT_MIN;
    int min_element = INT_MAX;
    
    
    for(int i=0; i<n; i++)
    {
        if(max_element < arr[i])
        {
            max_element = arr[i];
            count_max = 0;
        }
 
        if(max_element == arr[i])
            count_max++;
        
        if(min_element > arr[i])
        {
            min_element = arr[i];
            count_min = 0;
        }
 
        if(min_element == arr[i])
            count_min++;
    }
 
    if(max_element == min_element && count_min == count_max)
        cout << "0 " <<  count_min*(count_min-1)/2 << endl;
    else
        cout << max_element - min_element << " " << count_max*count_min << endl;
    return 0;
}