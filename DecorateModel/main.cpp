#include "Person.h"
#include "DecorateClass.h"

int main()
{
	Person *p = new Person("徐志祥");
	DecorateBlouse *blouse = new DecorateBlouse();
	DecorateJeans *jeans = new DecorateJeans();
	jeans -> DecorateObj(p);
	blouse -> DecorateObj(jeans);
	blouse -> show();
	std::cout << std::endl;

	blouse -> DecorateObj(p);
	jeans -> DecorateObj(blouse);
	jeans -> show();
	std::cout << std::endl; 
	
	delete p;
	delete blouse;
	delete jeans;
	return 0;
}

