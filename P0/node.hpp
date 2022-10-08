#include <iostream>
#include <string>
using namespace std;

struct Node{ 
    string* data; 
    int size;

    int nameLength;

    Node* rightChild;
    Node* leftChild;
};