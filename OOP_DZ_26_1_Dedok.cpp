#include <iostream>
#include <string>
using namespace std;
class TooFewDigitsException : public exception {
public:
	const char* what() const {
		return "Number contains 5 or fewer digits.";
	}
};
class TooManyDigitsException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Number contains 7 or more digits.";
	}
};
bool isHappyNumber(int number) {
	string numStr = to_string(number);
	if (numStr.length() <= 5)
		throw TooFewDigitsException();
	else if (numStr.length() >= 7)
		throw TooManyDigitsException();
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < numStr.length() / 2; ++i) {
		sum1 += numStr[i] - '0';
		sum2 += numStr[numStr.length() - i - 1] - '0';
	}
	return sum1 == sum2;
}
int main()
{
	int number;
	cout << "Enter a 6-digit number: ";
	cin >> number;
	try {
		if (isHappyNumber(number))
			cout << number << " is a happy number." << endl;
		else
			cout << number << " is not a happy number." << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}


