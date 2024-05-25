/* ---   Строитель   --- */

#include "0. Testing.h"

/*   Класс "Продукта":   */
class Product
{
public:
	int ValueLight;
	int ValueSound;
	int ValueLift;

	// Перегрузка operator<< для вывода значений
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

/*   Интерфейс "Строителя":   */
// Контроллер
__interface IController
{
	/*   Создающие методы:   */
	// Функция создания продукта
	virtual void CreateProduct() {};
	// Функции добавления контроля
	virtual void AddLightСontrol(int value) {};
	virtual void AddSoundСontrol(int value) {};
	virtual void AddLiftСontrol(int value) {};
};

/*   Конкректный "Строитель":   */
// Конкректный Контроллер
class ConcreteController : public IController
{
private:
	Product* СurrentProduct;

public:

	// Реализация виртуальных методов
	void CreateProduct() override
	{
		//std::cout << "ConcreteBuilder::CreateProduct()" << std::endl;
		СurrentProduct = new Product();
	}

	void AddLightСontrol(int value) override
	{
		//std::cout << "ConcreteBuilder::CurrentProduct->ValueLight = " << value << std::endl;
		СurrentProduct->ValueLight = value;
	}

	void AddSoundСontrol(int value) override
	{
		//std::cout << "ConcreteBuilder::CurrentProduct->ValueSound = " << value << std::endl;
		СurrentProduct->ValueSound = value;
	}

	void AddLiftСontrol(int value) override
	{
		//std::cout << "ConcreteBuilder::CurrentProduct->ValueLift = " << value << std::endl;
		СurrentProduct->ValueLift = value;
	}

	// Метод возврата продукта для клиента
	virtual Product* GetResult()
	{
		return СurrentProduct;
	}
};

/*   Класс "Директор":   */
class Director
{
public:
	// Метод, добавления контроля всех вариаций
	void ConstructAll(IController& controller)
	{
		controller.CreateProduct();
		controller.AddLightСontrol(10);
		controller.AddSoundСontrol(50);
		controller.AddLiftСontrol(80);
	}

	// Светомузыка: Метод, добавления контроля Света и Звука
	void Light_Music(IController& controller)
	{
		controller.CreateProduct();
		controller.AddLightСontrol(30);
		controller.AddSoundСontrol(30);
	}

	// Лифт: Метод, добавления контроля Звука и Подъёма
	void Elevator(IController& controller)
	{
		controller.CreateProduct();
		controller.AddSoundСontrol(20);
		controller.AddLiftСontrol(80);
	}

	// Автоподъёмник: Метод, добавления контроля Света и Подъёма
	void Autolift(IController& controller)
	{
		controller.CreateProduct();
		controller.AddLightСontrol(100);
		controller.AddLiftСontrol(30);
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

/*   Вывод:
* Патерн используется для получения продукта с конкректными характеристиками:
* инициализация уже встроенных в продукт переменных (в данном случае)
* или добавление функционала (при реализации "Продукта" со встроенным дин.массивом)
* 
* "Строитель" реализует те или иные методы инициализации переменных или добавления функционала
* и возвращает "Продукт" (результат используемых методов)
* 
* "Директор" реализует комбинации методов "Строителя"
*/