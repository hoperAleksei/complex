#pragma once

struct Complex {
	double real = 0;
	double imaginary = 0;
};

Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);

void operator+=(Complex &a, Complex b);
void operator-=(Complex &a, Complex b);
void operator*=(Complex &a, Complex b);
void operator/=(Complex &a, Complex b);

std::ostream& operator<< (std::ostream &out, Complex a);