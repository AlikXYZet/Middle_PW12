/* ---   Фабричный метод   --- */

#include "0. Testing.h"

/*   Интерфейс "Продуктов" (виртуальный класс):   */
// Груз
__interface ICargo
{
	virtual std::string Action() const = 0;
};

/*   Конкретные "Продукты":   */
// Круглый Груз
class RoundCargo : public ICargo
{
public:
	// Конкретное действие для конкретного "Продукта"
	std::string Action() const override
	{
		return "Круглое тащат";
	}
};
// Квадратный Груз
class SquareCargo : public ICargo
{
public:
	// Конкретное действие для конкретного "Продукта"
	std::string Action() const override
	{
		return "Квадратное катят";
	}
};

/*   Абстрактный класс "Фабрик" (виртуальный класс):   */
// Рабочие
class IWorkers
{
public:
	/*   "Фабричный метод" для получения "Продукта"   */
	// Получение типа груза
	virtual ICargo* GetCargoType() const = 0;

	/*   "Фабричный метод" для вывода информации   */
	// Вывод информации о работе
	std::string Work() const
	{
		/*   Вызываем "Фабричный метод" для получения "Продукта"   */
		// Получаем информацию о грузе
		ICargo* cargo = this->GetCargoType();
		/*   Вызываем функцию "Продукта"   */
		// Получаем информацию о работе над грузом
		std::string result = "Рабочие на данный момент " + cargo->Action();

		delete cargo;
		return result;
	}
};

/*   Конкретные "Фабрики":   */
// Сильные Рабочие
class StrongWorkers : public IWorkers
{
public:
	/*   Конкретный "Продукт" для конкретной "Фабрики"   */
	ICargo* GetCargoType() const override
	{
		return new RoundCargo;
	}
};
// Ленивые Рабочие
class LazyWorkers : public IWorkers
{
public:
	/*   Конкретный "Продукт" для конкретной "Фабрики"   */
	ICargo* GetCargoType() const override
	{
		return new SquareCargo;
	}
};

/*   Код "Клиента":   */
// Проверка, Контроль рабочих
void Verification(const IWorkers& workers)
{
	std::cout << "Проверка работы рабочих:\n"
		<< workers.Work() << std::endl;
}

int main1()
{
	//setlocale(LC_ALL, "Russian");

	std::cout << "Работают Сильные рабочие.\n";
	IWorkers* Group_No1 = new StrongWorkers;
	Verification(*Group_No1);

	std::cout << "\n";

	std::cout << "Работают Ленивые рабочие.\n";
	IWorkers* Group_No2 = new LazyWorkers;
	Verification(*Group_No2);

	delete Group_No1;
	delete Group_No2;
	return 0;
}

/*   Вывод:   
* Каждая "Фабрика" имеет свой "Продукт",
* но все "Фабрики" имеют общий интерфейс для взаимодействия со своим "Продуктом",
* а все "Продукты" – общий интерфейс с вызовом своей "Операции" над "Продуктом".
*/