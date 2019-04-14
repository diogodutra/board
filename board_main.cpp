#include <stdio.h>
#include "board_test.hpp"
//#include "board.hpp"

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
	cout << "Errors = " << (error == true) << endl;
	
	return 0;
}