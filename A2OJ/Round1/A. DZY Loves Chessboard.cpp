// http://codeforces.com/problemset/problem/445/A

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector< vector<char> > chess_board(n, vector<char>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> chess_board[i][j];


    queue< pair<int,int> > q;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(chess_board[i][j] == '.')
            {
                q.push(make_pair(i,j));
                chess_board[i][j] = 'B';
                pair<int,int> prev; 

                while(!q.empty())
                {
                    prev = q.front();
                    int row = prev.first;
                    int col = prev.second;
                    q.pop();

                    char c = 'W';
                    if(chess_board[row][col] == 'W')
                        c = 'B';

                    if(row + 1 <n && chess_board[row+1][col] == '.' )
                    {
                        chess_board[row+1][col] = c;
                        q.push(make_pair(row+1,col));
                    }
                    
                    if(col + 1 <m && chess_board[row][col+1] == '.' )
                    {
                        chess_board[row][col+1] = c;
                        q.push(make_pair(row,col+1));
                    }

                    if(row - 1 >=0 && chess_board[row-1][col] == '.' )
                    {
                        chess_board[row-1][col] = c;
                        q.push(make_pair(row-1,col));
                    }
                    
                    if(col - 1 >=0 && chess_board[row][col-1] == '.' )
                    {
                        chess_board[row][col-1] = c;
                        q.push(make_pair(row,col-1));
                    }
                }       
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << chess_board[i][j];
        
        cout << endl;
    }

    return 0;
}