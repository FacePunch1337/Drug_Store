#include <iostream>
#include <vector>
#include "Factory.h"
#include "Product.h"


struct ProductDeleter {

	void operator()(Product* p) {

		delete p;

	}


};

int main()
{


	ProdFactory factory;

	std::vector<Product*> store;
	store = factory.fromDirectory("./");

	
	std::vector<std::unique_ptr<Product>> unique_store;

	std::vector<std::weak_ptr<Product>> weak_store;
		
	std::vector<std::shared_ptr<Product>> shared_store;


	for (int i = 0; i < store.size(); i++) {


		shared_store.push_back(std::shared_ptr<Product>(store[i]));

	}


	std::cout << "Pills" << "\n";
	for (int i = 0; i < store.size(); i++) {

		if (dynamic_cast<Pills*>(store[i])) {

			std::cout << shared_store[i]->print() << "\n";
		}
	}

	std::cout << "Syrups" << "\n";
	for (int i = 0; i < store.size(); i++) {

		if (dynamic_cast<Syrup*>(store[i])) {

			std::cout << shared_store[i]->print() << "\n";
		}
	}






}