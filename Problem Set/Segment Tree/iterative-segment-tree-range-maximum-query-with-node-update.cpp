#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max_size;

void print_st(vector<int> st)
{
    int i = 0;
    while(i<max_size)
    {
        cout << st[i] << " ";
        i++;
    }
    
    cout << endl;
}

void update(vector<int> &st, int n, int i, int val)
{
    if(i<0 || i>=n) return;
    
    i +=n;
    st[i] = val;
    
    while(i>1)
    {
        i = i/2;
        st[i] = max(st[2*i], st[2*i+1]);
    }
}

int getMaximum(vector<int> st, int n, int l, int r)
{
    if(l<0 || r<0 || l>=n || r>=n || l>r) return -1;
    
    int ans = INT_MIN;
    l += n; r += n;
    
    while(l<r)
    {
        if(l & 1) { ans = max(ans, st[l]);  l++;  }
        if(r & 1) { r--;  ans = max(ans, st[r]);  }
        l /= 2; r /= 2;
    }
    return ans;
}

vector<int> construct_ST(vector<int> A, int n)
{
    max_size = 2*n;
    vector<int> st(2*n);
    for(int i=0; i<n; i++)
        st[n+i] = A[i];
        
    for(int i=n-1; i>=1; i--)
        st[i] = max(st[2*i], st[2*i+1]);
    
    return st;
}

int main() {
	
	// Iterative Segment Tree (Range Maximum Query with Node Update)
	// https://ide.geeksforgeeks.org/FpZMFzCmWN
	// https://www.geeksforgeeks.org/iterative-segment-tree-range-maximum-query-with-node-update/?ref=rp

	int n; cin >> n;
	vector<int> A(n); for(int i=0; i<n; i++) cin >> A[i];
	
	vector<int> st = construct_ST(A, n);
	
	print_st(st);
	
	cout << "find Maximum from index 2 to 6: " << getMaximum(st, n, 2, 6+1) << endl;
	A[4] = 50;
	cout << "update value A[4] = 50" << endl;
	update(st, n, 4, 50);
	cout << "find Maximum from index 2 to 6: " << getMaximum(st, n, 2, 6+1) << endl;
	
	return 0;
}