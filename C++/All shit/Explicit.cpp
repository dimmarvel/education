#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


struct Specialization 
{
	string spec;
	explicit Specialization(string new_spec)
	{
		spec = new_spec;
	}
};

struct Course
{
	string cour;
	explicit Course(string new_cour)
	{
		cour = new_cour;
	}
};

struct Week
{
	string week;
	explicit Week(string new_week)
	{
		week = new_week;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	explicit LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
	{
		specialization = new_specialization.spec;
		course = new_course.cour;
		week = new_week.week;
	}
};

int main() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	return 0;
}