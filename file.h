#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool CheckFile(const std::ifstream& stream)
{
	if (stream)
	{
		std::cout << "FILE IS VALID!" << "\n";
		return true;
	}
	std::cout << "FILE NOT VALID!" << "\n";
	return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vector)
{
	for (const T& buffer : vector) { stream << buffer << "\n"; }
	return stream;
}

template<typename T>
std::vector<T> ReadFile(const std::ifstream& stream)
{
	T buffer{};
	std::vector<T> result;
	if (!CheckFile(stream)) { return result; }
	if (stream.is_open())
	{
		while (stream.good())
		{
			std::getline(stream, buffer);
			result.push_back(buffer);
		}
	}
	return result;
}

template<typename T>
std::vector<T> ReadFile(const std::string& filepath)
{
	T buffer{};
	std::vector<T> result;
	std::ifstream stream(filepath);
	if (!CheckFile(stream)) { return result; }
	if (stream.is_open())
	{
		while (stream.good())
		{
			std::getline(stream, buffer);
			result.push_back(buffer);
		}
	}
	return result;
}