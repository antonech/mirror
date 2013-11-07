/**
 * @file mire/ct/default.hpp
 * @brief Default implementation of the compile-time algorithms
 *
 *  Copyright 2008-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef MIRE_CT_DEFAULT_1105240825_HPP
#define MIRE_CT_DEFAULT_1105240825_HPP

#include <mire/config.hpp>
#include <mire/ct/range.hpp>
#include <mire/ct/string.hpp>
#include <mire/ct/optional.hpp>
#include <mire/ct/evaluate.hpp>

namespace mire {
namespace ct {

/// Meta-function returning a null terminated C-string literal from a String
/**
 *  @see basic_string
 *
 *  @ingroup ct_utils
 */
template <typename String>
struct c_str
#ifndef MIRROR_DOCUMENTATION_ONLY
 : c_str<typename evaluate<String>::type>
{ };
#else
{
	/// The C-string literal
	static constexpr const char* value;
};
#endif

/// Meta-function returning the character type of a compile-time string
/**
 *  @see basic_string
 *
 *  @ingroup ct_utils
 */
template <typename String>
struct char_type
#ifndef MIRROR_DOCUMENTATION_ONLY
 : char_type<typename evaluate<String>::type>
{ };
#else
{
	/// The character type use by the examined compile-time string
	typedef unspecified_char_type type;
};
#endif

/// Meta-function returning true_type if a compile-time string is empty
/**
 *  @see basic_string
 *  @see nonempty
 *  @see size
 *  @see length
 *
 *  @ingroup ct_utils
 */
template <typename Range>
struct empty
#ifndef MIRROR_DOCUMENTATION_ONLY
 : empty<typename evaluate<Range>::type>
#else
 : BooleanConstantType
#endif
{ };

/// Meta-function returning true_type if a compile-time string is not empty
/**
 *  @see basic_string
 *  @see empty
 *  @see size
 *  @see length
 *
 *  @ingroup ct_utils
 */
template <typename Range>
struct nonempty
#ifndef MIRROR_DOCUMENTATION_ONLY
 : nonempty<typename evaluate<Range>::type>
#else
 : BooleanConstantType
#endif
{ };

/// Nil intrinsic meta-function for optionals
/**
 *  @tparam Optional the optional to be examined
 *  @see optional
 *  @see get
 *  @ingroup ct_utils
 */
template <typename Optional>
struct nil
#ifndef MIRROR_DOCUMENTATION_ONLY
 : nil<typename evaluate<Optional>::type>
#else
 : BooleanConstantType
#endif
{ };

/// Meta-function returning the length of a compile-time string
/**
 *  This meta-function is equivalent to the @c length meta-function.
 *  @see basic_string
 *  @see empty
 *  @see nonempty
 *  @see length
 *
 *  @ingroup ct_utils
 */
template <typename Range>
struct size
#ifndef MIRROR_DOCUMENTATION_ONLY
 : size<typename evaluate<Range>::type>
#else
 : IntegralConstantType
#endif
{ };

/// Meta-function returning the length of a compile-time string
/**
 *  This meta-function is equivalent to the @c size meta-function.
 *  @see basic_string
 *  @see empty
 *  @see nonempty
 *  @see size
 *
 *  @ingroup ct_utils
 */
template <typename Range>
struct length
#ifndef MIRROR_DOCUMENTATION_ONLY
 : length<typename evaluate<Range>::type>
#else
 : IntegralConstantType
#endif
{ };

/// Returns the element of the optional passed as argument
/**
 *  This operation may be invoked only on non-nil optionals.
 *
 *  @tparam Optional the optional the item of which is to be returned
 *  @see optional
 *  @see nil
 *  @ingroup ct_utils
 */
template <typename Optional>
struct get
#ifndef MIRROR_DOCUMENTATION_ONLY
 : get<typename evaluate<Optional>::type>
{ };
#else
{
	/// The type in the optional passed as argument
	typedef unspecified_type type;
};
#endif

/// Equality comparison meta-function for compile-time strings
/**
 *  @see basic_string
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct equal
#ifndef MIRROR_DOCUMENTATION_ONLY
 : equal<
	typename evaluate<Range1>::type,
	typename evaluate<Range2>::type
>
#else
 : BooleanConstantType
#endif
{ };

/// Non-equality comparison meta-function for compile-time strings
/**
 *  @see basic_string
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct nonequal
#ifndef MIRROR_DOCUMENTATION_ONLY
 : nonequal<
	typename evaluate<Range1>::type,
	typename evaluate<Range2>::type
>
#else
 : BooleanConstantType
#endif
{ };

/// Meta-function returning the first character in the compile-time string
/**
 *  @see basic_string
 *  @see empty
 *  @see nonempty
 *  @see next
 *
 *  @ingroup ct_utils
 */
template <typename Range>
struct front
#ifndef MIRROR_DOCUMENTATION_ONLY
 : front<typename evaluate<Range>::type>
#else
 : CharacterConstantType
#endif
{ };

/// Meta-function returning a compile-string without the first character
/**
 *  @see basic_string
 *  @see empty
 *  @see nonempty
 *  @see front
 *  @see skip_front
 *
 *  @ingroup ct_utils
 */
template <typename Range>
struct next
#ifndef MIRROR_DOCUMENTATION_ONLY
 : next<typename evaluate<Range>::type>
{ };
#else
{
	/// The original compile-time string without the first character
	typedef CompileTimeString type;
};
#endif

/// Meta-function concatenating several compile-time strings together
/**
 *  @see basic_string
 *
 *  @ingroup ct_utils
 */
template <typename ... Ranges>
struct concat
#ifndef MIRROR_DOCUMENTATION_ONLY
 : concat<typename evaluate<Ranges>::type...>
{ };
#else
{
	/// The concatenated compile-time string
	typedef CompileTimeString type;
};
#endif

/// Returns a range having the passed item appended.
/**
 *  @tparam Range the range to be modified
 *  @tparam T the type(s) to be appended to the range
 *
 *  @ingroup ct_utils
 */
template <class Range, typename ... T>
struct append
#ifndef MIRROR_DOCUMENTATION_ONLY
 : append<typename evaluate<Range>::type, T...>
{ };
#else
{
	/// The range with the types added
	typedef Range type;
};
#endif

/// Returns a string having the passed item appended.
/**
 *  @tparam String the range to be modified
 *  @tparam T the character(s) to be appended to the range
 *
 *  @ingroup ct_utils
 */
template <class String, char ... T>
struct append_char
#ifndef MIRROR_DOCUMENTATION_ONLY
 : append_char<typename evaluate<String>::type, T...>
{ };
#else
{
	/// The string with the character(s) added
	typedef String type;
};
#endif

/// Meta-function returning a string containing the first N characters
/**
 *  @see basic_string
 *  @see tail
 *  @see slice
 *
 *  @ingroup ct_utils
 */
template <typename Range, typename Size>
struct head
#ifndef MIRROR_DOCUMENTATION_ONLY
 : head<
	typename evaluate<Range>::type,
	typename Size::type
> { };
#else
{
	/// The head of the original compile-time string
	typedef CompileTimeString type;
};
#endif

/// Meta-function returning a string containing the first N characters
/**
 *  @see basic_string
 *  @see head_c
 *  @see tail
 *  @see slice
 *
 *  @ingroup ct_utils
 */
template <typename Range, size_t Size>
struct head_c;

/// Meta-function returning a string containing the last N characters
/**
 *  @see basic_string
 *  @see head
 *  @see tail
 *  @see tail_c
 *  @see slice
 *
 *  @ingroup ct_utils
 */
template <typename Range, typename Size>
struct tail
#ifndef MIRROR_DOCUMENTATION_ONLY
 : tail<
	typename evaluate<Range>::type,
	typename Size::type
> { };
#else
{
	/// The tail of the original compile-time string
	typedef CompileTimeString type;
};
#endif

/// Meta-function returning a string containing the last N characters
/**
 *  @see basic_string
 *  @see head
 *  @see tail
 *  @see slice
 *
 *  @ingroup ct_utils
 */
template <typename Range, size_t Size>
struct tail_c;

/// Meta-function returning a string starting with the searched sub-string
/** This meta-function template returns a substring of the original
 *  compile-time string, that starts with the searched string (in case
 *  the original contains it) or an empty string (otherwise).
 *
 *  @see basic_string
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct find
#ifndef MIRROR_DOCUMENTATION_ONLY
 : find<
	typename evaluate<Range1>::type,
	typename evaluate<Range2>::type
> { };
#else
{
	/// Sub-string starting with the searched string or empty string
	typedef CompileTimeString type;
};
#endif

/// Meta-function returning a sub-string of a compile-time string
/**
 *  @see basic_string
 *  @see head
 *  @see tail
 *
 *  @ingroup ct_utils
 */
template <typename Range, typename Start, typename Size>
struct slice
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
{
	/// Sub-string starting at a specified position with the given length
	typedef CompileTimeString type;
};
#endif

/// Meta-function returning a sub-string of a compile-time string
/**
 *  @see basic_string
 *  @see head_c
 *  @see tail_c
 *
 *  @ingroup ct_utils
 */
template <typename Range, size_t Start, size_t Size>
struct slice_c;

/// Meta-function returning a sub-string without the first N characters
/**
 *  @see basic_string
 *  @see head
 *  @see tail
 *  @see next
 *
 *  @ingroup ct_utils
 */
template <typename Range, typename Size>
struct skip_front
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
{
	/// Sub-string of the original string starting at the specified position
	typedef CompileTimeString type;
};
#endif

/// Meta-function returning a sub-string without the first N characters
/**
 *  @see basic_string
 *  @see head_c
 *  @see tail_c
 *  @see next
 *
 *  @ingroup ct_utils
 */
template <typename Range, size_t Count>
struct skip_front_c;

/// Meta-function returning the character at the N-th position
/**
 *  @see basic_string
 *  @see head
 *  @see front
 *
 *  @ingroup ct_utils
 */
template <typename Range, typename Position>
struct at
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
 : CharacterConstantType
{ };
#endif

/// Meta-function returning the character at the N-th position
/**
 *  @see basic_string
 *  @see head_c
 *  @see front
 *
 *  @ingroup ct_utils
 */
template <typename Range, size_t Position>
struct at_c;

/// Meta-function returns true_type if the string starts with another string
/**
 *  @see basic_string
 *  @see head
 *  @see equal
 *  @see contains
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct starts_with
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
 : BooleanConstantType
{ };
#endif


/// Meta-function returns true_type if the string ends with another string
/**
 *  @see basic_string
 *  @see tail
 *  @see equal
 *  @see contains
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct ends_with
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
 : BooleanConstantType
{ };
#endif

/// Meta-function returns true_type if the string contains another string
/**
 *  @see basic_string
 *  @see equal
 *  @see lacks
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct contains
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
 : BooleanConstantType
{ };
#endif

/// Meta-function returns true_type if the string does not contain another string
/**
 *  @see basic_string
 *  @see equal
 *  @see contains
 *
 *  @ingroup ct_utils
 */
template <typename Range1, typename Range2>
struct lacks
#ifndef MIRROR_DOCUMENTATION_ONLY
;
#else
 : BooleanConstantType
{ };
#endif

} // namespace ct
} // namespace mire

#endif //include guard

