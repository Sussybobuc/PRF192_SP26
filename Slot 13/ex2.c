#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0;

// --- 1. Add a value -----------------------------------------------------------
void addValue() {
	if (size >= MAX) {
		printf("Array is full! Cannot add more elements.\n");
		return;
	}
	int val;
	printf("Enter value to add: ");
	scanf("%d", &val);
	arr[size++] = val;
	printf("Value %d added at position %d.\n", val, size - 1);
}

// --- 2. Search a value --------------------------------------------------------
void searchValue() {
	if (size == 0) {
		printf("Array is empty.\n");
		return;
	}
	int val, found = 0;
	printf("Enter value to search: ");
	scanf("%d", &val);
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) {
			printf("Value %d found at index %d.\n", val, i);
			found = 1;
		}
	}
	if (!found)
		printf("Value %d not found in the array.\n", val);
}

// --- 3. Remove first existence of a value ------------------------------------
void removeFirst() {
	if (size == 0) {
		printf("Array is empty.\n");
		return;
	}
	int val;
	printf("Enter value to remove (first occurrence): ");
	scanf("%d", &val);
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) {
			// Shift elements left
			for (int j = i; j < size - 1; j++)
				arr[j] = arr[j + 1];
			size--;
			printf("First occurrence of %d removed.\n", val);
			return;
		}
	}
	printf("Value %d not found in the array.\n", val);
}

// --- 4. Remove all existences of a value -------------------------------------
void removeAll() {
	if (size == 0) {
		printf("Array is empty.\n");
		return;
	}
	int val;
	printf("Enter value to remove (all occurrences): ");
	scanf("%d", &val);
	int newSize = 0, count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != val)
			arr[newSize++] = arr[i];
		else
			count++;
	}
	size = newSize;
	if (count > 0)
		printf("%d occurrence(s) of value %d removed.\n", count, val);
	else
		printf("Value %d not found in the array.\n", val);
}

// --- 5. Print the array -------------------------------------------------------
void printArray() {
	if (size == 0) {
		printf("Array is empty.\n");
		return;
	}
	printf("Array [%d element(s)]: ", size);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// --- 6. Print in ascending order  ------------------
void printAscending() {
	if (size == 0) {
		printf("Array is empty.\n");
		return;
	}
	// Copy array
	int temp[MAX];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];

	// Bubble sort ascending
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (temp[j] > temp[j + 1]) {
				int t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}

	printf("Array in ascending order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", temp[i]);
	printf("\n");
}

// --- 7. Print in descending order  -----------------
void printDescending() {
	if (size == 0) {
		printf("Array is empty.\n");
		return;
	}
	// Copy array
	int temp[MAX];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];

	// Bubble sort descending
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (temp[j] < temp[j + 1]) {
				int t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}

	printf("Array in descending order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", temp[i]);
	printf("\n");
}

// --- Main Menu ----------------------------------------------------------------
int main() {
	int choice;

	printf("========================================\n");
	printf("       1-D Array Manager (max %d)      \n", MAX);
	printf("========================================\n");

	do {
		printf("\n-------- MENU --------\n");
		printf("1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Remove the first existence of a value\n");
		printf("4- Remove all existences of a value\n");
		printf("5- Print out the array\n");
		printf("6- Print out the array in ascending order\n");
		printf("7- Print out the array in descending order\n");
		printf("Others- Quit\n");
		printf("----------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
			case 1:
				addValue();
				break;
			case 2:
				searchValue();
				break;
			case 3:
				removeFirst();
				break;
			case 4:
				removeAll();
				break;
			case 5:
				printArray();
				break;
			case 6:
				printAscending();
				break;
			case 7:
				printDescending();
				break;
			default:
				printf("Exiting program. Goodbye!\n");
		}
	} while (choice >= 1 && choice <= 7);

	return 0;
}