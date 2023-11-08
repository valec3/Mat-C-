#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node *prev = NULL;
        struct Node *curr = head;
        struct Node *next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
    
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};