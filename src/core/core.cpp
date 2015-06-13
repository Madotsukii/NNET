/*
Copyright © 2015 Madotsuki <madotsuki@national.shitposting.agency>

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

	1.	The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software in
		a product, an acknowledgment in the product documentation would be
		appreciated but is not required.

	2.	Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.

	3. This notice may not be removed or altered from any source distribution.
*/

#include <iostream>

#include "core.hpp"
#include "config.hpp"		// CMake makes it in the same directory
#include "io.hpp"
#include "log.hpp"

// Public
ushort NNET::Core::start(const int &argc, char **argv)
{
NNET_core_restart:
	if (state == 3)
	{
		// TODO: Clean up classes
	}

	for (int i = 0; i < argc; ++i)
	{
		std::string arg = argv[i];

		if (arg == "-h" || arg == "--help")
			std::cout << "Usage: NNET [OPTIONS]\n\n"
					  << "Option\tLong option\tMeaning\n"
					  << " -h\t--help\t\tShow this message and exit\n"
					  << " -v\t--version\tPrints the executable version and exits\n";
		else if (arg == "-v" || arg == "--version")
			std::cout << "NNET v" << NNET_VERSION_MAJOR << '.'
					  << NNET_VERSION_MINOR << '\n';
		else if (arg == "-l" || arg == "--license") {}
		else if (arg == "-i" || arg == "--info") {}
	}

NNET_core_loop:
	state = 1;

	while (state == 1)
	{
		break;		// temp
	}

	while (state == 2)
	{
		if (state == 1)
			goto NNET_core_loop;
	}

	if (state == 3)
		goto NNET_core_restart;

	// TODO: Join threads before returning

	state = 0;

	std::cout << "Core state: " << state << '\n';

	return state;
}

void NNET::Core::stop() { state = 0; }

void NNET::Core::pause() { state = 2; }

void NNET::Core::resume() { state = 1; }

void NNET::Core::restart() { state = 3; }

ushort NNET::Core::getState() { return state; }
