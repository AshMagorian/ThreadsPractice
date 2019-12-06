#include "ReadInput.h"

#include <iostream>

ReadInput::ReadInput()
{
	running = true;
	inputValue = 'a';
}

ReadInput::~ReadInput()
{

}

void ReadInput::Run()
{
	while (running)
	{
		std::cin >> inputValue;
		printf("ReadInput input value %c \n", inputValue);
		if (inputValue == 'x')
		{
			Kill();
		}
	}
}

void ReadInput::Kill()
{
	running = false;
	printf("thread killed\n");
}