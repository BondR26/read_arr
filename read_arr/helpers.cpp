#include "helpers.h"

#include <algorithm>
#include <sstream>


namespace helpers
{
	std::vector<std::string> splitString(const std::string& data_, char delimter)
	{
		std::vector<std::string> arrs;
		std::istringstream iss(data_);
		std::string temp;
		while (std::getline(iss, temp, delimter))
		{
			arrs.push_back(temp);
		}

		return arrs;
	}
}