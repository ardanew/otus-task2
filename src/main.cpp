#include <iostream>
#include <exception>
#include "filter.h"

int main()
{
    try {
		Filter filter;
		filter.doInput(std::cin);
		filter.doSort();
		filter.doFullOutput(std::cout);
		filter.doFilteredOutput(std::cout, [](const Ip& ip) { return ip.bytes.b1 == 1; });
		filter.doFilteredOutput(std::cout, [](const Ip& ip) { return ip.bytes.b1 == 46 && ip.bytes.b2 == 70; });
		filter.doFilteredOutput(std::cout, [](const Ip& ip) {
			return ip.bytes.b1 == 46 || ip.bytes.b2 == 46 || ip.bytes.b3 == 46 || ip.bytes.b4 == 46;
		});
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}
    return 0;
}
