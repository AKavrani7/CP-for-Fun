#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int max_size;

void print_st(int *st)
{
    int i = 0;
    while(i<max_size)
    {
        cout << st[i] << " ";
        i++;
    }
    
    cout << endl;
}

int updateUtil(int *st, int A[], int s, int e, int i, int index)
{
    if(i<s || i>e) // ..i.. s...e.. or ...s...e.. i..
        return INT_MIN;
    
    // ...s..i...e..
    
    if(s == e)
    {
        st[index] = A[s];
        return st[index]; 
    }
    
    int mid = s + (e-s)/2;
    int val1 = updateUtil(st, A, s, mid, i, index*2+1);
    int val2 = updateUtil(st, A, mid+1, e, i, index*2+2);
    
    // val1 = st[2*index+1] 
    // val2 = st[2*index+2]
    
    st[index] = max(val1, val2);
    
    return st[index];
}

void update(int *st, int A[], int n, int i, int val)
{
    if(i<0 || i>=n) return;
    
    A[i] = val;
    
    updateUtil(st, A, 0, n-1, i, 0);
}

int getMaximumUtil(int *st, int s, int e, int l, int r, int index)
{
    if( l>e || r<s )  // ...s..e..l..r.. || ...l..r..s..e..
        return INT_MIN;   
    if( l<=s && r>=e )      // ...l.. s...e ..r... part of the solution
        return st[index];
    
    int mid = s + (e-s)/2;
    
    // ...s..[l..r]..e... overlap
    int val1 = getMaximumUtil(st, s, mid, l, r, index*2+1);
    int val2 = getMaximumUtil(st, mid+1, e, l, r, index*2+2);
    
    // val1 = st[2*index+1] 
    // val2 = st[2*index+2]
    
    return max(val1, val2);
}

int getMaximum(int *st, int n, int l, int r)
{
    if(l<0 || r<0 || l>=n || r>=n || l>r) return -1;
    
    return getMaximumUtil(st, 0, n-1, l, r, 0);
}

int construct_STUtil(int A[], int *st, int s, int e, int index)
{
    if(s == e)
    {
        st[index] = A[s];
        return st[index];
    }
    
    int mid = s + (e-s)/2;
    int val1 = construct_STUtil(A, st, s, mid, 2*index+1);  
    int val2 = construct_STUtil(A, st, mid+1, e, 2*index+2);
    
    st[index]  = max(val1, val2);  
    // val1 = st[2*index+1] 
    // val2 = st[2*index+2]
    
    return st[index];
}

int* construct_ST(int A[], int n)
{
    int h = (int)(ceil(log2(n)));
    max_size = 2*(int)pow(2,h) - 1;
    
    int *st = new int[max_size];
    
    construct_STUtil(A, st, 0, n-1, 0);
    
    return st;
}

int main() {
	
	// Segment Tree | Set 2 Range Maximum Query with Node Update
	// https://ide.geeksforgeeks.org/q1uK45jADs
	// https://www.geeksforgeeks.org/segment-tree-set-2-range-maximum-query-node-update/?ref=rp

	int n; cin >> n;
	int A[n]; for(int i=0; i<n; i++) cin >> A[i];
	
	int *st = construct_ST(A, n);
	
	print_st(st);
	
	cout << "find Maximum from index 2 to 6: " << getMaximum(st, n, 2, 6) << endl;
	cout << "update value A[4] = 10" << endl;
	update(st, A, n, 4, 10);
	cout << "find Maximum from index 2 to 6: " << getMaximum(st, n, 2, 6) << endl;
	
	return 0;
}