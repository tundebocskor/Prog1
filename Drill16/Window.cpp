#include "Window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib {

Window::Window(int ww, int hh, const string& title)

:Fl_Window(ww,hh,title.c_str()),w(ww),h(hh)
{
	init();
}

Window::Window(Point xy, int ww, int hh, const string& title)
// el kell kérnünk a koordinátákat
:Fl_Window(xy.x,xy.y,ww,hh,title.c_str()),w(ww),h(hh)
{ 
	init();
}

void Window::init()
{
	//ez fogja kirajolni azt az ablakot, ami méretezhető
   resizable(this);
   show();
} 

void Window::draw()
{
	Fl_Window::draw(); 
	//Végig megyünk a shape-eken, és a megfelelő drawlines függvényt fogja meghivni 
	//unsigned, az előjel nélküli, vagyis nem lehet negativ 

	for (unsigned int i=0; i<shapes.size(); ++i) shapes[i]->draw();
}
//ezt ablakra fogjuk fölcsatolni 
void Window::attach(Widget& w)
{
	begin();
		w.attach(*this);
		//ezzel jelezzük(end), hogy nem akarunk többet fölcsatolni 

	end();
}

void Window::detach(Widget& b)
{
	  b.hide();
}

void Window::attach(Shape& s)
{
		shapes.push_back(&s);
}
void Window::detach(Shape& s)
{
	//a végéről haladunk előre 
	//ha megtaláltuk  shape_t, akkor kiszedjük 
	//kitöröljük az utolsót 
		for (unsigned int i = shapes.size(); 0<i; --i)
			if (shapes[i-1]==&s)
				shapes.erase(shapes.begin()+(i-1));
}

void Window::put_on_top(Shape& p) {
	for (int i=0; i<shapes.size(); ++i) {
		if (&p==shapes[i]) {
			for (++i; i<shapes.size(); ++i)
				shapes[i-1] = shapes[i];
			shapes[shapes.size()-1] = &p;
			return;
		}
	}
}
//ez fogja az egész programot elindítani 

int gui_main() { return Fl::run(); }

} 
