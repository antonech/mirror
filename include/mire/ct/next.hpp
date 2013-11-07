/**
 * @file mire/ct/next.hpp
 * @brief Implementation of the next meta-function
 *
 *  Copyright 2008-2011 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef MIRE_CT_NEXT_1105240825_HPP
#define MIRE_CT_NEXT_1105240825_HPP

#include <mire/ct/default.hpp>

namespace mire {
namespace ct {

#ifndef MIRROR_DOCUMENTATION_ONLY

template <typename Char, Char C, Char ... Cn>
struct next<basic_string<Char, C, Cn...> >
{
	typedef basic_string<Char, Cn...> type;
};

template <typename Char>
struct next<basic_string<Char> >
{
	typedef basic_string<Char> type;
};

#endif

} // namespace ct
} // namespace mire

#endif //include guard

