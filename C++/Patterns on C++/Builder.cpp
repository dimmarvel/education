#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Anketa
{
public:
	Anketa(){}
	void setName(string _name)
	{
		name = _name;
	}
	void setAge(string _Age)
	{
		Age = _Age;
	}
	void setText(string _Text)
	{
		Text = _Text;
	}
	void setSoftSkills(string _SoftSkills)
	{
		SoftSkills = _SoftSkills;
	}
	void setAnotherSkills(string _AnotherSkills)
	{
		AnotherSkills = _AnotherSkills;
	}
	void Out_Info() {
		cout << "Name: " << name << endl;
		cout << "Age: " << Age << endl;
		cout << "Text: " << Text << endl;
		cout << "Soft skills: " << SoftSkills << endl;
		cout << "Another skills: " << AnotherSkills << endl;
	}
private:
	string name;
	string Age;
	string Text;
	string SoftSkills;
	string AnotherSkills;
};

class Builder
{
public:
	virtual void configureName(string) = 0;
	virtual void configureAge(string) = 0;
	virtual void configureText(string) = 0;
	virtual void configureSoftSkills(string) = 0;
	virtual void configureAnotherSkills(string) = 0;
	Anketa *getResult() { return _result; }
protected:
	Anketa *_result;
};

class AnketaBuilder : public Builder
{
public:
	AnketaBuilder()
	{
		_result = new Anketa();
	}
	void configureName(string _name)
	{
		_result->setName(_name);
	}
	void configureAge(string _Age)
	{
		_result->setAge( _Age);
	}
	void configureText(string _Text)
	{
		_result->setText(_Text);
	}
	void configureSoftSkills(string _SoftSkills)
	{
		_result->setSoftSkills(_SoftSkills);
	}
	void configureAnotherSkills(string _AnotherSkills)
	{
		_result->setAnotherSkills(_AnotherSkills);
	}
};


class Manager
{
public:
	void setBuilder(Builder *b) { _builder = b; }
	void construct(vector<string> info);
private:
	Builder *_builder;
};
void Manager::construct(vector<string> info)
{
	_builder->configureName(info[0]);
	_builder->configureAge(info[1]);
	_builder->configureText(info[2]);
	_builder->configureSoftSkills(info[3]);
	_builder->configureAnotherSkills(info[4]);
}

int main()
{
	AnketaBuilder anketaBuilder;
	Manager reader;
	reader.setBuilder(&anketaBuilder);

	vector<string> info = {
		"Dima",
		"11.11.2000",
		"none",
		"C++,C,C#,",
		"Communication"
	};

	reader.construct(info);
	anketaBuilder.getResult()->Out_Info();

	system("pause");
}