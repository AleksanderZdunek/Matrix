#include "traceprint.h"

Traceprint trace;

void Traceprint::Init(std::ostream& out, bool active)
{
	this->out = &out;
	this->active = active;
}

void Traceprint::Summary()
{ 
	if(out) *out << "Traceprints: " << counter << std::endl;
}