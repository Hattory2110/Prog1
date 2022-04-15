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

for(int i=2; i<=8; i+=2)
{
Image kep(Point(0,i*100), "badge.jpg");
kep.set_mask(Point(40,40),200,200);
}

Image mkep(Point(0,0), "badge.jpg");
mkep.set_mask(Point(40,40),100,100);

for(int i=0; i<4; ++i)
{
mkep.move(i*100,0);
win.wait_for_button();
}


}
