#ifndef COMPLEX
#define COMPLEX

#include <iostream>
#include <cmath>

#define PI 3.1415926536
using namespace std;

class Complex{
	double Re, Im;
	double angle;
	double apsoluteValue;

	Complex &calculateNormal(){
		Re = apsoluteValue * cos(angle);
		Im = apsoluteValue * sin(angle); 
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
	/*Complex(double an, double val) : angle(an), apsoluteValue(val){
		Re = apsoluteValue * cos(angle);
		Im = apsoluteValue * sin(angle); 
	}*/

	Complex &setNormal(double re, double im){
		Re = re;
		Im = im;
		return *this;
	}

	Complex &setVersor(double ap, double an){
		apsoluteValue = ap;
		angle = an;
		return *this;
	}

	string getNumberNormal() const;
	string getNumberVersor() const;
	
	ostream &print(ostream &os = cout) const;

	Complex operator+(Complex c) const;
	Complex operator-(Complex c) const;
	Complex &operator+=(Complex c);
	Complex &operator-=(Complex c);
	bool operator==(Complex c) const;
	bool operator!=(Complex c) const;
	Complex operator*(Complex c) const;
	Complex operator/(Complex c) const;
	Complex &operator*=(Complex c);
	Complex &operator/=(Complex c);

};

#endif