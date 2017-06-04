#include <iostream>

class A
{
	public:
	virtual void Run() {std::cout << "I am Running.\n";}
};

class B : public A
{
	public:
	virtual void Run() {std::cout << "I am barking.\n";}
};

int main()
{
	A* m = new B();
	m->Run();
	return 0;
}
