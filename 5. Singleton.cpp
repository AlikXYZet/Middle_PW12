/* ---   Одиночка   --- */

#include "0. Testing.h"

/*   Реализация патерна "Одиночки" ("Singleton"):   */
// Бабушка
class Grandmother
{
private:
	// "Одиночки" не должны быть клонируемыми.
	Grandmother() {}
	Grandmother(const Grandmother&) = delete;
	Grandmother& operator=(Grandmother&) = delete;
	// PS: Если "private", то "= delete" не обязательно

	// Имя козла отпущения (Азазель)
	std::string Azazel;

protected:
	/* Конструктор класса, объявленный как "protected", для того чтобы :
	* - невозможно было создать экземпляр класса непосредственно оператором new;
	* - можно было наследовать данный класс из других классов.
	*/
	// Grandmother() {};

public:
	/*   Статический метод, возвращающий экземпляр класса "Одиночки":   */
	static Grandmother& getInstance() {
		static Grandmother instance;
		return instance;
	}

	/*   Методы (операции) для доступа к внутренним данным класса:   */
	// Запомнить имя того, кто "Промолчал"
	void Silence(std::string inName)
	{
		Azazel = inName;
	}

	// Получить имя "Негодника"
	std::string GetName()
	{
		return Azazel;
	}
};

int main5()
{
	// Бабушки
	Grandmother& Grandmother_1 = Grandmother::getInstance();
	Grandmother& Grandmother_2 = Grandmother::getInstance();
	Grandmother& Grandmother_3 = Grandmother::getInstance();
	Grandmother& Grandmother_4 = Grandmother::getInstance();
	Grandmother& Grandmother_5 = Grandmother::getInstance();

	// Кто и с кем не поздоровался
	Grandmother_3.Silence("Вася Пупкин");

	// Вывод каждой Бабушки
	std::cout << "Имя \"Негодника\": " << Grandmother_1.GetName() << '\n';
	std::cout << "Имя \"Негодника\": " << Grandmother_2.GetName() << '\n';
	std::cout << "Имя \"Негодника\": " << Grandmother_3.GetName() << '\n';
	std::cout << "Имя \"Негодника\": " << Grandmother_4.GetName() << '\n';
	std::cout << "Имя \"Негодника\": " << Grandmother_5.GetName() << '\n';
	std::cout << std::endl;

	return 0;
}

/*   Вывод:
* Класс "Одиночка" гарантирует наличие единственного экземпляра данного класса,
* что позволяет получать доступ к одной и той же информации в любой части кода
*/