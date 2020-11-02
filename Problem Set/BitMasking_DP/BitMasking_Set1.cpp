#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void removeSet(int &set, int x)
{
    if(set & (1 << (x-1)) )
        set = set ^ (1 << (x-1));
}

void addSet(int &set, int x)
{
    // add x in the set
    set = set | (1 << (x-1));
}

void display(int set)
{
    cout << "My set: " << set << " represent: \n";   
    for(int bit_no =0; bit_no<=20; bit_no++)
    {
        if(set & (1<< bit_no))
            cout << bit_no+1 << " ";
    }
    
    cout << endl;
}

int main() {
    
    // Represent a set by using bit-masking 
    // add, remove, display
    
    
    int set_size = 10; //  if ith bit is on the no is in the subset
    int set = pow(2, set_size)-1; // first 31 natural no
    
    display(set);   
	addSet(set, 15);
	display(set);
	addSet(set, 19);
	display(set);
	removeSet(set, 10);
	display(set);
	removeSet(set,10);
	display(set);
	
	return 0;
}