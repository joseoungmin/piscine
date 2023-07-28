#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "- STACK -\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "top " << mstack.top() << std::endl; mstack.pop();
	std::cout << "size " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] 
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "- LIST -\n";
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << "back " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "size " << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator itL = mlist.begin();
	std::list<int>::iterator iteL = mlist.end();
	// std::list<int>::reverse_iterator itL = mlist.rbegin();
	// std::list<int>::reverse_iterator iteL = mlist.rend();
	++itL;
	--itL;
	while (itL != iteL) {
		std::cout << *itL << std::endl;
		++itL;
	}
	std::list<int> sl(mlist);
	return 0;
}