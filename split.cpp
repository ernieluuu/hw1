/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

void insert(Node*& first_node, Node* insertion_node); // helper function

void split(Node*& in, Node*& odds, Node*& evens)
{
    // when the linked list is empty.
    if (in == NULL)
    {
        return;
    }

    /*because we will be changing first_node->next to NULL in insert()
    we cannot simply do recursion on in->next*/
    Node* temp = in->next;

    if (in->value % 2 == 0) { // is even
        insert(evens, in);
    }
    else { // is odd
        insert(odds, in);
    }

    split(temp, odds, evens);

    in = NULL; // after 'in' is distributed to other lists

    return;
}

void insert(Node*& first_node, Node* insertion_node) 
{
    if (first_node == NULL)
    {
        first_node = insertion_node;
        first_node->next = NULL;
        return;
    }
    else if (first_node->next == NULL)
    {
        first_node->next = insertion_node;
        first_node->next->next = NULL;
        return;
    }
    else
    {
        /*iterates through evens or odds to reach last element*/
        insert(first_node->next, insertion_node);
    }
}