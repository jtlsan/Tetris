#ifndef __CELL_H__
#define __CELL_H__
#include "base.h"

class Cell
{
private:
	int color;
	int xpos;
	int ypos;
	bool active;
public:
	Cell() : color(0), xpos(0), ypos(0), active(false) {}
	~Cell() {};
	int get_xpos() { return xpos; }
	int get_ypos() { return ypos; }
	int get_color() { return color; }
	bool Is_active() { return active; }
	void set_xpos(int pos) { xpos = pos; }
	void set_ypos(int pos) { ypos = pos; }
	void set_color(int color) { this->color = color; }
	void set_active(bool input) { active = input; }
};

#endif