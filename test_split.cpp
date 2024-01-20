/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
    /*alternatively, write a linked list class*/

    Node* one = new Node(14, NULL);
    Node* two = new Node(15, one);
    Node* three = new Node(17, two);
    Node* four = new Node(18, three);
    Node* five = new Node(20, four);
    Node* six = new Node(21, five);
    Node* seven = new Node(1, six);
    Node* eight = new Node(2, seven);
    Node* nine = new Node(0, eight);
    Node* ten = new Node(958, nine);

    Node* odds = NULL;
    Node* evens = NULL;

    split(ten, odds, evens);

    /*print out the original linked list; prints out the evens; prints out the odds: */
}
