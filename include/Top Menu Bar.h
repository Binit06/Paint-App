/*
	Top Menu Bar.h
	Implements the drawing of the Top Menu Bar and handling of all associated events
*/

#pragma once

#include <vector>

class TopMenuBar {

public:

	// Store a vector containing top menu bar buttons
	static std::vector<Button> buttons;


	/*
		Initializes the top menu bar
	*/
	static void Init() {
		// Create instances of the button classes and add them to the vector
		buttons.push_back(Button::Create(0, 0, 70, 40, (char *)"New", NewButtonPressed, true));
		buttons.push_back(Button::Create(70, 0, 80, 40, (char *)"Open", OpenButtonPressed, true));
		buttons.push_back(Button::Create(150, 0, 80, 40, (char *)"Save", SaveButtonPressed, true));
		buttons.push_back(Button::Create(230, 0, 110, 40, (char *)"SaveAs", SaveAsButtonPressed, true));
	}


	static void Display(int window_width, int window_height) {
		for (int i = 0; i < buttons.size(); i++) {
			// Pass on event to each button
			buttons[i].Display(window_width, window_height);
		}
	}


	static bool Pressed(int button, int state, int x, int y) {
		for (int i = buttons.size() - 1; i >= 0; i--) {
			// Pass on event to each button
			if (buttons[i].Pressed(button, state, x, y)) {
				return true;
			}
		}
		return false;
	}


	static bool Hover(int x, int y) {
		bool output = false;
		for (int i = buttons.size() - 1; i >= 0; i--) {
			// Pass on event to each button
			if (buttons[i].Hover(x, y)) {
				output = true;
			}
		}
		return output;
	}
	
};