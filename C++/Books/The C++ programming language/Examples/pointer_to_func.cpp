#include <iostream>
#include <stdio.h>
#include <string.h>
void (*eftc)(char*);
void error(char* p) { printf("%s", p); }

void f()
{
    eftc = &error;
    (*eftc)("error\n");
}

// examples
typedef int (*SIG_TYP)(int);
typedef void(SIG_ARG_TYP)(int);
SIG_TYP signale(int, SIG_ARG_TYP);
//-------------------
void cut() { return; }
void paste() { return; }
void snarf() { return; }
void search() { return; }
void open() { return; }
void reshape() { return; }
void close() { return; }
void write() { return; }

typedef void (*PF)();
PF edit_ops[] = {&cut, &paste, &snarf, &search};

PF file_ops[] = {&open, &reshape, &close, &write};
//------------------
struct user
{
    char* name;
    char* id;
    int dept;
};

typedef user* pUser;
user heads[] = {
    "Richard", "dmr", 11271, "Tom", "trav", 11272, "Jhony", "nls", 11273, "Sam", "skot", 11276, "Serios", "bwk", 11275,
};

void print_id(pUser v, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << v[i].name << "\t" << v[i].id << "\t" << v[i].dept << "\n";
}

int cmpUserName(void* p1, void* p2) { return strcmp(pUser(p1)->name, pUser(p2)->name); }

int cmpUserId(void* p1, void* p2) { return pUser(p1)->dept - pUser(p2)->dept; }

typedef int (*CFT)(void*, void*);
void sortUser(void* base, unsigned n, unsigned int sz, CFT cmp)
// соритровка вектора base из n элементов
// в возрастающем порядке
// используется функция сравнения, на которую указывает cmp
// размер элементов развен sz
// алгоритм очень неэффективный: сортировка пузырьковым методом
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; i < j; j--)
        {
            char* pj = (char*)base + j * sz; // b[j]
            char* pj1 = pj - sz;             // b[j-1]
            if (((*cmp)(pj, pj1)) < 0)
            {
                for (int k = 0; k < sz; k++)
                { // swap
                    char temp = pj[k];
                    pj[k] = pj1[k];
                    pj1[k] = temp;
                }
            }
        }
    }
}

int main()
{
    sortUser(heads, 6, sizeof(user), cmpUserName);
    print_id(heads, 6);

    std::cout << '\n';

    sortUser(heads, 6, sizeof(user), cmpUserId);
    print_id(heads, 6);
}
