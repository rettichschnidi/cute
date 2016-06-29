/*********************************************************************************
 * This file is part of CUTE.
 *
 * CUTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CUTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with CUTE.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2015 Reto Schneider
 *
 *********************************************************************************/

#ifndef SUMMARY_LISTENER_H_
#define SUMMARY_LISTENER_H_
#include "cute_listener.h"
#include "cute_counting_listener.h"
#include <ostream>
namespace cute{
		template <typename Listener=null_listener>
		struct summary_listener:counting_listener<Listener> {
				template<typename ... Tail>
				summary_listener(std::ostream &os, Tail&& ... tail)
				:counting_listener<Listener>(std::forward<Tail>(tail)  ...),out(os) {}

				~summary_listener() {
						out << "\nUnit testing results:\n";
						out << "Number of tests: " << counting_listener<Listener>::numberOfTests << '\n';
						out << "Success: " << counting_listener<Listener>::successfulTests << '\n';
						out << "Failures: " << counting_listener<Listener>::failedTests << '\n';
						out << "Errors: " << counting_listener<Listener>::errors << '\n';
						out << std::flush;
				}
				std::ostream &out;
		};
}
#endif /*SUMMARY_LISTENER_H_*/
