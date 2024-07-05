#include "file_reader.h"

#include <filesystem>
#include <fstream>
#include <sstream>


FileReader::FileReader()
{

}

FileReader::~FileReader()
{

}

std::string FileReader::open(const std::string& filename_)
{
	std::string temp;

	std::ifstream file(filename_.c_str(), std::ios::binary);
	if (file.is_open())
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		temp = buffer.str();
		return temp;
	}

	return {};
}