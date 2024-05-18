/* ---   Прототип   --- */

#include "0. Testing.h"

/*   Интерфейс "Прототипа":   */
class IPrototype
{
public:
	virtual IPrototype* clone() = 0;
	virtual void StageName() = 0;
};

/*   "Прототип" 1-ого типа:   */
class Yin : public IPrototype
{
	IPrototype* clone() override
	{
		return new Yin(*this);
	}
	void StageName() override
	{
		std::cout << "Инь";
	}
};

/*   "Прототип" 2-ого типа:   */
class Yang : public IPrototype
{
	IPrototype* clone() override
	{
		return new Yang(*this);
	}
	void StageName() override
	{
		std::cout << "Янь";
	}
};

/*   "Прототип" 3-ого типа:   */
class Horseradish : public IPrototype
{
	IPrototype* clone() override
	{
		return new Horseradish(*this);
	}
	void StageName() override
	{
		std::cout << "Хрень";
	}
};

int main4()
{
	// Массив всех вариаций Прототипа
	IPrototype* aPrototype[3] = { new Yin, new Yang, new Horseradish };
	// Количество вариаций клонирования (размер массива aPrototype)
	int aSize = sizeof(aPrototype) / sizeof(*aPrototype);

	// Вектор для хранения клонов
	std::vector<IPrototype*> vPrototype;
	// Переменная количества "полос жизни" (определяет размер вектора vPrototype)
	int NumberOfLifeBands;

	std::cout << "Количество вариаций клонирования: " << aSize << '\n';
	std::cout << "Введите количество полос жизни: ";
	std::cin >> NumberOfLifeBands;
	std::cout << std::endl;

	// Использовать текущее время в качестве начального значения для генератора псевдослучайных чисел
	srand(time(0));

	// Цикл работы с вектором
	for (int i = 0; i < NumberOfLifeBands; ++i)
	{
		// Хранение клона в векторе
		vPrototype.push_back(aPrototype[rand() % aSize]->clone());
		// Вовод информации из вектора
		vPrototype[i]->StageName();
		// Удаление элемента вектора и освобождение ячейки памяти
		delete vPrototype[i];
		std::cout << '\n';
	}
	std::cout << std::endl;

	// Вызов Деструктора вектора
	vPrototype.~vector();

	// Проверка сохранности массива прототипов aPrototype
	std::cout << '\n' << "Проверка сохранности aPrototype: " << '\n';
	for (int i = 0; i < aSize; ++i)
	{
		// Вовод информации из вектора
		aPrototype[i]->StageName();
		std::cout << "   ";
	}
	std::cout << std::endl;

	return 0;
}

/*   Вывод:
* Каждый "Прототип" имеет реализацию клонирования объекта своего типа (самого себя),
* что даёт возможность работать с индентичным "Клоном" объекта не изменяя "Оригинал"
*/