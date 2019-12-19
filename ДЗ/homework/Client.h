#pragma once
#include "human.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Client : public Human {
public:
	/*���������
	@param string Name - ���
	@param string LastName - �������
	@param string SecondName - ��������
	*/
	Client(string Name, string LastName, string SecondName) : Human(Name, LastName, SecondName) {}
	/*����� ������ ����������*/
	void get_full_info() {
		cout << Human::get_full_name() << endl;
		show_contracts();
	}
	/*���������� ���������
	@param string c_name - �������� ���������
	*/
	void add_contact(string c_name, int c_price) {
		this->contract_name[contracts] = c_name;
		this->contract_price[contracts] = c_price;
		contracts++;
	}
	/*����� ���������� �� �����*/
	void show_contracts() {
		for (int i = 0; i < contracts; i++) {
			cout << "�" << i << "\t" << this->contract_name[i] << "\t" << contract_price[i] << endl;
		}
	}
private:
	int contracts = 0;
	string contract_name[50];
	int contract_price[50];
};