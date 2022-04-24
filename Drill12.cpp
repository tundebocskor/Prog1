#include "Simple_window.h"
	#include "Graph.h"
 int main()
{

	using namespace Graph_lib;

	
	int xmax=600;
	int ymax=400 ;
	
//mettől meddig rajzolja ki 
// Y koordináták lefelé növekszenek ... 

	Simple_window win {Point{100,100}, xmax, ymax, "Canvas"}; 

	Axis xa {Axis::x, Point{20,300}, 500, 10, "x axis"};  
	Axis ya {Axis::y, Point{20,300}, 250, 10, "y axis"};
	ya.set_color(Color::yellow);                       // choose a color
	ya.label.set_color(Color::dark_red); 
	win.attach(xa);                       // attach xa to the window, win
	win.attach(ya);
	//win.set_label("Canvas #5");
	//win.wait_for_button();

	Rectangle ri {Point{300,50}, 80, 50}; //téglalap
	ri.set_fill_color(Color::cyan);
	// Stílusát megváltoztatjuk
	ri.set_style(Line_style(Line_style::dashdot, 2));
	ri.set_fill_color(Color::yellow);
	Function sine {sin,0,100,Point{20,280},1000,10,10};       // sine függvény
          //   // ábrázolja a sin()-t a [0:100) tartományban (0,0) a (20,280) értékkel
          // 1000 pont felhasználásával, annyi pontot rajzol ki ; scale x values *10, scale y values *10
	sine.set_color(Color::blue);
	//Szöveg kiiratása
	Text t {Point{150,150}, "Hello, graphical world!"};

	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{30, 55}, "image.jpeg"};


	Circle c {Point{300,200},50};
	Ellipse e {Point{300,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};

	Polygon poly;

	poly.add(Point{350,200});
	poly.add(Point{400,100});
	poly.add(Point{450,200});	
	poly.set_fill_color(Color::blue); //színt adunk neki 

	Closed_polyline poly_rect;
	poly_rect.add(Point{450,50});
	poly_rect.add(Point{500,50});
	poly_rect.add(Point{500,100});
	poly_rect.add(Point{450,100});
	poly_rect.add(Point{400,75});



	win.attach(ii);
	win.attach(c);
	win.attach(e);
	win.attach(sine);
	win.attach(poly_rect);
	win.attach(m);
	win.attach(sizes);
	win.attach(ri);

	win.attach(poly);


	win.wait_for_button();
}
