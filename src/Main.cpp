#include <iostream>

class CaffeineBeverage{
public:
	// what is final in java in C++ can be done by just leaving out the virtual!
	// this is a template! some methods in it are defined in this class! (boilWater and pourInCup) and some 
	// are defined in its subclass!
	
	void prepareRecipe(){
		boilWater();
		brew();
		pourInCup();
		if (customerWantsCondiments()) {addCondiments();}
	}
	virtual void brew(){};
	virtual void addCondiments(){};
	
	void boilWater(){
		std::cout << "Boiling water!" << std::endl;
	}
	
	void pourInCup(){
		std::cout << "Pour in cup! " << std::endl;
	}
	// hook - subclass can override this method but does not have to
	//virtual bool customerWantsCondiments(){
	//	return true;
	//}
	bool customerWantsCondiments() {
		std::cout << "add condiments 0/1 -> " << std::endl;
		std::string answer="";
		std::getline(std::cin, answer);
		if (answer=="1") {return true;}
		else {return false;}
		
	}
};

class Tea : public CaffeineBeverage{
public:
	void brew() override {
		std::cout << "Brewing tea! " << std::endl;
	}
	
	void addCondiments() override {
		std::cout << "Adding Lemon! " << std::endl;
	}
	
};

class Coffee : public CaffeineBeverage{
public:
	void brew() override {
		std::cout << "Dripping Coffee through filter" << std::endl;
	}
	
	void addCondiments() override {
		std::cout << "Adding Sugar and Milk" << std::endl;
	}
	
	
};


int main(){
	CaffeineBeverage* coffe = new Coffee();
	
	
	coffe->prepareRecipe();
	
	std::cout << "Hello world - Git!" << std::endl;
	std::cin.get();
	
}