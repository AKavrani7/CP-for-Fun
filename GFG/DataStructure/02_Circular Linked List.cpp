#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _CNode
{
    int data;
    struct _CNode *next;
}CNode;

int main()
{
    int n,value;
    CNode *last = NULL;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> value;
        push(&last,value);
    }

    printList(last);

    return 0;
}

CNode *makeNode(int value)
{
    CNode *nd;
    nd = new Node;
    nd->data = value;
    nd->next = NULL;
    return nd;
}

//// 1. PRINT LIST /////

void printList(CNode *last)
{
    CNode *start;
    start = last->next;

    while(start != last)
    {
        cout << start->data << " ";
        start = start->next;
    }
    cout << start->data;

}

////-------------///////

//// 2. Inserting Node /////
// 2.1 Add a node at the first //
void push(Node **lastRef, int value)
{
    if(*lastRef == NULL)
    {
        *lastRef = makeNode(value);
        (*lastRef)->next = (*lastRef);
        return;
    }

    CNode *start;
    start = (*lastRef)->next;
    CNode *nd;
    nd = makeNode(value);

    nd->next = start;
    *lastRef->next = nd;

    *lastRef = nd;
}
// 2.2 Add a Node after a given Node //
void insertAfter(CNode **lastRef, CNode *nodeAfter, int value)
{
    Node *nd;
    nd = makeNode(value);
    nd->next = nodeAfter->next;
    nodeAfter->next = nd;
    if(nodeAfter == *lastRef)
    {
     *lastRef = nodeAfter;
    }
}
// 2.3 Add Node at the end //
void append(Node **lastRef, int value)
{
    Node *nd;
    nd = makeNode(value);
    nd->next = (*lastRef)->next;
    (*lastRef)->next = nd;
    *lastRef = nd;
}

//// 3. Split a Circular Linked List into two halves ////
void splitCL(CNode *last, CNode **headRef1, CNode **headRef2)
{
    *headRef1 = last;
    if(last == NULL  || last == last->next)
    {
        *headRef2 = NULL;
        return;
    }

    CNode *start = last->next;

    CNode *slow, *fast;
    slow = start;
    fast = start;

    while(start != fast->next && fast->next->next != start)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast->next->next == start)
    {
        fast = fast->next;
    }

    *headRef2 = slow->next;
    slow->next = *headRef1;

    fast->next = *headRef2;
    return;
}

//// 4. Length of Linked list ///
//// 4.1 Iterative
int lengthIterative(CNode *last)
{
    if(last == NULL)
        return 0;

    int i=1;
    last = last->next;

    while(last != last)
    {
        i++;
        last = last->next;
    }

    return i;
}

//// 5. Sorted Insertion
void sortedInsert(CNode **headRef, int k)
{
    CNode *nd;
    nd = makeNode(k);

    CNode *head;
    head = *headRef;

    // Case A empty list
    if(head == NULL)
    {
        *headRef = nd;
        nd->next = nd;
        return;
    }

    // For a non empty list

    CNode *frw, *curr;
    curr = head;
    frw = head;

    while(frw->next != head && frw->data <= k)
    {
        curr = frw;
        frw = frw->next;
    }

    // Case B new tail
    if(frw->next == head && frw->data <= k)
    {
        frw->next = nd;
        nd->next = head;

    }
    else if(frw->next == head && frw->data >k)
    {
        curr->next = nd;
        nd->next = frw;
        if(frw == head)
            *headRef = nd;

    }
    else if(frw == head)
    {
        while(frw->next != head)
            frw = frw->next;

        nd->next = head;
        frw->next = nd;
        *headRef = nd;
    }
    else
    {
        curr->next = nd;
        nd->next = frw;
    }
}
