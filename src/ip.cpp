#include "ip.h"
#include <sstream>

using namespace std;

Ip::Ip(const string& from) {
	from_string(from);
}

string Ip::to_string() const {
	return std::to_string(bytes[0]) + "." + std::to_string(bytes[1]) + "." +
		std::to_string(bytes[2]) + "." + std::to_string(bytes[3]);
}

ostream& operator<<(ostream& os, const Ip& ip)
{
	os << ip.to_string();
	return os;
}

void Ip::from_string(const string& from) {
	istringstream ss(from);
	char dot;
	int tmp;
	ss >> tmp >> dot;
	bytes[0] = static_cast<uint8_t>( tmp );
	ss >> tmp >> dot;
	bytes[1] = static_cast<uint8_t>( tmp );
	ss >> tmp >> dot;
	bytes[2] = static_cast<uint8_t>( tmp );
	ss >> tmp;
	bytes[3] = static_cast<uint8_t>( tmp );
}
