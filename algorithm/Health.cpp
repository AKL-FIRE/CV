#include<iostream>

int main()
{
	int p, e, i, d;
	std::cin >> p >> e >> i >> d;
	int temp = (21252 + p) / 23;
	for(int h = 1; h <= temp; h++)
		if((h * 23 + p - e) % 28 == 0)
			if((h * 23 + p - i) % 33 == 0)
				{
				std::cout << "the next triple peak occurs in " << h * 23 + p - d << " days.\n";
				break;
				}
	return 0;
}
