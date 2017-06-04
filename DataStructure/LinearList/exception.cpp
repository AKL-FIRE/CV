#include <iostream>

class illegalParameterValue
{
	private:
		std::string str;
	public:
		illegalParameterValue(std::string thestr) : str(thestr) {}
		illegalParameterValue(char* thestr) {str = thestr;}
		void outputMessage() {std::cout << str << std::endl;}
};

class illegalIndex
{
	private:
		std::string str;
	public:
		illegalIndex(std::string thestr) : str(thestr) {}
		illegalIndex(char* thestr) {str = thestr;}
		void outputMessage() {std::cout << str << std::endl;}
};
