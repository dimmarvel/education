#include <thread>
#include <iostream>
#include <chrono>

using namespace std;
class Myclass{

public:
	int addfunc(int a, int b) {
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "ID - " << this_thread::get_id() << "----------THREAD ADDFUNC START-----------" << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
	
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "ID - " << this_thread::get_id() << "----------THREAD ADDFUNC END-----------" << endl;
		return a + b;
	}
	void addfunc2(int a, int b) {
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "ID - " << this_thread::get_id() << "----------THREAD ADDFUNC START-----------" << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
	
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "ID - " << this_thread::get_id() << "----------THREAD ADDFUNC END-----------" << endl;
		cout << a + b<<endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Myclass m,m2;
	int result;
	

	thread t([&]() 
	{
		result = m.addfunc(5, 7);
	});
	/*
	//another syntaxis
	thread t2(&Myclass::addfunc2, m2, 2,6);
	

	thread t([&]()
	{
		m2.addfunc2(5,7);
	});
	*/
	for (int i = 0; i < 20 ; i++)
	{
		cout << "ID - " << this_thread::get_id() << "\t MAIN IS WORK\t - " << i << endl;
		
		this_thread::sleep_for(chrono::milliseconds(800));

		//if ((i % 5) == 0)
		//	addfunc(2, 5);
	}
	t.join();

	cout << endl << result << endl;
	system("pause");
	return 0;
}