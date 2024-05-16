/* ---   ���������   --- */

#include "0. Testing.h"

/*   ����� "��������":   */
class Product
{
public:
	int ValueLight;
	int ValueSound;
	int ValueLift;

	// ���������� operator<< ��� ������ ��������
	friend std::ostream& operator<<(std::ostream& out, const Product& p)
	{
		if (p.ValueLight)
			out << "ValueLight = " << p.ValueLight << '\n';

		if (p.ValueSound)
			out << "ValueSound = " << p.ValueSound << '\n';

		if (p.ValueLift)
			out << "ValueLift = " << p.ValueLift << '\n';

		return out;
	}
};

/*   ��������� "���������":   */
// ����������
class IController
{
public:
	/*   ��������� ������:   */
	// ������� �������� ��������
	virtual void CreateProduct() {};
	// ������� ���������� ��������
	virtual void AddLight�ontrol(int value) {};
	virtual void AddSound�ontrol(int value) {};
	virtual void AddLift�ontrol(int value) {};
};

/*   ����������� "���������":   */
// ����������� ����������
class ConcreteController : public IController
{
private:
	Product* �urrentProduct;

public:

	// ���������� ����������� �������
	void CreateProduct() override
	{
		//std::cout << "ConcreteBuilder::CreateProduct()" << std::endl;
		�urrentProduct = new Product();
	}

	void AddLight�ontrol(int value) override
	{
		//std::cout << "ConcreteBuilder::CurrentProduct->ValueLight = " << value << std::endl;
		�urrentProduct->ValueLight = value;
	}

	void AddSound�ontrol(int value) override
	{
		//std::cout << "ConcreteBuilder::CurrentProduct->ValueSound = " << value << std::endl;
		�urrentProduct->ValueSound = value;
	}

	void AddLift�ontrol(int value) override
	{
		//std::cout << "ConcreteBuilder::CurrentProduct->ValueLift = " << value << std::endl;
		�urrentProduct->ValueLift = value;
	}

	// ����� �������� �������� ��� �������
	virtual Product* GetResult()
	{
		return �urrentProduct;
	}
};

/*   ����� "��������":   */
class Director
{
public:
	// �����, ���������� �������� ���� ��������
	void ConstructAll(IController& controller)
	{
		controller.CreateProduct();
		controller.AddLight�ontrol(10);
		controller.AddSound�ontrol(50);
		controller.AddLift�ontrol(80);
	}

	// �����������: �����, ���������� �������� ����� � �����
	void Light_Music(IController& controller)
	{
		controller.CreateProduct();
		controller.AddLight�ontrol(30);
		controller.AddSound�ontrol(30);
	}

	// ����: �����, ���������� �������� ����� � �������
	void Elevator(IController& controller)
	{
		controller.CreateProduct();
		controller.AddSound�ontrol(20);
		controller.AddLift�ontrol(80);
	}

	// �������������: �����, ���������� �������� ����� � �������
	void Autolift(IController& controller)
	{
		controller.CreateProduct();
		controller.AddLight�ontrol(100);
		controller.AddLift�ontrol(30);
	}
};

int main3()
{
	Product* product1, * product2, * product3, * product4;
	ConcreteController B;
	Director D;

	D.ConstructAll(B);
	product1 = B.GetResult();

	D.Light_Music(B);
	product2 = B.GetResult();

	D.Elevator(B);
	product3 = B.GetResult();

	D.Autolift(B);
	product4 = B.GetResult();

	std::cout << '\n';
	std::cout << "product1:\n" << *product1 << std::endl;
	std::cout << "product2:\n" << *product2 << std::endl;
	std::cout << "product3:\n" << *product3 << std::endl;
	std::cout << "product4:\n" << *product4 << std::endl;

	delete product1, product2, product3, product4;
	return 0;
}

/*   �����:
* ������ ������������ ��� ��������� �������� � ������������ ����������������:
* ������������� ��� ���������� � ������� ���������� (� ������ ������)
* ��� ���������� ����������� (��� ���������� "��������" �� ���������� ���.��������)
* 
* "���������" ��������� �� ��� ���� ������ ������������� ���������� ��� ���������� �����������
* � ���������� "�������" (��������� ������������ �������)
* 
* "��������" ��������� ���������� ������� "���������"
*/