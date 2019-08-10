#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a =  sqrt(n);
    int b =  sqrt(m);

    bool case_1 = false;

    if(b>a)
    {
        case_1 = true;
    }

    int count = 0;
    for(i=0; i<=min(a,b); i++)
    {
        int j = 0;
        if(case_1)
        {
            j = n - i*i;
            if(j>=0 && (i + j*j == m))
                count++;
        }
        else
        {
            j = m - i*i;
            if(j>=0 && (i + j*j == n))
                count++;
        }
    }

    cout << count;

    return 0;
}