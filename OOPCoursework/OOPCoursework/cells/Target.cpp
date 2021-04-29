#include "Target.h"

Target::Target(unsigned int value)
	:value(value)
{

}

unsigned int Target::GetValue() const
{
	return value;
}