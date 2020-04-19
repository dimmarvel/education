#include<iostream>

using namespace std;

struct arr {

	arr() { size_ = 0; data_ = new double(); }
	explicit arr(size_t num, double def = 0.);

	~arr();

	arr(arr const& other);
	arr& operator=(arr other);

	double& at(size_t i) { return data_[i]; }
	double  at(size_t i) const { return data_[i]; }

	size_t size() const { return size_; }
	bool   empty() const { return data_ == NULL ? true : false; }

	void resize(size_t i) { size_ = i; }
	void push_back(double);

private:
	void fill_with(double value);

private:
	double* data_;
	size_t  size_;
};

arr::arr(size_t num, double def)
	: data_(new double[num]),
	size_(num)
{
	fill_with(def);
}

arr::arr(arr const& other) //copy constructor
	: data_(new double[other.size_])
	, size_(other.size_)
{
	copy(data_, data_ + size_, other.data_);
}

arr::~arr() {
	delete data_;
}
/*
//this == swap trik look down
arr& arr::operator=(arr const& other) {

	if (&other != this) {
		delete data_;
		data_ = new double(other.size_);
		size_ = other.size_;
		copy(data_, data_ + size_, other.data_);
	}

	return *this;
}
*/

//swap trik
arr& arr::operator=(arr other) {
	swap(*this, other);
	return *this;
}

void arr::push_back(double value) {
	delete data_;
	data_ = new double(value);
}

void arr::fill_with(double value) {
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = value;
	}
}


int main() {
	arr a1(5, 5.);

	arr a2(10,3.);
	cout << a2.at(4) << endl;
	cout << a1.at(2) << endl;
	system("pause");
}