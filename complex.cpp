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

Complex Complex::operator+(Complex c) {
	Complex sum(this->Re + c.Re, this->Im + c.Im);
	return sum;
}

Complex Complex::operator-(Complex c) {
	Complex diff(this->Re - c.Re, this->Im - c.Im);
	return diff;
}

Complex &Complex::operator+=(Complex c) {
	this->Re += c.Re;
	this->Im += c.Im;
	this->calculateVersor();
	return *this;
}

Complex &Complex::operator-=(Complex c){
	this->Re -= c.Re;
	this->Im -= c.Im;
	this->calculateVersor();
	return *this;
}

bool Complex::operator==(Complex c) {
	return (this->Re == c.Re && this->Im == c.Im) ? true : false;
}

bool Complex::operator!=(Complex c) {
	return (this->Re == c.Re && this->Im == c.Im) ? false : true;
}

Complex Complex::operator*(Complex c) {
	Complex mult(this->apsoluteValue * c.apsoluteValue, this->angle + c.angle);
	return mult;
}

Complex Complex::operator/(Complex c) {
	Complex div(this->apsoluteValue / c.apsoluteValue, this->angle - c.angle);
	return div;
}

Complex &Complex::operator*=(Complex c) {
	this->apsoluteValue *= c.apsoluteValue;
	this->angle += c.angle;
	this->calculateNormal();
	return *this;
}

Complex &Complex::operator/=(Complex c) {
	this->apsoluteValue /= c.apsoluteValue;
	this->angle -= c.angle;
	this->calculateNormal();
	return *this;
}