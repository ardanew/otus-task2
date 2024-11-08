#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "ip.h"

class Filter
{
public:
	void doInput(std::istream& is);
	void doSort();
	void doFullOutput(std::ostream& os);
	void doFilteredOutput(std::ostream& os, std::function<bool(const Ip&)> &&filter);

protected:
	std::vector<Ip> m_data;
};