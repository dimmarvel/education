#include<iostream>
#include<string.h>

using namespace std;

int no_of_errors;

double error(const char* s)
{
	cerr << "Error: " << s << '\n';
	no_of_errors++;
	return 1;
}

enum token_value {
	NAME, NUMBER, END,
	PLUS='+', MINUS='-', MUL='*',
	PRINT=';', ASSIGN='=', DIV='/',
	LP='(', RP=')'
};

token_value curr_tok; //last token from get_token()

double expr();
double term();
double prim();
double get_token();

int main()
{
	return 0;
}

double expr()
{
	double left = term();
	for(;;)
	{
		switch(curr_tok)
		{
		case PLUS:
			get_token();
			left += term();
			break;
		case MINUS:
			get_token();
			left -= term();
			break;
		default:
			return left;
		}
	}
	error("double expr() ???");
	return -1;
}

double term()
{
	double left = prim();
	for(;;)
	{
		switch(curr_tok)
		{
			case MUL:{
				get_token();
				left *= prim();
				break;
			}
			case DIV:{
				get_token();
				double d = prim();
				if(d == 0) return error("div on zero!");
				left /= d;
				break;
			}
			default:{
				return left;
			}
		}
	}
	error("double term() ???");
	return -1;
}

//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

struct name {
	char* string;
	name* next;
	double value;
};

double number_value;
char name_string[256];
const int TBLSZ = 23;
name* table[TBLSZ];


name* look(const char*, int ins = 0);
inline name* insert(const char*);

double prim()
{
	switch(curr_tok)
	{
		case NUMBER:{
			get_token();
			return number_value;
		}
		case NAME:{
			if(get_token() == ASSIGN)
			{
				name* n = insert(name_string);
				get_token();
				n->value = expr();
				return n->value;
			}
			return look(name_string)->value;
		}
		case MINUS:{
			get_token();
			return -prim();
		}
		case LP:{
			get_token();
			double e = expr();
			if(curr_tok != RP) return error("need )");
			get_token();
			return e;
		}
		case END:{
			return 1;
		}
		default:{
			return error("need первичное");
		}
	}
}

double get_token()
{
	char ch;
	do //skip spaces
	{
		if(!cin.get(ch)) return curr_tok = END;
	}while(ch != '\n' && isspace(ch));

	switch(ch)
	{
	case ';': // end of string lexeme
	case '\n':
		cin >> ws;
		return curr_tok = PRINT;
	case '*':// operations
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok = token_value(ch);
	case '1': // number lexeme
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER;
	default:
		if(isalpha(ch))
		{
			char* p = name_string;
			*p++ = ch;
			while(cin.get() && isalnum(ch)) *p++ = ch;
			cin.putback(ch);
			*p = 0;
			return curr_tok = NAME;
		}
		error("bad lexeme");
		return curr_tok = PRINT;
	}

}

inline name* insert(const char* s)
{
	return look(s, 1);
}

name* look(const char* p, int ins)
{
	int hash_code = 0;
	const char* pp = p;

	while(*pp) hash_code = hash_code << 1 ^ *pp++;// all symbols
	// from input string p for queue add to hash_code
	// разряд в результате x^y равен 1 тогда и только тогда
	// когда эти разряды в операндах х и у различны. << - сдвиг влево
	if(hash_code < 0) hash_code = -hash_code;
	hash_code %= TBLSZ;

	//find name for hash code in chartable
	for(name* n = table[hash_code]; n; n = n->next)
	{
		if(strcmp(p, n->string) == 0) return n;
	}
	if(ins == 0) error("name not found");
	name* nn = new name; // new object for add new name in chartable
	nn->string = new char[strlen(p) + 1];
	strcpy(nn->string, p);
	nn->value = 1;
	nn->next = table[hash_code]; // add new name
	table[hash_code] = nn;
	return nn;
}




