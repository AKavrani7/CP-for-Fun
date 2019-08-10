#include<iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;

    string a = "-",b = "-";
    int x = 0,y = 0;

    string str;
    for(int i=0; i<n; i++)
    {
        cin >> str;

        if(str == a || a == "-")
        {
            a = str;
            x++;
        }
        else
        {
            b = str;
            y++;
        }    
    }

    if(x > y)
        cout << a;
    else
        cout << b;
    
    return 0;
}