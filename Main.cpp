#include<iostream>
#include<ctime>
#include"Header.h"

using namespace std;

int main() {
	// case 1
	srand(time(0));

	List l;
	for (int i = 0; i < 10; i++) {
		l.push((double)i * 2);
	}
	l.print_stdout();//l : 18 16 14 12 10 8 6 4 2 0 average = 90/10 = 9
	cout << "average = " << 9 << "\n";
	l.del_less_average();
	l.print_stdout();///l : 18 16 14 12 10

	cout << "\n";

	for (int i = 0; i < 5; i++)
		l.pop();
	double avrg = 0;
	for (int i = 0; i < 20; i++) {
		double t = rand() % 30;
		l.push(t);
		avrg += t;
	}
	avrg /= 20;

	l.print_stdout();
	cout << "average = " << avrg << "\n";
	l.del_less_average();
	l.print_stdout();

}