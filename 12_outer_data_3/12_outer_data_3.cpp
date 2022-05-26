#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

int pos(const char* second_str, const char* first_str, int n)
{
	int i, j,
		first_counter, 
		second_counter;

	for (first_counter = 0; first_str[first_counter]; first_counter++);
	for (second_counter = 0; second_str[second_counter]; second_counter++);

	for (i = 0; i <= second_counter - first_counter; i++) {
		for (j = 0; second_str[i + j] == first_str[j]; j++);
		if (j - first_counter == 1 && 
			i == second_counter - first_counter &&
			!(n - 1)) 
		{ 
			return i; 
		}
		if (j == first_counter)
		{
			if (n - 1) { n--; }
			else { return i; }
		}
	}
	return -1;
}
int main() {
	setlocale(LC_ALL, "rus");
	char first_str[30]; char second_str[33];
	int inp_char, k, g;
	int ar[30];
	string line, a, 
		str_file = "C://Users//ilya//source//repos//12_outer_data_3//12_outer_data_3//str_file.txt",
		bin_file = "C://Users//ilya//source//repos//12_outer_data_3//12_outer_data_3//bin_file.txt",
		bin_file_2 = "C://Users//ilya//source//repos//12_outer_data_3//12_outer_data_3//bin_file_2.txt";
	ifstream file(str_file);
	cout << "ASCII код\n : ";
	k = 0;
	while (file >> inp_char) {
		ar[k++] = inp_char;
	}
	for (int i = 0; i < k; i++) {
		cout << ar[i] << " ";
	}
	file.close();
	cout << endl;
	cout << "Перевод с языка: \n";
	for (int i = 0; i < 30; i++) {
		second_str[i] = ar[i];
		cout << second_str[i] << "";
	}
	cout << endl;
	ofstream out(bin_file, ios::binary | ios::out);
	out.write((char*)&second_str, sizeof second_str);
	out.close();

	ifstream in(bin_file_2, ios::binary | ios::in);
	in.read((char*)&first_str, sizeof first_str);
	in.close();
	cout << "Данные из файла:\n";
	cout << first_str << endl;
	cout << "Введите номер для поиска: \n";
	cin >> a;
	const char* s = first_str;
	const char* p = a.c_str();
	int i, n = 0;
	for (i = 1; n != -1; i++) {
		n = pos(s, p, i);

		if (n >= 0)
			cout << n << endl;
	}
	cout << "После удаления:\n ";
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < 30; ++j) {
			first_str[j] = first_str[j + 1];
		}
	}
	for (int i = 0; i <= 30; i++) {
		cout << first_str[i] << "";
	}
	return 0;
}