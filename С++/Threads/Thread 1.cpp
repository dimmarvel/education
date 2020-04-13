#include <thread>

void threadFunction()
{
	// do smth
}

int main()
{
	std::thread thr(threadFunction);
	thr.join();
	system("pause");
	return 0;
}