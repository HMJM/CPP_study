#include "9_3_TMP.hpp"
#include "9_3_1_Fibo.hpp"
#include <iostream>
#include <string>

int main()
{
	typedef Ratio<2, 3> rat;
	typedef Ratio<3, 2> rat2;
	typedef Ratio_add<rat, rat2> rat3;
	/* same as
	using rat = Ratio<2, 3>;
	using rat2 = Ratio<3, 2>;
	using rat3 = Ratio_add<rat, rat2>;
	(from C++11)
	*/

	std::cout << "gcd (36, 24) :: " << GCD<36, 24>::value << std::endl;

	std::cout << rat3::num << " / " << rat3::den << std::endl;

	std::cout << fib<5>::value << std::endl;
}
