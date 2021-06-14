#include "complex.h"

string Complex::getNumberNormal() const{
	stringstream ss;
	string out;
	ss << Re << " ", (Im < 0) ? ss << "- " << Im*(-1) << "i": ss << "+ " << Im << "i";  
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
	return ((int)(this->Re*EQUALS) == (int)(c.Re*EQUALS) && (int)(this->Im*EQUALS) == (int)(c.Im*EQUALS)) ? true : false;
}

bool Complex::operator!=(Complex c) {
	return ((int)(this->Re*EQUALS) == (int)(c.Re*EQUALS) && (int)(this->Im*EQUALS) == (int)(c.Im*EQUALS)) ? false : true;
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

void loadNormal(Complex &z){
	string comlexNumber1;
	stringstream ss;
	double a, b;
	char choice;

	std::cin >> comlexNumber1;
	ss << comlexNumber1;
	ss >> a >> b >> choice;
	z.setNormal(a,b);
}

void loadVerzor(Complex &z){
	string comlexNumber1;
	stringstream ss;
	double a, b;
	char choice;

	std::cin >> comlexNumber1;
	ss << comlexNumber1;
	ss >> a >> b >> choice;
	z.setVersor(a,b);
}

void loadComplexNumber(Complex &z){
	char choice;
	//system("clear");
	std::cout << "Do you want to enter a normal form or a verzor form? (N/v)" << endl;
	std::cin >> choice;
	
	if(choice == 'v'){
		std::cout << "Enter a complex number in verzor form(xLy): ";
		loadVerzor(z);
	}
	else{
		std::cout << "Enter a complex numberin normal form(x+/-yi): ";
		loadNormal(z);
	}
}