#include "TargetInfo.h"

TargetInfo::TargetInfo()
	:Printable("Target")
{

}

void TargetInfo::Print(const Target& target) const
{
	std::cout << name << ": " << target.GetSymbol() << " - " << target.GetValue() << " points to score";
}