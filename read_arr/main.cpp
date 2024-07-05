#include <iostream>
#include <memory>

#include "file_reader.h"
#include "num_array.h"

#include "array_transform_policies.h"
#include "policy_factory.h"

int main(int argc, char* argv[])
{
	FileReader rd;
	if (argc > 1)
	{
		std::string data = rd.open(argv[1]);
		ePolicy policy_;
		if (argc > 2)
		{
			try 
			{
				// little hack
				policy_ = static_cast<ePolicy>(std::stoi(argv[2]));
			}
			catch (std::exception& exc)
			{
				std::cout << exc.what();
				return EXIT_FAILURE;
			}
		}

		run_arrTransform(data, policy_);

	}
	else
	{
		std::cout << "read_arr.exe <filename> <transform array policy(0-4)>" << std::endl;
	}
	
	return EXIT_SUCCESS;
}