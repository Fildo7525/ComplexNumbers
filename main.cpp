#include "complex.h"

int main(){
	system("clear");
	char c;
	Complex z,x;
	bool loop = true;
	
	std::cout << "~~~ This is a general Complex number calculator ~~~" << endl << endl;
	while(loop){
		cout << "Do you want to:\n\ta) Display number\n\tb) add numbers\n\tc) substract numbers\n\td) multiply numbers\n\te) divide numbers\n\tf) compare numbers\n\n"<<ends;
		cin >> c;
		switch (c)
		{
			case 'a':
				loadComplexNumber(z);
				z.print();
				break;

			case 'b':
				loadComplexNumber(z);
				loadComplexNumber(x);
				z += x;
				cout << "Z:\n\t";
				z.print();
				break;
			
			case 'c':
				loadComplexNumber(z);
				loadComplexNumber(x);
				z -= x;
				cout << "Z:\n\t";
				z.print();
				break;

			case 'd':
				loadComplexNumber(z);
				loadComplexNumber(x);
				z *= x;
				cout << "Z:\n\t";
				z.print();
				break;
			
			case 'e':
				loadComplexNumber(z);
				loadComplexNumber(x);
				z /= x;
				cout << "Z:\n\t";
				z.print();
				break;

			case 'f':
				string str;
				loadComplexNumber(z);
				loadComplexNumber(x);
				str = (z == x) ? "Equal" : "Unequal";
				cout << str << endl;
				z.print();
				x.print();
				break;
		}
		cout << "Do you want to enter another entry?(Y/n)" << endl;
		cin >> c;
		if(c == 'n' || c == 'N')
			loop = false;
		system("clear");
	}
	return 0;
}