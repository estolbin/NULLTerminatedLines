#include<iostream>
#include<Windows.h>
#include<math.h>
#include<regex>
#include<string>

#define tab "\t\t"

using namespace std;


int StrLen(char str[]); // принимает строку, возвращает длину строки

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);

bool is_bin(char str[]);
bool is_integer(char str[]);
bool is_hex(char str[]);

int bin2dec(char str[]);
int arr2int(char str[]);

int hex2dec(char str[]);
int convert_to_dec(int num_sys, char str[]);
int hex_sym_to_int(char sym);

int dec2bin(int num);
char dec2hex(int num);
char* convert_from_dec(int num, int num_sys);

bool is_mac_address(char str[]);
bool is_ip_address(char str[]);

int main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	//cout << str << endl;

	// SetConsoleCP(1251);
	// SetConsoleOutputCP(1251);

	// const int n = 256;
	// char str[n];
	// cout << "Введите строку: "; //cin >> str;
	// cin.getline(str, n);
	// cout << str << endl;
	// cout << "Длина введенной строки: " << StrLen(str) << endl;

	// to_upper(str);
	// to_lower(str);
	// shrink(str);
	// cout << "Двоичная строка: " << is_bin(str) << endl;
	// char str1[8] = "01001";
	// cout << "Двоичная строка: " << str1 << tab << is_bin(str1) << endl;

	// char h_str[9] = "0x1234FF";
	// cout << "Это шестнадцатиричная: " << h_str << tab << is_hex(h_str) << endl;
	// cout << "Это шестнадцатиричная: " << str << tab << is_hex(str) << endl;

	// char d_str[8] = "0123459";
	// cout << "Это десятичная: " << d_str << tab << is_integer(d_str) << endl;
	// cout << "Это десятичная: " << str << tab << is_integer(str) << endl;

//	char str1[8] = "01001";
//	cout << "Перевод двоичной в десятичную: " << bin2dec(str1) << endl;

	char h_str[9] = "0x1234FF";
	cout << "Перевод шестнадцатиричной в десятичную: " << hex2dec(h_str) << endl;


	return 0;
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
		if (
			str[i] >= 'a' && str[i] <='z' || 
			str[i] >= 'à' && str[i] <= 'ÿ'
			)
			str[i] -= 32;
	}
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
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
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

bool is_integer(char str[])
{
	for (int i = 0;str[i];i++)
	{
		if (str[i] >= 48 && str[i] <= 57) return true;
	}
	return false;
}

bool is_hex(char str[])
{
	
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70)) return true;
	}
	return false;
}

int bin2dec(char str[])
{
	return convert_to_dec(2, str);
}

int arr2int(char str[])
{
	int i = 0, num = 0;
	for (;str[i];i++)
	{
		num += int(str[i]);
		num *= 10;
	}

	return num;
}

int hex2dec(char str[])
{
	return convert_to_dec(16, str);
}

int convert_to_dec(int num_sys, char str[])
{

	int in = 0, res = 0, num, len = StrLen(str)-1;
	for (int i = len; i >= 0; i++)
	{
		if (('a' <= str[i] && str[i] <= 'f') || ('A' <= str[i] && str[i] <= 'F')) 
		{ 
			num = hex_sym_to_int(str[i]);
		}
		else 
		{
			num = (int)str[i];
		}
		res += (num * pow(num_sys, in));
		in++;
	}
	return res;
}

int hex_sym_to_int(char sym)
{
	int res=0;
	if (sym == 'a' || sym == 'A') {res = 10;} 
	else if (sym == 'b' || sym == 'B') {res = 11;} 
	else if (sym == 'c' || sym == 'C') {res = 12;}
	else if (sym == 'd' || sym == 'D') {res = 13;}
	else if (sym == 'e' || sym == 'E') {res = 14;}
	else if (sym == 'f' || sym == 'F') {res = 15;}
	return res;	
}


int dec2bin(int num)
{
	return convert_from_dec(num, 2);
}

char dec2hex(int num)
{
	return convert_from_dec(num, 16);
}

char* convert_from_dec(int num, int num_sys)
{
	int arr[64], i=0, r;
	while (num != 0)
	{
		r = num % num_sys;
		arr[i++] = r;
		num /= num_sys;
	}

	int ii = 0;
	char* tmp = new char[i + 1]{};
	for (int j = i -1; j>=0; j--) {
		tmp[ii++] = arr[j];
	}

	return tmp;
}

bool is_mac_address(char str[])
{
    const regex pattern( "^([0-9A-Fa-f]{2}[:-]){5}" "([0-9A-Fa-f]{2})|([0-9a-" "fA-F]{4}\\.[0-9a-fA-F]" "{4}\\.[0-9a-fA-F]{4})$");
	
    return regex_match(str, pattern);
}

bool is_ip_address(char str[])
{
	const regex patter("(([\d]{1,3}.){3}[\d]{1,3})");

	return regex_match(str, pattern);

}
