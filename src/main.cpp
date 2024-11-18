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
		filter.doFilteredOutput(std::cout, [](const Ip& ip) { return ip.bytes[0] == 1; });
		filter.doFilteredOutput(std::cout, [](const Ip& ip) { return ip.bytes[0] == 46 && ip.bytes[1] == 70; });
		filter.doFilteredOutput(std::cout, [](const Ip& ip) {
			return ip.bytes[0] == 46 || ip.bytes[1] == 46 || ip.bytes[2] == 46 || ip.bytes[3] == 46;
		});
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}
    return 0;
}
