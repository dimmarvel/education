#include <iostream>
#include <string.h>
using namespace std;

struct enode
{
    token_value oper;
    enode* left;
    enode* right;
};

enode* expr()
{
    enode* left = term();
    for (;;)
    {
        switch (curr_tok)
        {
        case PLUS:
        case MINUS:
            get_token();
            enode* n = new enode;
            n->oper = curr_tok;
            n->left = left;
            n->right = term();
            left = n;
            break;
        default:
            return left;
        }
    }
}

char* save_string(const char* p)
{
    char* s = new char[strlen(p) + 1];
    strcpy(s, p);
    return s;
}

void generate(enode* n)
{
    switch (n->oper)
    {
    case PLUS:
        delete n;
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2)
        exit(1);
    char* p = save_string(argv[1]);
    delete[] p;
}
