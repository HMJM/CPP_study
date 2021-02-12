#include <iostream>
#include <string>

class Date {
	private:
  	int year_;
		int month_;
	  int day_;

		int CalcMonthDays(int month)
		{
				int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
				
				if (month == 2 && year_ % 4 == 0)
				{
						if (year_ % 100 == 0)
						{
								if (year_ % 400 == 0)
									return (29);
								else
									return (28);
						}
						else
								return (29);
				}
				else
					return (days[month]);
		}

 public:
  void SetDate(int year, int month, int date)
  {
	  year_ = year;
	  month_ = month;
	  day_ = date;
	  return ;
  }
  void AddYear(int inc)
  {
		if (year_ + inc < 0)
				std::cout << "Warning: Result below is not valid!" << std::endl;
		else
	  		year_ += inc;
	  return ;
  }
  void AddMonth(int inc)
  {
		while (inc)
		{
				if (month_ + inc > 12)
				{
						AddYear(1);
						inc -= 12;
				}
				else if (month_ + inc < 1)
				{
						AddYear(-1);
						inc += 12;
				}
				else
				{
						month_ += inc;
						inc = 0;
				}
		}
		return ;
  }
  void AddDay(int inc)
  {
		int tmp;

		while (inc)
		{
				if ((tmp = CalcMonthDays(month_)) < day_ + inc)
				{
						inc = inc - tmp;
						AddMonth(1);
				}
				else if (day_ + inc < 1)
				{
						AddMonth(-1);
						inc = inc + CalcMonthDays(month_);
				}
				else
				{
						day_ += inc;
						inc = 0;
				}
		}
		return ;
  }
  void ShowDate()
  {
	  std::cout << year_ << "/" << month_ << "/" << day_ << std::endl;
	  return ;
  }
};

int main(int argc, char **argv)
{
	Date				date;
	std::string str1(argv[1]);
	std::string str2(argv[2]);
	std::string str3(argv[3]);

	date.SetDate(1900, 01, 01);
	date.AddYear(std::stoi(str1));
	date.ShowDate();
	date.AddMonth(std::stoi(str2));
	date.ShowDate();
	date.AddDay(std::stoi(str3));
	date.ShowDate();
	return (0);
}
