#include "falcon_mouse.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

Display *display;
Window winRoot;

bool initDisplay()
{
	// Initialise X11 Low-level variables
	display = XOpenDisplay(0);
	if(display == NULL)
		return false;
	winRoot = XDefaultRootWindow(display);
	return true;
}

void setMousePosition(int x, int y)
{
	XTestFakeMotionEvent(display, -1, x, y, 0);
}

void closeDisplay()
{
	XCloseDisplay(display);
}

//To press a button
//XTestFakeButtonEvent(display, button, release, 0);
