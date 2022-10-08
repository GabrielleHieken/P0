#include <iostream>
using namespace std;

int testScanner(){
string token ; 

cin << token; // get a token

while (true) {
  //print descriptive token  followed by token instance if any followed by line number if applicable then \n
  if (token == EOFTk)
    break;
  token=scanner();
} 
}