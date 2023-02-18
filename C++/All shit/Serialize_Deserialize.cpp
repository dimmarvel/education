#include <iostream>
#include <vector>

using namespace std;

static vector<int8_t> s;
static size_t offset = 0u;

template <typename T>
void serialize(T& type)
{
    size_t i = s.size();

    offset = s.size() + sizeof(type);

    s.resize(s.size() + sizeof(type));

    memcpy(s.data() + i, &type, sizeof(type));
}

template <typename T>
void deserialize(T& type)
{
    size_t i = s.size() - sizeof(type);

    memcpy(&type, s.data() + i, sizeof(type));

    s.resize(i);

    offset -= sizeof(type);
}

int main()
{
    int64_t temp = 11;
    int32_t temp1 = 12;
    int16_t temp2 = 13;

    cout << "uint 64_t = " << temp << endl;
    cout << "uint 32_t = " << temp1 << endl;
    cout << "uint 16_t = " << temp2 << endl;

    cout << "Ofset - " << offset << endl;
    ;

    cout << "---serialize...\n";
    serialize(temp);
    serialize(temp1);
    serialize(temp2);
    cout << "---Success!\n";

    temp = 155;
    temp1 = 555;
    temp2 = 1777;
    cout << "Ofset - " << offset << endl;
    ;

    cout << "uint 64_t = " << temp << endl;
    cout << "uint 32_t = " << temp1 << endl;
    cout << "uint 16_t = " << temp2 << endl;

    cout << "---Deserialize...\n";
    deserialize(temp2);
    deserialize(temp1);
    deserialize(temp);
    cout << "---Success!\n";

    cout << "Ofset - " << offset << endl;
    ;

    cout << "uint 64_t = " << temp << endl;
    cout << "uint 32_t = " << temp1 << endl;
    cout << "uint 16_t = " << temp2 << endl;
    return 0;
}
