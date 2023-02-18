#include <iostream>

int main()
{
    int max_length = 10;
    int i = 0;
    int quest_count = 0;
    char input_line[max_length] = "hey?im?qw";

    while (i < max_length)
        if (input_line[i++] == '?')
            quest_count++;
    std::cout << "quest_cout(while): " << quest_count << std::endl;

    quest_count = 0;
    for (char* p = input_line; p < &input_line[max_length]; p++)
    {
        if (*p == '?')
            quest_count++;
        std::cout << *p << std::endl;
    }
    std::cout << "quest_cout(pointer): " << quest_count << std::endl;
}
