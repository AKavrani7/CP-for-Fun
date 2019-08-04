#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int min_index = 0;
    int max_index = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] <= arr[min_index])
            min_index = i;
        if(arr[i] > arr[max_index])
            max_index = i;
    }

    if(min_index < max_index)
        cout << (max_index) + (n-1-min_index) - 1;
    
    if(min_index > max_index)
        cout << (n-1-min_index) + (max_index);
    
    if(min_index == max_index)
        cout << 0;
    
    return 0;
}
