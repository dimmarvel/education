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







