#include <iostream>
using namespace std;

int main()
{
    int input[3][3];
    int output[3][3];


    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> input[i][j];
            input[i][j] = input[i][j]%2;
            output[i][j] = 1;
        }
    }

    if(input[0][0])
    {
        output[0][1]++;
        output[1][0]++;
        output[0][0]++;
    }

    if(input[0][1])
    {
        output[0][1]++;
        output[0][0]++;
        output[1][1]++;
        output[0][2]++;
    }

    if(input[0][2])
    {
        output[0][1]++;
        output[1][2]++;
        output[0][2]++;
    }

    if(input[1][0])
    {
        output[0][0]++;
        output[1][0]++;
        output[1][1]++;
        output[2][0]++;
    }

    if(input[1][1])
    {
        output[0][1]++;
        output[1][1]++;
        output[1][0]++;
        output[1][2]++;
        output[2][1]++;
    }

    if(input[1][2])
    {
        output[0][2]++;
        output[1][1]++;
        output[1][2]++;
        output[2][2]++;
    }

    if(input[2][0])
    {
        output[1][0]++;
        output[2][1]++;
        output[2][0]++;
    }

    if(input[2][1])
    {
        output[1][1]++;
        output[2][2]++;
        output[2][0]++;
        output[2][1]++;
    }

    if(input[2][2])
    {
        output[2][1]++;
        output[1][2]++;
        output[2][2]++;
    }


    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << output[i][j]%2 ;
        }
        cout << endl;
    }

    return 0;
}
