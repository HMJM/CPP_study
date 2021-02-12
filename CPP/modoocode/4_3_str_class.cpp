#include <string.h>
#include <iostream>

class string {
	char *str;
	int len;

	public:
		string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
		string(const char *s);
		string(const string &s);
		~string();

		void add_string(const string &s);   // str 뒤에 s 를 붙인다.
		void copy_string(const string &s);  // str 에 s 를 복사한다.
		int ft_strlen();
		void show_string();
};

int string::ft_strlen()
{
	int		len = 0;

	while (str[len])
		len++;
	return (len);
}

string::string(char c, int n)
{
	len = n;
	string::str = new char[len + 1];
	memset(str, c, len);
	str[len] = 0;
}

string::string(const char *s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

string::string(const string &s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

string::~string()
{
	if (str)
		delete[] str;
}

void string::add_string(const string &s)
{
	char *tmp;

	len += s.len;
	tmp = new char[len + 1];
	strcpy(tmp, str);
	strcat(tmp, s.str);
	delete[] str;
	str = tmp;
}

void string::copy_string(const string &s)
{
	strlcpy(str, s.str, len + 1);
}

void string::show_string()
{
	std::cout << str << std::endl;
}

int main(void)
{
	string a('*', 8);
	string b("abcde");
	string c("12345");

	a.show_string();
	b.show_string();
	c.show_string();
	a.add_string(c);
	a.show_string();
	a.copy_string(b);
	a.show_string();
	b.add_string(c);
	b.show_string();
	return (0);
}
