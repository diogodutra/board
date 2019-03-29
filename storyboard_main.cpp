#include <stdio.h>
#include "storyboard_test.hpp"
//#include "storyboard.hpp"

bool runAllTests()
{
	bool error = false;
	
	if (testAddNote())
		error = true;
	
	if (testDelNote())
		error = true;
	
	return error;	
}

int main(void)
{
	bool error = runAllTests();
	
    std::cout << std::boolalpha;	
	cout << "Errors = " << (error==true) << endl;
	
	return 0;
}