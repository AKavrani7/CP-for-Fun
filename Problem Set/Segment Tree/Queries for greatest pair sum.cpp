#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int max_size, n;
vector<pair<int,int>> st; // max_val, greatestPsum

pair<int,int> util_findGpairSum(int s, int e, int l, int r, int index)
{
    if(l>e || s>r)          //...s..e ..l..r or ..l..r.. s..e..
        return {INT_MIN, INT_MIN};
        
    if(s>=l && r>=e)        //...l ..s..e.. r..
        return st[index];
        
    //..l..s..r..e.. or ...s..l..e..r..
    int m = s + (e-s)/2;
    
    pair<int, int> p1 = util_findGpairSum(s, m, l, r, 2*index+1);
    pair<int, int> p2 = util_findGpairSum(m+1, e, l, r, 2*index+2);
    
    pair<int,int> p;
    p.F = max(p1.F, p2.F);
    p.S = max( {p1.F+p2.F, p1.S, p2.S} );
    return p;
}


int findGpairSum(int l, int r)
{
    if(l<0 || r<0 || l>=n || r>=n || l>r) return 0;
    
    return util_findGpairSum(0, n-1, l, r, 0).S;
}

void fill_tree(int A[], int s, int e, int index)
{
    if(s == e)
    {
        st[index].F = A[s];
        st[index].S = A[s];
        return;
    }
    
    int m = s + (e-s)/2;
    
    fill_tree(A, s, m, index*2+1);
    fill_tree(A, m+1, e, index*2+2);
    
    st[index].F = max(st[2*index+1].F, st[2*index+2].F);
    
    st[index].S = max( { 
                         st[2*index+1].F + st[2*index+2].F
                        ,st[2*index+1].S 
                        ,st[2*index+2].S 
                       }
                    );
}

void buildTree(int A[])
{
    int h = (int)(ceil(log2(n)));
    max_size = 2*pow(2,h) - 1;
    
    st.resize(max_size);
    fill_tree(A, 0, n-1, 0);
}

int main() {

    // https://www.geeksforgeeks.org/queries-for-greatest-pair-sum-in-the-given-index-range-using-segment-tree/?ref=rp
    // Queries for greatest pair sum in the given index range using Segment Tree
    // The time complexity for tree construction is O(N) where N is the size of the array.
    // The time complexity for each query is O(log(N)) where N is the size of the array.
    // https://ide.geeksforgeeks.org/BL3uNykACU
    
    
    cin >> n; 
    int A[n]; for(int i=0; i<n; i++)    cin >> A[i];
    
    buildTree(A);
    
    int l, r; cin >> l >> r;
    cout << findGpairSum(l, r) << endl;
    
	return 0;
}