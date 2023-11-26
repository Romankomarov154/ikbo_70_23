// GenAlg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

const int BOTTOM = -100, TOP = 100, E = 2; //минимальное и максимальное число для х и у, количество знаков после запятой

const int POPULATION_SIZE = 10000, MAX_GENERATIONS = 500; //размер популяции и количество вхождений в цикл
const float P_CROSSOVER = 0.9f, P_MUTATION = 0.1f; //вероятность скрещивания и мутации

float createGen()
{
	return BOTTOM + (rand() % ((TOP - BOTTOM) * int(pow(10, E)))) / pow(10.0f, E);
}

class Individual
{
public:
	float X, Y;
	Individual();
	Individual(float x, float y);
	~Individual();
	float getResult()
	{
		return 4 + pow((pow(X, 2) + pow(Y, 2)), 2.0f / 3.0f); //функция из варианта, заменить на нужную
	}
private:
};

Individual::Individual()
{
}

Individual::Individual(float x, float y)
{
	X = x;
	Y = y;
}

Individual::~Individual()
{
}

Individual createIndividual()
{
	float x = createGen();
	float y = createGen();
	return Individual(x, y);
}

Individual cloneIndividual(Individual ind)
{
	Individual new_ind;
	new_ind.X = ind.X;
	new_ind.Y = ind.Y;
	return new_ind;
}

Individual selection(Individual* population)
{
	int candidates = 3, k, maxIndex;
	maxIndex = 0;
	for (int j = 0; j < candidates; j++)
	{
		k = rand() % POPULATION_SIZE;
		if (population[maxIndex].getResult() > population[k].getResult()) //функция для поиска минимума, для поиска максимума заменить > на <
		{
			maxIndex = k;
		}
	}
	return cloneIndividual(population[maxIndex]);
}

Individual crossing(Individual* population)
{
	return Individual(population[rand() % POPULATION_SIZE].X, population[rand() % POPULATION_SIZE].Y);
}

Individual mutation(Individual ind)
{
	if (rand() % 2)
		return Individual(ind.X, createGen());
	else
		return Individual(createGen(), ind.Y);
}

int main()
{
	// 5) 4 + (x^2 + y^2)^(2/3)
	srand(time(0));
	float x, y;
	Individual population[POPULATION_SIZE], new_population[POPULATION_SIZE];
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		population[i] = createIndividual();
	}

	for (int k = 0; k < MAX_GENERATIONS; k++)
	{
		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			new_population[i] = selection(population);
		}
		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			population[i] = cloneIndividual(new_population[i]);
		}

		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			if ((rand() % 100) / 100.0f < P_CROSSOVER)
				new_population[i] = crossing(population);
		}
		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			population[i] = cloneIndividual(new_population[i]);
		}

		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			if ((rand() % 100) / 100.0f < P_MUTATION)
				new_population[i] = crossing(population);
		}
		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			population[i] = cloneIndividual(new_population[i]);
		}
	}
	cout << "X\t\t\tY\t\t\tZ" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << population[i].X << "\t\t\t" << population[i].Y << "\t\t\t" << population[i].getResult() << endl;
	}
}

//изменить код согласно комментариям, проблемы могут быть решены изменением констант, которые закоментированы