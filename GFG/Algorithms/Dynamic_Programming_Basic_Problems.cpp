#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}

//// Solution of Basic Problems based on Dynamic Programming

// 1. Longest Increasing Subsequence
// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

int LIS(int arr[], int n)
{
    int dp[n];
    int ans = 1;
    
    for(int i=0; i<n; i++)
    {
        dp[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(arr[i] >= arr[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(dp[i], ans);
    }
    return ans;
}

// 2. Longest Common Subsequence
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

int LCS(string first, string second)
{
    int first_l = first.length();
    int second_l = second.length();

    int dp[first_l+1][second_l+1];

    for(int i=0; i<=first_l; i++)
    {
        for(int j=0; j<=second_l; j++)
        {
            if( i == 0 || j ==0)
                dp[i][j] = 0;
            else if(first[i-1] == second[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }   
    }
    return dp[first_l][second_l];
}

// 3. Edit Distance 
// https://www.geeksforgeeks.org/edit-distance-dp-5/
// convert first into second
int editDistance(string first, string second, int m, int n)
{
    int dp[m+1][n+1];

    // insert (i,j-1)
    // remove (i-1,j)
    // replace (i-1,j-1)


    for(int i=0; i<=m; i++)
    {
        for(int j=0;j<=n; j++)
        {
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(first[i-1] == second[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }

    dd[m][n];
}

// 4. Min Cost Path
// https://www.geeksforgeeks.org/min-cost-path-dp-6/

int min_cost_path( vector< vector<int> > cost, int n)
{
    if(n==0) return 0;
    int dp[n][n];
    dp[0][0] = cost[0][0];
    
    for(int i=1; i<n; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    for(int j=1; j<n; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];

    for(int i=1; i<n; i++ )
    {
        for(int j=1; j<n; j++)
        {

            int min_value = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            dp[i][j] = min_value + cost[i][j];
        }
    }
    return dp[n-1][n-1];
}

// 5. Coin Change
// https://www.geeksforgeeks.org/coin-change-dp-7/

int coin_change(int coins[], int n, int m)
{
    if(m == 0)
        return 1;
    
    if(n<=0 || m<0)
        return 0;

    int dp[m+1][n];
    sort(coins, coins + n);
    
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == 0)
            {    
                dp[0][j] = 1;
                continue;
            }

            int x = (i>=coins[j]) ? dp[i-coins[j]][j] : 0;
            int y = (j>=1) ? dp[i][j-1] : 0;

            dp[i][j] = x + y;
        }
    }

    return dp[m][n-1];
}

// 6. Matrix Chain Multiplication
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

int matric_chain_order(int p[], int n)
{
    if(n<2)
        return 0;

    int dp[n][n];

    for(int i=0; i<n; i++)
        dp[i][i] = 0;
    
    // Based on the length
    for(int l=2; l<n; l++)
    {
        for(int i=1; i<n-l+1; i++)
        {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++)
            {
                
                int cal = p[i-1]*p[k]*p[j] + dp[i][k] + dp[k+1][j]; 
                dp[i][j] = min(dp[i][j], cal);
            }
        }
    }
    
    return dp[1][n-1];
}

// 7. Binomial Coefficient 
// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

int binomial_coefficient(int n, int k)
{
    if(k>n) return 0;

    int dp[n+1][k+1];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=min(i,k); j++)
        {
            if(j==0 || j==i)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];    
            }
        }
    }

    return dp[n][k];
}

// 8. 0-1 Knapsack Problem
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int knapsack(int n, int val[], int wg[], int W)
{
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = (j >= wg[i-1]) ? max(dp[i-1][j], val[i-1] + dp[i-1][j-wg[i-1]]) : dp[i-1][j]; 
        }
    }
    return dp[n][W];
}

// 9. Egg Dropping Puzzle
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

int egg_drop(int n, int k)
{
    int dp[n+1][k+1];
    // i: no_of_eggs_left
    // j: no_of_floors

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else if(i==1)
                dp[1][j] = j;
            else if(j==1)
                dp[i][1] = 1;
            else
            {
                dp[i][j] = INT_MAX;
                for(int floor_no = 1; floor_no<=j; floor_no++)
                {
                    trial_for_x = 1 + max(dp[i-1][floor_no-1] ,dp[i][j-floor_no]);
                    dp[i][j] = max(dp[i][j], trial_for_x);
                }
            }
        }
    }
    return dp[n][k];
}

// 10. Longest Palindromic Subsequence 
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

int longest_palindromic_subsequence(string str)
{
    int n = str.length();
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
        dp[i][i] = 1;
    }

    for(int str_l = 2; str_l <= n; str_l++)
    {
        for(int i=1; i<=n; i++)
        {
            j = i+l-1;

            if(str[i-1] == str[j-1])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[1][n];
}

// 11. Cutting a Rod | DP-13
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
int cutRod(int price[], int n)
{
    int profit[n+1];
    profit[0] = 0;

    for(int i=1; i<=n; i++)
    {
        profit[i] = 0;
        for(int j=0; j<i; j++)
            profit[i] = max(profit[i-j-1] + price[j], profit[i]);
    }
    return profit[n];
}

// 12. Maximum Sum Increasing Subsequence
// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
// N positive numbers

int maximum_sum_increasing_subsequence(int seq[], int n)
{
    if(n <= 0) return 0;

    int dp[n+1];
    dp[0] = 0;

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        dp[i] = 0;
        for(int j=1; j<i; j++) 
            if(seq[j-1] < seq[i-1])
                dp[i] = max(dp[j], dp[i]);

        dp[i] = dp[i] + seq[i-1];

        ans = max(ans, dp[i]);
    }

    return ans;
}

// 13. Longest Bitonic Subsequence 
// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/

int longest_bitonic_subseqence(int arr[], int n)
{
    int inc_dp[n];
    int dec_dp[n];

    for(int i=n-1; i>=0; i--)
    {
        dec_dp[i] = 1;
        for(int j=n-1; j>i; j--)
            if(arr[j] < arr[i])
                dec_dp[i] = max(1+dec_dp[j], dec_dp[i]);
    }


    int ans = 0;
    for(int i=0; i<n; i++)
    {
        inc_dp[i] = 1;
        for(int j=0; j<i; j++)
        { 
            if(arr[j] < arr[i])
                inc_dp[i] = max(1 + inc_dp[j], inc_dp[i]);

        }
        ans = max(ans, inc_dp[i] + dec_dp[i]-1);
    }

    return ans;
}

//----------------------- I N C O M P L E T E -------------------------------------
// 14. Floyd Warshall Algorithm
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
// After Graph
//----------------------------------------------------------------------------------

// 15. Palindrome Partitioning 
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

int min_palindrome_partition(string str, int n)
{
    int min_cuts[n];
    bool palindrome[n][n];

    for(int i=0; i<n; i++)
        palindrome[i][i] = true;
    
    // Build the palindrome array
    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j = i+l-1;
            if(l == 2)
                palindrome[i][j] = (str[i] == str[j]);
            else
                palindrome[i][j] = (str[i] == str[j]) && palindrome[i+1][j-1];
        }
    }

    // Use the palindrome to calculate the min_cuts
    for(int i=0; i<n; i++)
    {
        if(palindrome[0][i])
            min_cuts[i] = 0;
        else 
        {
            min_cuts[i] = INT_MAX;
            for(int j=0; j<i; j++)
            {
                if(palindrome[j+1][i])
                    min_cuts[i] = min(1+ min_cuts[j], min_cuts[i]);
            }
        }
        
    }

    return min_cuts[n-1];
}

// 16. Partition problem
// https://www.geeksforgeeks.org/partition-problem-dp-18/

bool partition_problem(int arr[], int n)
{
    if(n<=0) return true;

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    if(sum%2 == 1) return false;

    sum = sum/2;
    bool dp[sum+1][n+1];
    
    for(int i=0; i<=sum; i++)
        dp[i][0] = false;

    for(int j=0; j<=n; j++)
        dp[0][j] = true;

    for(int i=1; i<=sum; i++)
        for(int j=1; j<=n; j++)
            dp[i][j] = (arr[j-1] <= i) ? dp[i-arr[j-1]][j-1] || dp[i][j-1] : dp[i][j-1];

    return dp[sum][n];
}

// 17. Word Wrap Problem
// https://www.geeksforgeeks.org/word-wrap-problem-dp-19/

int print_solution(int print_line[], int n)
{
    int line_no = 0;
    if(print_line[n] == 1)
        line_no = 1;
    else
        line_no = print_solution(print_line, print_line[n]-1) + 1;
    
    cout << "Line number " << line_no <<": From word no. "<< print_line[n] << " to "<< n << endl;
    return line_no;
}

void solve_word_wrap(int length[], int n, int max_width)
{
    // Extra Space
    int extra_space[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        extra_space[i][i] = max_width - length[i-1];
        for(int j=i+1; j<=n; j++)
        {
            extra_space[i][j] = extra_space[i][j-1] - length[j-1] - 1; 
        }
    }
    // print extra space
    cout << "extra space" << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
            cout << extra_space[i][j] << " ";
        cout << endl;
    }
    

    // Calculate space cost array
    int space_cost[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if(extra_space[i][j] >=0 && j == n)
                space_cost[i][j] = 0;
            else if(extra_space[i][j] >=0)
                space_cost[i][j] = extra_space[i][j]*extra_space[i][j];
            else
                space_cost[i][j] = -1;
        }
    }
    // print space_cost
    cout << "space_cost" << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
            cout << space_cost[i][j] << " ";
        cout << endl;
    }


    // calculate Cost
    int cost[n+1];
    int print_line[n+1];

    cost[0] = 0;
    print_line[0] = 0;
    // Fill cost array i denote no of words
    for(int i=1; i<=n; i++)
    {
        cost[i] = INT_MAX;
        // cost of words from 1 to i words
        for(int j=1; j<=i; j++)
        {
            if(cost[j-1] != -1 && space_cost[j][i] != -1 && cost[i] > cost[j-1] + space_cost[j][i])
            {
                cost[i] = cost[j-1] + space_cost[j][i];
                print_line[i] = j;
            }
        }
    }
    // print cost
    cout << "cost" << endl;
    for(int i=0; i<=n; i++)
    {
        cout << cost[i] << " ";
    }
    cout << endl;

    // print print_line
    cout << "print_line" << endl;
    for(int i=0; i<=n; i++)
    {
        cout << print_line[i] << " ";
    }
    cout << endl;

    print_solution(print_line, n);
}

// 18. Maximum Length Chain of Pairs 
// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

int max_chain_length(vector< pair<int,int> > seq)
{
    sort(seq.begin(), seq.end());

    int n = seq.size();

    int max_chain[n];
    int ans = 1;

    for(int i=0; i<n; i++)
    {
        max_chain[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(seq[j].second < seq[i].first && max_chain[i] < max_chain[j] + 1)
                max_chain[i] = max_chain[j] + 1;
        }

        ans = max(ans, max_chain[i]);
    }

    return ans;
}

// 19. Variations of LIS 
// https://www.geeksforgeeks.org/variations-of-lis-dp-21/

struct BOX
{
    int h, w, l;
};

// Decreasing Order
int compare( const void *a, const void *b)
{
    
    BOX *box_a = (BOX *)a;
    BOX *box_b = (BOX *)b;
    
    int base_area_a = (*box_a).w * (*box_a).l;
    int base_area_b = (*box_b).w * (*box_b).l;

    return base_area_b - base_area_a;
    
    /*
    return ( (*(BOX *)b).l * (*(BOX *)b).w ) - 
           ( (*(BOX *)a).l * (*(BOX *)a).w );
    */
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    BOX possibilites[3*n];
    int index = 0;

    for(int i=0; i<n; i++)
    {   
        // Case 1 (h,w,l)
        possibilites[index].h = height[i];
        possibilites[index].w = min(width[i], length[i]);
        possibilites[index].l = max(width[i], length[i]);
        index++;
        
        // Case 2 (w,l,h)
        possibilites[index].w = min(height[i], width[i]);
        possibilites[index].l = max(height[i], width[i]);
        possibilites[index].h = length[i];
        index++;

        // Case 3 (l,h,w)
        possibilites[index].l = max(height[i], length[i]);
        possibilites[index].h = width[i];
        possibilites[index].w = min(height[i] ,length[i]);
        index++;
    }   
    
    // Decreasing order of base area
    qsort(possibilites, 3*n, sizeof(possibilites[0]), compare);
    
    int max_h[3*n];
    int ans = 0;

    for(int i=0; i<3*n; i++)
    {
        max_h[i] = possibilites[i].h; 
        for(int j=0; j<i; j++)
        {
            if(possibilites[i].l < possibilites[j].l &&
               possibilites[i].w < possibilites[j].w &&
               max_h[i] < possibilites[i].h + max_h[j]
            )
            max_h[i] = possibilites[i].h + max_h[j];
        }
        ans = max(ans, max_h[i]);
    }

    return ans;
}

// 20. Program for Fibonacci numbers
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
unsigned long int fibonacciNo(int n)
{
    unsigned long int fNo[n+1];
    fNo[0] = 0;
    fNo[1] = 1;
    int mod = 1000000007;

    for(int i=2; i<=n; i++)
    {
        fNo[i] = (fNo[i-1]%mod + fNo[i-2]%mod)%mod;
    }
    return fNo[n]%mod;
}

// 21.Minimum number of jumps to reach end
// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

// Method 1 O(n^2)
// Left to right
int min_jumps_method_1(int arr[], int n)
{
    int jumps[n];
    jumps[0] = 0;

    for(int i=1; i<n; i++)
    {
        jumps[i] = INT_MAX;
        for(int j=0; j<i; j++)
        {
            if(i+1 <= j+1 + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[j] + 1, jumps[i]);
                break;
            }
        }
    }

    if(jumps[n-1] == INT_MAX)
        jumps[n-1] = -1;
    
    return jumps[n-1];
}
// Method 2 O(n^2) Worst case
// Right to left
int min_jumps_method_2(int arr[], int n)
{
    int jumps[n];
    jumps[n-1] = 0;

    for(int i=n-2; i>=0; i--)
    {   
        if(arr[i] == 0)
            jumps[i] = INT_MAX;
        else if(arr[i] >= n-i-1)
            jumps[i] = 1;
        else
        { 
            jumps[i] = INT_MAX;
            for(int j=i+1; j<n; j++)
            {
                if(i+1 + arr[i] >= j+1 && jumps[j] != INT_MAX)
                {
                    jumps[i] = min(jumps[j] + 1, jumps[i]);
                }
            }
        }
    }

    if(jumps[0] == INT_MAX)
        jumps[0] = -1;
    
    return jumps[0];
}

// Method 3 o(n)
// https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

int min_jumps_method_3(int arr[], int n)
{
    if(n<=1) 
        return 0;

    if(arr[0] == 0)
        return -1;

    int max_reach = arr[0];
    int step = arr[0];
    int min_jump = 1;

    for(int i=1; i<n; i++)
    {
        if(i == n-1)
            return min_jump;
        
        max_reach = max(max_reach, i+arr[i]);

        step--;

        if(step == 0)
        {
            min_jump++;

            if(i >= max_reach)
                return -1;
            
            step = max_reach - i;
        }
    }

    return -1;
}

// 21. Maximum size square sub-matrix with all 1s
// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

int max_sub_square(vector< vector<int> > matrix)
{
    int m = v.size();
    int n = v[0].size();

    vector< vector<int> > dp(m, vector<int>(n,0));
    int ans = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = matrix[i][j];
            else if(matrix[i][j])
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            else
                dp[i][j] = 0;
            
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

// 22. Ugly Number
// https://www.geeksforgeeks.org/ugly-numbers/
int uglyNumber(int n)
{
    int ans[n], ugly;
    ans[0] = 1;
    
    int i2,i3,i5;
    i2 = i3 = i5 = 0;

    int next_mul_2 = 2;
    int next_mul_3 = 3;
    int next_mul_5 = 5;

    for(int i=1; i<n; i++)
    {   
        ugly = min(next_mul_2, min(next_mul_3,next_mul_5));
        ans[i] = ugly;
        
        if(ans[i] == next_mul_2)
        {
            i2++;
            next_mul_2 = ans[i2]*2;
        }
        
        if(ans[i] == next_mul_3)
        {
            i3++;
            next_mul_3 = 3*ans[i3];
        }
        
        if(ans[i] == next_mul_5)
        {
            i5++;
            next_mul_5 = 5*ans[i5];
        }
        //cout << ans[i] << " " << i2 << " " << i3 << " " << i5 << " " << next_mul_2 << " " << next_mul_3 << " " << next_mul_5 << endl ;
        
    }

    return ans[n-1];
}

// 23. Largest Sum Contiguous Subarray
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// Note: Now Solve Problem 20

int max_sub_array_sum(int arr[], int n)
{
    int max_sum_so_far = INT_MIN;
    int max_ending = 0;

    for(int i=0; i<n; i++)
    {
        max_ending = max_ending + arr[i];

        if(max_sum_so_far < max_ending)
            max_sum_so_far = max_ending;
        
        if(max_ending < 0)
            max_ending = 0;
    }

    return max_sum_so_far;
}

// 24. Longest Palindromic Substring
// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

void longest_palindromic_substring(string str)
{
    int n = str.length();
    bool is_palindrome[n][n];
    int start = 0;
    int max_length = 1;

    for(int i=0; i<n; i++)
        is_palindrome[i][i] = true;
    
    // l: Lemgth of sub string
    for(int l = 2; l<=n; l++)
    {
        //cout << start << " " << max_length << endl;
        for(int i=0; i<=n-l+1; i++)
        {
            int j = i+l-1;
            if(str[i] == str[j] && i+1 == j)
            {
                is_palindrome[i][j] = true;
                if(max_length < l)
                {
                    start = i;
                    max_length = l;
                }
            }
            else if(str[i] == str[j] && is_palindrome[i+1][j-1])
            {
                is_palindrome[i][j] = true;
                if(max_length < l)
                {
                    start = i;
                    max_length = l;
                }
            }
            else
                is_palindrome[i][j] = false;
        }
    }

    string ans = str.substr(start, max_length);
    cout << ans << endl;
}

//-------------------------------------- I N C O M P L E T E ----------------------------------
// 25. Bellman–Ford Algorithm
// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
// After Graph
//---------------------------------------------------------------------------------------------

// 26. Optimal Binary Search Tree
// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/

int sum(int freq[], int i, int j)
{
    int sum = 0;
    for(int z=i; z<=j; z++)
        sum += freq[z];
    
    return sum;
}

// Method 1 Recursive Approach
// Basic formula opt_cost(i, j) = sum(freq, i, j) + min(opt_cost(i, r-1) + opt_cost(r+1, j)) #r is root(i to j)

int optimal_cost_recursive(int freq, int i, int j)
{
    if(j<i)
        return 0;
    
    if(j == i)
        return freq[i];
    
    int fsum = sum(freq, i, j);

    int min_cost = INT_MAX;

    for(int r=i; r<=j; i++)
    {
        int cost = optimal_cost_recursive(i,r-i) + optimal_cost_recursive(freq,r+i, j);
        min_cost = min(min_cost, cost);
    }

    return fsum + min_cost;
}

int optimal_cost_BST_recursive(int keys[], int freq[], int n)
{
    // Here array keys[] is assumed to be sorted in increasing order. If keys[]  
    // is not sorted, then add code to sort keys, and rearrange freq[] accordingly.  
    return optimal_cost_recursive(freq, 0, n - 1); 
}

// Method 2 DP

int optimal_cost_BST_dp(int keys[], int freq[], int n)
{
    // Here array keys[] is assumed to be sorted in increasing order. If keys[]  
    // is not sorted, then add code to sort keys, and rearrange freq[] accordingly.  
    
    int cost[n][n];

    for(int i=0; i<n; i++)
        cost[i][i] = freq[i];

    for(int l = 2; l<=n; l++)
    {
        for(int i=0; i<=n-l+1; i++)
        {
            int j = i+l-1;
            cost[i][j] = INT_MAX;
            
            int fsum_i_j = sum(freq, i, j);

            for(int r=i; r<=j; r++)
            {   
                int c = fsum_i_j; 
                // Case 1
                if(i<r)
                    c += cost[i][r-1];
                if(r<j)
                    c += cost[r+1][j];

                cost[i][j] = min(cost[i][j], c); 
            }
        }
    }

    return cost[0][n-1];
}

// 27. Largest Independent Set Problem 
// https://www.geeksforgeeks.org/largest-independent-set-problem-dp-26/

typedef struct _Btree
{
    int data;
    int lis; // For DP solution
    struct _Btree *left;
    struct _Btree *right;
}Btree;

int largest_independent_set_recursive(Btree *root)
{
    if(root == NULL)
        return 0;
    
    int size_exclude_root = largest_independent_set_recursive(root->left) +
                             largest_independent_set_recursive(root->right);
    
    int size_include_root = 1;

    if((root->left != NULL))
    size_include_root += largest_independent_set_recursive(root->left->left) + 
                            largest_independent_set_recursive(root->left->right);
    
    if((root->right != NULL))
    size_include_root += largest_independent_set_recursive(root->right->left) + 
                            largest_independent_set_recursive(root->right->right);

    return max( size_exclude_root, size_include_root);
}

int largest_independent_set_dp(Btree *root)
{
    if(root == NULL)
        return 0;
    
    if(root->lis)
        return root->lis;
    
    if(root->left == NULL && root->right == NULL)
    {
        root->lis = 1;
        return root->lis;
    }

    int size_exclude_root = largest_independent_set_dp(root->left) + largest_independent_set_dp(root->right);

    int size_include_root = 1;

    if((root->left != NULL))
    size_include_root += largest_independent_set_dp(root->left->left) + 
                            largest_independent_set_dp(root->left->right);
    
    if((root->right != NULL))
    size_include_root += largest_independent_set_dp(root->right->left) + 
                            largest_independent_set_dp(root->right->right);

    return max( size_exclude_root, size_include_root);
    
}

// 28. A Subset Sum Problem o(n*sum)
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

// Given a set of non-negative integers, and a value sum, 
// determine if there is a subset of the given set with sum equal to given sum.

int isSubSetSum_A(int set[], int n, int sum)
{
    bool dp[sum+1][n+1];

    for(int i=0; i>=sum; i++)
        dp[i][0] = false;
    
    for(int j=0; j<=n; j++)
        dp[0][j] = true;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            bool without = dp[i][j-1];
            bool with = (i>=set[j-1]) ? dp[i-set[j-1]][j-1] : false;

            dp[i][j] = with || without; 
        }
    }
    return dp[sum][n];
}

// 28. B Subset Sum Problem in O(sum) space
// https://www.geeksforgeeks.org/subset-sum-problem-osum-space/

int isSubSetSum_B(int set[], int n, int sum)
{
    bool dp[2][sum+1];

    for(int j=0; j<=sum; j++)
    {
        for(int i=0; i<=n; i++)
        {
            if(j==0)
                dp[i%2][j] = true;

            else if(i==0)
                dp[i][j] = false;
            
            else if(j >= set[i-1])
            {
                dp[i%2][j] = dp[(i+1)%2][j] || dp[(i+1)%2][j-set[i-1]];
            }
            else
            {
                dp[i%2][j] = dp[(i+1)%2][j];
            }
        }
    }

    return dp[n%2][sum];
}

// 29. Maximum sum rectangle in a 2D matrix 
// https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/

int kadane(int arr[], int *start, int *finish, int n)
{
    *finish = -1;
    
    int sum = 0;
    int max_sum = INT_MIN;
    int local_start = 0;

    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if(sum > max_sum)
        {
            max_sum = sum;
            *start = local_start;
            *finish = i;
        }
        //cout << sum << " " << max_sum << " " << *start << " " << *finish << " " << local_start << endl; 
    }

    if(*finish != -1)
        return max_sum;
    
    for(int i=0; i<n; i++)
    {
        if(max_sum < arr[i])
        {
            max_sum = arr[i];
            *start = i;
            *finish = i;
        }
    }
    //cout << *finish << " " << max_sum << endl;
    return max_sum;
}

int max_sum_rect(vector< vector<int> > matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int max_sum = INT_MIN, final_left, final_right, final_top, final_bottom;

    int tmp[row];
    int sum, start, finish;

    for(int left=0; left<col; left++)
    {
        memset(tmp, 0, sizeof(tmp));

        for(int right=left; right<col; right++)
        {

            for(int i=0; i<row; i++)
                tmp[i] = tmp[i] + matrix[i][right];
            
            //cout << right << endl;
            sum = kadane(tmp, &start, &finish, row);

            if (sum > max_sum)  
            {  
                max_sum = sum;  
                final_left = left;  
                final_right = right;  
                final_top = start;  
                final_bottom = finish;  
            }  
        }
    }
    return max_sum;
}

// 30. Count number of binary strings without consecutive 1’s
// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

int count_no_binary_consecutive_ones(int n)
{
    if(n<=0)
        return 0;
    if(n == 1)
        return 2;
    if(n == 2)
        return 3;

    int a = 2;
    int b = 3;

    int ans;

    for(int i=3; i<=n; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }

    return ans;
}

// 31. Boolean Parenthesization Problem
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

#define mod 1003

int count_boolean_parenthesization(char symbol[], char operators[], int n)
{
    int F[n][n];
    int T[n][n];

    for(int i=0; i<n; i++)
    {
        F[i][i] = (symbol[i] == 'F') ? 1 : 0;
        T[i][i] = (symbol[i] == 'T') ? 1 : 0;
    }

    for(int gap=1; gap<n; gap++)
    {   
        for(int i=0,j=gap; j<n; i++, j++)
        {
            T[i][j] = 0;
            F[i][j] = 0;

            for(int g=0; g<gap; g++)
            {
                int k = i + g;
                
                int tik = (T[i][k] + F[i][k]);
                int tkj = (T[k+1][j] + F[k+1][j]);

                if(operators[k] == '&')
                {
                    T[i][j] += (T[i][k]*T[k+1][j]);
                    F[i][j] += (tik*tkj) - (T[i][k]*T[k+1][j]);
                }
                
                if(operators[k] == '|')
                {
                    F[i][j] += (F[i][k]*F[k+1][j]);   
                    T[i][j] += (tik*tkj) - (F[i][k]*F[k+1][j]);
                }

                if(operators[k] == '^')
                {
                    T[i][j] += (F[i][k]*T[k+1][j]) + (T[i][k]*F[k+1][j]);
                    F[i][j] += (T[i][k]*T[k+1][j]) + (F[i][k]*F[k+1][j]);
                }
                
                T[i][j] = T[i][j]%mod;
                F[i][j] = F[i][j]%mod;
            }
        }
    }

    return T[0][n-1]%mod;
}

// 32. Count ways to reach the n'th stair
// https://www.geeksforgeeks.org/count-ways-reach-nth-stair/

#define print_matrix(x,n) for(int i=0; i<n; i++){ for(int j=0; j<n; j++) cout << x[i][j] << " "; cout << endl; }

long int  mod = 1000000007;

long int count(int n)
{
    if(n<=0)
        return 0;
    if(n<=2)
        return n;
        
    long int  mod = 1000000007;
    long int F[2][2] = {{1,1},{1,0}};
    long int M[2][2] = {{1,1},{1,0}};
    
    for(int i=2; i<=n/2; i++)
    {
        long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
        long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
        long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
        long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
        F[0][0] = x%mod; 
        F[0][1] = y%mod; 
        F[1][0] = z%mod; 
        F[1][1] = w%mod;
        
        //print_matrix(F,2)
    }

    long int x =  F[0][0]*F[0][0] + F[0][1]*F[1][0]; 
    long int y =  F[0][0]*F[0][1] + F[0][1]*F[1][1]; 
    long int z =  F[1][0]*F[0][0] + F[1][1]*F[1][0]; 
    long int w =  F[1][0]*F[0][1] + F[1][1]*F[1][1]; 
  
    F[0][0] = x%mod; 
    F[0][1] = y%mod; 
    F[1][0] = z%mod; 
    F[1][1] = w%mod;
    
    if(n%2)
    {
        x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
        y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
        z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
        w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
        F[0][0] = x%mod; 
        F[0][1] = y%mod; 
        F[1][0] = z%mod; 
        F[1][1] = w%mod;
    }
    
    return F[0][0]%mod;
}

// 33. Minimum Cost Polygon Triangulation
// https://www.geeksforgeeks.org/minimum-cost-polygon-triangulation/

struct Point
{
    int x,y;
};

double dist(Point p1, Point p2) 
{ 
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + 
                (p1.y - p2.y)*(p1.y - p2.y)); 
}

double cost_triangle(Point points[], int i, int k, int j)
{
    double l1 = dist(points[i], points[k]);
    double l2 = dist(points[j], points[k]);
    double l3 = dist(points[i], points[j]);

    return l1+l2+l3;
}

double min_cost_polygon(Point points[], int n)
{
    if(n<3)
        return 0;
    
    double cost_table[n][n];

    for(int sides = 0; sides<n; sides++)
    {
        for(int i=0, j=sides; j<n; i++, j++ )
        {
            if(j<i+2)
                cost_table[i][j] = 0.0;
            else
            {
                cost_table[i][j] = INT_MAX;
                for(int k=i+1; k<j; k++)
                {
                    cost_table[i][j] = min(cost_table[i][j], 
                                        cost_table[i][k] + cost_table[k][j] + 
                                        cost_triangle(points, i, k, j));
                }
            }
            
        }
    }

    return cost_table[0][n-1];
}

// 34. Mobile Numeric Keypad Problem
// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/

int count_mobile_number(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 10;

    char keypad[4][3] = {
                         {'1', '2', '3'},
                         {'4', '5', '6'}, 
                         {'7', '8', '9'}, 
                         {'*', '0', '#'}
                        };
    
    int row[] = {0, 0, 0, -1, 1};
    int col[] = {0, 1, -1, 0, 0};

    int count[10][n+1];

    for(int i=0; i<10; i++)
    {
        count[i][0] = 0;
        count[i][1] = 10;
    }

    for(int i=2; i<=n; i++)
    {
        
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<3; k++)
            {
                if(keypad[j][k] >= '0' && keypad[j][k] <= '9')
                {
                    int num = keypad[j][k]-'0'; 
                    count[num][i] = 0;

                    for(int move=0; move<5; move++)
                    {
                        int x = j + row[move];
                        int y = k + col[move];

                        if(x>=0 && x<4 && y>=0 && y<3)
                        {
                            if(keypad[x][y] >= '0' && keypad[x][y] <= '9')
                                count[num][i] += count[keypad[x][y]-'0'][i-1];
                        } 
                    }
                }
            }
        }
    }    
    
    int ans = 0;
    for(int i=0; i<10; i++)
        ans += count[i][n];
    
    return ans;
}

// 35. Count of n digit numbers whose sum of digits equals to given sum
// https://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/

// 1 <= n <= 100 and 1 <= sum <= 500

// A lookup table used for memoization 
unsigned long long int lookup[101][501];

unsigned long long int count_numbers(int n, int sum)
{
    if(n==0 && sum == 0)
        return 1;
    if(n==0)
        return 0;
    if(lookup[n][sum] != -1)
        return lookup[n][sum];
    
    unsigned long long int ans;

    // Number's second digit will vary from 0 to 9
    for(int i=0; i<10; i++)
    {
        if(sum >=i)
        {
            ans += count_numbers(n-1, sum-i);
        }
    }

    lookup[n][sum] = ans;
    return ans;
}

unsigned long long int count_n_digits_sum(int n, int sum)
{
    memset(lookup, -1, sizeof(lookup) );

    unsigned long long int ans;

    // Numbers begin from 1 to 9
    for(int i=1; i<=9; i++)
    {
        if(sum >=i)
        {
            ans += count_numbers(n-1, sum-i);
        }
    }
    return ans;
}

// 36.Minimum Initial Points to Reach Destination
// https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

int min_initial_points(vector< vector<int> > matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int points[m][n];

    points[m-1][n-1] = (matrix[m-1][n-1]>0) ? 1 : abs(matrix[m-1][n-1])+1; 
    
    for(int i=n-2; i>=0; i--)
        points[m-1][i] = max(points[m-1][i+1] - matrix[m-1][i], 1);

    for(int i=m-2; i>=0; i--)
        points[i][n-1] = max(points[i+1][n-1] - matrix[i][n-1], 1);

    for(int i=m-2; i>=0; i--)
    {
        for(int j=n-2; j>=0; j--)
        {
            int min_exit_point = min(points[i+1][j], points[i][j+1]);
            points[i][j] = max(min_exit_point - matrix[i][j], 1);
        }
    }

    return points[0][0];
}

// 37. Total number of non-decreasing numbers with n digits
// https://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/

// url: https://ide.geeksforgeeks.org/LTOHzIEbR2

int total_number_non_decreasing(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 10;
        
    int count[10][n+1];

    for(int i=0; i<10; i++)
    {
        count[i][0] = 0;
        count[i][1] = 1;
    }    
    
    for(int j=2; j<=n; j++)
    {
        for(int i=0; i<10; i++)
        {
            count[i][j] = 0;
            for(int k=0; k<=i; k++)
            {
                count[i][j] += count[i-k][j-1];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<10; i++)
        ans += count[i][n];
    
    return ans;
}

// 38. Find length of the longest consecutive path from a given starting character
// https://www.geeksforgeeks.org/find-length-of-the-longest-consecutive-path-in-a-character-matrix/

#define M_38 10
#define N_38 10

int dp_38[M_38][N_38];

int row[] = {0, 1, 1, -1, 1, 0, -1, -1}; 
int col[] = {1, 0, 1, 1, -1, -1, 0, -1}; 

bool is_valid(int i, int j, int m, int n)
{
    return (i>=0 && i<m && j>=0 && j<n);
}

bool is_adjacent(char curr, char prev)
{
    return ((curr - prev) == 1);
}

int get_len_util(vector< vector<char> > matrix,int i, int j, char start_char)
{
    int m = matrix.size();
    int n = matrix[0].size();

    if(!is_valid(i,j,m,n))
        return 0;
    if(!is_adjacent(matrix[i][j], start_char))
        return 0;

    if(dp_38[i][j] != -1)
        return dp_38[i][j];
    
    int ans = 0;

    for(int move=0; move<8; move++)
    {
        int len_move = 1 + get_len_util(matrix, i+row[move], j+col[move], start_char);
        ans = max(ans, len_move);
    }
    
    dp_38[i][j] = ans;

    return ans;
}

int get_max_len(vector< vector<char> > matrix, char start_char)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = 0;

    memset(dp_38, -1, sizeof(dp_38));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j] == start_char)
            {
                for(int move=0; move<8; move++)
                {
                    int len_move = 1 + get_len_util(matrix, i+row[move], j+col[move], start_char);
                    ans = max(ans, len_move);
                }
            }
        }
    }

    return ans;
}

// 39. Tiling Problem
// Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles.
// https://www.geeksforgeeks.org/tiling-problem/
int count_tiling(int n)
{
    int count[n+1];
    count[0] = 0;
    count[1] = 1;
    count[2] = 2;

    for(int i=3; i<=n; i++)
    {
        count[i] = count[i-2]+count[i-1];
    }
    return count[n];
}

// 40. Minimum number of squares whose sum equals to given number n
// https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/

int get_minsquares(int n)
{
    if(n<=0)
        return 0;
    if(n<3)
        return n;
    
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++)
    {
        dp[i] = i;
        for(int j=1; j*j<=i; j++)
            dp[i] = min(dp[i], 1 + dp[i-j*j]);
    }
    
    return dp[n];
}

// 41. Find minimum number of coins that make a given value
// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

int min_no_coins(int change[], int n, int v)
{
    if(v==0 || n==0)
        return 0;
    
    int dp[v+1];
    dp[0] = 0;

    for(int i=1; i<=v; i++)
    {
        dp[i] = INT_MAX;
        for(int j=0; j<n; j++)
        {
            if( i >= change[j] && dp[i-change[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i-change[j]]);
            }
        }
    }
    
    if(dp[v] == INT_MAX)
        dp[v] = -1;
    return dp[v];
}

// 42. Collect maximum points in a grid using two traversals
// https://www.geeksforgeeks.org/collect-maximum-points-in-a-grid-using-two-traversals/

// A Memoization based program to find maximum collection 
// using two traversals of a grid 

#define R 5 
#define C 4 
  
// checks whether a given input is valid or not 
bool isValid(int x, int y1, int y2) 
{ 
    return (x >= 0 && x < R && y1 >=0 && 
            y1 < C && y2 >=0 && y2 < C); 
} 
  
// Driver function to collect max value 
int getMaxUtil(int arr[R][C], int mem[R][C][C], int x, int y1, int y2) 
{ 
    /*---------- BASE CASES -----------*/
    // if P1 or P2 is at an invalid cell 
    if (!isValid(x, y1, y2)) return INT_MIN; 
  
    // if both traversals reach their destinations 
    if (x == R-1 && y1 == 0 && y2 == C-1) 
       return (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2]; 
  
    // If both traversals are at last row but not at their destination 
    if (x == R-1) return INT_MIN; 
  
    // If subproblem is already solved 
    if (mem[x][y1][y2] != -1) return mem[x][y1][y2]; 
  
    // Initialize answer for this subproblem 
    int ans = INT_MIN; 
  
    // this variable is used to store gain of current cell(s) 
    int temp = (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2]; 
  
    /* Recur for all possible cases, then store and return the 
       one with max value */
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2-1)); 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2+1)); 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2)); 
  
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2)); 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2-1)); 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2+1)); 
  
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2)); 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2-1)); 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2+1)); 
  
    return (mem[x][y1][y2] = ans); 
} 
  
// This is mainly a wrapper over recursive function getMaxUtil(). 
// This function creates a table for memoization and calls 
// getMaxUtil() 
int geMaxCollection(int arr[R][C]) 
{ 
    // Create a memoization table and initialize all entries as -1 
    int mem[R][C][C]; 
    memset(mem, -1, sizeof(mem)); 
  
    // Calculation maximum value using memoization based function 
    // getMaxUtil() 
    return getMaxUtil(arr, mem, 0, 0, C-1); 
} 
 
// 43. Shortest Common Supersequence
// https://www.geeksforgeeks.org/shortest-common-supersequence/

// Method 1
int shortest_common_supersequence_1(string a, string b)
{
    int m = a.length();
    int n = b.length();

    // 2. Longest Common subsequence
    int l = LCS(a,b);

    return m+n-l;
}

// Method 2
int shortest_common_supersequence_2(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

// 44. Compute sum of digits in all numbers from 1 to n
// https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/

// Formula: sum(10^d - 1) = sum(10^(d-1) - 1) * 10 + 45*(10^(d-1)) 

int sum_of_digits(int n)
{
    if(n<=0)
        return 0;

    if(n<10)
        return n*(n+1)/2;
    
    int d = log10(n);

    int sum_9n[d+1];
    sum_9n[0] = 0;
    sum_9n[1] = 45;

    for(int i=2; i<=d; i++)
    {
        sum_9n[i] = sum[i-1]*10 + 45*(ceil(pow(10,i-1)));
    }

    int p = ceil(pow(10,d));
    // most significant digit msd
    int msd = n/p;

    // EXPLANATION FOR FIRST and SECOND TERMS IN BELOW LINE OF CODE 
    // First two terms compute sum of digits from 1 to 299

    // EXPLANATION FOR THIRD AND FOURTH TERMS IN BELOW LINE OF CODE 
    // The last two terms compute sum of digits in number from 300 to 328 
    // Third term (300 + 301 + ..... 328) = 3*29 + (1+2+3+.....28)
    return msd*sum_9n[d] + (msd*(msd-1)/2)*p +
           msd*(1+n%p) + sum_of_digits(n%p);
}

// 45. Count possible ways to construct buildings
// https://www.geeksforgeeks.org/count-possible-ways-to-construct-buildings/

int count_building_ways(int n)
{
    if(n<=0)
        return 0;
    
    if(n == 1)
        return 4;
    
    int count_B = 1;
    int count_S = 1;
    int prev_count_B, prev_count_S;

    for(int i=2; i<=n; i++)
    {
        prev_count_B = count_B;
        prev_count_S = count_S;

        count_B = prev_count_S;
        count_S = prev_count_B + prev_count_S;
    }

    int res = count_B + count_S;

    return res*res;
}

// 46. Maximum profit by buying and selling a share at most twice
// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

// final_profit => profit(0 to i) + profit(i, n-1) 

int max_profit(int price[], int n)
{
    int profit[n];
    memset(profit, 0, sizeof(profit));

    // fill 2nd transaction 
    // profit(i to n-1)
    int max_price = price[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(price[i] > max_price)
            max_price = price[i];
        
        profit[i] = max(profit[i+1], max_price-price[i]); 
    }

    // fill overall transaction through 2nd transaction
    // final_profit => profit(0 to i-1) + profit(i, n-1)
    int min_price = price[0];
    for(int i=1; i<n; i++)
    {
        if(price[i] < min_price)
            min_price = price[i];
        
        // profit[i] stores profit from 0 to i
        profit[i] =  max(profit[i-1], profit[i] + price[i] - min_price );
    }

    return profit[n-1];
}

// 47. How to print maximum number of A’s using given four keys
// https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/

// Method 1 Recursive
int find_optimal_recursive(int n)
{
    if(n<=0)
        return 0;
    if(n<7)
        return n;

    int ans = 0;
    for(int i=n-3; i>=1; i--)
    {
        int curr = (n-i-1)*find_optimal_recursive(i);
        ans = max(ans, curr);
    }

    return ans;
}

// Method 2 DP
int find_optimal_dp(int n)
{
    if(n>75)
        return -1;
        
    if(n<=0)
        return 0;
    if(n<7)
        return n;

    int dp[n+1];

    for(int i=0; i<7; i++)
        dp[i] = i;
    
    for(int i=7; i<=n; i++)
    {
        dp[i] = 0;
        for(int j=i-3; j>=1; j--)
        {
            int curr = (i-j-1)*dp[j];
            dp[i] = max(curr, dp[i]);
            //cout << j << " " << curr << " " << dp[i] << endl;
        }
        //cout << i << " " << dp[i] << endl; 
    }

    return dp[n];
}

// 48. Find the minimum cost to reach destination using a train
// https://www.geeksforgeeks.org/find-the-minimum-cost-to-reach-a-destination-where-every-station-is-connected-in-one-direction/

int min_train_fare(vector< vector<int> > cost)
{
    int n = cost.size();
    
    int fare[n];
    fare[0] = 0;

    for(int i=1; i<n; i++)
    {
        fare[i] = cost[0][i];

        for(int j=1; j<i; j++)
        {
            fare[i] = min(fare[i], fare[j] + cost[j][i]);
        }
    }

    return fare[n-1];
}

//------------------------------------- I N C O M P L E T E -----------------------------------
// 49. Vertex Cover Problem | Set 2 (Dynamic Programming Solution for Tree)
// https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/
//---------------------------------------------------------------------------------------------

// 50. Count number of ways to reach a given score in a game
// https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/

// Consider a game where a player can score 3 or 5 or 10 points in a move. 
// Given Total score

// If you consider (5,3) and (3,5) as different permutations
int count_ways_score_A(int n)
{
    if(n<3)
        return 0;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;

    for(int i=3; i<=n; i++)
    {
        dp[i] = 0;

        if(i>=10)
        {
            dp[i] += dp[i-10];
        }

        if(i>=5)
        {
            dp[i] += dp[i-5];
        }

        if(i>=3)
        {
            dp[i] += dp[i-3];
        }
    }

    return dp[n]; 
}

// If you consider (5,3) and (3,5) as same permutations
int count_ways_score_B(int n)
{
    if(n<3)
        return 0;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;

    // score by move = 3, move{3}
    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-3];
    }

    // score by move = 5, move{3,5}
    // if n = 8, {{3,5}} #last score by move = 5 
    for(int i=5; i<=n; i++)
    {
        dp[i] += dp[i-5];
    }

    // score by move = 10, move{3,5,10} 
    for(int i=10; i<=n; i++)
    {
        dp[i] += dp[i-10];
    }

    return dp[n]; 
}

// 51. Weighted Job Scheduling
// https://www.geeksforgeeks.org/weighted-job-scheduling/

struct Job
{
    int start, finish, profit;
};

// sort in ascending order
bool job_comparataor(Job a, Job b)
{
    return (b.finish > a.finish);
}

int latest_non_conflicting_job(Job arr[], int i)
{
    for(int j=i-1; j>=0; j--)
    {
        if(arr[j].finish <= arr[i-1].start)
            return j;
    }

    return -1;
}

int find_max_profit(Job arr[], int n)
{
    sort(arr, arr+n, job_comparataor);

    int table[n];
    table[0] = arr[0].profit;
    
    for(int i=1; i<n; i++)
    {
        int include_job = arr[i].profit;
        int latest_job = latest_non_conflicting_job(arr, i);
        if(latest_job != -1)
            include_job += table[latest_job];  

        table[i] = max(include_job, table[i-1]);
    }

    return table[n-1];
}

// 52. Longest Even Length Substring such that Sum of First and Second Half is same
// https://www.geeksforgeeks.org/longest-even-length-substring-sum-first-second-half/

// Method 1 Naive Approach
int find_length_A(string str)
{
    int n = str.length();
    int max_len = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j=j+2)
        {
            int length = j-i+1;
            int left_sum = 0, right_sum = 0;
            for(int x=0; x<length/2; x++)
            {
                left_sum += str[i+x] - '0';
                right_sum += str[i+length/2+x] - '0'; 
            }

            if(left_sum == right_sum && max_len < length)
                max_len = length;
        }
    }

    return max_len;
}

// Method 2 DP 
// O(n2) and O(n2) extra space
int find_length_B(string str)
{
    int n = str.length();

    int sum[n][n];

    int max_len = 0;
    for(int i=0; i<n; i++)
    {
        sum[i][i] = str[i]-'0';
    }

    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j=i+l-1;
            sum[i][j] = sum[i][i+l/2 -1] + sum[i+l/2][j];

            if(l%2 == 0 && sum[i][i+l/2 -1] == sum[i+l/2][j] && max_len < l)
                max_len = l;
        }
    }

    return max_len;
}

// Method 3 DP 
// O(n2) and O(n) extra space
int find_length_C(string str)
{
    int n = str.length();

    int max_len = 0;
    
    int sum[n+1];
    sum[0] = 0;

    for(int i=1; i<=n; i++)
        sum[i] = sum[i-1] + str[i]-'0';

    for(int l=2; l<=n; l = l+2)
    {
        for(int i=0; i<n-l+1; i++)
        {
            int j=i+l-1;
            
            int left_sum = sum[i+l/2] - sum[i];
            int right_sum = sum[i+l] - sum[i+l/2];

            if(left_sum  == right_sum  && max_len < l)
                max_len = l;
        }
    }

    return max_len;
}

// Method 4 consider all possible mid points (of even length substrings)
//  O(n2) time and O(1) extra space solution
int find_length_D(string str)
{
    int n = str.length();
    int max_len = 0;
    

    for(int i=0; i<=n-2; i++)
    {   
        int left = i, right = i+1;

        int left_sum = 0;
        int right_sum = 0;

        while(right<n && left>=0)
        {
            left_sum = str[left] - '0';
            right_sum = str[right] - '0';
            if(left_sum == right_sum)
            {
                int len = 2*(right-i);
                max_len = max(len, max_len);
            }

            left--;
            right++;
        }
        
    }

    return max_len;
}



// 53. Program for nth Catalan Number
// https://www.geeksforgeeks.org/program-nth-catalan-number/
unsigned long int catalan(int n)
{
    unsigned long int cat[n+1];
    cat[0] = 1;
    cat[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        cat[i] = 0;
        for(int j=0; j<i; j++)
        {
            cat[i] += cat[j]*cat[i-j-1]; 
        }
    }
    return cat[n];
}

// 54. Bell Numbers (Number of ways to Partition a Set)
// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
int bellNumber(int n) 
{ 
   int bell[n+1][n+1]; 
   bell[0][0] = 1; 
   for (int i=1; i<=n; i++) 
   { 
      bell[i][0] = bell[i-1][i-1]; 
  
      for (int j=1; j<=i; j++) 
         bell[i][j] = bell[i-1][j-1] + bell[i][j-1]; 
   } 
   return bell[n][0]; 
} 

// 55. Gold Mine Problem
// https://www.geeksforgeeks.org/gold-mine-problem/ 

bool check_coord(int i, int j, int row, int column)
{
    if(i >=0 && i <= row-1 && j >=0 && j<=column-1)
        return true;
    
    return false;
}

int get_max_gold(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();

    vector< vector<int> > goldTable(n, vector<int> (m,0));

    for(int i=m-1; i>=0; i--)
    {
        for(int j=0; j<n; j++)
        {
            int right_top = 0;
            int right = 0;
            int right_bottom = 0;

            if(check_coord(j-1,i+1,n,m))
                right_top = goldTable[j-1][i+1];
            if(check_coord(j,i+1,n,m))
                right = goldTable[j][i+1];
            if(check_coord(j+1,i+1,n,m))
                right_bottom = goldTable[j+1][i+1];

            goldTable[j][i] = v[j][i] + max(right, max(right_bottom, right_top));
            
            //cout << goldTable[j][i] << " ";
        }
        //cout << endl;
    }

    int max_gold=0;

    for(int j=0; j<n; j++)
    {
        max_gold = max(max_gold, goldTable[j][0]);
    }

    return max_gold;
}


// 56. Friends Pairing Problem
// Given n friends, each one can remain single or can be paired up with some other friend. 
// Total no of count 
// https://www.geeksforgeeks.org/friends-pairing-problem/
int countFriendsPairings(int n)
{
    if(n<3) return n;

    int count[n+1];
    count[0] = 0;
    count[1] = 1;
    count[2] = 2;

    for(int i=3; i<=n; i++)
    {
        int single = count[i-1];
        int paired = count[i-2]*(i-1);

        count[i] = single + paired;    
    }
    return count[n];
}

// 57. Subset Sum Problem Given a set of non-negative integers, and
// a value sum, determine if there is a subset of the given set with sum equal to given sum.
// Method 1 O(n*sum)
bool isSubsetSum(vector<int> set, int sum)
{
    int n = set.size();
    bool dp[sum+1][n+1];
    
    for(int i=0; i<=n; i++)
        dp[0][i] = true;
    
    for(int i=1; i<=sum; i++)
        dp[i][0] = false;
    
    for(int i=1; i<=sum; i++)
    {
        for(int j=1; j<=n; j++)
        {
            bool without = dp[i][j-1];
            bool with = (i-set[j-1]>=0) ? dp[i-set[j-1]][j-1] : false;

            dp[i][j] = with || without;
        }
    }

    return dp[sum][n];
} 
// Method 2 O(2*sum)
// Hint: “subset[2][sum+1]” is that for filling a row only the values from previous row is required. 
bool isSubsetSum_2(vector<int> v, int sum)
{
    int n = v.size(); 
    vector< vector<bool> > isSumTable(2, vector<bool>(sum+1,false));

    for(int j=0; j<=sum; j++)
    {
        for(int i=0; i<=n; i++)
        {
            if(j == 0)
                isSumTable[i][j] = true;
            else if(i == 0)
                isSumTable[0][j] = false;
            else if(j >= v[i-1])
            {
                isSumTable[i%2][j] = isSumTable[(i+1)%2][j] || isSumTable[(i+1)%2][j-v[i-1]];
            }
            else
            {
                isSumTable[i%2][j] = isSumTable[(i+1)%2][j];
            }
        }
    }
    return isSumTable[n%2][sum];
}