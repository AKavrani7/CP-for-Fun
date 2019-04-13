#include <iostream>
using namespace std;

string  printQ(string str, int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(str[i] == 'B' && str[i+1] == 'G')
        {
            str[i] = 'G';
            str[i+1] = 'B';
            i++;
        }
    }

    return str;
}

int main()
{
    int n,i;
    cin >> n >> i;
    string str;
    cin >> str;
    for(int j=0; j<i; j++)
    {
        str = printQ(str,n);
    }

    cout << str;

    return 0;
}
