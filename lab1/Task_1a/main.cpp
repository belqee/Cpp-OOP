
#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>


int main()
{
	std::cout << "Hello world!" << "\n";

	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using namespace Module1;
	std::cout << getMyName() << "\n"; // (A)
	std::cout << Module2::getMyName() << "\n";

	//using namespace Module2; // (B) Ошибка комплияции возникала изза того что компилятор не понимал к какому именному пространству принадлежит getMyName()
	std::cout << Module2::getMyName() << "\n"; // COMPILATION ERROR (C) // решаем эту проблему следующим образом

	std::cout << Module2::getMyName() << "\n"; // (D)
    using Module3::getMyName;
    std::cout << getMyName() << "\n";

}