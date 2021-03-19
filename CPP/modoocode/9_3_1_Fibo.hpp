#ifndef FIBO_9_3_1_HPP
#define FIBO_9_3_1_HPP

template <int N>
struct fib
{
	static const int value = fib<N - 1>::value + fib<N - 2>::value;
};

template <>
struct fib<0>
{
	static const int value = 1;
};

template <>
struct fib<1>
{
	static const int value = 1;
};

#endif
