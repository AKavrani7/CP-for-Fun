class Solution{

	public:

    vector<pair<int,int>> move = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    vector<vector<int>> keypad = { 
                                   {'1', '2', '3'},
                                   {'4', '5', '6'},
                                   {'7', '8', '9'},
                                   {'*', '0', '#'}
                                 };
    
	long long getCount(int N)
	{
		// Your code goes here
		long long dp[N][10];
		
		for(int i=0; i<=9; i++)
		    dp[0][i] = 1;
		
        for(int i=1; i<N; i++)
		{
		    dp[i][0] = dp[i-1][0] + dp[i-1][8];
		    dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][4];
		    dp[i][2] = dp[i-1][2] + dp[i-1][3] + dp[i-1][5] + dp[i-1][1];
		    dp[i][3] = dp[i-1][3] + dp[i-1][2] + dp[i-1][6];
		    dp[i][4] = dp[i-1][4] + dp[i-1][5] + dp[i-1][1] + dp[i-1][7];
		    dp[i][5] = dp[i-1][5] + dp[i-1][2] + dp[i-1][6] + dp[i-1][8] + dp[i-1][4];
		    dp[i][6] = dp[i-1][6] + dp[i-1][3] + dp[i-1][9] + dp[i-1][5];
		    dp[i][7] = dp[i-1][7] + dp[i-1][8] + dp[i-1][4];
		    dp[i][8] = dp[i-1][8] + dp[i-1][5] + dp[i-1][9] + dp[i-1][0] + dp[i-1][7];
		    dp[i][9] = dp[i-1][9] + dp[i-1][8] + dp[i-1][6];
		}
		
		long long ans = 0;
		for(int i=0; i<=9; i++)
		    ans += dp[N-1][i];
		
		return ans;
	}
};