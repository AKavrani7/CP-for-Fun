#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
#define fix(n) cout << fixed << setprecision(n)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(long i=a; i<=b; i++)
#define REN(i, a, b) for(long i=b; i>=a; i--)
// Debugging 
#define line cout << endl
#define out(n) cout << n << " "
#define bug(n) cout << n << "\n"
#define print(arr, start, end) REP(i, start, end) out(arr[i]); line

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef map<int, int> mii;

///// General Purpose functions /////

/////////////////

bool findEmpty(vector<vector<int> > A, int &row, int &col)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(A[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
    
    return false;
}

bool isSafe(vector<vector<int> > &A, int row, int col, int num)
{
    // row check
    if(A[row][col] != 0)
        return false;
    
    for(int i=0; i<9; i++)
        if(A[row][i] == num)
            return false;
    
    // col check
    for(int i=0; i<9; i++)
        if(A[i][col] == num)
            return false;
    
    // box check
    int box_row = (row/3)*3;
    int box_col = (col/3)*3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(A[i+box_row][j+box_col] == num)
                return false;
    
    return true;
}

bool solve(vector<vector<int> > &A)
{
    int row,col;
    if(!findEmpty(A, row, col))
        return true;
    
    for(int i=1; i<=9; i++)
    {
        int num = i;
        if(isSafe(A, row, col, num))
        {
            A[row][col] = num;
            
            if(solve(A))
                return true;
            
            A[row][col] = 0;
        }
    }
    
    return false;
}


void solve(){
    vector<vector<int>> A(9, vector<int>(9));
    
    REP(i,0,8)
        REP(j,0,8)
            cin >> A[i][j];
    
    solve(A);
    
    REP(i,0,8)
        REP(j,0,8)
            out(A[i][j]);
    
    line;
}

void prep(){

}

int main()
{
	// https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0
	//code
	io;
	int t = 1;
	cin >> t;
	prep();
	fix(12);
	while(t--){
	    solve();
	}
	
	return 0;
}