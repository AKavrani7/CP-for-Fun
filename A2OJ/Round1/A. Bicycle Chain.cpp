#include<iostream>
#include<cmath>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    double front[n];
    for(int i=0; i<n; i++)
        cin >> front[i];
 
    int m;
    cin >> m;
 
    double rear[m];
    for(int i=0; i<m; i++)
        cin >> rear[i];
 
    int count = 0;
    int max_ratio = 0;
 
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            double ratio = rear[j]/front[i];
 
            if(ceil(ratio) == floor(ratio))
            {
                if(max_ratio < ratio)
                {
                    max_ratio = ratio;
                    count = 1;
                }
                else if(max_ratio == ratio)
                    count++;
            }
        }
    }
 
    cout << count;
 
    return 0;
}