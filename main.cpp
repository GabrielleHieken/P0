#include <iostream>
#include <fstream>
#include "tree.hpp"

using namespace std; 

int spaceFunction(string);
void treeAddition(int, string, string);
void printTree(BinarySearchTree, string);

int main(int argc, char *argv[]){
    int spacecount;
    string text; 
    BinarySearchTree BST;

    // for taking input "./file < filename.extension"
    if(argc == 1){
        
        // cout << argv[1] << argv[3];
        string text;
        getline(cin, text);

        spacecount = spaceFunction(text);
        treeAddition(spacecount, text, "outP0");
    }

    //taking input "./file fileName" and appending .cs4280 extension
    else if(argc == 2){
        ifstream test; 
        string fileToOpen = argv[1];
        fileToOpen +=  ".cs4280";
        cout << fileToOpen;
        test.open(fileToOpen);

        while(getline(test, text)){
            cout << text << endl;
        }

        spacecount = spaceFunction(text);
        treeAddition(spacecount, text, fileToOpen);
        test.close();

    //for user input names directly from command line "./program name name name ..."
    }else {
        for(int i = 1; i < argc; i++){
            BST.insert(&(BST.root), argv[i]);
        }
        printTree(BST, "outP0");
    }

    return 0;
}

//Printing the tree to file
void printTree(BinarySearchTree BST, string fileName){

    //Print Inorder
    BST.printInorder(BST.root, 0, fileName);

    //Print Postorder 
    BST.printPostorder(BST.root, 0, fileName);

    //Print Preorder
    BST.printPreorder(BST.root, 0, fileName);
}

//Find number of spaces in document to know how many times to add a name to tree
int spaceFunction(string text){
    int space = 0;
    int spacecount = 0;

    //Find number of spaces in document
    while(text.find(" ", space+1) != -1){
        space = text.find(" ", space+1);
        spacecount++;
    }

    return spacecount;
}

//chops one name from the input string and adds it to the tree
void treeAddition(int spacecount, string text, string fileName){
    string individual;
    BinarySearchTree BST;

    for(int i = 0; i < spacecount; i++){
        individual = text.substr(0,text.find(" "));
        text = text.substr(text.find(" ")+1, text.length());
    
        //put 'individual' name in tree
        BST.insert(&(BST.root), individual);
    }
    BST.insert(&(BST.root), text);

    //use fileName for output 
    if(fileName.find(".cs4280")){
        fileName = fileName.substr(0, fileName.find(".cs4280"));
    }

   printTree(BST, fileName);
}  