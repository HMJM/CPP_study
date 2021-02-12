#include "9_2_template.hpp"

/*
warning: variadic templates are a C++11 extension [-Wc++11-extensions]
template <typename T, typename... Types>

warning: pack fold expression is a C++17 extension [-Wc++17-extensions]
        return (... + args);
*/

int main(void)
{
	print('a', 'b', "cde", 0.1f, 3);
	
	std::cout << myStrCat("adsdasdsd", "dasdasdsd", "21321") << std::endl;

	std::cout << calcAverage(1, 2, 3, 4, 5) << std::endl;
	return (0);
}
