#include "Simple_window.h"
#include "Graph.h"

#include "std_lib_facilities.h"

double one(double x) {return x;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

int main()
{
	using namespace Graph_lib;
	
	int xmax=600;
	int ymax=600;
	
	Simple_window win {Point{120,120}, xmax, ymax, "Function graphs" };
	
	int x_orig=300;
	int y_orig=300;
	
	constexpr int x_scale=20;
	constexpr int y_scale=20;
	
	int x_length=400;
	int y_length=400;
	
	Point orig {x_orig, y_orig};
	
	Axis x {Axis::x, Point{100, y_orig}, x_length, x_length/x_scale, "x"};
	Axis y {Axis::y, Point{x_orig, y_length + 100}, y_length, y_length/y_scale, "y"};

	x.set_color(Color::red);
	y.set_color(Color::red);


	constexpr int r_min=-10;
	constexpr int r_max=11;
	
	int num_points=400;
	
	Function f1 {one, r_min, r_max, orig, num_points,x_scale,y_scale };
	Function f2 {slope, r_min, r_max, orig, num_points,x_scale,y_scale };
	
	Text label {Point{450,250}, "x/2"};

	Function f3 {square, r_min, r_max, orig, num_points, x_scale, y_scale};
	Function f4 {cos, r_min, r_max, orig, num_points, x_scale, y_scale};
	f4.set_color(Color::blue);

	Function f5 {sloping_cos, r_min, r_max, orig, num_points, x_scale, y_scale};

	
	win.attach(x);
	win.attach(y);
	win.attach(f1);
	win.attach(f2);
	win.attach(label);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	
	
	
	
	
	win.wait_for_button();
}
