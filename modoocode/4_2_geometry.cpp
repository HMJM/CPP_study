#include <iostream>
#include <cmath>

int init_x, init_y;

class Point {
  int x, y;

 public:
	Point()
	{
		x = init_x++;
		y = init_y++;
	}
	Point(int pos_x, int pos_y)
	{
		x = pos_x;
		y = pos_y;
	}
	int point_x() { return (x); }
	int point_y() { return (y); }
	void ShowPoints() { std::cout << "( " << x << ", " << y << " )"; }
};

class Geometry {
  Point* point_array[100];
  int i;

  double CalcDist(Point a, Point b)
  {
	  unsigned int x;
	  unsigned int y;

	  x = pow(a.point_x() - b.point_x(), 2);
	  y = pow(a.point_y() - b.point_y(), 2);
	  return (sqrt(x + y));
  }

  double CalcSlope(Point a, Point b)
  {
	  int dist_x;

	  if ((dist_x = a.point_x() - b.point_x()) == 0)
	  	return (2147483647);
	  return ((a.point_y() - b.point_y()) / dist_x);
  }

 public:
  Geometry(Point **point_list, int len)
  {
	  for (i = 0; i < len; i++)
	  	point_array[i] = point_list[i];
  }

  Geometry()
  {
	  i = 0;
	  point_array[0] = 0;
  }

  void AddPoint(Point &point)
  {
	  point_array[i++] = &point;
  }

  void PrintDistance()
  {
	  double dist;

	  for (int j = 0; j < i; j++)
	  {
		  for (int k = j + 1; k < i; k++)
		  {
			  dist = CalcDist(*point_array[k], *point_array[j]);
			  std::cout << "Dist [ ";
			  point_array[j]->ShowPoints();
			  std::cout << " , ";
			  point_array[k]->ShowPoints();
			  std::cout << " ] = " << dist << std::endl;
		  }
	  }
  }

  void PrintNumMeets();
  // 교점 구하는 것을 잘 못 하겠음
};

int main (void)
{
	Point *points[10];

	for (int i = 0; i < 10; i++)
	{
		Point *p = new Point();
		points[i] = p;
	}
	Geometry geo(points, 10);
	Point *p = new Point();
	geo.AddPoint(*p);
	geo.PrintDistance();
}
