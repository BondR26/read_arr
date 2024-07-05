#pragma once
#include <string>
#include <vector>
#include <regex>
#include <map>

#include "helpers.h"

// use crtp to implement the required funcitons
template <typename T, typename TransformArrPolicy>
class ArrayTransformer
{
public:
	ArrayTransformer(const std::string& str_, const TransformArrPolicy& policy_ = TransformArrPolicy()) : _policy(policy_)
	{
		auto strings = helpers::splitString(str_, '\n');
		_data.resize(strings.size());
		// split the string into the array of numbers
		int i = 0;
		for (auto& str : strings)
		{
			_data[i] = helpers::getNumbers<T>(str);
			i++;
		}
		//
	}

	ArrayTransformer(const std::vector<T>& data_, const TransformArrPolicy& policy_ = TransformArrPolicy()) 
		: _policy(policy_)
	{
		_data.emplace_back(data_);
	}

	ArrayTransformer(const std::vector<std::vector<T>>& data_, const TransformArrPolicy& policy_ = TransformArrPolicy())
		: _data(data_)
		, _policy(policy_)
	{
		
	}

	~ArrayTransformer()
	{

	}

	const std::vector<std::vector<T>>& getArr()
	{
		return _data;
	}

	auto run_policy() 
	{
		return _policy(_data);
	}

private:
	TransformArrPolicy _policy;
	std::vector<std::vector<T>> _data;
};
