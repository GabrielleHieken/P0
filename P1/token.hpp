#include <string>
using namespace std; 

enum tokenID {ALPHA_tk, IDENT_tk, KW_tk, OP_tk, INT_tk, COM_tk};

string tokenNames[] ={"Alphabet","Identifier", "Keyword", "OperateDelim", "Integer", "Comment"};

struct token { 
    tokenID TID; 
    string name; 
    int lineNum;
};