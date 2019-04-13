#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    float x = 0,y =0 ,z = 0;
    float i,j,k;

    for(int a = 0; a<n; a++)
    {
        cin >> i >> j >> k;
        x += i;
        y += j;
        z += k;
    }

    if(x == 0 && y ==0 && z ==0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
