#include <iostream>
using namespace std;
/*
1.	Базовый конструктор																		+
2.	Конструктор копирования																	+
3.	Оператор присваивания копированием														+
4.	Деструктор																				+
5.	Операторы += и +, *= и *																+
6.	Оператор ++ префиксный и постфиксный (увеличение действительной части числа на 1)		+
7.	Операторы ввода и вывода																+

*/

struct Complex
{
private:

	long long n_R = 0;
	long long n_C = 0;

public:

	friend ostream& operator << (ostream& out, const Complex& c);
	friend istream& operator >> (istream& in, Complex& c);

	explicit Complex() : n_R(0), n_C(0) { }

	Complex(long long r, long long i) : n_R(r), n_C(i) { }

	Complex(long long r) : n_R(r), n_C(0) { }


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	~Complex() { }
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


	Complex(const Complex& other) : Complex(other.n_R, other.n_C) {}


	Complex& operator = (const Complex& other)
	{
		Complex tmp = other;
		swap(this->n_R, tmp.n_R);
		swap(this->n_C, tmp.n_C);

		return *this;
	}

	Complex& operator += (const Complex& other) //оператор +=
	{
		long long real = this->n_R + other.n_R;
		long long imag = this->n_C + other.n_C;

		Complex tmp(real, imag);

		swap(this->n_R, tmp.n_R);
		swap(this->n_C, tmp.n_C);

		return *this;
	}

	Complex operator + (const Complex& other) const  //оператор +
	{
		Complex tmp = *this;
		tmp += other;
		return tmp;

	}

	Complex& operator *= (const Complex& other)  //оператор *=
	{
		long long real = this->n_R * other.n_R - this->n_C * other.n_C; 
		long long imag = this->n_C * other.n_R + this->n_R * other.n_C;

		Complex tmp(real, imag);

		swap(this->n_R, tmp.n_R);
		swap(this->n_C, tmp.n_C);

		return *this;

		// (1+3i)*(1+2i)=(1*1-3*2)+(2*1+3*1)i=-5+5i
	}

	Complex operator * (const Complex& other) const //оператор *
	{
		Complex tmp = *this;
		tmp *= other;
		return tmp;

	}

	Complex& operator ++ ()			//префикс
	{
		this->n_R++;
		return *this;

	}

	Complex operator ++ (int)		//постфикс
	{
		Complex tmp = *this;
		++this->n_R;
		return tmp;
	}
}; //-5+5i->-4+5i

ostream& operator << (ostream& out, const Complex& c)
{
	if (c.n_C < 0) {out << c.n_R << " - " << c.n_C * (-1) << "i";}
	else {out << c.n_R << " + " << c.n_C << "i";}
	return out;
}

istream& operator >> (istream& in, Complex& c)
{
	in >> c.n_R;
	in >> c.n_C;

	return in;
}

int main()
{
	Complex c1(1, 3);
	Complex c2(1, 2);
	Complex c3 = c1 + c2;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	c1 *= c2;
	cout << "c1*=c2: " << c1 << endl;
	Complex ppc = ++c1;
	cout << "++c: " << ppc << endl;
	cout << "c: " << c1 << endl;
	Complex cpp = c1++;
	cout << "c++: " << cpp << endl;
}