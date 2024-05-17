/* ---   ��������   --- */

#include "0. Testing.h"

/*   ���������� ������� "��������" ("Singleton"):   */
// �������
class Grandmother
{
private:
	// "��������" �� ������ ���� ������������.
	Grandmother() {}
	Grandmother(const Grandmother&) = delete;
	Grandmother& operator=(Grandmother&) = delete;
	// PS: ���� "private", �� "= delete" �� �����������

	// ��� ����� ��������� (�������)
	std::string Azazel;

protected:
	/* ����������� ������, ����������� ��� "protected", ��� ���� ����� :
	* - ���������� ���� ������� ��������� ������ ��������������� ���������� new;
	* - ����� ���� ����������� ������ ����� �� ������ �������.
	*/
	// Grandmother() {};

public:
	/*   ����������� �����, ������������ ��������� ������ "��������":   */
	static Grandmother& getInstance() {
		static Grandmother instance;
		return instance;
	}

	/*   ������ (��������) ��� ������� � ���������� ������ ������:   */
	// ��������� ��� ����, ��� "���������"
	void Silence(std::string inName)
	{
		Azazel = inName;
	}

	// �������� ��� "���������"
	std::string GetName()
	{
		return Azazel;
	}
};

int main5()
{
	// �������
	Grandmother& Grandmother_1 = Grandmother::getInstance();
	Grandmother& Grandmother_2 = Grandmother::getInstance();
	Grandmother& Grandmother_3 = Grandmother::getInstance();
	Grandmother& Grandmother_4 = Grandmother::getInstance();
	Grandmother& Grandmother_5 = Grandmother::getInstance();

	// ��� � � ��� �� ������������
	Grandmother_3.Silence("���� ������");

	// ����� ������ �������
	std::cout << "��� \"���������\": " << Grandmother_1.GetName() << '\n';
	std::cout << "��� \"���������\": " << Grandmother_2.GetName() << '\n';
	std::cout << "��� \"���������\": " << Grandmother_3.GetName() << '\n';
	std::cout << "��� \"���������\": " << Grandmother_4.GetName() << '\n';
	std::cout << "��� \"���������\": " << Grandmother_5.GetName() << '\n';
	std::cout << std::endl;

	return 0;
}

/*   �����:
* ����� "��������" ����������� ������� ������������� ���������� ������� ������,
* ��� ��������� �������� ������ � ����� � ��� �� ���������� � ����� ����� ����
*/