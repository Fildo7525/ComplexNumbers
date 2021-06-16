#include "complex.h"

int main(){
	system("clear");
	char c;
	Complex z1(10,10),z2(0,10),a1, a2, ans;
	bool loop = true;

	a1 = z1 * z2;
	cout << "Ans1:" << endl;
	a1.print();
	cout << endl;

	a2 = z1 + z2;
	cout << "Ans2:" << endl;
	a2.print();
	cout << endl;

	ans = a1/a2;
	cout << "Ans:" << endl;
	ans.print();
	cout << endl;

	Complex compare(2,6);
	cout << "Compare:" << endl;
	compare.print();
	cout << endl;
	cout << "Comparing: " << (ans==compare) << endl;


	z1.print();
	z2.print();

	
	/*std::cout << "~~~ This is a general Complex number calculator ~~~" << endl << endl;
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
	}*/
	return 0;
}
