#include "Simple_window.h"

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    //ablak szélessége az x_max 
    // fombnak is kell méret (70,20)
    //a gomb felirata(Next)
    //regisztalva milyen cb-et kell hivnia 
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

bool Simple_window::wait_for_button()
{
    //hogy megjelenjen az ablak 

    show();
    // mivel többször tudjuk hívni, és hogy megálljon a vezérlés, 
    //ezért false ra kell állítanunk a pushed értékét 
    button_pushed = false;
    //ha ez igaz, ez a része fusson le a kódnak 

    //vagy az if vagy az else fog bekerülni a kódrészbe
    //attol fugg mennyi lesz az értéke 

#if 1
    //megállítja a futást és vár a gombnyomásra
    while (!button_pushed) Fl::wait();
    //ujra kell rajzolni az ablakot 

    Fl::redraw();
#else
    Fl::run();
#endif
    return button_pushed;
}

void Simple_window::cb_next(Address, Address pw)
{// memóriacímet fogjuk átkasztolni referenciatípussá
    
    
    reference_to<Simple_window>(pw).next();    
}

void Simple_window::next()
{
    button_pushed = true;
    hide();
}
