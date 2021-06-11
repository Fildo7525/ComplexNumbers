#include "complex.h"

#include <sstream>
#include <string>

string Complex::getNumberNormal() const{
	stringstream ss;
	string out;
	ss << Re << " + " << Im << "i";   
	getline(ss, out);
	return out;
}

string Complex::getNumberVersor() const{
	stringstream ss;
	string out;
	ss << apsoluteValue << " L " << angle;
	getline(ss, out);
	return out;
}

ostream &Complex::print(ostream &os) const{
	cout << "Normal: " << getNumberNormal() << "\nVersor: " << getNumberVersor() << endl;
	return os;
}

inline Complex Complex::operator+(Complex c) const{
	Complex sum(this->Re + c.Re, this->Im + c.Im);
	return sum;
}

inline Complex Complex::operator-(Complex c) const{
	Complex diff(this->Re - c.Re, this->Im - c.Im);
	return diff;
}

inline Complex &Complex::operator+=(Complex c) {
	this->Re += c.Re;
	this->Im += c.Im;
	this->calculateVersor();
	return *this;
}

inline Complex &Complex::operator-=(Complex c){
	this->Re += c.Re;
	this->Im += c.Im;
	this->calculateVersor();
	return *this;
}

inline bool Complex::operator==(Complex c) const{
	return (this->Re == c.Re && this->Im == c.Im) ? true : false;
}

inline bool Complex::operator!=(Complex c) const{
	return (this->Re == c.Re && this->Im == c.Im) ? false : true;
}

inline Complex Complex::operator*(Complex c) const{
	Complex mult(this->apsoluteValue * c.apsoluteValue, this->angle + c.angle);
	return mult;
}

inline Complex Complex::operator/(Complex c) const{
	Complex div(this->apsoluteValue / c.apsoluteValue, this->angle - c.angle);
	return div;
}

inline Complex &Complex::operator*=(Complex c) {
	this->apsoluteValue *= c.apsoluteValue;
	this->angle += c.angle;
	this->calculateNormal();
	return *this;
}

inline Complex &Complex::operator/=(Complex c) {
	this->apsoluteValue /= c.apsoluteValue;
	this->angle -= c.angle;
	this->calculateNormal();
	return *this;
}