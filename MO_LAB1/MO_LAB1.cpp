#include <iostream>

using namespace std;

double func(double x)
{
	return x + 1 / (x - 2.5);
}

double fib(int n)
{
	if (n <= 1) return n;
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

	cout << a << " " << b << " " << (a+b)/2 << " "<< n<< " "<<(b-a)/2;
	return a, b, n;
}

double golden_ratio(double a, double b, double delta)
{
	double fi = (sqrt(5) - 1) / 2;

	double x_1 = a + (1 - fi) * (b - a);
	double x_2 = a + fi * (b - a);

	double func_1 = func(x_1);
	double func_2 = func(x_2);

	int n = 0;
	while (abs(a - b) > 2 * delta)
	{
		double x_1 = a + (1 - fi) * (b - a);
		double x_2 = a + fi * (b - a);



		

		n++;
	}
	
	cout << a << " " << b << " " << (a+b)/2<<" "<<n;
	return a, b, n;

}

double fib_method(double a, double b)
{
	int n;
	cin >> n;

	double delta = (b - a) / fib(n);

	while (abs(a - b) > delta)
	{
		double x_1 = a + fib(n - 2) / fib(n) * (b - a);	
		double x_2 = a + fib(n - 1) / fib(n) * (b - a);

		if (func(x_1) > func(x_2)) a = x_1;
		else b = x_2;
	}

	cout << a <<" "<< b;

	return a< b, n;
}




int main()
{
	double a = 3;
	double b = 6;
	double delta = 0.001;

	dixotomia(a, b, delta);
	golden_ratio(a, b, delta);
	//fib_method(a, b);

}