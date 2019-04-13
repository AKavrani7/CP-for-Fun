#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str;
    getline(cin , str);

    int n = str.length();

    for(int i=0; i<n; i++)
    {
        if(str[i] == '.')
            cout << "0";
        else
        {
            if(str[i+1] == '-')
                cout << "2";
            else
                cout << "1";
            i++;
        }
    }

    return 0;
}
