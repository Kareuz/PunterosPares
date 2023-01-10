#include <iostream>
#include <vector>

using namespace std;

void AddNumbers(vector<int>* const numbers);
void ShowNumbers(const vector<int>* const numbers);
void ShowPosEvenNumbers(vector<int>* const numbers);

int main()
{
	vector<int> numbers(5);
	AddNumbers(&numbers);
	ShowNumbers(&numbers);
	ShowPosEvenNumbers(&numbers);

}

void AddNumbers(vector<int>* const numbers) {

	int num;
	for (int i = 0; i < numbers->size(); i++)
	{
		cout << "\nIngresa el numero en la posicion " << i << ": ";
		cin >> num;
		(*numbers)[i] = num;
	}
}

void ShowNumbers(const vector<int>* const numbers) {

	for (int i = 0; i < numbers->size(); i++)
	{
		cout << "\nPos " << i << ": " << (*numbers)[i] << endl;

	}
}

void ShowPosEvenNumbers(vector<int>* const numbers) {

	int largestEvenNum = 0;
	int posLargestEvenNum = 0;
	int posAnotherLargestNum = 0;
	int posPairNum = 0;
	vector<int> AnotherPairNum;

	for (int i = 0; i < numbers->size(); i++)
	{
		int aux = (*numbers)[i];
		int counterEvenNum = 0;

		while (aux != 0)
		{
			int num = aux % 10;
			if (num % 2 == 0)
			{
				counterEvenNum++;
			}

			aux = aux / 10;
		}

		if (counterEvenNum > 0) {
			posPairNum = i;
	      cout << "\nLos numeros con pares: "
		  << posPairNum << ": " << (*numbers)[posPairNum] << endl;
		}

		if (counterEvenNum > largestEvenNum)
		{
			largestEvenNum = counterEvenNum;
			posLargestEvenNum = i;
		}

		if ((counterEvenNum == largestEvenNum) && (counterEvenNum != 0))
		{
			AnotherPairNum.push_back(i);
		}

		

	}


	cout << "\nEl numero con mayor dígitos pares se enencuentra la posicion "
		<< posLargestEvenNum << ": " << (*numbers)[posLargestEvenNum] << endl;
	
	for (int i = 0; i < AnotherPairNum.size(); i++) {
		
		cout << "Un numero con la misma cantidad de numeros pares: "
			<< (*numbers)[AnotherPairNum[i]] << " en la posicion: " << AnotherPairNum[i] << endl;
	}
	
}