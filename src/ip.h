#pragma once
#include <string>
#include <cstdint>
#include <array>
#include "version.h"

// solution with union to get
// - quick sort using u32
// - quick filter using bytes
struct Ip
{
	Ip() = default;
	Ip(const std::string& from);
	Ip(Ip&& other) = default;
	Ip& operator=(Ip&& other) noexcept = default;
	Ip(const Ip&) = delete;
	Ip& operator=(const Ip&) = delete;

	std::string to_string() const;
	void from_string(const std::string& from);

	std::array<uint8_t, 4> bytes;
};
std::ostream& operator<<(std::ostream& os, const Ip& ip);
