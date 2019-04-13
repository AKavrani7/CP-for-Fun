#include <iostream>
using namespace std;

int absX(int x)
{
    if(x>3)
        return x-3;

    return 3-x;
}

int main()
{
    int x = 0;

    for(int i=1; i<6; i++)
    {
        for(int j=1; j<6; j++)
        {

            cin >> x;
            if(x)
            {
                cout << absX(i) + absX(j);
                break;
            }
        }
    }

    return 0;
}
