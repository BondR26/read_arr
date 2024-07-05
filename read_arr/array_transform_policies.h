#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>

#include "helpers.h"


struct SortPolicy
{
public:

	template <typename DigitType>
	void operator()(std::vector<std::vector<DigitType>>& data_) const
	{
		for (auto& arr : data_)
		{
			helpers::selectionSort<DigitType>(arr);
		}
	}
};

struct DumpPolicy
{
public:
	template <typename DigitType>
	void operator()(const std::vector<std::vector<DigitType>>& data_) const
	{
		for (auto arr : data_)
		{
			for (auto digit : arr)
				std::cout << digit << " ";

			std::cout << std::endl;
		}
	}
};

struct FindIntersectionPolicy 
{
public:
	template <typename DigitType>
	std::vector<DigitType> operator()(const std::vector<std::vector<DigitType>>& data_) const
	{
		std::vector<DigitType> res;
		for (int i = 0; i < data_.size() - 1; i++)
		{
			// first cycle we need to find the similair between first two
			if (i == 0)
			{
				res = helpers::findIntersection(data_[i], data_[i + 1]);
				// increase the iterator number to 1 
				// the next iteration after first would begin at index 2 
				// thus we would compare the result from 0 and 1 intersect and the next one 
				i++;
			}
			else
				res = helpers::findIntersection(data_[i], res);
		}

		return res;
	}
};


struct FindIntersectionAmongTwoLongestPolicy 
{
public:
	template <typename DigitType>
	std::vector<DigitType> operator()(const std::vector<std::vector<DigitType>>& data_) const
	{
		// on size ultiuple indexes
		std::multimap<DigitType, DigitType, std::greater<DigitType>> size_to_index;

		// fill it up
		for (size_t i = 0; i < data_.size(); ++i)
		{
			size_to_index.insert({ data_[i].size(), i });
		}

		auto it = size_to_index.begin();
		int first_max_index = it->second;
		++it;
		int second_max_index = it->second;

		if (size_to_index.size() < 2)
		{
			// if the set contain only one value it maeans that the vector are all equall or dont have two 
			throw("vectors are all equall size or not enough vectors");
		}
		else
			return helpers::findIntersection(data_[first_max_index], data_[second_max_index]);
	}
};


struct SortUniqueNumbersOnlyPolicy 
{
public:

	template <typename DigitType>
	std::vector<DigitType> operator()(const std::vector<std::vector<DigitType>>& data_)
	{
		std::set<DigitType> unique_sorted;

		for (auto& arr : data_)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				unique_sorted.insert(arr[i]);
			}
		}

		return {unique_sorted.begin(), unique_sorted.end()};
	}
};