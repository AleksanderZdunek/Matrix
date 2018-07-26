#pragma once
#include <ostream>

class Traceprint
{
public:
	Traceprint() = default;
	//Traceprint(std::ostream& out, bool active = true) : out(&out), active(active) {};
	void Init(std::ostream& out, bool active = true);
	template<typename T> Traceprint& operator<<(T val)
	{
		#ifndef NDEBUG
		if(out && active) *out << val;
		++counter;
		#endif;
		return *this;
	}
	unsigned int Counter() { return counter; }
	void Activate() { active = true; }
	void Disable() { active = false; }
	void Summary();
private:
	std::ostream* out{nullptr};
	bool active{false};
	unsigned int counter{0};
};

extern Traceprint trace;