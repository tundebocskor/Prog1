#include "Simple_window.h"
	#include "Graph.h"
 
 double one(double) {return 1; }

 double square(double x) {return x*x; }
int main()
{

	using namespace Graph_lib;

	//Point t1{100, 100}; //hol fog kezdődni kirajzolódni 
	//Simple_window win {t1, 640, 600, "Canvas"};  //egy pont meg egy méret 

	// Háromszög kirajzolása
	/*Polygon poly;

	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});	

	win.attach(poly);*/
	int xmax=600;
	int ymax=400 ;

	int x_orig =xmax/2;
	int y_orig=ymax/2;
	
	
int rmin = -9; 
int rmax = 9;
//mettől meddig rajzolja ki 

int n_points = 400;
	Simple_window win {Point{100,100}, xmax, ymax, "Canvas"}; 

	Point origo(x_orig, y_orig);

	int xlength= xmax-40;
	int ylength= ymax-40;
	int xscale=30, yscale=30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale );
	Function r (square, rmin, rmax, origo, n_points, xscale, yscale );
	//Lokálisan adjuk meg a függvényt a következőbe 
	Function cos_func ( [] (double x) {return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale );


	Rectangle ri {Point{200,200}, 100, 50};
	ri.set_fill_color(Color::green);
	// Stílusát megváltoztatjuk

	ri.set_style(Line_style(Line_style::dot, 4));

	//Szöveg kiiratása
	Text t {Point{x_orig+90, y_orig-130}, "Helllo"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{10, 10}, "badge.jpg"};

	Circle c {Point {xmax-120, xmax-300}, 50};
	Polygon poly;

	poly.add(Point{500,200});
	poly.add(Point{550,100});
	poly.add(Point{600,200});	
	poly.set_fill_color(Color::blue);
	c.set_fill_color(Color::red);
	Axis x{Axis::x, Point{20,y_orig}, xlength, xlength/xscale, "x"};
	Axis y{Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};
	win.attach(ii);
	win.attach(c);
	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(r);
	win.attach(cos_func);
	win.attach(ri);
	win.attach(t);
	win.attach(poly);


	win.wait_for_button();
}
