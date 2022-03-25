#include "GUI.h"

using namespace Graph_lib;

struct Simple_window : Graph_lib::Window {
	//Ponot, hogy hova rajzoloja 
	//szélesség magasság, valamint ablak neve
	Simple_window(Point xy, int w, int h, const string& title );
// Vezényelni fogja magát az ablak működését 
	bool wait_for_button();

//Gomb 
	Button next_button;

private:
	//
	bool button_pushed;
	//addr... ablak példány cime, ahol megnyomjuk a gombot
	// static annyit jelent, hogy nem csak objektum pédány tagjaként akarjuk használni
	//tudjuk hívni, mert ott van a mert ott van a memoriában
	
	static void cb_next(Address, Address addr);
// a függvény , ami végrehajtódik, amikor megnyomjuk a gomot 
	void next();

};
