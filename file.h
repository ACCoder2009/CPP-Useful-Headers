#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <future>

bool CheckFile(const std::ifstream& stream)
{
	if (stream) { return true; }
	return false;
}

bool CheckFile(const std::ofstream& stream)
{
	if (stream) { return true; }
	return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vector)
{
	for (const T& buffer : vector) { stream << buffer << "\n"; }
	return stream;
}

template<typename T>
std::vector<T> ReadFile(std::ifstream& stream)
{
	T buffer{};
	std::vector<T> result;
	if (!CheckFile(stream))
	{
		result.push_back("FILE NOT VALID!");
		return result;
	}
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
	if (!CheckFile(stream))
	{
		result.push_back("FILE NOT VALID!");
		return result;
	}
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
int OverwriteFile(const std::string& filepath, const T& content, bool newline = true)
{
	std::ofstream stream(filepath, stream.binary);
	if (!CheckFile(stream)) { return 1; }
	if (newline) { stream << content << "\n"; }
	else { stream << content; }
	return 0;
}

template<typename T>
int AppendFile(const std::string& filepath, const T& content, bool newline = true)
{
	std::ofstream stream(filepath, stream.app | stream.binary);
	if (!CheckFile(stream)) { return 1; }
	if (newline) { stream << content << "\n"; }
	else { stream << content; }
	return 0;
}