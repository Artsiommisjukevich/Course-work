#pragma once
#include "Screen.h"

class ToBeDrawnInterface
{
public:
	virtual void Draw(Screen* screen) = 0;
};