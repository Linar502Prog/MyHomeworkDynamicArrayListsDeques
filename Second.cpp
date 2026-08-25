#include<iostream>
#include<format>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int number);

int main() {
	setlocale(LC_ALL, "RUS");
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
	int number{ 1 };
	while (number != 0) {
		std::cout << "Введите элемент для добавления: ";
		std::cin >> number;
		append_to_dynamic_array(arr,logicalSize,actualSize,number);
		std::cout << "Динамический массив: ";
		print_dynamic_array(arr, logicalSize, actualSize);
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

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int number) {
	if (logical_size < actual_size) {
		arr[logical_size] = number;
		logical_size += 1;
	}
	else {
		int new_actual_size = 2 * actual_size;
		int* arr_new = new int[new_actual_size] {0};
		for (size_t i = 0; i < actual_size; i++) {
			arr_new[i] = arr[i];
		}
		actual_size = new_actual_size;
		arr = arr_new;
		arr[logical_size] = number;
		logical_size += 1;
	}

}