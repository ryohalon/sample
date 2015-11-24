#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	int map_chip_data_[32][16];

	const char* p_ch = "res/test_stage.csv";
	std::ifstream* map_file = new std::ifstream(p_ch);

	if (map_file->fail())
	{
		std::cerr << "failed. \n";

		exit(0);
	}

	int p;
	std::string str;
	std::vector<std::vector<std::string>> map_chip_data;

	while (getline(*map_file, str))
	{
		if (p = str.find("//") != str.npos)
			continue;

		std::vector<std::string> inner;

		while ((p = str.find(",")) != str.npos)
		{
			inner.push_back(str.substr(0, p));

			str = str.substr(p + 1);
		}

		inner.push_back(str);

		map_chip_data.push_back(inner);
	}

	for (unsigned int i = 0; i < map_chip_data.size(); ++i)
	{
		for (unsigned int k = 0; k < map_chip_data[i].size(); ++k)
		{
			map_chip_data_[i][k] = std::stoi(map_chip_data[i][k]);
		}
	}

	std::ofstream ahoyama;
	ahoyama.open("res/test_stage.txt");

	for (int i = 0; i < 16; ++i)
	{
		for (int k = 0; k < 32; ++k)
		{
			ahoyama << map_chip_data[i][k] << " ";
		}

		ahoyama << std::endl;
	}

}