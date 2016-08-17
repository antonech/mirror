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
#include <mirror/get_fingerprint.hpp>

namespace lagoon {

class base_registry;

class proxy_metaobject
 : public metaobject
{
private:
	mirror::fingerprint _fpt;
	base_registry& _reg;
public:
	proxy_metaobject(const mirror::fingerprint& fpt, base_registry& reg)
	noexcept
	 : _fpt(fpt)
	 , _reg(reg)
	{ }

	bool is_none(void) const
	override;

	std::string_view get_base_name(void)
	override;

	std::string_view get_full_name(void)
	override;

	std::string_view get_display_name(void)
	override;

	shared_metaobject get_type(void)
	override;

	shared_metaobject get_scope(void)
	override;

	shared_metaobject get_aliased(void)
	override;

	shared_metaobject_sequence get_data_members(void)
	override;

	shared_metaobject_sequence get_member_types(void)
	override;
};

} // namespace lagoon

#include <lagoon/proxy_metaobject.inl>

#endif //include guard

