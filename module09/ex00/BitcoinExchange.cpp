#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::string file)
{
	std::ifstream fin(file);
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

static int parse_date(std::string dateString)
{
	if (dateString.size() != 10)
		return (std::cout << "Invalid date" << std::endl, 0);

	// Initialize a tm structure to hold the parsed date
	std::tm tm = {};

	// Create a string stream to parse the date string
	std::istringstream ss(dateString);

	// Parse the date string using std::get_time
	ss >> std::get_time(&tm, "%Y-%m-%d");

	// Check if parsing was successful
	if (ss.fail())
		return (std::cout << "Invalid date" << std::endl, 0);

	// Convert the parsed date to a time_t value
	std::time_t date = mktime(&tm);
	if (date == -1)
		return (std::cout << "Invalid date" << std::endl, 0);

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
	{
		std::cout << "Invalid line: " << line << std::endl;
	}
}


static bool isValidPositiveFloat(const std::string& valueString) {
    std::istringstream ss(valueString);
    float value;

    ss >> std::noskipws >> value;

    // Check if parsing succeeded, no extra characters remain, and the number is positive
    bool ret = !ss.fail() && ss.eof() && value >= 0;
	if (!ret)
		std::cout << "Invalid value: " << std::endl;
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
		
	}
}