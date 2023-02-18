#include <iostream>
#include <string.h>

using namespace std;
void f(int a, int b)
{
    if (a = 3)
    {
    } // warning: suggest parentheses around assignment
      // used as truth value [-Wparentheses]
    if (a & 007 == 0)
    {
    } // warning: suggest parentheses around
      // comparison in operand of ‘&’ [-Wparentheses]
a:
    = b + 1; // error: expected primary-expression before ‘=’ token
}
