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
		data.emplace_back(line);
	}
	m_data.swap(data);
}

void Filter::doSort()
{
	sort(m_data.begin(), m_data.end(), [](const Ip& first, const Ip& second) -> bool {
		if (first.bytes[0] != second.bytes[0])
			return first.bytes[0] > second.bytes[0];
		if (first.bytes[1] != second.bytes[1])
			return first.bytes[1] > second.bytes[1];
		if (first.bytes[2] != second.bytes[2])
			return first.bytes[2] > second.bytes[2];
		return first.bytes[3] > second.bytes[3];
// 		return std::tie(first.bytes[0], first.bytes[1], first.bytes[2], first.bytes[3]) >
// 			std::tie(second.bytes[0], second.bytes[1], second.bytes[2], second.bytes[3]);
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
