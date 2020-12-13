#include <iostream>
#include <string.h>

bool clearCin() {			//Перевод cin в рабочее состояние и очистка буфера

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, something went wrong. Please, try again.\n";
		return false;
	}
	std::cin.ignore(32767, '\n');
	return true;

}

int inputQuantity() {					//Ввод длины массива														

	while (true) {
		std::cout << "How many names would you like to enter? ";
		int number;
		std::cin >> number;

		if (clearCin()) {
			return number;
		}
	}
}

std::string inputNames() {			//Ввод имён

	std::string name;
	std::cin >> name;

	return name;
}

void alphabeticalSort(int quantity, std::string* array) {

	std::string temp;

	for (int i = 0; i < quantity; ++i) {

		bool earlyTermination{ true };

		for (int j = 0; j < quantity - 1; ++j) {
			if (array[j + 1] < array[j]) {
				temp = array[j];						//Сортировка пузырьком
				array[j] = array[j + 1];
				array[j + 1] = temp;
				earlyTermination = false;
			}
		}

		if (earlyTermination) {							//Если сортировка закончилась до прогона всего массива, то выходим из цикла
			break;
		}
	}
}

int main() {

	int quantity{ inputQuantity() };
	std::string* arrayOfNames = new std::string[quantity];

	for (int i = 0; i < quantity; ++i) {		
		std::cout << "Input " << i + 1 << " name ";
		arrayOfNames[i] = inputNames();
	}

	alphabeticalSort(quantity, arrayOfNames);

	std::cout << "Here is your sorted list:\n";
	for (int i = 0; i < quantity; ++i) {
		std::cout << "Name #" << i + 1 << ": " << arrayOfNames[i] << "\n";
	}

	delete[] arrayOfNames; //Освобождаем память

	system("pause");
	return 0;
}