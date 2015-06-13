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

#ifndef NNET_CORE_HPP
#define NNET_CORE_HPP

#include <atomic>

#include "../definitions.hpp"

namespace NNET
{
	class Core
	{
	public:
		ushort start(const int &argc, char **argv);
		void stop();
		void pause();
		void resume();
		void restart();

		ushort getState();

	private:
		// 0 = off/exit, 1 = running, 2 = paused, 3 = restart, 4 = error
		std::atomic_ushort state;
	};
}

#endif // NNET_CORE_HPP
