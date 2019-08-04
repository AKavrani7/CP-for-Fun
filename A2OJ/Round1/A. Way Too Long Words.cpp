#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    string str[t];
    for(int i=0; i<t; i++)
        cin >> str[i];
 
    for(int i=0; i<t; i++)
    {
        if(str[i].length() > 10)
            cout << str[i][0] << str[i].length()-2 << str[i][str[i].length()-1] << endl;
        else
            cout << str[i] << endl;
    }
    return 0;
}