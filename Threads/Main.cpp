#include <iostream>
#include <thread>
#include <mutex>

#include "ReadInput.h"

void foo(int *_counter);
void bar(int *_counter);

void MainLoop(ReadInput *_reader);

std::mutex mtx;

int main()
{
	int counter = 0;

	std::thread first(foo, &counter);
	std::thread second(bar, &counter);

	printf("main, foo and bar all execute concurrently...\n");

	first.join();
	second.join();

	std::cout << "foo and bar completed" << std::endl;

	//---------------------------------------------------------------------------------------------------------

	

	ReadInput *reader = new ReadInput();
	std::thread readerThread(&ReadInput::Run, reader);

	MainLoop(reader);
	readerThread.join();

	delete reader;
	return 0;
}

void foo(int *_counter)
{
	mtx.lock();
	(*_counter)++;
	printf("foo is executing %i \n", *_counter);
	mtx.unlock();
}

void bar(int *_counter)
{
	mtx.lock();
	(*_counter)++;
	printf("bar is executing %i \n", *_counter);
	mtx.unlock();
}

void MainLoop(ReadInput *_reader)
{
	bool endTrigger = false;
	printf("main loop started \n");
	while (endTrigger == false)
	{

		if (_reader->getRunning() == false)
		{
			endTrigger = true;
		}
	}
	printf("main loop finished");
}