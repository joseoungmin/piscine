#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>

//// static class ?? ////


class Convert
{
	private:
		Convert();
		double	mData
		char	*mEndptr;
	public:
		Convert(const Convert & obj);
		Convert& operator = (Convert & obj);
		~Convert();
	
		void	setData(char * input);

		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();
};

Convert::Convert()
: mData(0), mEndptr(NULL) {}

Convert::Convert(const Convert & obj) {
	*this = obj;
}

Convert& Convert::operator = (const Convert & obj) {
	if (this != &obj)
		mData = obj->mData;
	return (*this);
}

Convert::~Convert() {}

Convert::setData(char * input) {

}


#endif
