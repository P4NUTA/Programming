#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include<ctime>
using namespace std;
class Human {
public:
	/*���������
	@param int day - ���� ��������
	@param int month - ����� ��������
	@param int year - ��� ��������
	@param string Name - ���
	@param string LastName - �������
	@param string SecondName - ��������
	*/
	Human(int day, int month, int year, string Name, string LastName, string SecondName) {
		this->day = day;
		this->month = month;
		this->year = year;
		this->Name = Name;
		this->LastName = LastName;
		this->SecondName = SecondName;
	}
	/*���������
	@param string Name - ���
	@param string LastName - �������
	@param string SecondName - ��������
	*/
	Human(string Name, string LastName, string SecondName) {
		this->day = 0;
		this->month = 0;
		this->year = 0;
		this->Name = Name;
		this->LastName = LastName;
		this->SecondName = SecondName;
	}
	/*����� ������� �����
	@return full_name - ���
	*/
	virtual string get_full_name() {
		ostringstream full_name;
		full_name << this->LastName << " " << this->Name << " " << this->SecondName;
		return full_name.str();
	}
	/*����� ���������� ���,�������,����
	*/
	virtual void year_num() {
		if (year) {
			time_t now;
			struct tm timeinfo;
			time(&now);
			localtime_s(&timeinfo, &now);
			int nowyear = timeinfo.tm_year + 1900;
			int nowmonth = timeinfo.tm_mon;
			int nowday = timeinfo.tm_mday;

			int temp_day = nowday - day;
			int temp_month = nowmonth - month;
			int temp_year = nowyear - year;
			if (temp_day < 0) {
				temp_month--;
				temp_day += 30;
			}
			if (temp_month < 0) {
				temp_year--;
				temp_month += 12;
			}
			cout << "���: " << temp_year << endl;
			cout << "�������: " << temp_month << endl;
			cout << "����: " << temp_day << endl;
		}
	}
private:
	int year;
	int month;
	int day;
	string Name;
	string LastName;
	string SecondName;
};

class Staff : public Human {
public:
	/*���������
	@param int day - ���� ��������
	@param int month - ����� ��������
	@param int year - ��� ��������
	@param string Name - ���
	@param string LastName - �������
	@param string SecondName - ��������
	*/
	Staff(int day, int month, int year, string Name, string LastName, string SecondName) : Human(day, month, year, Name, LastName, SecondName) {}
	/*���������
	@param string Name - ���
	@param string LastName - �������
	@param string SecondName - ��������
	*/
	Staff(string Name, string LastName, string SecondName) : Human(Name, LastName, SecondName) {}
	/*���������
	@param int day - ���� ��������
	@param int month - ����� ��������
	@param int year - ��� ��������
	@param string Name - ���
	@param string LastName - �������
	@param string SecondName - ��������
	@param int Cash - ��������
	@param string post - ���������
	*/
	Staff(int day, int month, int year, string Name, string LastName, string SecondName, int Cash, string post) : Human(day, month, year, Name, LastName, SecondName) {
		this->Cash = Cash;
		this->post = post;
	}
	/*���������� ��������*/
	void add_cash() {
		int temp;
		cout << "������� �������� ��� " << Human::get_full_name() << endl;
		cin >> temp;
		this->Cash = temp;
	}
	/*���������� ���������*/
	void add_post() {
		string temp;
		cout << "������� ��������� ��� " << Human::get_full_name() << endl;
		cin >> temp;
		this->post = temp;
	}
	/*����� ������ ����������*/
	void get_full_info() {
		cout << Human::get_full_name() << " " << post << endl;
		cout << "��������: " << Cash << endl;

		Human::year_num();
	}
private:
	int Cash;
	string post;
};