#pragma once
#include <string>
#include "cells/Target.h"

class Printable
{
protected:
	std::string name; //The name, which will appear in the console

public:
	Printable(const std::string& name);

	std::string GetName() const { return name; }

	virtual void Print(const Target& target) const = 0;
};