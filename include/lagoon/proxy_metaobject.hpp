/**
 * @file lagoon/proxy_metaobject.hpp
 * @brief Declaration of the `proxy_metaobject` class
 *
 * Copyright Matus Chochlik.
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef LAGOON_PROXY_METAOBJECT_1105240825_HPP
#define LAGOON_PROXY_METAOBJECT_1105240825_HPP

#include "metaobject.hpp"
#include "fingerprint.hpp"

namespace lagoon {

class base_registry;

class proxy_metaobject
 : public metaobject
{
private:
	fingerprint _fpt;
	base_registry& _reg;
public:
	proxy_metaobject(fingerprint fpt, base_registry& reg)
	noexcept
	 : _fpt(fpt)
	 , _reg(reg)
	{ }

	bool is_none(void) const
	override;

	fingerprint get_fingerprint(void)
	override;

	const metaobject_traits* traits(void)
	override;

	std::string_view get_source_file(void)
	override;

	unsigned get_source_line(void)
	override;

	unsigned get_source_column(void)
	override;

	std::string_view get_base_name(void)
	override;

	std::string_view get_full_name(void)
	override;

	std::string_view get_display_name(void)
	override;

	any_constant get_constant(void)
	override;

	shared_metaobject get_type(void)
	override;

	shared_metaobject get_scope(void)
	override;

	shared_metaobject get_aliased(void)
	override;

	shared_metaobject get_base_class(void)
	override;

	shared_metaobject get_elaborated_type_specifier(void)
	override;

	shared_metaobject get_access_specifier(void)
	override;

	shared_metaobject_sequence get_base_classes(void)
	override;

	shared_metaobject_sequence get_data_members(void)
	override;

	shared_metaobject_sequence get_member_types(void)
	override;

	shared_metaobject_sequence get_enumerators(void)
	override;

	shared_metaobject_sequence get_members(void)
	override;
};

} // namespace lagoon

#include <lagoon/proxy_metaobject.inl>

#endif //include guard

