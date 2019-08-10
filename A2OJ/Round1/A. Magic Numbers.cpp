#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    
    int a=0;
 
    while(n)
    {
        int d = n%10;
        
        if(d == 1 && (a == 44 || a == 4 || a == 0) )
        {
            a = 0;
            n = n/10;
        }
        else if(d == 4 && a == 4)
        {
            a = a*10 + d;
            n = n/10;
        }
        else if(d == 4 && a == 0)
        {
            a = 4;
            n = n/10;
        }
        else
        {
            break;     
        }
 
    }
 
    if(n == 0 && a == 0)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}