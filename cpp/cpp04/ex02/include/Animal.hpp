#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();
	Animal& operator=(const Animal& other);

	virtual void makeSound() const = 0; // 반드시 재정의 해야만 하는 함수 = 순수가상함수
	std::string getType() const;		// 순수가상함수가 들어간 클레스  = 추상 클래스
};

#endif