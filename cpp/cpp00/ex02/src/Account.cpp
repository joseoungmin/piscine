#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void){
	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit(int deposit){
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return true;
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void){
	time_t		t = time(0);
	struct tm	*now = localtime(&t);
	std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] ";
}

int		Account::getNbAccounts(void){
	return Account::_nbAccounts;
}

int		Account::getTotalAmount(void){
	return Account::_totalAmount;
}

int		Account::getNbDeposits(void){
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals(void){
	return Account::_totalNbWithdrawals;
}