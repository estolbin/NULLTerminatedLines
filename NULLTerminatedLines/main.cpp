#include<iostream>
#include<Windows.h>
using namespace std;

int StrLen(char str[]); // принимает строку, возвращает длину строки

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);

bool is_bin(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	//cout << str << endl;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 20;
	char str[n];
	cout << "Введите строку: "; //cin >> str;
	cin.getline(str, n);
	cout << str << endl;
	cout << "Длина введенной строки: " << StrLen(str) << endl;

	to_upper(str);
	to_lower(str);
	shrink(str);
	cout << "Двоичная строка: " << is_bin(str) << endl;
	char str1[8] = "01001";
	cout << "Двоичная строка: " << str1 << "\t" << is_bin(str1) << endl;

}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{

	for (int i = 0; str[i]; i++)
	{
		// latin 97-122. Capital 65-90
		// cyrilic -32-0. Capital -64 -33
		if ((97 <= str[i] && str[i] <= 122) || (-32 <= int(str[i]) && str[i] <= 0))
		{
			str[i] -= 32;
		}
	}
	cout << "Строка, преобразованная в верхний регистр: " << str << endl;

}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((65 <= str[i] && str[i] <= 90) || (-64 <= str[i] && str[i] <= -33)) str[i] += 32;

	}
	cout << "Строка в нижнем регистре: " << str << endl;
}

void shrink(char str[])
{
	int i = 0, j = 0;
	for (; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			++j;
		}
	}
	str[j] = 0;

	cout << "Без пробелов: " << str << endl;
}

bool is_bin(char str[])
{
	bool res = true;
	for (int i = 0; str[i]; i++)
	{
		if (!(res && (str[i] == '0' || str[i] == '1'))) res = false;
	}
	return res;
}