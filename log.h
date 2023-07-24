#include <iostream>

class Log
{
private:
	Log()
	{

	}
public:
	static enum LogLevel
	{
		LogLevelError, LogLevelWarning, LogLevelInfo
	}Variable;
private:
	static int m_LogLevel;
public:
	static void SetLevel(LogLevel Level)
	{
		m_LogLevel = Level;
	}

	template<typename T>
	static void Error(T message)
	{
		if (m_LogLevel >= LogLevelError)
		{
			std::cout << "[ERROR]: " << message << std::endl;
		}
		else
		{
			std::cout << "[LOG]: " << "LEVEL NOT VALID!" << std::endl;
		}
	}

	template<typename T>
	static void Warn(T message)
	{
		if (m_LogLevel >= LogLevelWarning)
		{
			std::cout << "[WARNING]: " << message << std::endl;
		}
		else
		{
			std::cout << "[LOG]: " << "LEVEL NOT VALID!" << std::endl;
		}
	}

	template<typename T>
	static void Info(T message)
	{
		if (m_LogLevel >= LogLevelInfo)
		{
			std::cout << "[INFO]: " << message << std::endl;
		}
		else
		{
			std::cout << "[LOG]: " << "LEVEL NOT VALID!" << std::endl;
		}
	}
};

int Log::m_LogLevel = Log::LogLevelInfo;