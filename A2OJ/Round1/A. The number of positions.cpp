#include<iostream>
 
using namespace std;
 
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
 
    // a,b < n
    // case 1 
    if( n-a <= b)
        cout << n-a << endl;
    else
        cout << b+1 << endl;
    
    return 0;
}
