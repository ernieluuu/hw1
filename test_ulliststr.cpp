#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	//ULListStr myULListStr;

	///*first test push_back and push_front*/

	//string seven = "7";

	//myULListStr.push_back(seven);

	//cout << "Value: " << myULListStr.front() << endl;

	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");

	string zero = dat.get(0);
	string one = dat.get(1);
	string two = dat.get(2);

	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	// prints: 8 7 9
	cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

	return 0;
}
