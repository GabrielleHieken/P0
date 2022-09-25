#include <iostream>
#include<fstream>
#include "tree.hpp"
using namespace std;

Node* BinarySearchTree::newNode(string name){

    Node* dynamicNode = new Node; 
    dynamicNode->data = new string[1];
    dynamicNode->data[0]= name;
    dynamicNode->size = 1;
    dynamicNode->nameLength = name.length();
    dynamicNode->rightChild = NULL;
    dynamicNode->leftChild = NULL;

    return dynamicNode;
}

Node* BinarySearchTree::insert(Node** currentNode, string name){
    if(*currentNode == NULL){
        *currentNode = newNode(name);
    }
    else if(name.length() < (*currentNode)->nameLength){
        insert(&(*currentNode)->leftChild, name);
    }
    else if(name.length() == (*currentNode)->nameLength){
        string* newArray = new string[(*currentNode)->size + 1];
        for(int i = 0; i < (*currentNode)->size; i++){
            newArray[i] = (*currentNode)->data[i];
        }
        newArray[(*currentNode)->size] = name;
        (*currentNode)->size++;

        delete [] (*currentNode)->data;
        (*currentNode)->data = newArray;
    }
    else{
        insert(&(*currentNode)->rightChild, name);
    }
        return *currentNode;
}

//writes and formats the input for each traversal
void printToFileCurrentNode(int depth, int length, int size, string* data, string fileName, string fileExtension){
    ofstream ofile;
    ofile.open(fileName+fileExtension, ios::app);

    //find the depth of the node in the tree for formatting and insert it to file
    for(int i = 0; i<depth; i++){
        ofile << "   ";
    }
    ofile << length << ": ";
    for(int i = 0; i< size; i++){
        ofile << data[i] << " ";
    }
    ofile << endl;

    ofile.close();
}

//Inorder Travresal
void BinarySearchTree::printInorder(Node *currentNode, int depth, string fileName){
    if(currentNode == NULL){
        return;
    }

    printInorder(currentNode->leftChild, depth+1, fileName);

    printToFileCurrentNode(depth, currentNode->nameLength, currentNode->size, currentNode->data, fileName, ".inorder");

    printInorder(currentNode->rightChild, depth+1, fileName);

    return;
}

//Postorder Traversal
void BinarySearchTree::printPostorder(Node *currentNode, int depth, string fileName){
    if(currentNode == NULL){
        return;
    }

    printPostorder(currentNode->leftChild, depth+1, fileName);

    printPostorder(currentNode->rightChild, depth+1, fileName);

    printToFileCurrentNode(depth, currentNode->nameLength, currentNode->size, currentNode->data, fileName, ".postorder");

    return;
}

//Preorder Traversal
void BinarySearchTree::printPreorder(Node *currentNode, int depth, string fileName){
    if(currentNode == NULL){
        return;
    }
    
    printPreorder(currentNode->leftChild, depth+1, fileName);

    printPreorder(currentNode->rightChild, depth+1, fileName);

    printToFileCurrentNode(depth, currentNode->nameLength, currentNode->size, currentNode->data, fileName, ".preorder");

    return;
}  