#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int upper = 0;
    int lower = 0;

    for(int i=0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else
            lower++;
    }

    if(lower >= upper)
    {
        for(int i=0; str[i]; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                cout << str[i];
            else
                cout << char(str[i]-'A' + 'a');
        }
    }
    else
    {
        for(int i=0; str[i]; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                cout << str[i];
            else
                cout << char(str[i]-'a' + 'A');
        }
    }

    return 0;
}