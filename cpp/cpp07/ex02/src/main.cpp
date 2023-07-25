#include <iostream>
#include <Array.hpp>

int main(int, char **) {

	std::cout << "int\n";
	Array<int> numbers(5);

	try {
		numbers[6] = 1;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[-2] = 1;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nchar\n";
	Array<char> str1(3);
	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';

	Array<char> str2(str1);
	str2[0] = '1';
	str2[1] = '2';
	str2[2] = '3';

	for (int i = 0; i < 3; i++)
		std::cout << "[" << i << "] = " << str1[i] << ", " << str2[i] << "\n";
	std::cout << "size = " << str1.size() << " " << str2.size() << "\n";

	std::cout << "\nstring\n";
	Array<std::string>	string_set(3);

	string_set[0] = "abcde";
	string_set[1] = "12345";
	string_set[2] = "a2c4e"; 

	for (size_t i = 0; i < string_set.size(); i++)
		std::cout << "string[" << i << "] = " << string_set[i] << "\n";

}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//

//     return 0;
// }