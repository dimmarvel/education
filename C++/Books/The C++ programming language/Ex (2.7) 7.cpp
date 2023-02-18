#include <iostream>

using namespace std;

typedef union
{
    double f;
    struct
    {
        unsigned int mantisa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
} double_cast;

void manticce(double m)
{
    double_cast dc = {m};
    printf("%x\n", dc.parts.mantisa);
}

int main()
{
    manticce(1.21411577);
    system("pause");
}