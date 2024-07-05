#pragma once
#include <memory>

#include "array_transform_policies.h"
#include "num_array.h"


enum class ePolicy : int
{
	eSort,
	eDump,
	eFindIntersection,
	eFindIntersectionAmongTwoLongest,
	eSortUniqueNumbersOnly
};

// Template specialization to map enum values to policy types
template <ePolicy>
struct PolicyType {};

template <>
struct PolicyType<ePolicy::eSort> {
	using type = SortPolicy;
};

template <>
struct PolicyType<ePolicy::eDump> {
	using type = DumpPolicy;
};

template <>
struct PolicyType<ePolicy::eFindIntersection> {
	using type = FindIntersectionPolicy;
};

template <>
struct PolicyType<ePolicy::eFindIntersectionAmongTwoLongest> {
	using type = FindIntersectionAmongTwoLongestPolicy;
};

template <>
struct PolicyType<ePolicy::eSortUniqueNumbersOnly> {
	using type = SortUniqueNumbersOnlyPolicy;
};

// Function to get the policy type based on the enum
template <ePolicy plc_>
using PolicyType_t = typename PolicyType<plc_>::type;

void run_arrTransform(const std::string& data, ePolicy plc);