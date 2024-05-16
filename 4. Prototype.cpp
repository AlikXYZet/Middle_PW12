/* ---   ��������   --- */

#include "0. Testing.h"

/*   ��������� "���������":   */
class IPrototype
{
public:
	virtual IPrototype* clone() = 0;
	virtual void StageName() = 0;
};

/*   "��������" 1-��� ����:   */
class Yin : public IPrototype
{
	IPrototype* clone() override
	{
		return new Yin(*this);
	}
	void StageName() override
	{
		std::cout << "���";
	}
};

/*   "��������" 2-��� ����:   */
class Yang : public IPrototype
{
	IPrototype* clone() override
	{
		return new Yang(*this);
	}
	void StageName() override
	{
		std::cout << "���";
	}
};

/*   "��������" 3-��� ����:   */
class Horseradish : public IPrototype
{
	IPrototype* clone() override
	{
		return new Horseradish(*this);
	}
	void StageName() override
	{
		std::cout << "�����";
	}
};

int main4()
{
	// ������ ���� �������� ���������
	IPrototype* aPrototype[3] = { new Yin, new Yang, new Horseradish };
	// ���������� �������� ������������ (������ ������� aPrototype)
	int aSize = sizeof(aPrototype) / sizeof(*aPrototype);

	// ������ ��� �������� ������
	std::vector<IPrototype*> vPrototype;
	// ���������� ���������� "����� �����" (���������� ������ ������� vPrototype)
	int NumberOfLifeBands;

	std::cout << "���������� �������� ������������: " << aSize << '\n';
	std::cout << "������� ���������� ����� �����: ";
	std::cin >> NumberOfLifeBands;
	std::cout << std::endl;

	// ������������ ������� ����� � �������� ���������� �������� ��� ���������� ��������������� �����
	srand(time(0));

	// ���� ������ � ��������
	for (int i = 0; i < NumberOfLifeBands; ++i)
	{
		// �������� ����� � �������
		vPrototype.push_back(aPrototype[rand() % aSize]->clone());
		// ����� ���������� �� �������
		vPrototype[i]->StageName();
		// �������� �������� ������� � ������������ ������ ������
		delete vPrototype[i];
		std::cout << '\n';
	}
	std::cout << std::endl;

	// ����� ����������� �������
	vPrototype.~vector();

	// �������� ����������� ������� ���������� aPrototype
	std::cout << '\n' << "�������� ����������� aPrototype: " << '\n';
	for (int i = 0; i < aSize; ++i)
	{
		// ����� ���������� �� �������
		aPrototype[i]->StageName();
		std::cout << "   ";
	}
	std::cout << std::endl;

	return 0;
}

/*   �����:
* ������ "��������" ����� ���������� ������������ ������� ������ ���� (������ ����),
* ��� ��� ����������� �������� � ����������� "������" ������� �� ������� "��������"
*/