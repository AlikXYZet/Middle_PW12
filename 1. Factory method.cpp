/* ---   Фабричный метод   --- */

#include <iostream>

class ICargo
{
public:
	virtual ~ICargo() {};
	virtual std::string Action() const = 0;
};

class RoundCargo : public ICargo
{
public:
	std::string Action() const override
	{
		return "Круглое тащат";
	}
};

class SquareCargo : public ICargo
{
public:
	std::string Action() const override
	{
		return "Квадратное катят";
	}
};



class IWorkers
{
public:
	virtual ~IWorkers() {};
	virtual ICargo* GetCargoType() const = 0;

	std::string Work() const
	{
		ICargo* cargo = this->GetCargoType();
		std::string result = "Рабочие на данный момент " + cargo->Action();

		delete cargo;
		return result;
	}
};

class StrongWorkers : public IWorkers
{
public:
	ICargo* GetCargoType() const override
	{
		return new RoundCargo;
	}
};

class LazyWorkers : public IWorkers
{
public:
	ICargo* GetCargoType() const override
	{
		return new SquareCargo;
	}
};

void Verification(const IWorkers& workers)
{
	std::cout << "Проверка работы рабочих:\n"
		<< workers.Work() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

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

