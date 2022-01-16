#pragma once
#include <iostream>
#include <string>

class Product {

private:
	std::string category;
	std::string title;
	std::string price;
	std::string manufacturer;
public:
	Product* setCategory(std::string category) {

		this->category = category;
		return this;

	}
	Product* setTitle(std::string title) {

		this->title = title;
		return this;

	}
	Product* setManufacturer(std::string manufacturer) {

		this->manufacturer = manufacturer;
		return this;
	}
	Product* setPrice(std::string price) {

		this->price = price;
		return this;

	}
	std::string getCategory() {

		return category;
	}
	std::string getTitle() {

		return title;
	}
	std::string getManufacturer() {

		return manufacturer;
	}
	std::string getPrice() {

		return price;
	}
	virtual std::string print() = 0;

};




class Pills : public Product {

private:
	int amount;

public:

	Pills* setAmount(int amount) {

		this->amount = amount;
		return this;
	}

	int getAmount() {

		return amount;
	}

	std::string print() {

		return getTitle() + " " + std::to_string(getAmount()) + " tablets " + "price:" + getManufacturer() + getPrice();
	}

};

class Syrup : public Product {

private:
	std::string  ml;

public:

	Syrup* setMl(std::string ml) {

		this->ml = ml;
		return this;
	}

	std::string getMl() {

		return ml;
	}

	std::string print() {

		return getTitle() + " " + getMl() + " price:" + getManufacturer() + getPrice();
	}

};