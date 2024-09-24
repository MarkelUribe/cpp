#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::endl;
	else
	{
		for (int j=1; j < argc; j++)
		{
			for (int i=0; i < (int)strlen(argv[j]); i++)
				std::cout << (char)toupper(argv[j][i]);
		}
		std::cout << std::endl;
	}
	return 0;
}