#include <iostream>

using std::cout, std::cin, std::endl;
bool is_valid_range(int a, int b);
char classify_mv_range_type(int a);
void count_valid_mv_numbers(int a, int b);

int main() {
	// TODO(student): print prompt for input
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	// TODO(student): read the numbers from standard input
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;


	// TODO(student): validate input (and reprompt on invalid input)
	while (!is_valid_range(a, b))
		{
			cout << "Invalid Input" << endl;
			cout << "Enter numbers 10 <= a <= b < 10000: ";// allow input values to be put up again
			cin >> a;
			cin >> b;

		}
		count_valid_mv_numbers(a,b);	
	// TODO(student): compute and display solution
	
	return 0;
}