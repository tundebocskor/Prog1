#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Drill 13

    // 1. Hozzon létre egy 800x800 es ablakot
  
    Simple_window win {Point {100, 100}, 800, 800, "Drill 13"};
    win.wait_for_button();

    // 2. Készíts 8x8 as, 100X100 pixeles négyzetrácsos ablakot
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    //Vonalak
    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});    
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);
    win.wait_for_button();

    // 3. Átlósan piros négyzetek
    
    Vector_ref<Rectangle> vr;
    //Névtelen objektumok létrehozásához szükséges. 
        for(int i=0;i<8;i++)
        {
            //Létrehozza ezeket a névtelen objektumokat

            vr.push_back(new Rectangle(Point{100*i,100*i},100,100));
            vr[vr.size()-1].set_fill_color(Color::red);
            win.attach(vr[vr.size()-1]);
        }
        win.wait_for_button();


    // 4. Adjon hozzá egy 200x200 as képet és helyezze el 3 helyen
    Image madar1 {Point{0,400}, "image.jpeg"};
    Image madar2 {Point{300,600}, "image.jpeg"};
    Image madar3 {Point{500,100}, "image.jpeg"};

    win.attach(madar1);
    win.attach(madar2);
    win.attach(madar3);
    win.wait_for_button();

    // 5. Adjon hozzá egy 100x100 as képet és mozogjon ha a "Nextet" megnyomjuk
    Image kep {Point{0,0}, "kep.jpg"};
    win.attach(kep);
    win.wait_for_button();
    int u=0;
    int veg=7;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < veg; ++j) {
            
            kep.move(100, 0);
            u=j;


            win.wait_for_button();

        }   
        veg=veg-1;
        u=u*(-100);
        kep.move(u, 100);         
        win.wait_for_button();
    }
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
