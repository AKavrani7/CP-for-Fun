#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _Node
{
    int data;
    struct _Node *next;
}Node;

int main()
{
    int n,value;
    Node *start = NULL;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> value;
        push(&start,value);
    }

    printList(start);

    return 0;
}

Node *makeNode(int value)
{
    Node *nd;
    nd = new Node;
    nd->data = value;
    nd->next = NULL;
    return nd;
}

//// 1. PRINT LIST /////

void printList(Node *start)
{
    while(start != NULL)
    {
        cout << start->data << " ";
        start = start->next;
    }
}

////-------------///////

//// 2. Inserting Node /////
// 2.1 Add a node at the first //
void push(Node **startRef, int value)
{
    Node *nd;
    nd = makeNode(value);
    nd->next = *startRef;
    *startRef = nd;
}
// 2.2 Add a Node after a given Node //
void insertAfter(Mode *nodeAfter, int value)
{
    if(nodeAfter == NULL)
    {
        cout << "Empty List" ;
    }
    Node *nd;
    nd = makeNode(value);
    nd->next = nodeAfter->next;
    nodeAfter->next = nd;
}
// 2.3 Add Node at the end //
void append(Node **startRef, int value)
{
    Node *nd;
    nd = makeNode(value);

    if(*startRef == NULL)
    {
        *startRef = nd;
        return;
    }

    Node *start;
    start = *startRef;
    while(start->next != NULL)
    {
        start = start->next;
    }

    start->next = nd;
}
//// 3. Delete Node of a given Key ////
void deleteNodeKey(Node **startRef, int key)
{
    Node *nd;
    nd = *startRef;
    if(nd->data == key)
    {
        *startRef = nd->next;
        free(nd);
        return;
    }

    while(nd->next->data != key && nd->next != NULL)
    {
        nd = nd->next;
    }

    Node *tmp;
    tmp = nd->next;
    nd->next = tmp->next;
    free(tmp);
}

//// 4. Length of Linked list ///
//// 4.1 Iterative
int lengthIterative(Node *start)
{
    int i=0;
    while(start != NULL)
    {
        i++;
        start = start->next;
    }

    return i;
}
//// 4.2 Recursive
int lengthRecursive(Node *start)
{
    if(start == NULL)
        return 0;
    return 1 + lengthRecursive(start->next);
}
//// 5. Swap Nodes, given the values of nodes
void swapNodes(Node **headRef, int x, int y)
{
    if(x == y)
        return;

    Node *head, *prvX, *prvY, *swapXY, *tmp;
    head = *headRef;
    //Case1 X is start
    if(head->data == x)
    {
        //Find Y
        prvY = head;
        while(prvY->next->data != y && prvY->next != NULL)
        {
            prvY = prvY->next;
        }

        if(prvY->next != NULL)
            return;

        tmp = prvY->next;
        swapXY = head->next;

        prvY->next = head;
        head->next = tmp->next;

        tmp->next = swapXY;
        *headRef = tmp;
        return;
    }
    if(head->data == y)
    {
        //Find X
        prvX = head;
        while(prvX->next->data != x && prvX->next != NULL)
        {
            prvX = prvX->next;
        }

        if(prvX->next != NULL)
            return;

        tmp = prvX->next;
        swapXY = head->next;

        prvX->next = head;
        head->next = tmp->next;

        tmp->next = swapXY;
        *startRef = tmp;
        return;
    }

    prvX = head;
    prvY = head;
    //Find X
    while(prvX->next->data != x && prvX->next != NULL)
    {
        prvX = prvX->next;
    }

    if(prvX->next != NULL)
        return;

    // Find Y
    while(prvY->next->data != y && prvY->next != NULL)
    {
        prvY = prvY->next;
    }

    if(prvY->next != NULL)
        return;

    tmp = prvX->next;
    swapXY = prvY->next;
    head = swapXY->next;

    prvX->next = swapXY;
    swapXY->next = tmp->next;

    prvY->next = tmp;
    tmp->next = head;
    return;
}

//// 6. Reverse Linked list
// 6.1 Iterative
void reverseIter(Node **headRef)
{
    Node *curr = *headRef;
    Node *prv = NULL;

    while(curr != NULL)
    {
        *headRef = curr;
        curr = curr->next;
        (*headRef)->next = prv;
        prv = *headRef;
    }
}
// 6.2 Recursive
void reverseRec(Node **headRef)
{
    if(*headRef == NULL)
        return;

    Node *first;
    Node *rest;

    first = *headRef;
    rest = first->next;

    // only 1 Node
    if(rest == NULL)
        return;

    reverseRec(&rest);

    first->next->next = first;
    first->next = NULL;
    *headRef = rest;
}
//// 7. Merge Two Sorted Linked list ///
Node *mergeLists(Node *startA, Node *startB)
{
    Node *start = NULL;

    if(startA == NULL)
        return startB;
    if(startB == NULL)
        return startA;

    if(startA->data > startB->data)
    {
        start = startB;
        start->next = mergeLists(startA,startB->next);
    }
    else
    {
        start = startA;
        start->next = mergeLists(startB,startA->next);
    }

    return start;
}
//// 8.  Merge Sort /////
void mergeSort(Node **startRef)
{
    Node *start;
    start = *startRef;

    if(start = NULL || start->next == NULL)
        return;

    Node *a, *b;

    split(start,&a,&b);

    mergeSort(&a);
    mergeSort(&b);

    *startRef = mergeLists(a,b);

}
void split(Node *source, Node **firstHalf, Node **secondHalf)
{
    Node *fast, *slow;
    fast = source->next;
    slow = source;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *firstHalf = source;
    *secondHalf = slow->next;
    slow->next = NULL;
}

///// 8. Reverse a Linked List in groups of given size
Node *reverseK(Node *start, int k)
{
    Node *curr, *prv, *next;
    curr = start;
    prv = next = NULL;
    int countN = 0;

    while(curr != NULL && countN < k)
    {
        next = curr->next;
        curr->next = prv;
        prv = curr;
        curr = next;
        countN++;
    }

    if(curr != NULL)
        start->next = reverseK(curr,k);

    return prv;
}

///// 9. Detect Loop in SLL
bool detectLoop(Node *start)
{
    // source: https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
    unordered_set<Node *> s;

    while(start != NULL)
    {

        if(s.find(start) != s.end())
            return true;

        s.insert(start);
        start = start->next;
    }

    return false;
}

//// 10. Remove the Loop
void removeTheLoop(Node *start)
{
    Node *ptr1, *ptr2;
    ptr1 = start;

    unordered_set<Node *> s;

    while(ptr1 != NULL)
    {
        if(s.find(ptr1) != s.end())
        {
            ptr2->next = NULL;
            return;
        }
        else
        {
            s.insert(ptr1);
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
    }

}

//// 11. Add two numbers represented by linked lists ////
Node * addLL(Node *a, Node *b)
{
    Node *start = NULL, *nd, *curr;
    int carry = 0;
    int data = 0;

    while(a != NULL && b != NULL)
    {
        data = a->data + b->data + carry;
        carry = data/10;
        data = data%10;

        if(start == NULL)
        {
            start = makeNode(data);
            curr = start;
        }
        else
        {
            nd = makeNode(data);
            curr->next = nd;
            curr = curr->next;
        }

        a = a->next;
        b = b->next;
    }


    while(a != NULL && b == NULL)
    {
        data = a->data + carry;
        carry = data/10;
        data = data%10;

        if(start == NULL)
        {
            start = makeNode(data);
            curr = start;
        }
        else
        {
            nd = makeNode(data);
            curr->next = nd;
            curr = curr->next;
        }

        a = a->next;
    }

    while(a == NULL && b != NULL)
    {
        data = b->data + carry;
        carry = data/10;
        data = data%10;

        if(start == NULL)
        {
            start = makeNode(data);
            curr = start;
        }
        else
        {
            nd = makeNode(data);
            curr->next = nd;
            curr = curr->next;
        }

        b = b->next;
    }

    if(a == NULL && b == NULL && carry != 0)
    {
        nd = makeNode(carry);
        curr->next = nd;
    }

    return start;
}

//// 12. Rotate the linked list counter-clockwise by k nodes
void rotate(Node **headRef, int k)
{
  // Complete this method
  Node *newH, *Kth, *last;
  Node *oldH = *headRef;
   int count = 0;

   newH = oldH;

   while(newH != NULL && count < k)
   {
        Kth = newH;
        newH = newH->next;
        count++;
   }

   if(newH == NULL)
    return;

   last = newH;

   while(last->next != NULL)
   {
       last = last->next;
   }

   Kth->next = NULL;
   last->next = oldH;
   *headRef =  newH;
}

//// 13. Generic Linked List in C
// source: https://www.geeksforgeeks.org/generic-linked-list-in-c-2/
