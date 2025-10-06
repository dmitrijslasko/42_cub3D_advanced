#include "cub3d.h"

int move_mouse_to_center_of_active_window(void) 
{
	Display *dpy = XOpenDisplay(NULL);
	if (!dpy) {
		fprintf(stderr, "Unable to open X display\n");
		return 1;
	}

	Window root = DefaultRootWindow(dpy);
	Atom activeAtom = XInternAtom(dpy, "_NET_ACTIVE_WINDOW", True);
	Atom actualType;
	int actualFormat;
	unsigned long nItems, bytesAfter;
	unsigned char *prop = NULL;

	if (XGetWindowProperty(dpy, root, activeAtom, 0, (~0L), False, AnyPropertyType,
						   &actualType, &actualFormat, &nItems, &bytesAfter, &prop) != Success || !prop) {
		fprintf(stderr, "Unable to get _NET_ACTIVE_WINDOW\n");
		XCloseDisplay(dpy);
		return 1;
	}

	Window activeWindow = *(Window *) prop;
	XFree(prop);

	XWindowAttributes attr;
	if (!XGetWindowAttributes(dpy, activeWindow, &attr)) {
		fprintf(stderr, "Failed to get window attributes\n");
		XCloseDisplay(dpy);
		return 1;
	}

	int x, y;
	Window child;
	XTranslateCoordinates(dpy, activeWindow, root, 0, 0, &x, &y, &child);

	int center_x = x + attr.width / 2;
	int center_y = y + attr.height / 2;

	XWarpPointer(dpy, None, root, 0, 0, 0, 0, center_x, center_y);
	XFlush(dpy);
	XCloseDisplay(dpy);
	return 0;
}