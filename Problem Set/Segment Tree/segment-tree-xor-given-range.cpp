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


void updateUtil(int *st, int A[], int s, int e, int i, int index, int prv)
{
    
    if(i<s || i>e) // ..i.. s...e.. or ...s...e.. i..
        return;
        
    // ...s..i...e..
    
    
    st[index] = (st[index]^A[i])^prv;
    
    if(s == e) return;
    
    int mid = s + (e-s)/2;
    updateUtil(st, A, s, mid, i, index*2+1, prv);
    updateUtil(st, A, mid+1, e, i, index*2+2, prv);
}


void update(int *st, int A[], int n, int i, int val)
{
    if(i<0 || i>=n) return;
    
    int prv = A[i];
    A[i] = val;
    
    updateUtil(st, A, 0, n-1, i, 0, prv);
}

int getXORUtil(int *st, int s, int e, int l, int r, int index)
{
    if( l>e || r<s )  // ...s..e..l..r.. || ...l..r..s..e..
        return 0;   
    if( l<=s && r>=e )      // ...l.. s...e ..r... part of the solution
        return st[index];
    
    int mid = s + (e-s)/2;
    
    // ...s..[l..r]..e... overlap
    int val1 = getXORUtil(st, s, mid, l, r, index*2+1);
    int val2 = getXORUtil(st, mid+1, e, l, r, index*2+2);
    
    return val1 ^ val2;
}

int getXOR(int *st, int n, int l, int r)
{
    if(l<0 || r<0 || l>=n || r>=n || l>r) return -1;
    
    return getXORUtil(st, 0, n-1, l, r, 0);
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
    
    st[index]  = val1 ^ val2;
    
    return st[index];
}

int* construct_ST(int A[], int n)
{
    int h = (int)(ceil(log2(n)));
    max_size = 2*pow(2,h)-1;
    
    int *st = new int[max_size];
    
    construct_STUtil(A, st, 0, n-1, 0);
    
    return st;
}

int main() {
	
    // https://www.geeksforgeeks.org/segment-tree-xor-given-range/
    // Segment Tree | (XOR of given range)
    // https://ide.geeksforgeeks.org/RzxjdZ8Lzp
    
	int n; cin >> n;
	int A[n]; for(int i=0; i<n; i++) cin >> A[i];
	
	int *st = construct_ST(A, n);
	print_st(st);
	
	cout << "find XOR from index 0 to 2: " << getXOR(st, n, 0, 2) << endl;
	
	cout << "update value A[1] = 10" << endl;
	update(st, A, n, 1, 10);
	print_st(st);
	
	cout << "find count from index 0 to 2: " << getXOR(st, n, 0, 2) << endl;
	
	return 0;
}