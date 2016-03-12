#include <functional>

#include "../benchUtil.h"

// Callback Pointer C
// Struct operator() std::function (functor)
// std::function with bind
// std::function Reference
//

const long qty = 1000000000;

class Tomate {
public:
	void Yay() {
		std::cout << "uyay" << std::endl;
	}
	int fuckyou = 42;
	double mangedlamarde = 56;
};

class Base {
public:
	virtual double func(double n);
};

double Base::func(double n)
{
	return n * 2;
}

class A : public Base {
public:
	virtual double func(double n);
};

double A::func(double n)
{
	return n * 2;
}

class Normal {
public:
	double func(double n);
};

double Normal::func(double n)
{
	return n * 2;
}

inline double funcInline(double n)
{
	return n * 2;
}

double func(double n)
{
	return n * 2;
}

auto funcLamda = [](double n) { return n * 2; };

std::function<double(double)> funcFunc = [](double n) { return n * 2.0; };

int main(int argc, char** argv)
{
	Bench::title("Comparing different ways to call methods and functions.");

	Bench::start();
	for (int n = 0; n < qty; n++) {
		func(qty);
	}

	Bench::end("Completely normal function call");

	Bench::start();
	for (int n = 0; n < qty; n++) {
		funcInline(qty);
	}
	Bench::end("Inline function call");

	Bench::start();
	for (int n = 0; n < qty; n++) {
		funcLamda(qty);
	}
	Bench::end("lambda");

	Bench::start();
	for (int n = 0; n < qty; n++) {
		funcFunc(qty);
	}
	Bench::end("std::function and lambda");

	Normal obj;
	Bench::start();
	for (int n = 0; n < qty; n++) {
		obj.func(qty);
	}
	Bench::end("Function called from an object");

	Normal* p = new Normal();
	Bench::start();
	for (int n = 0; n < qty; n++) {
		p->func(qty);
	}
	Bench::end("Function called from a pointer");

	A aobj;
	Bench::start();
	for (int n = 0; n < qty; n++) {
		aobj.func(qty);
	}
	Bench::end("Virtual on object");

	A* aRef = &aobj;
	Bench::start();
	for (int n = 0; n < qty; n++) {
		aRef->func(qty);
	}
	Bench::end("Pointer on virtual on object");

	A& aCast = *aRef;
	Bench::start();
	for (int n = 0; n < qty; n++) {
		aCast.func(qty);
	}
	Bench::end("Reference on pointer on virtual on object");

	A* a = new A();
	Bench::start();
	for (int n = 0; n < qty; n++) {
		a->func(qty);
	}
	Bench::end("Virtual on pointer");

	Tomate t;

#ifdef _MSC_VER
	system("pause");
#endif
}
