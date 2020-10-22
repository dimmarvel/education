#include <iostream>

int main()
{
	int max_length = 100;
	int i = 0;
	int quest_count = 0;
	char input_line[max_length] = "hey? how are you?";
	while(i < max_length)
	{
		if(input_line[i++] == '?') quest_count++;
	}
	std::cout << "quest_cout: " << quest_count << std::endl;
}
