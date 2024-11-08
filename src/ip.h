#pragma once
#include <string>
#include <cstdint>
#include "version.h"

// solution with union to get
// - quick sort using u32
// - quick filter using bytes
union Ip
{
	Ip() = default;
	Ip(const std::string& from);

	std::string to_string() const;
	void from_string(const std::string& from);

	struct Bytes {
#if CURRENT_BYTE_ORDER == LITTLE_ENDIAN
		uint8_t b4, b3, b2, b1;
#else // NOTE not tested
		uint8_t b1, b2, b3, b4;
#endif
	} bytes;
	uint32_t u32;
};

std::ostream& operator<<(std::ostream& os, const Ip& ip);
