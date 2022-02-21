/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 1000;
    int ymax = 800;
	Simple_window win {Point{100,100}, xmax, ymax, "Display"};

	Lines grid;	
	
	Vector_ref<Rectangle> diagonal;

	for(int i=0; i<=8; ++i)
	{
		grid.add(Point(0,i*100), Point(800,i*100));
		grid.add(Point(i*100,0), Point(i*100,800));
		diagonal.push_back(new Rectangle(Point(i*100,i*100),100,100));
		diagonal[diagonal.size()-1].set_fill_color(Color::red);
		win.attach(diagonal[diagonal.size()-1]);
	}
	win.attach(grid);
	/*
	for(int i=2; i<=8; i+=2)
	{
		Image kep(Point(100,i*100), "badge.jpg");
		//kep.set_mask(Point(40,40),200,200);
		win.attach(kep);
	}*/
	
	Image kep(Point(0,200), "badge.jpg");
	kep.set_mask(Point(100,100),200,200);
	win.attach(kep);
	
	Image kep2(Point(0,400), "badge.jpg");
	kep2.set_mask(Point(100,100),200,200);
	win.attach(kep2);
	
	Image kep3(Point(0,600), "badge.jpg");
	kep3.set_mask(Point(100,100),200,200);
	win.attach(kep3);
	win.wait_for_button();

	Image mkep(Point(0,0), "badge.jpg");
	mkep.set_mask(Point(120,120),100,100);
	win.attach(mkep);
	
	for(int i=0; i<4; ++i)
	{
		mkep.move(100,0);
		win.wait_for_button();
		win.attach(mkep);
	}
}
