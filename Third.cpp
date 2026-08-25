#include<iostream>
#include<format>
#include"Windows.h"

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int actualSize, logicalSize;
	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> actualSize;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logicalSize;
	if (logicalSize > actualSize) {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
		return EXIT_FAILURE;
	}
	int* arr = new int[actualSize] {0};
	for (size_t i = 0; i < logicalSize; i++) {
		std::cout << std::format("Введите arr[{}]: ", i);
		std::cin >> arr[i];
	}
	print_dynamic_array(arr, logicalSize, actualSize);
	std::string question{""};
	while (true) {
		std::cout << "Удалить первый элемент? ";
		std::cin >> question;
		if (question == "да") {
			if (logicalSize == 0) {
				std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания! " << std::endl;
				return EXIT_SUCCESS;
			}
			else {
				remove_dynamic_array_head(arr, logicalSize, actualSize);
				std::cout << "Динамический массив: ";
				print_dynamic_array(arr, logicalSize, actualSize);
			}
		}
		else if (question == "нет"){
			break;
		}
		else {
			continue;
		}

	}
	std::cout << "Спасибо! Ваш массив: ";
	print_dynamic_array(arr, logicalSize, actualSize);
	
	return EXIT_SUCCESS;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (size_t i = 0; i < actual_size; i++) {
		if (i >= logical_size && i < actual_size) {
			std::cout << "_ ";
		}
		else {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}


void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
	if ((logical_size - 1) > (actual_size/3.0)) {
		for (size_t i = 0; i < logical_size; i++) {
			arr[i] = arr[i + 1];
		}
		logical_size -= 1;
	}
	else if(logical_size == 1 && actual_size < 3) {
		for (size_t i = 0; i < logical_size; i++) {
			arr[i] = arr[i + 1];
		}
		logical_size -= 1;
	}
	else {
		int new_size = actual_size / 3;
		int* new_arr = new int[new_size] {0};
		for (size_t i = 0; i < logical_size; i++) {
			new_arr[i] = arr[i + 1];
		}
		arr = new_arr;
		logical_size -= 1;
		actual_size /= 3;
	}
}