#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Point {
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x, y;
};

int main() {

	setlocale(LC_ALL, "Rus");
	vector<Point> arr{
		Point(1,5),
		Point(4,5),
		Point(3,1),
	};
	vector<Point> arr2{
		Point(3,3),
		Point(1,5),
		Point(3,8),
	};

	bool res = equal(begin(arr), end(arr), begin(arr2), end(arr2), [](Point const & p1, Point const & p2) {
		return (p1.x == p2.x && p1.y == p2.y);
	});
	cout << res << endl;
	system("Pause");
}