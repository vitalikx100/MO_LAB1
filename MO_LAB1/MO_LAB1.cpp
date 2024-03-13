#include <iostream>

using namespace std;

double func(double x)
{
	return x + 1 / (x - 2.5);
}

double fib(int n)
{
	if (n <= 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

double dixotomia(double a, double b, double delta)
{
	double x_c;
	double eps = delta / 100;
	int n = 0;
	while (abs(a - b) > 2 * delta)
	{
		x_c = (a + b) / 2;
		double x_1 = x_c - eps / 2;
		double x_2 = x_c + eps / 2;

		if (func(x_1) > func(x_2)) a = x_1;
		else b = x_2;

		n+=2;
	}

	cout << a << " " << b << " " << (a + b) / 2 << " " << n << " " << (b - a) / 2 << endl;
	return a, b, n;
}

double golden_ratio(double a, double b, double delta)
{
	double fi = (1 + sqrt(5)) / 2;
	double x_1 = b - (b - a) / fi;
	double x_2 = a + (b - a) / fi;

	double f_x1 = func(x_1);
	double f_x2 = func(x_2);

	int n = 2;
	while (abs(a - b) > 2 * delta)
	{
		
		if (f_x1 > f_x2)
		{
			a = x_1;
			x_1 = x_2;
			f_x1 = f_x2;
			x_2 = b - (x_1 - a);
			f_x2 = func(x_2);
		}
		else 
		{
			b = x_2;
			x_2 = x_1;
			f_x2 = f_x1;
			x_1 = a + (b - x_2);
			f_x1 = func(x_1);
		}

		n++;
	}
	
	cout << a << " " << b << " " << (a + b) / 2 << " " << n <<" "<<(b - a) / 2 << endl;
	return a, b, n;

}

double fib_method(double a, double b, double delta)
{
	int n = 0;

	while (fib(n) <= (b - a) / delta) n++;
	
	n =	20;
	int i = 2;

	double x_1 = a + fib(n - 2) / fib(n) * (b - a);
	double x_2 = a + fib(n - 1) / fib(n) * (b - a);

	double f_x1 = func(x_1);
	double f_x2 = func(x_2);
	while (n > 0)
	{
		double eps = (b - a) / 100;
		if (f_x1 > f_x2)
		{
			a = x_1;
			x_1 = x_2;
			f_x1 = f_x2;
			x_2 = a + fib(n - 1) / fib(n) * (b - a);
			if (abs(x_2 - x_1) < eps) x_2 += eps;
			f_x2 = func(x_2);
		}
		else
		{
			b = x_2;
			x_2 = x_1;
			f_x2 = f_x1;
			x_1 = a + fib(n - 2) / fib(n) * (b - a);
			if (abs(x_2 - x_1) < eps) x_1 -= eps;
			f_x1 = func(x_1);
		}
		n--;
		i++;
		cout.precision(15);
		cout <<a<<" "<< b << " " << b - a <<" "<<x_1<<" "<<x_2<< endl;
	}

	cout << a << " " << b << " " << (a + b) / 2<< " " << i <<" "<< (b - a) / 2;

	return a< b, i;
}




int main()
{
	double a = 3;
	double b = 6;
	double delta = 0.0001;

	dixotomia(a, b, delta);
	golden_ratio(a, b, delta);
	fib_method(a, b, delta);

}