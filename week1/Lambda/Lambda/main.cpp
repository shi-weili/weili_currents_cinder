
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// 1A - Definition

// [capture list] (parameter list) -> return type { function body }
// [capture list] { function body }

auto calculateUltimatedAnswer = [] { return 42; };

// Equivalent to:
// int calculateUltimateAnswer() { return 42; }

// 2B - Passing argument to a lambda; Passing lambda as an argument.

class Country {
public:
	string name;
	int population;
};

auto smaller = [] (shared_ptr<Country> &country1, shared_ptr<Country> &country2) {
	return country1->population <= country2->population;
};

int main(int argc, const char * argv[]) {
	
	// 1B - Definition
	int answer = calculateUltimatedAnswer();
	cout << answer << endl;
	
	// 2A - Passing argument to a lambda; Passing lambda as an argument.
	vector<int> number;
	for (int i = 0; i < 10; i++) {
		number.push_back(rand() % 100);
	}
	for (auto it = number.begin(); it != number.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	
	// Introducing std::sort()
	sort(number.begin(), number.end(), less<int>());
		// less<T>() is a function template.
	for (auto it = number.begin(); it != number.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	
	sort(number.begin(), number.end(), greater<int>());
	// less<T>() is a function template.
	for (auto it = number.begin(); it != number.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	
	vector<shared_ptr<Country>> countries;
	
	auto c1 = shared_ptr<Country>(new Country);
	c1->name = "United States";
	c1->population = 325629697;
	countries.push_back(c1);
	
	auto c2 = shared_ptr<Country>(new Country);
	c2->name = "China";
	c2->population = 1386103746;
	countries.push_back(c2);
	
	auto c3 = shared_ptr<Country>(new Country);
	c3->name = "Vatican";
	c3->population = 451;
	countries.push_back(c3);
	
	for (auto it = countries.begin(); it != countries.end(); it++) {
//		cout << typeid(it).name() << endl;
//		cout << typeid(*it).name() << endl;
//		cout << typeid((*it)->name).name() << endl;
		cout << (*it)->name << endl;
	}
	cout << endl;
	
	sort(countries.begin(), countries.end(), smaller);
	for (auto it = countries.begin(); it != countries.end(); it++) {
		cout << (*it)->name << endl;
	}
	cout << endl;
	
	sort(countries.begin(), countries.end(), [] (shared_ptr<Country> &country1, shared_ptr<Country> &country2) {
		return country1->population >= country2->population;
	});
	for (auto it = countries.begin(); it != countries.end(); it++) {
		cout << (*it)->name << endl;
	}
	cout << endl;
	
	// 3 - Captures
	
	// Capture by value:
	auto f1 = [answer] { cout << answer << endl; }; // Answer is a local int varibable of main() captured by the lambda.
	f1();
	
	answer = 43;
	f1();
	
	// Capture by reference:
	auto f2 = [&answer] { cout << answer << endl; };
	f2();
	answer = 42;
	f2();
	
	auto f3 = [&answer] { answer = 0; };
	f3();
	cout << answer << endl;
	
	answer = 42;
	int question = 0;
	auto f4 = [=] { cout << answer << question << endl; };
	answer = 43;
	f4();
	
	auto f5 = [&] { answer = 0; };
	f5();
	cout << answer << endl;
	
    return 0;
}
