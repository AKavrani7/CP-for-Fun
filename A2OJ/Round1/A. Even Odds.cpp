#include<iostream>
using namespace std;

int main()
{
    long long int  n,k;
    cin >> n >> k;

    if(n%2 == 0)
    {
        if(k<=n/2)
            cout << 1 + 2*(k-1);
        else
            cout << 2 + 2*(k-n/2-1);
    }
    else
    {
        if(k<=n/2+1)
            cout << 1 + 2*(k-1);
        else
            cout << 2 + 2*(k-n/2-2);
    }
    
    return 0;
}