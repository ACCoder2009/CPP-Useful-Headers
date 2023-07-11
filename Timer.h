#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class Timer
{
private:
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;
public:
	Timer() : start(std::chrono::high_resolution_clock::now()), end(std::chrono::high_resolution_clock::now()), duration(end - start) {}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		auto duration_ms = duration * 1000.0f;
		std::cout << duration_ms.count() << " ms\n";
	}
};