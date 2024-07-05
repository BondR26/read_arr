#include "policy_factory.h"

void run_arrTransform(const std::string& data, ePolicy plc)
{
	switch (plc)
	{
	case ePolicy::eDump:
	{
		ArrayTransformer<int, PolicyType_t<ePolicy::eDump>> arr(data);
		arr.run_policy();
	}break;
	case ePolicy::eSort:
	{
		ArrayTransformer<int, PolicyType_t<ePolicy::eSort>> arr(data);
		arr.run_policy();
		
		// 
		ArrayTransformer<int, PolicyType_t<ePolicy::eDump>> transformed_arr(arr.getArr());
		transformed_arr.run_policy();

	}break;
	case ePolicy::eFindIntersection:
	{
		ArrayTransformer<int, PolicyType_t<ePolicy::eFindIntersection>> arr(data);
		auto res = arr.run_policy();
		
		//
		ArrayTransformer<int, PolicyType_t<ePolicy::eDump>> transformed_arr(res);
		transformed_arr.run_policy();

	}break; 
	case ePolicy::eFindIntersectionAmongTwoLongest:
	{
		ArrayTransformer<int, PolicyType_t<ePolicy::eFindIntersectionAmongTwoLongest>> arr(data);
		auto res = arr.run_policy();
		//
		ArrayTransformer<int, PolicyType_t<ePolicy::eDump>> transformed_arr(res);
		transformed_arr.run_policy();

		
	}break;
	case ePolicy::eSortUniqueNumbersOnly:
	{
		ArrayTransformer<int, PolicyType_t<ePolicy::eSortUniqueNumbersOnly>> arr(data);
		auto res = arr.run_policy();
		//
		ArrayTransformer<int, PolicyType_t<ePolicy::eDump>> transformed_arr(res);
		transformed_arr.run_policy();

	}break;
	}
}


