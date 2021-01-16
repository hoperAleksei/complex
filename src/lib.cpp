#include <stdexcept>
#include <iostream>
#include "lib.h"


using namespace std;

Complex operator+(Complex a, Complex b)
{
	Complex res;
	
	res.real = a.real + b.real;
	res.imaginary = a.imaginary + b.imaginary;
	
	return res;
}

Complex operator-(Complex a, Complex b)
{
	Complex res;
	
	res.real = a.real - b.real;
	res.imaginary = a.imaginary - b.imaginary;
	
	return res;
}

Complex operator*(Complex a, Complex b)
{
	Complex res;
	
	res.real = (a.real * b.real) - (a.imaginary * b.imaginary);
	res.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
	
	return res;
}

Complex operator/(Complex a, Complex b)
{
	Complex res;
	
	double num;
	double denum;
	
	num = (a.real * b.real) + (a.imaginary * b.imaginary);
	denum = (b.real * b.real) + (b.imaginary * b.imaginary);
	if (denum == 0)
	{
		throw logic_error("ERROR: zero division");
	}
	res.real = num / denum;
	
	num = (b.real * a.imaginary) - (a.real * b.imaginary);
	res.imaginary = num / denum;
	
	return res;
}

void operator+=(Complex &a, Complex b)
{
	a = a + b;
}

void operator-=(Complex &a, Complex b)
{
	a = a - b;
}

void operator*=(Complex &a, Complex b)
{
	a = a * b;
}

void operator/=(Complex &a, Complex b)
{
	a = a / b;
}

ostream& operator<< (ostream& out, Complex a)
{
	
	if ((a.real == 0) && (a.imaginary == 0))
	{
		out << 0;
	}
	else if (a.real == 0)
	{
		out << a.imaginary << 'i';
	}
	else if (a.imaginary == 0)
	{
		out << a.real;
	}
	else
	{
		out << a.real;
		//cout << a.real << endl;
		if (a.imaginary > 0)
		{
			if (a.imaginary == 1)
			{
				out << '+' << 'i';
			}
			else
			{
				out << '+' << a.imaginary << 'i';
			}
		}
		else
		{
			if (a.imaginary == -1)
			{
				out << "-i";
			}
			else
			{
				out << a.imaginary << 'i';
			}
		}
	}
}