#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include "filter.h"
using namespace std;

TEST(IpFilter, SimpleLines) {
	Filter filter;
	stringstream ss;
	ss << "1.2.3.4" << endl;
	ss << "1.2.3.5" << endl;
	ss << "2.2.3.4" << endl;
	ss << "2.2.3.5" << endl;

	filter.doInput(ss);
	filter.doSort();

	stringstream os;
	filter.doFullOutput(os);

	std::string s;
	os >> s;
	EXPECT_EQ("2.2.3.5", s);
	os >> s;
	EXPECT_EQ("2.2.3.4", s);
	os >> s;
	EXPECT_EQ("1.2.3.5", s);
	os >> s;
	EXPECT_EQ("1.2.3.4", s);
}

TEST(IpFilter, LinesWithComments) {
	Filter filter;
	stringstream ss;
	ss << "1.2.3.4 skipped skipped" << endl;
	ss << "1.2.3.5 some" << endl;
	ss << "2.2.3.4" << endl;
	ss << "2.2.3.5 no comments at all" << endl;

	filter.doInput(ss);
	filter.doSort();

	stringstream os;
	filter.doFullOutput(os);

	std::string s;
	os >> s;
	EXPECT_EQ("2.2.3.5", s);
	os >> s;
	EXPECT_EQ("2.2.3.4", s);
	os >> s;
	EXPECT_EQ("1.2.3.5", s);
	os >> s;
	EXPECT_EQ("1.2.3.4", s);
}

TEST(IpFilter, SimpleFilter) {
	Filter filter;
	stringstream ss;
	ss << "1.2.3.4 skipped skipped" << endl;
	ss << "1.2.3.5 some" << endl;
	ss << "2.2.3.4" << endl;
	ss << "2.2.3.5 no comments at all" << endl;

	filter.doInput(ss);
	filter.doSort();

	stringstream os;
	filter.doFilteredOutput(os, [](const Ip& ip) { return ip.bytes.b4 == 4; });

	std::string s;
	os >> s;
	EXPECT_EQ("2.2.3.4", s);
	os >> s;
	EXPECT_EQ("1.2.3.4", s);
}
