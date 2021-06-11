#include "complex.h"

int main(){
	Complex z, x(rand() % 15, rand() % 15), y;
	cout << "x:" << endl;
	x.print();

	cout << "Z:" << endl;
	z.setVersor(sqrt(50), 64).print();
	cout << endl;

	cout << "x += z" << endl;
	x += z;
	x.print();
	cout << endl;

	cout << "x -= z" << endl;
	x -= z;
	x -= z;
	x.print();
	cout << endl;

	cout << "x *= z" << endl;
	x *= z;
	x.print();
	cout << endl;

	cout << "x /= z" << endl;
	z /= z;
	x.print();
	cout << endl;

	cout << "y = z - x" << endl;
	y = z - x;
	y.print();
	cout << endl;

	cout << "y = z + x" << endl;
	y = z + x;
	y.print();
	cout << endl;

	cout << "y = z * x" << endl;
	y = z * x;
	y.print();
	cout << endl;

	cout << "y = z / x" << endl;
	y = z / x;
	y.print();
	cout << endl;
	//cout << "Complex size: " << sizeof(z) << endl;
	return 0;
}
