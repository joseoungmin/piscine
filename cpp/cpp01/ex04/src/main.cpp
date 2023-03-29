#include "replace.hpp"

int main(int ac, char **av){
	std::string 	s1;
	std::string 	s2;
	std::string 	line;
	std::string		newLine;
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (ac != 4){
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (0);
	}
	ifs.open(av[1]);
	if (!ifs.is_open()){
		std::cout << "Error: file not found" << std::endl;
		return (0);
	}
	s1 = av[2];
	if (s1 == ""){
		std::cout << "Error: empty target" << std::endl;
		return (0);
	}
	s2 = av[3];
	ofs.open(av[1] + std::string(".replace"));
	if (!ofs.is_open()){
		std::cout << "Error: failed to open output file" << std::endl;
		return (0);
	}
	while (!ifs.eof() && std::getline(ifs, line)){
		while (line.find(s1) != std::string::npos){
			newLine = line.substr(0, line.find(s1));
			newLine += s2;
			ofs << newLine;
			line = line.substr(line.find(s1) + s1.length());
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
