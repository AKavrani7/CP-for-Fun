#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int max_happiness(string a, int l, int r, int score[5][5])
{
    int cal=0;
    if(l == r)
    {
        cal += score[a[0] - '0' - 1][a[1] - '0' - 1] + score[a[1] - '0' - 1][a[0] - '0' - 1] + score[a[2] - '0' - 1][a[3] - '0' - 1] + score[a[3] - '0' - 1][a[2] - '0' - 1];  
        cal += score[a[1] - '0' - 1][a[2] - '0' - 1] + score[a[2] - '0' - 1][a[1] - '0' - 1] + score[a[3] - '0' - 1][a[4] - '0' - 1] + score[a[4] - '0' - 1][a[3] - '0' - 1];
        cal += score[a[2] - '0' - 1][a[3] - '0' - 1] + score[a[3] - '0' - 1][a[2] - '0' - 1];
        cal += score[a[3] - '0' - 1][a[4] - '0' - 1] + score[a[4] - '0' - 1][a[3] - '0' - 1];
    }
    else
    {   
        for(int i=l; i<=r; i++)
        {
            swap(a[l], a[i]);
            
            int ans = max_happiness(a, l+1, r, score);
            cal = max(cal, ans);
            
            swap(a[l], a[i]);
        }
    }
    
    return cal;
}

int main()
{
    int score[5][5];

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> score[i][j];

    string str = "12345";

    int ans =  max_happiness(str, 0, 4, score);

    cout << ans << endl;

    return 0;
}