#pragma once
#include <thread>

class ReadInput
{
public:
	ReadInput();
	~ReadInput();

	void Run();

	void Kill();

	bool getRunning() { return running; }

private:

	bool running;
	char inputValue;

};