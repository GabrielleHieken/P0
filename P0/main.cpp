#include <iostream>
#include <fstream>
#include "tree.hpp"

using namespace std; 

void printTree(BinarySearchTree, string);
Node* addLineToTree(BinarySearchTree, string);


//Could move the tree print to once at the end 
int main(int argc, char *argv[]){
    int spacecount;
    string text; 
    BinarySearchTree BST;

    // for taking input "./file < filename.extension"
    if(argc == 1){
        string text;
        while (getline(cin, text)){
            //cout << text << endl;
            BST.root = addLineToTree(BST, text);
        }

        printTree(BST, "outP0");
    }

    //taking input "./file fileName" and appending .cs4280 extension
    else if(argc == 2){
        ifstream test; 
        string fileToOpen = argv[1];
        fileToOpen +=  ".cs4280";
        test.open(fileToOpen.c_str());
        if (test.is_open()){
            while(!test.eof()){
                test >> text;
                BST.insert(&(BST.root), text);
            }

            test.close();
            // use fileName for output
            if (fileToOpen.find(".cs4280"))
            {
                fileToOpen = fileToOpen.substr(0, fileToOpen.find(".cs4280"));
            }
            printTree(BST, fileToOpen);
        }else {
            cout << "Error opening file/file not found in directory. Ending program" << endl;
            return 0;
        }

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

// Text is either one word (the words are serpated by enters in this case), a bunch of words with tabs inbetween, or a bunch of words with spaces inbetween
Node* addLineToTree(BinarySearchTree BST, string text)
{
    if (text.empty())
    {
        cout << "Text is emopty, red alert" << endl;
        return BST.root;
    }

    string singleWord;
    // Pulls out words from a string with spaces
    if (!(text.find(" ") == -1))
    {
        while (!(text.find(" ") == -1))
        {
            singleWord = text.substr(0, text.find(" "));
            text = text.substr(text.find(" ") + 1, text.length());

            // put 'individual' name in tree
            BST.insert(&(BST.root), singleWord);
        }
    }

    //Pulls out words from a string with tabs
    if (!(text.find("\t") == -1))
    {

        while (!(text.find("\t") == -1))
        {
            singleWord = text.substr(0, text.find("\t"));
            text = text.substr(text.find("\t") + 1, text.length());

            // put 'individual' name in tree
            BST.insert(&(BST.root), singleWord);
        }
    }

    //Insert the last word with all tabs or spaces removed
    BST.insert(&(BST.root), text);  

    return BST.root;
}