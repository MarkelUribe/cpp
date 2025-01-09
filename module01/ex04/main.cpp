#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	// Error control
	if (argc != 4 || !*argv[2]) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::string	fileName = argv[1];
	std::ifstream	ifs(fileName.c_str());

	if (!ifs.is_open()) {
		std::cerr << "Error opening the file!" << std::endl;
		return 1;
	}

	std::string line, text;

	while (std::getline(ifs, line))
	{
		text += line;
		text += "\n";
	}
	ifs.close();

	std::string s1, s2;
	size_t	found = 0;
	s1 = argv[2];
	s2 = argv[3];
	while ((found = text.find(s1, found)) != std::string::npos) {
		text.erase(found, s1.length());
		text.insert(found, s2);
		found += s2.length();
	}
	std::string	newFileName = fileName;
	newFileName += ".replace";
	std::ofstream	ofs(newFileName.c_str());
	ofs << text << std::endl;
	ofs.close();

	return 0;
}
