#include <bits/stdc++.h>
using namespace std;

typedef struct _Btree
{
    int data;
    struct _Btree *left;
    struct _Btree *right;

}Btree;

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

Btree *makeNode(int value)
{
    Btree *nd;
    nd = new Btree;
    nd->data = value;
    nd->left = NULL;
    nd->right =  NULL;
    return nd;
}

/// 1. Properties 
// 1.1 height 
int height(Btree *start)
{
    if(start == NULL)
        return 0;
    
    int left_height = height(start->left);
    int right_height = height(start->right);

    if(left_height > right_height)
        return left_height + 1;
    
    return right_height + 1;
}
// 1.2 diameter 
// https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
int diameter(Btree *start)
{
    if(start == NULL)
        return 0;
    
    int left_height = height(start->left);
    int right_height = height(start->right);

    int left_diameter = diameter(start->left);
    int right_diameter = diameter(start->right);

    return max(left_height + right_height + 1, max(left_diameter,right_diameter));
}

// 1.3 max Depth
// https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
int maxDepth(Btree *start)
{
    if(start == NULL)
        return 0;
    
    int left_depth = maxDepth(start->left);
    int right_depth= maxDepth(start->right);

    return max(left_depth,right_depth)+1;
}

/// 2. Order Of Traversal ///
// 2.1.A Method A. Level Order Tree Traversal or BFS
void printGivenLevel(Btree *start, int level)
{
    if(start == NULL)
        return;
    if(level == 1)
        cout << start->data << " ";
    else if(level > 1)
    {
        printGivenLevel(start->left,level-1);
        printGivenLevel(start->right,level-1);
    }
}
void printLevelOrder(Btree *start)
{
    if(start == NULL)
        return;
    
    int h =  height(start);
    
    for(int i=1;i<=h; i++)
        printGivenLevel(start,i);

}
// 2.1.B Method B. Queue Method
void printLevelQueue(Btree *start)
{
    if(start == NULL)
        return;
    queue<Btree *> q;
    q.push(start);

    while(!q.empty())
    {
        Btree *curr;
        curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
    }
}
// 2.2.1 DFS Inorder
void inorderPrint(Btree *start)
{
    if(start == NULL)
        return;
    
    printTree(start->left);
    cout << start->data << " ";
    printTree(start->right); 
}
// 2.2.2 DFS Postorder
void postorderPrint(Btree *start)
{
    if(start == NULL)
        return;
    
    postorderPrint(start->left);
    postorderPrint(start->right);
    cout << start->data << " ";
}
// 2.2.3 DFS Preorder
void preorderPrint(Btree *start)
{
    if(start == NULL)
        return;
    
    cout << start->data << " ";
    preorderPrint(start->left);
    preorderPrint(start->right);
}

//// 3. Inorder Tree Traversal without Recursion (stack)
void inorderTraversalWithoutRecurssion(Btree *root)
{
    if(root == NULL)
        return;
    
    stack<Btree *> s;
    Btree *curr = root;

    while(!s.empty || curr != NULL)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

// 4. Inorder Tree Traversal without recursion and without stack! //
// Moris Traversal #IMP
void inorderTraversalWithoutRecurssionWithoutStack(Btree *root)
{
    Btree *curr, *pre;

    curr =  root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;

            while(pre->right != NULL || pre->right != curr)
                pre = pre->right;

            if(pre->right == NULL)
            {   
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr =  curr->right; 
            }
        } 
    }
}

// 5. Clone a Binary Tree with Random Pointers
// https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/

// 6. Construct Tree from given Inorder and Preorder traversals
int search(int inorder[], int strt, int end, int data)
{
    for(int i=strt; i<= end; i++)
    {
        if(data == inorder[i])
            break;
    }
    return i;
}

Btree *buildTree(int inorder[], int preorder[], int strt, int end)
{
    if(strt > end)
        return NULL;
    
    static int i = 0;

    Btree *start;
    start = makeNode(preorder[i++]);

    if(strt == end)
        return start;
    
    int index = search(inorder, strt, end, start->data);

    if(index <= end){
        start->left = buildTree(inorder, preorder, strt, index-1);
        start->right = buildTree(inorder, preorder, index+1, end);
    }
    
    return start;
}

//// 7.Maximum width of a binary tree
// Method A. By level order traversal 
int noNodes_atLevel(Btree *start, int level)
{

    if(start == NULL || level<=0) return 0;
    else if(level == 1) return 1;

    return noNodes_atLevel(start->left,level-1) + noNodes_atLevel(start->right,level-1);

}
int maxWidth_LevelOrder(Btree *start)
{
    if(start == NULL) return 0;
    int height;
    int maxWidth=1;
    height =  height(start);

    for(int i=2; i<=height; i++)
    {
        maxWidth = max(maxWidth, noNodes_atLevel(start,i));
    }
    return maxWidth;
}
// Method B. Using Level Order Traversal with Queue
int maxWidth_levelOrder_queue(Btree *start)
{
    if(start == NULL) return NULL;
    int maxWidth = 0;
    
    queue<Btree *> q;
    q.push(start);
    
    Btree *nd;

    int noNodes_atlevel;
    
    while(!q.empty())
    {
        noNodes_atLevel = q.size();
        maxWidth = max(noNodes_atLevel,maxWidth);

        for(int i=0; i<noNodes_atLevel; i++)
        {
            nd = q.top();
            q.pop();
            if(nd->left != NULL) q.push(nd->left);
            if(nd->right != NULL) q.push(nd->right);
        }
    }

    return maxWidth;
}
// Method C. Using Preorder Traversal
void fill_count(Btree *start, int count[], int level)
{
    if(start != NULL)
    {
        count[level]++;

        fill_count(start->left,count,level+1);
        fill_count(start->right,count,level+1);
    }
}
int maxWidth_preorder(Btree *start)
{
    if(start == NULL)
        return 0;

    int h = height(start);
    int count* = new int[h];

    int level = 0;

    fill_count(start,count,level);

    int maxWidth = 0;
    for(int i=1; i<h; i++)
    {
        maxWidth = max(count[i], maxWidth);
    }
    return maxWidth;
}
//// 8. Print nodes at k distance from root
void printNodes_Kdistance(Btree *start, int k)
{
    if(start !=NULL)
    {
        if(k==0)
            cout << start->data << " ";
        else
        {
            printNodes_Kdistance(start->left,k-1);
            printNodes_Kdistance(start->right,k-1);
        }
    }
}
//// 9. Print Ancestor of a given node in Binary Tree
void printAncestor(Btree *start, int value)
{
    if(start != NULL)
    {
        if(start->left != NULL && start->left->data == value)
        { 
            cout << start->data;
            return;
        }
        else if(start->right != NULL && start->right->data == value)
        { 
            cout << start->data << endl;
            return;
        }

        printAncestor(start->left,value);
        printAncestor(start->right,value);
    }   
}
//// 10. Print Ancestors of a given node in Binary Tree
bool printAncestors(Btree *start, int value)
{
    if(start == NULL)
        return false;
    
    if(start->left != NULL && start->left->data == value)
    {
        cout << start->data << " ";
        return true;
    }
    if(start->right != NULL && start->right->data == value)
    {
        cout << start->data << " ";
        return true;
    }
    
    if(printAncestors(start->left,value)) 
    {
        cout << start->data << " ";
        return true;
    }

    if(printAncestors(start->right,value)) 
    {
        cout << start->data << " ";
        return true;
    }

    return false;
}
//// 11. Check if a binary tree is subtree of another binary tree | Set 1
bool areIdentical(Btree *t, Btree *s)
{   
    if(t == NULL && s == NULL)
        return true;
    if(t == NULL || s == NULL)
        return false;
    
    if(t->data == s->data)
    {
        return areIdentical(t->right,s->right) && areIdentical(t->left,s->left);
    }

    return false;
}
bool isSubTree(Btree *t, Btree *s)
{
    if(s == NULL) return true;
    if(t == NULL) return false;

    if(areIdentical(t,s))
        return true;

    return isSubTree(t->right,s) || isSubTree(t->left,s);

}