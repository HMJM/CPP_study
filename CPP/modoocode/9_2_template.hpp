#ifndef TEMPLATE_9_2_HPP
# define TEMPLATE_9_2_HPP

# include <iostream>
# include <string>

template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args)
{
	std::cout << arg << ' ';
	print(args...);
}

template <typename T>
size_t getStrLen(T str)
{
	return (std::string(str).length());
}

template <typename T, typename... Types>
size_t getStrLen(T str, Types... strs)
{
	return (std::string(str).length() + getStrLen(strs...));
}

void appendStr(std::string &dst) { return ; }

template <typename T, typename... Types>
void appendStr(std::string &dst, const T &src, Types... strs)
{
	dst.append(src);
	appendStr(dst, strs...);
}

template <typename T, typename... Types>
std::string myStrCat(const T str, Types... strs)
{
	std::string ret;

	ret.reserve(getStrLen(str, strs...));
	ret = str;
	appendStr(ret, strs...);
	return (ret);
}

template <typename... Types>
int			sum(Types... args)
{
	return (... + args);
}

template <typename... Types>
int			calcAverage(Types... args)
{
	return (::sum(args...) / sizeof...(args));
}

#endif
