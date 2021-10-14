#pragma once
#include <ostream>
#include <mutex>

std::mutex coutLock;

class pcout
{
public:
	pcout() 
	{
		coutLock.lock();
	}

	~pcout()
	{
		coutLock.unlock();
	}

	template <typename T>
	pcout& operator<< (const T& t)
	{
		std::cout << t;
		return *this;
	}

	pcout& operator<< (std::ostream& (*fp)(std::ostream&))
	{
		std::cout << fp;
		return *this;
	}
};