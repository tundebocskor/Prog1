#ifndef WINDOW_GUARD
#define WINDOW_GUARD 1

#include "fltk.h"

#include "std_lib_facilities.h"

#include "Point.h"

namespace Graph_lib {

class Shape;
class Widget;
// Fl window osztályt fogjuk kibőviteni 

class Window : public Fl_Window { 
public: 
	//hova tegye az ablakot 

	Window(int w, int h, const string& title );
	Window(Point xy, int w, int h, const string& title );
	
	virtual ~Window() { }
	//eltudjuk kérni az ablak méretét 
	int x_max() const { return w; }
	int y_max() const { return h; }
// át tudjuk méretezni az ablakot 
	//mekkorára akarjuk átméretezni, hivjuk az ősosztály size 
	//függvényét és az átméretezi 

	void resize(int ww, int hh) { w=ww, h=hh; size(ww,hh); }
//Függvény, amivel át tudjuk nevezni, valamint elkérjuk az ős osztály tagját 

	void set_label(const string& s) { label(s.c_str()); }
//függvények, amivel fel kell tegyük az ablakra ...
	void attach(Shape& s);
	void attach(Widget& w);
//függvények, amivel le tudjuk venni 
	void detach(Shape& s);
	void detach(Widget& w);
//ha esetleg kitakarás lenne, fel tudjuk tenni a tetejére 
	
	void put_on_top(Shape& p);

protected:
	void draw();
     //ebbe fogjuk eltárolni, hogyí milyen shapeket rajzoljon ki

private:
	  vector<Shape*> shapes;
	  int w,h;

	  void init();
}; 

int gui_main();
//ha ezeket akarjuk lekérdezni 

inline int x_max() { return Fl::w(); }
inline int y_max() { return Fl::h(); }

}
#endif
