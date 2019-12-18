#include "human.h"
#include <string>
class teacher : public human {
public:
	/* ����������� ������ teacher
	@param string last_name - teacher's last name
	@param string name - teacher's name
	@param string second_name - teacher's second name
	*/
	teacher(
		std::string last_name,
		std::string name,
		std::string second_name,
		// ���������� ������� ����� �� ������� � �������������
		unsigned int work_time
	) : human(
		last_name,
		name,
		second_name
	) {
		this->work_time = work_time;
	}
	/* ��������� ���������� ������� ����� 
	@return work_time - teacher's work time
	*/
	unsigned int get_work_time()
	{
		return this->work_time;
	}
private:
	// ������� ����
	unsigned int work_time;
};