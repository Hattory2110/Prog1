//g++ drill_5.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Lines_window.h"

int main()
{try{
	Lines_window win {Point{100,100}, 1200,800, "Canvas"};
	
	return gui_main();


}catch(exception& e){
	cerr<<"error: "<<e.what()<<'\n';
	return 1;
	
}catch(...){
	cerr<<"Something went wrong."<<'\n';
	return 2;
}
}
