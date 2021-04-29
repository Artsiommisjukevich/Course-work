#pragma once
#include "Printable.h"

class TargetInfo : public Printable
{
public:
	TargetInfo();

	void Print(const Target& target) const override;
};