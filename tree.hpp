#include <iostream>
#include "node.hpp"
using namespace std;

class BinarySearchTree{

    public:
    Node* root;   

    Node* newNode(string);
    void buildTree();
    void printInorder(Node *currentNode, int depth, string);
    void printPreorder(Node *currentNode, int depth, string);
    void printPostorder(Node *currentNode, int depth, string);

    BinarySearchTree(){
        root = NULL;
    }

    Node* insert(Node** currentNode, string name);

};