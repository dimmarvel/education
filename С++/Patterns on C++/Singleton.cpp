#include <iostream>
#include <fstream>
using namespace std;
class IJob;
class FootJob;
class HandJob;
class Worker;

class IJob {
public:
	virtual void DoJob() = 0;
};
class FootJob : public IJob {
public:
	void DoJob() {
		cout << "FootJob" << endl;
	} 
	int a;
};
class HandJob : public IJob {
public:
	void DoJob() {
		cout << "HandJob" << endl;
	}
};
class Worker {
public:
	void DoWork(IJob* job) {
		job->DoJob();
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Worker wrker;
	FootJob *fjb = new FootJob();
	HandJob *fjb2 = new HandJob();
	wrker.DoWork(fjb);
	wrker.DoWork(fjb2);
	system("pause");
	return 0;
}


