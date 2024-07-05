#pragma once
#include <vector>
#include <string>
#include <regex>
#include <set>


namespace helpers
{
	std::vector<std::string> splitString(const std::string& data_, char delimter);

	template <typename T>
	std::vector<T> getNumbers(const std::string& str_)
	{
		std::regex pattern("\\d+");
		std::sregex_iterator it(str_.begin(), str_.end(), pattern);
		std::sregex_iterator end;

		std::vector<T> arr;
		while (it != end)
		{
			auto str = it->str();
			int res = std::stoi(it->str());
			auto r = static_cast<T>(res);
			arr.push_back(r);
			++it;
		}

		return arr;
	}

	template <typename T>
	void selectionSort(std::vector<T>& arr)
	{
		for (int i = 0; i < arr.size() - 1; i++)
		{
			int min_index = i;
			for (int j = i + 1;j< arr.size(); j++)
			{
				if (arr[j] < arr[min_index])
				{
					min_index = j;
				}
			}
			std::swap(arr[i], arr[min_index]);
		}
	}

	template <typename T>
	std::vector<T> findIntersection(const std::vector<T>& arr1, const std::vector<T>& arr2)
	{
		std::set<T> first(arr1.begin(), arr1.end());

		std::vector<T> res;
		for (auto digit : arr2)
		{
			if (first.find(digit) != first.end())
			{
				res.push_back(digit);
			}
		}
		return res;
	}
}