/* ---   ����������� �������   --- */

#include <iostream>
#include "0. Testing.h"

/*   ��������� "���������" 1-��� ���� (����������� �����):   */
// �����������
class IGreeting
{
public:
	virtual std::string ToGreet() const = 0;
};

/*   ���������� "��������" 1-��� ����:   */
// ����������� �� �������
class RuGreeting : public IGreeting
{
public:
	// ���������� �������� ��� ����������� "��������"
	std::string ToGreet() const override
	{
		return "������";
	}
};
// ����������� �� ����������
class EnGreeting : public IGreeting
{
public:
	// ���������� �������� ��� ����������� "��������"
	std::string ToGreet() const override
	{
		return "Hello";
	}
};


/*   ��������� "���������" 2-��� ���� (����������� �����):   */
// ��������
class IGoodbye
{
public:
	virtual std::string ToSayGoodbye() const = 0;
};

/*   ���������� "��������" 2-��� ����:   */
// �������� �� �������
class RuGoodbye : public IGoodbye
{
public:
	// ���������� �������� ��� ����������� "��������"
	std::string ToSayGoodbye() const override
	{
		return "����";
	}
};
// �������� �� ����������
class EnGoodbye : public IGoodbye
{
public:
	// ���������� �������� ��� ����������� "��������"
	std::string ToSayGoodbye() const override
	{
		return "Bye";
	}
};


/*   ��������� "������" (����������� �����):   */
// �������
class IHuman
{
public:
	/*   "��������� �����" ��� ��������� "��������" 1-��� ����   */
	// ��������� ���� �����������
	virtual IGreeting* GetGreeting() const = 0;
	/*   "��������� �����" ��� ��������� "��������" 2-��� ����   */
	// ��������� ���� ��������
	virtual IGoodbye* GetGoodbye() const = 0;
};

/*   ���������� "�������":   */
// ������� �� �������
class RuHuman : public IHuman
{
public:
	/*   ���������� "�������" ��� ���������� "�������"   */
	IGreeting* GetGreeting() const override
	{
		return new RuGreeting;
	}

	IGoodbye* GetGoodbye() const override
	{
		return new RuGoodbye;
	}
};
// ������� �� ����������
class EnHuman : public IHuman
{
public:
	/*   ���������� "�������" ��� ���������� "�������"   */
	IGreeting* GetGreeting() const override
	{
		return new EnGreeting;
	}

	IGoodbye* GetGoodbye() const override
	{
		return new EnGoodbye;
	}
};

/*   ��� "�������":   */
// �������
void �ommunication(const IHuman& human)
{
	std::cout << "������� ��������:\n"
		<< human.GetGreeting()->ToGreet() << '\n'
		<< " ... \n"
		<< human.GetGoodbye()->ToSayGoodbye() << '\n'
		<< std::endl;
}

int main2()
{
	//setlocale(LC_ALL, "Russian");

	std::cout << "������ �������.\n";
	IHuman* Human_1 = new RuHuman;
	�ommunication(*Human_1);

	std::cout << "������ �������.\n";
	IHuman* Human_2 = new EnHuman;
	�ommunication(*Human_2);

	delete Human_1;
	delete Human_2;
	return 0;
}

/*   �����:
* ������ "�������" ����� ���� "��������" ������� ����,
* �� ��� "�������" ����� ����� ��������� ��� �������������� �� ����� "���������",
* � ��� "��������" ������ ���� � ����� ��������� (������������ ���) � ������� ����� "��������" ��� "���������".
*/