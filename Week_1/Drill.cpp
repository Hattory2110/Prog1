#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
	using namespace Graph_lib;

	int xmax = 600;
	int ymax = 400;

	int x_orig = xmax/12;
	int y_orig = ymax/8;

	int rmin = -11;
	int rmax = 11;
    
	int n_points = 600;

	Simple_window win {Point{200,200}, xmax, ymax, "My window"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 100;
	int ylength = ymax - 50;

	int xscale = 20, yscale = 20;

	Axis x {Axis::x, Point{30, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 30}, ylength, ylength/yscale, "y"};
	
	x.set_color(Color::blue);
	x.label.set_color(Color::cyan);
	
	y.set_color(Color::green);
	y.label.set_color(Color::dark_green);
	
	
	Function consline (one, rmin, rmax, origo, n_points, xscale, yscale);
	consline.set_color(Color::white);
	
	Function parab (square, rmin, rmax, origo, n_points, xscale, yscale);
	parab.set_color(Color::yellow);
	parab.set_style(Line_style(Line_style::dash, 8));
	
	Function cos_func ( [] (double x) { return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale);
	cos_func.set_style(Line_style(Line_style::dash, 2));
	
	Polygon poly;
	poly.add(Point{50,50});
	poly.add(Point{150,200});
	poly.add(Point{300,300});
	
	poly.set_color(Color::dark_red);
	poly.set_style(Line_style::dash);

	
	Rectangle r {Point{200,200}, 200,100};

	r.set_fill_color(Color::black);
	r.set_style(Line_style(Line_style::dash, 4));

	Closed_polyline cpoly;
	cpoly.add(Point{25,50});
	cpoly.add(Point{100,50});
	cpoly.add(Point{300,20});
	cpoly.add(Point{105,300});
	


	Text t {Point{200,400}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(40);

	Image ii {Point{100,100}, "badge.jpg"};
	ii.set_mask(Point(120,120),50,50);
	
	Circle c {Point{150,150}, 70};

	Ellipse e {Point{200,200}, 60, 30};
	e.set_fill_color(Color::white);

	win.attach(poly);
	win.attach(cpoly);
	win.attach(r);
	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(consline);
	win.attach(parab);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);
	
	win.wait_for_button();
}
