#include<iostream>
#include<format>

void print_dynamic_array(int* arr, int logical_size, int actual_size);

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
		std::cout << std::format("Введите arr[{}]: ",i);
		std::cin >> arr[i];
	}
	print_dynamic_array(arr, logicalSize, actualSize);
	delete[] arr;
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