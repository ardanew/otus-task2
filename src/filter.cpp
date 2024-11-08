#include "filter.h"
#include <algorithm>
#include <iterator>
using namespace std;

void Filter::doInput(std::istream &is)
{
	vector<Ip> data;
	while (true)
	{
		std::string line;
		getline(is, line);
		if (line.empty())
			break;
		Ip ip{ line };
		data.push_back(std::move(ip));
	}
	m_data.swap(data);
}

void Filter::doSort()
{
	sort(m_data.begin(), m_data.end(), [](const Ip& first, const Ip& second) {
		return first.u32 > second.u32; // sort backwards
	});
}

void Filter::doFullOutput(std::ostream& os)
{
	for (const auto& ip : m_data)
		os << ip << endl; // full output
}

void Filter::doFilteredOutput(std::ostream& os, std::function<bool(const Ip&)> &&filter)
{
	copy_if(m_data.begin(), m_data.end(), ostream_iterator<Ip>(os, "\n"), filter);

}
