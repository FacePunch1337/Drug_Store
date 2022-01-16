#pragma once
#include <iostream>
#include "Product.h"
#include <fstream>
#include <filesystem>
#include <vector>


class ProdFactory {

private:

	size_t parts;

	std::string* splitString(std::string str, char sym) {

		size_t pos = 0;
		parts = 1;

		while ((pos = str.find(sym, pos + 1)) != std::string::npos) {
			parts++;
		}

		std::string* res = new std::string[parts];
		pos = 0;
		size_t pos2;

		for (int i = 0; i < parts - 1; i++) {

			pos2 = str.find(sym, pos + 1);
			res[i] = str.substr(pos, pos2 - pos);
			pos = pos2;


		}

		res[parts - 1] = str.substr(pos + 1);



		return res;
	}

public:

	Product* fromString(std::string str) {

		auto arr = splitString(str, '\n');

		size_t lines = parts;

		if (lines != 4) {

			return NULL;
		}


		auto title = splitString(arr[0], ':');
		auto price = splitString(arr[1], ':');
		auto manufacturer = splitString(arr[2], ':');
		auto part5 = splitString(arr[3], ':');


		if (part5[0] == "amount") {

			Pills* pills = new Pills;
			pills->setAmount(stoi(part5[1]))->setTitle(title[1])->setPrice(price[1])->setManufacturer(manufacturer[1]);
			return pills;

		}
		if (part5[0] == "ml") {

			Syrup* syrup = new Syrup;
			syrup->setMl(part5[1])->setTitle(title[1])->setPrice(price[1])->setManufacturer(manufacturer[1]);
			return syrup;

		}

		return NULL;

	}

	Product* fromFile(std::string filename) {

		std::ifstream input;
		input.open(filename);
		char chunk[100];
		std::string str;

		while (!input.eof())
		{
			input.read(chunk, 10);
			std::streamsize n = input.gcount();
			chunk[n] = 0;


			str += chunk;
		}

		input.close();

		return fromString(str);


	}


	std::vector<Product*> fromDirectory(std::string directory) {



		std::vector<Product*>products;

		for (std::filesystem::directory_entry const& dir : std::filesystem::directory_iterator(directory)) {

			if (dir.is_regular_file()) {

				if (dir.path().extension() == ".prod") {

					Product* prod = fromFile(dir.path().string());
					if (prod) {

						products.push_back(prod);

					}

				}
			}

		}

		return products;
	}


};
