#include <bits/stdc++.h>
using namespace std;

typedef struct _BStree
{
    int data;
    struct _Btree *left;
    struct _Btree *right;

}BStree;

int main()
{
    int n,value;
    Btree *start = NULL;
    
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> value;
        // Insert values in the tree  
        cout << value << endl;
    }

    return 0;
}

BStree *makeNode(int value)
{
    Btree *nd;
    nd = new Btree;
    nd->data = value;
    nd->left = NULL;
    nd->right =  NULL;
    return nd;
}

//// 1. Binary Search Tree | Set 1 (Search and Insertion)
BStree *insert(BStree *start, int data)
{
    BStree *nd;
    nd = makeNode(data);
    if(start == NULL)
        return nd;
    
    if(start->data >= data) 
        start->left = insert(start->left, data);
    else
        start->right = insert(start->right, data);
    
    return start;
}
//// 2. Binary Search Tree | Set 2 (Delete)
BStree *deleteNode(BStree *root, int x)
{
    // your code goes here
    if(root == NULL) return NULL;
    if(root->data > x)
        root->left = deleteNode(root->left,x);
    else if(root->data < x)
        root->right = deleteNode(root->right,x);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            Node *tmp;
            tmp = root->right;
            free(root);
            return tmp;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            Node *tmp;
            tmp = root->left;
            free(root);
            return tmp;
        }
        else 
        {
            Node *curr;
            curr = root->right;
            
            while(curr->left != NULL)
                curr = curr->left;
       
            root->data = curr->data;
            curr->data = x;
            root->right = deleteNode(root->right,curr->data);        
        }
    }
        
    return root;
}

//// 3. Find the node with minimum value in a Binary Search Tree
BStree *miniValue(BStree *root)
{
    if(root == NULL) return NULL;

    while(root->left != NULL)
        root = root->left;
    
    return root->data;
}
//// 4. Inorder predecessor and successor for a given key in BST
void inorder_pre_succ(BStree *root, BStree **pre, BStree **suc, int key)
{
    if(root == NULL) return;
    
    if(root->data == key)
    {
        *pre = NULL;
        *suc = NULL;
        if(root->left != NULL)
        {
            while((*pre)->left !=NULL)
                (*pre) = (*pre)->left;
        }

        if(root->right != NULL)
        {
            while((*pre)->right !=NULL)
                (*suc) = (*suc)->right;
        }
    }
    else if(root->data > key)
    {
        (*suc) = root;
        inorder_pre_succ(root->left,pre,suc,key);
    }
    else
    {
        (*pre) = root;
        inorder_pre_succ(root->right,pre,suc,key);
    }
    
    return;
}
//// 5. A program to check if a binary tree is BST or not
bool isBSTutil(BStree *root, int min, int max)
{   
    if(root == NULL) return true;

    if(!(root->data > min && root->data < max))
        return false;
    
    return isBSTutil(root->left,min,root->data) && isBSTutil(root->right,root->data,max);

}
bool isBST(BStree *root)
{
    return isBSTutil(root, INT_MIN, INT_MAX);
}

// 6. Lowest Common Ancestor in a Binary Search Tree
BStree *lowestCommomAncestor(BStree *root, int a, int b)
{
    if(root == NULL) 
        return NULL;
    // case1 root is not equal to a,b
    if(root->data > a && root->data > b)
        return lowestCommomAncestor(root->left, a, b);
    if(root->data <  a && root->data < b)
        return lowestCommomAncestor(root->right, a, b);
    
    // case2 root is equal to a or b
    return root;
}
    
// 7. Inorder Successor in Binary Search Tree
BStree *inOrderSuccessor(BStree *root, BStree *x)
{
    //Your code here
    if(x == NULL) return NULL;

    if(x->right != NULL)
    {
        x = x->right;
        while(x->left != NULL)
            x = x->left;    
        return x;
    }

    BStree *ans = NULL;
    while(root != NULL)
    {
        if(root->data < x->data)
            root = root->right;
        else if(root->data > x->data)
        {
            ans = root;
            root = root->left;
        }
        else
            break;
    }

    return ans;
}

//// 8. Find k-th smallest element in BST (Order Statistics in BST)
// https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
int KthSmallestElement(BStree *root, int k)
{
    //add code here.
    if( k == root->lCount + 1)
        return root->data;
    else if( k > root->lCount)
        return KthSmallestElement(root->right, k-root->lCount-1);

    return KthSmallestElement(root->left, k);
}

//// 9. Merge two BSTs with limited extra space
void inorder(BStree *start)
{
    if(start == NULL)
        return;
    
    printTree(start->left);
    cout << start->data << " ";
    printTree(start->right); 
}
void merge(BStree *root1, BStree *root2)
{
    if(root1 == NULL)
    {
        inorder(root2);
        return;
    }

    if(root2 == NULL)
    {
        inorder(root1);
        return;
    }

    BStree *curr1 = root1;
    stack<BStree *> s1;

    BStree *curr2 = root2;
    stack<BStree *> s2;

    while( curr1 != NULL || !s1.empty() || curr2 != NULL || !s2.empty())
    {
        /* code */
        if(curr1 != NULL || curr2 != NULL)
        {
            if(curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            
            if(curr2 != NULL)
            {
                s2.push(curr2);
                curr2 = curr2->left;
            }
        }
        else
        {
            if(s1.empty())
            {
                while(!s2.empty())
                {
                    curr2 = s2.top();
                    s2.pop();
                    curr2->left = NULL;
                    inorder(curr2);
                }
                return;
            }
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    curr1 = s1.top();
                    s1.pop();
                    curr1->left = NULL;
                    inorder(curr1);
                }
                return;
            }

            curr1 = s1.top();
            curr2 = s2.top();

            if(curr1->data > curr2->data)
            {
                cout << curr2->data < " ";
                s2.pop();
                curr2 = curr2->right;
                curr1 = NULL;
            }
            else
            {
                cout << curr1->data < " ";
                s1.pop();
                curr1 = curr1->right;
                curr2 = NULL;
            }
        }   
    }
}
//// 10. Two nodes of a BST are swapped, correct the BST
void swap(int *a, int *b)
{
    int *tmp;
    *tmp = *b;
    *b = *a;
    *a = *tmp;
}
void correctBSTUtil(BStree root, BStree **first, BStree **second,  int min, int max)
{
    if(root == NULL) 
        return;
    
    if(root->data < min || root->data > max)
    {
        if(*first == NULL)
            *first = root;
        else if(*second == NULL)
            *second = root;

        correctBSTUtil(root->left,first,second,min,max);
        correctBSTUtil(root->right,first,second,min,max);
    }
    
    correctBSTUtil(root->left,first,second,min,root->data);
    correctBSTUtil(root->right,first,second,root->data,max);
    
}

BStree *correctBST( BStree *root )
{
    // add code here.
    
    if(root == NULL) return NULL;
    
    int min = INT_MIN;
    int max = INT_MAX;
    
    BStree *first, *second;
    first = NULL;
    second = NULL;
    
    correctBSTUtil(root,&first,&second,min,max);
    if(first!=NULL && second != NULL)
        swap(&first->data,&second->data);
    else if(first!=NULL && second == NULL)
        swap(&first->data,&root->data);
    
    return root;
}
//// 11. Ceil from a BST (Ceil Value Node: Node with smallest data larger than or equal to key value.)
// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int ceil(BStree *root, int input)
{
    if(root == NULL)
        return -1;
    
    if(root->data == input)
    {
        return input;
    }
    else if(root->data < input)
    {
        return ceil(root->right, input);
    }

    int ans = ceil(root->left, input)
    if(ans >= input) 
        return ans;
    return root->data;
} 

//// 12. In-place conversion of Sorted DLL to Balanced BST
// https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/

//// 13. Find a pair with given sum in a Balanced BST
// https://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/


bool is_pair_present(BStree *root, int target)
{
    stack<BStree *> s1;
    BStree* tmp1 = root;
    
    stack<BStree *> s2;
    BStree * tmp2 = root;
    

    while(1)
    {
        while(tmp1)
        {
            s1.push(tmp1);
            tmp1 = tmp1->left;
        }
        
        while(tmp2)
        {
            s2.push(tmp2);
            tmp2 = tmp2->right;
        }
        
        if(s1.empty() || s2.empty() ) 
            break;
        
        tmp1 = s1.top();
        tmp2 = s2.top();
        
        
        if(tmp1->val + tmp2->val == target)
        {    
            if(tmp1 == tmp2)
                return false;
            
            return true;
        }
        else if(tmp1->val + tmp2->val > target)
        {
            s2.pop();
            tmp2 = tmp2->left;
            tmp1 = NULL;
        }
        else
        {
            s1.pop();
            tmp1 = tmp1->right;
            tmp2 = NULL;
        }
        
    }
    return false;
}

//// 14. Total number of possible Binary Search Trees and Binary Trees with n keys
// https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-with-n-keys/

unsigned long int binomial_coefficient(unsigned int n, unsigned int k) 
{ 
    unsigned long int res = 1; 
    if(n-k < k)
        k = n-k;
    
    for(int i=0; i<k; i++)
    {
        res = res*(n-i);
        res = res/(i+1);
    }

    return res; 
}

unsigned long int catalan(unsigned int n) 
{  
    unsigned long int coefficient = binomial_coefficient(2*n,n); 

    return coefficient/(n+1); 
} 
unsigned long int countBST(unsigned int n) 
{ 
    // find nth catalan number 
    unsigned long int count = catalan(n); 
  
    // return nth catalan number 
    return count; 
} 

//// 15. Binary Tree to Binary Search Tree Conversion
// https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/

typedef struct _Btree
{
    int data;
    struct _Btree *left;
    struct _Btree *right;

}Btree;

int countNodes(Btree *root)
{
    if(!root)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void storeInorder(Btree *root, int inorder[], int *index_ptr)
{
    if(!root)
        return;
    
    storeInorder(root->left, inorder, index_ptr);

    inorder[*index_ptr] = root->data;
    (*index_ptr)++;

    storeInorder(root->right, inorder, index_ptr);
}

void arrayToBST(int inorder[], Btree *root, int *index_ptr)
{
    if(!root)
        return;
    
    arrayToBST(inorder, root->left, index_ptr);

    root->data = inorder[*index_ptr];
    (*index_ptr)++;

    arrayToBST(inorder, root->right, index_ptr);
}

void binaryTreeToBST(Btree *root)
{  
    if(root == NULL)
        return;

    int n = countNodes(root); 

    int *arr = new int[n];

    int i=0;
    storeInorder(root, arr, &i);

    sort(arr, arr+n);
    
    i=0;
    arrayToBST(arr, root , &i);
}


