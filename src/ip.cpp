#include "ip.h"
#include <sstream>

using namespace std;

Ip::Ip(const string& from) {
	from_string(from);
}

string Ip::to_string() const {
	return std::to_string(bytes.b1) + "." + std::to_string(bytes.b2) + "." +
		std::to_string(bytes.b3) + "." + std::to_string(bytes.b4);
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
	bytes.b1 = static_cast<uint8_t>( tmp );
	ss >> tmp >> dot;
	bytes.b2 = static_cast<uint8_t>( tmp );
	ss >> tmp >> dot;
	bytes.b3 = static_cast<uint8_t>( tmp );
	ss >> tmp;
	bytes.b4 = static_cast<uint8_t>( tmp );
}
