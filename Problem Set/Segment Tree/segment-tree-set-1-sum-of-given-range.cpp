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

void updateUtil(int *st, int s, int e, int i, int diff, int index)
{
    if(i<s || i>e) // ..i.. s...e or ...s...e.. i..
        return;
    
    st[index] += diff;
    
    if(s == e) return;
    
    int mid = s + (e-s)/2;
    updateUtil(st, s, mid, i, diff, index*2+1);
    updateUtil(st, mid+1, e, i, diff, index*2+2);
}

void update(int *st, int A[], int n, int i, int val)
{
    if(i<0 || i>=n) return;
    
    int diff = val - A[i];
    A[i] = val;
    
    updateUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int *st, int s, int e, int l, int r, int index)
{
    if( l>e || r<s )  // ...s..e..l..r.. || ...l..r..s..e..
        return 0;   
    if( l<=s && r>=e )      // ...l.. s...e ..r... reverse formation
        return st[index];
    
    int mid = s + (e-s)/2;
    
    // ...s..[l..r]..e... overlap
    return getSumUtil(st, s, mid, l, r, index*2+1)
        +  getSumUtil(st, mid+1, e, l, r, index*2+2);
}

int getSum(int *st, int n, int l, int r)
{
    if(l<0 || r<0 || l>=n || r>=n || l>r) return -1;
    
    return getSumUtil(st, 0, n-1, l, r, 0);
}

int construct_STUtil(int A[], int *st, int s, int e, int index)
{
    if(s == e)
    {
        st[index] = A[s];
        return st[index];
    }
    
    int mid = s + (e-s)/2;
    st[index]  = construct_STUtil(A, st, s, mid, 2*index+1) +
                 construct_STUtil(A, st, mid+1, e, 2*index+2);
    
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
	
	
	// https://ide.geeksforgeeks.org/WxhvtV2H9m
	// https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
	
	int n; cin >> n;
	int A[n]; for(int i=0; i<n; i++) cin >> A[i];
	
	int *st = construct_ST(A, n);
	
	print_st(st);
	
	cout << "sum from index 2 to 6: " << getSum(st, n, 2, 6) << endl;
	cout << "update value A[4] = 10: " << endl;
	update(st, A, n, 4, 10);
	cout << "sum from index 2 to 6: " << getSum(st, n, 2, 6) << endl;
	
	return 0;
}