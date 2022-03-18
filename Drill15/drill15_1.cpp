#include "Graph.h"
#include "Simple_window.h"

using namespace std;


double one(double x) {return 1;}
double slope(double x){return x/2;}
double square(double x) {return x*x;}
//double cosinus(double x){return cos(x);}
double sloping_cos(double x) {return slope(x)+cos(x);}
int main()
{
	//cout<<"Hello" <<endl;
	int w=600, h=600;
	Point origo(w/2, h/2);
	Simple_window win (Point{100,100}, w, h, "Function graphs");
	int n=20;
	
	//						   Kezdőpont    Hosszúság,  '20' közök
		Axis x_axis (Axis::x, Point{100,300},400, n, "1==20 pixels");
	x_axis.set_color(Color::red);

	Axis y_axis (Axis::y, Point{300,500}, 400, n, "1==20 pixels");
	y_axis.set_color(Color::red);


win.attach(x_axis);
	win.attach(y_axis);


	int range_min=-10, range_max=11;
	int points=400;
	int xscale=20, yscale=20;
	Function o(one, range_min, range_max, origo, points, xscale, yscale );
	Function s(slope, range_min, range_max, origo, points, xscale, yscale );
	Text label {Point {500,190}, "x/2"};
	Function sq(square, range_min, range_max, origo, points, xscale, yscale );
	//Függvény nélküli 
	//Function c(cos, range_min, range_max, origo, points, xscale, yscale );
	Function c([](double x){return cos(x);}, range_min, range_max, origo, points, xscale, yscale );
	c.set_color(Color::blue);
	
	Function sl(sloping_cos, range_min, range_max, origo, points, xscale, yscale );
	
	win.attach(o);
	win.attach(s);
	win.attach(sq);
	win.attach(label);
	win.attach(c);
	win.attach(sl);
	win.wait_for_button();
}
