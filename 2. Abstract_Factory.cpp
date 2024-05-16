/* ---   Абстрактная фабрика   --- */

#include <iostream>
#include "0. Testing.h"

/*   Интерфейс "Продуктов" 1-ого типа (виртуальный класс):   */
// Приветствие
class IGreeting
{
public:
	virtual std::string ToGreet() const = 0;
};

/*   Конкретные "Продукты" 1-ого типа:   */
// Приветствие на русском
class RuGreeting : public IGreeting
{
public:
	// Конкретное действие для конкретного "Продукта"
	std::string ToGreet() const override
	{
		return "Привет";
	}
};
// Приветствие на английском
class EnGreeting : public IGreeting
{
public:
	// Конкретное действие для конкретного "Продукта"
	std::string ToGreet() const override
	{
		return "Hello";
	}
};


/*   Интерфейс "Продуктов" 2-ого типа (виртуальный класс):   */
// Прощание
class IGoodbye
{
public:
	virtual std::string ToSayGoodbye() const = 0;
};

/*   Конкретные "Продукты" 2-ого типа:   */
// Прощание на русском
class RuGoodbye : public IGoodbye
{
public:
	// Конкретное действие для конкретного "Продукта"
	std::string ToSayGoodbye() const override
	{
		return "Пока";
	}
};
// Прощание на английском
class EnGoodbye : public IGoodbye
{
public:
	// Конкретное действие для конкретного "Продукта"
	std::string ToSayGoodbye() const override
	{
		return "Bye";
	}
};


/*   Интерфейс "Фабрик" (виртуальный класс):   */
// Рабочие
class IHuman
{
public:
	/*   "Фабричный метод" для получения "Продукта" 1-ого типа   */
	// Получение типа приветствия
	virtual IGreeting* GetGreeting() const = 0;
	/*   "Фабричный метод" для получения "Продукта" 2-ого типа   */
	// Получение типа прощания
	virtual IGoodbye* GetGoodbye() const = 0;
};

/*   Конкретные "Фабрики":   */
// Человек на русском
class RuHuman : public IHuman
{
public:
	/*   Конкретный "Продукт" для конкретной "Фабрики"   */
	IGreeting* GetGreeting() const override
	{
		return new RuGreeting;
	}

	IGoodbye* GetGoodbye() const override
	{
		return new RuGoodbye;
	}
};
// Человек на английском
class EnHuman : public IHuman
{
public:
	/*   Конкретный "Продукт" для конкретной "Фабрики"   */
	IGreeting* GetGreeting() const override
	{
		return new EnGreeting;
	}

	IGoodbye* GetGoodbye() const override
	{
		return new EnGoodbye;
	}
};

/*   Код "Клиента":   */
// Общение
void Сommunication(const IHuman& human)
{
	std::cout << "Попытка говорить:\n"
		<< human.GetGreeting()->ToGreet() << '\n'
		<< " ... \n"
		<< human.GetGoodbye()->ToSayGoodbye() << '\n'
		<< std::endl;
}

int main2()
{
	//setlocale(LC_ALL, "Russian");

	std::cout << "Первый человек.\n";
	IHuman* Human_1 = new RuHuman;
	Сommunication(*Human_1);

	std::cout << "Второй человек.\n";
	IHuman* Human_2 = new EnHuman;
	Сommunication(*Human_2);

	delete Human_1;
	delete Human_2;
	return 0;
}

/*   Вывод:
* Каждая "Фабрика" имеет свои "Продукты" разного типа,
* но все "Фабрики" имеют общий интерфейс для взаимодействия со своим "Продуктом",
* а все "Продукты" одного типа – общий интерфейс (определяющий тип) с вызовом своей "Операции" над "Продуктом".
*/