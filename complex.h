#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <sstream>

#define PI 3.1415926536
#define EQUALS 10000

using namespace std;

class Complex{
	double Re, Im;
	double angle;
	double apsoluteValue;

	Complex &calculateNormal(){
		Re = apsoluteValue * cos(angle * (PI/180));
		Im = apsoluteValue * sin(angle * (PI/180)); 
		return *this;
	}

	Complex &calculateVersor(){
		apsoluteValue = sqrt(pow(Re, 2) + pow(Im, 2));
		angle = atan(Im/(double)Re) * (180/PI);
		return *this;
	}

public:
	Complex() = default;
	Complex(double re, double im) : Re(re), Im(im){
		apsoluteValue = sqrt(pow(Re, 2) + pow(Im, 2));
		angle = atan(Im/Re) * (180/PI);
	}

	Complex &setNormal(double re, double im){
		Re = re;
		Im = im;
		this->calculateVersor();
		return *this;
	}

	Complex &setVersor(double ap, double an){
		apsoluteValue = ap;
		angle = an;
		this->calculateNormal();
		return *this;
	}

	string getNumberNormal() const;
	string getNumberVersor() const;
	
	ostream &print(ostream &os = cout) const;

	Complex operator+(Complex c);
	Complex operator-(Complex c);
	Complex &operator+=(Complex c);
	Complex &operator-=(Complex c);
	bool operator==(Complex c);
	bool operator!=(Complex c);
	Complex operator*(Complex c);
	Complex operator/(Complex c);
	Complex &operator*=(Complex c);
	Complex &operator/=(Complex c);
};

void loadNormal(Complex &z);
void loadVerzor(Complex &z);

void loadComplexNumber(Complex &z);

#endif
