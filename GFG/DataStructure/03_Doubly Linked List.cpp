#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _DNode
{
    int data;
    struct _DNode *next;
    struct _DNode *prv;
}DNode;

int main()
{
    int n,value;
    DNode *head = NULL;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> value;
        push(&head,value);
    }

    printList(last);

    return 0;
}

DNode *makeNode(int value)
{
    DNode *nd;
    nd = new Node;
    nd->data = value;
    nd->next = NULL;
    nd->prv =  NULL;
    return nd;
}

//// 1. PRINT LIST /////

void printList(DNode *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

////-------------///////

//// 2. Inserting Node /////
// 2.1 Add a node at the first //
void push(Node **headRef, int value)
{
    if(*headRef == NULL)
    {
        *headRef = makeNode(value);
        return;
    }

    DNode *nd;
    nd = makeNode(value);

    nd->next = *headRef;
    (*headRef)->prv = nd;

    *headRef = nd;
}
// 2.2 Add a Node after a given Node //
void insertAfter(DNode *head, int pos, int data)
{
    DNode *nd;
    nd = makeNode(data);

    while(pos)
    {
        head = head->next;
        pos--;
    }

    nd->next =  head->next;
    nd->prev = head;
    head->next = nd;
}


//// 3. Delete a given Node ////
void deleteNode(DNode **headRef, int pos)
{
    DNode *tmp;
    tmp = *headRef;
    if(pos == 1)
    {
        *headRef = tmp->next;
        (*headRef)->prv =  NULL;
        free(tmp);
        return;
    }

    pos--;
    while(pos != 1)
    {
        tmp = tmp->next;
        pos--;
    }
    DNode *curr = tmp;
    tmp = tmp->next;
    curr->next = tmp->next;
    free(tmp);
}

//// 4. Length of Linked list ///
//// 4.1 Iterative
int lengthIterative(DNode *head)
{
    int i=0;

    while(head != NULL)
    {
        i++;
        head = head->next;
    }

    return i;
}

//// 5. Reverse a Doubly Linked List
DNode reverseDLL(DNode *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    DNode *curr, *prv, *next;
    curr = head;
    prv = NULL;
    next = head;

    while(curr != NULL)
    {
        next = curr->next;
        curr->prv = next;
        curr->next = prv;
        prv = curr;
        curr = next;
    }
    return prv;
}

//// 6. The Great Tree-List Recursion Problem //

//// 7. QuickSort on Doubly Linked List //

//// 8. Merge Sort for Doubly Linked List //

