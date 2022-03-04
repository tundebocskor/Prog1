#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Drill 13

    // 1. Hozzon létre egy 800x1000 es ablakot
    const Point tl {100, 100};
    Simple_window win {tl, 800, 800, "Drill 13"};
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

    // 3. A bal felső saroktól kezdődően a jobb sarokig piros kockak legyenek
    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
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
    Image Cica {Point{0,0}, "cica.gif"};
    win.attach(Cica);
    win.wait_for_button();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 8; ++j) {
            Cica.move(100, 0);
            win.wait_for_button();
        }   
        Cica.move(-700, 100);          // buggy
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
