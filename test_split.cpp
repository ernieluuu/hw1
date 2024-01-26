/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    Node* one = new Node(14, NULL);

    Node* head = one;

    Node* two = new Node(15, NULL);
    one->next = two;

    Node* three = new Node(17, NULL);
    two->next = three;

    Node* four = new Node(18, NULL);
    three->next = four;

    Node* five = new Node(20, NULL);
    four->next = five;

    Node* six = new Node(21, NULL);
    five->next = six;

    Node* seven = new Node(1, NULL);
    six->next = seven;

    Node* eight = new Node(2, NULL);
    seven->next = eight;

    Node* nine = new Node(0, NULL);
    eight->next = nine;

    Node* ten = new Node(958, NULL);
    nine->next = ten;

    Node* odds = NULL;
    Node* evens = NULL;

    split(head, odds, evens);

    /*print out the original linked list; prints out the evens; prints out the odds: */

    cout << "The linked list: " << endl;
    
    Node* curr = evens;

    cout << "Evens: " << endl;

    while (curr != NULL)
    {
        cout << "value: " << curr->value << endl;
        curr = curr->next;
    }

    cout << "end of evens." << endl;

    curr = odds;

    cout << "Odds: " << endl;

    while (curr != NULL)
    {
        cout << "value: " << curr->value << endl;
        curr = curr->next;
    }

    cout << "end of odds." << endl;

    Node* temp;
    /*clean up memory*/
    while(curr != NULL) // odds
    {
        temp = curr;
        curr = curr->next;
        delete temp;
    }

    curr = evens;
    while(curr != NULL) // evens
    {
        temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
