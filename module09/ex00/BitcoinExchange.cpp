#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::string file)
{
	std::ifstream fin(file.c_str());
	if (!fin)
		throw std::runtime_error("Error: could not open the data.csv file.");
	std::string date;
	float value;
	while (fin >> date >> value)
	{
		_map[date] = value;
	}
	fin.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _map(copy._map) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &model)
{
	if (this != &model)
		this->_map = model._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static int parse_date(const std::string &dateString)
{
	if (dateString.size() != 10 || dateString[4] != '-' || dateString[7] != '-')
	{
		std::cout << "Invalid date format" << std::endl;
		return 0;
	}

	int year, month, day;
	std::istringstream ss(dateString);

	ss >> year;
	ss.ignore();
	ss >> month;
	ss.ignore();
	ss >> day;

	if (ss.fail() || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "Invalid date values" << std::endl;
		return 0;
	}

	return 1;
}

static int splitLine(const std::string &line, std::string &date, std::string &val)
{
	std::size_t pos = line.find(" | ");

	if (pos != std::string::npos)
	{
		date = line.substr(0, pos);
		val = line.substr(pos + 3);
	}
	else
		return (std::cout << "Invalid line: " << line << std::endl, 0);
	return 1;
}

static bool isValidPositiveFloat(const std::string &valueString)
{
	std::istringstream ss(valueString);
	float value;

	ss >> std::noskipws >> value;

	// Check if parsing succeeded, no extra characters remain, and the number is positive
	bool ret = !ss.fail() && ss.eof() && value >= 0;
	if (!ret)
		std::cout << "Invalid float value" << std::endl;
	return ret;
}

void BitcoinExchange::printValue(std::ifstream &file)
{
	std::string line, date, val;

	while (std::getline(file, line))
	{
		// Skip empty lines
		if (line.empty())
			continue;

		if (!splitLine(line, date, val) && !parse_date(date) && !isValidPositiveFloat(val))
			continue;

		// Find exact date or closest lower one
		std::map<std::string, float>::iterator it = _map.lower_bound(date);

		if (it == _map.end() || it->first != date) // If exact date not found
		{
			if (it == _map.begin()) // No lower value exists
			{
				std::cout << "No valid lower date found for: " << date << std::endl;
				continue;
			}
			--it; // Move to the closest lower date
		}

		// Print the found value
		std::cout << "Date: " << date << " -> Value: " << val << std::endl;
	}
}