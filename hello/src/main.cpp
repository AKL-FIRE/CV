#include "arrayList.cpp"

using namespace std;

int main()
{
	arrayList<double> y(10);
	for(int i = 0;i < 6;i++)
		y.insert(i, i+1);

	y.output(cout);
}
