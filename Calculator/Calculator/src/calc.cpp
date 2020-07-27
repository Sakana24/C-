//calc.cpp
//Калькулятор
#include <iostream>
#include <io.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>

class Math
{
	double a;
	double b;
	double ans;

public:
	double GetA()
	{
		return a;
	}
	double GetB()
	{
		return b;
	}
	void SetA(double value)
	{
		a = value;
	}
	void SetB(double value)
	{
		b = value;
	}
	double Add(double aV, double bV)
	{
		ans = aV + bV;
		return ans;
	}
	double Sub(double aV, double bV)
	{
		ans = a - b;
		return ans;
	}
	double Mul(double aV, double bV)
	{
		ans = a * b;
		return ans;
	}
	double Div(double aV, double bV)
	{
		ans = a / b;
		return ans;
	}
	void Add()
	{
		SetA(GetNumber());
		std::cout << " + ";
		SetB(GetNumber());
		std::cout << " = ";
		std::cout << Add(a, b);
	}
	void Sub()
	{
		SetA(GetNumber());
		std::cout << " - ";
		SetB(GetNumber());
		std::cout << " = ";
		std::cout << Sub(a, b);
	}
	void Mul()
	{
		SetA(GetNumber());
		std::cout << " * ";
		SetB(GetNumber());
		std::cout << " = ";
		std::cout << Mul(a, b);
	}
	void Div()
	{
		SetA(GetNumber());
		std::cout << " / ";
		SetB(GetNumber());
		std::cout << " = ";
		std::cout << Div(a, b);
	}
	double GetAns()
	{
		return ans;
	}

	double GetNumber()
	{
		double number;
		std::string num;
		char temp = 0;
		int pointFlag = 0;
		int signFlag = 0;

		do
		{
			temp = _getch();
			if (isdigit(temp))
			{
				num += temp;
				std::cout << temp;
			}
			else if (temp == '\b')
			{
				if (num.size() == 0) continue;
				else
				{
					if (num[num.size() - 1] == '.') pointFlag--;
					if (num[num.size() - 1] == '-') signFlag--;
					num.pop_back();
					std::cout << temp << ' ' << temp;
				}
			}
			else if (temp == '.' && pointFlag == 0)
			{
				if (num.size() == 0 || num[num.size() - 1] == '-')
				{
					num += '0';
					std::cout << '0';
				}
				num += temp;
				std::cout << temp;
				pointFlag++;
			}
			else if (temp == '-' && signFlag == 0 && num.size() == 0)
			{
				num += temp;
				std::cout << temp;
				signFlag++;
			}
			else if (temp == '\r' && num.size() == 0)
			{
				std::cout << '0';
			}
		} while (temp != '\r');

		try
		{
			number = stod(num);
		}
		catch (const std::exception&)
		{
			number = 0;
		}
		return number;
	}
};

class History
{
	std::string str;
	std::vector<std::string> list;
	char sign;
	std::string path = "History.txt";

public:
	char GetSign()
	{
		return sign;
	}
	void SetSign(char cV)
	{
		sign = cV;
	}
	std::string GetStr()
	{
		return str;
	}
	void SetStr(std::string strV)
	{
		str = strV;
	}
	void SetStr(double aV)
	{
		str = std::to_string(aV);
	}
	std::vector<std::string> GetList()
	{
		return list;
	}
	void SetList(std::vector<std::string> vectV)
	{
		list = vectV;
	}

	std::string SetStr(char cV, double aV, double bV, double ansV)
	{
		str = std::to_string(aV) + " " + cV + " " + std::to_string(bV) + " = " + std::to_string(ansV);
		return str;
	}

	void Push(std::string strV)
	{
		list.push_back(strV);
	}
	void Clear()
	{
		list.clear();
	}

	void Show()
	{
		system("cls");
		std::cout << "+*-_-*+\t\tИстория операций\t\t\t+*-_-*+\n\n";
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << list[i] << std::endl;
		}
	}

	std::ofstream fout;
	void Save()
	{
		try
		{
			fout.open(path, std::ofstream::app);
			for (int i = 0; i < str.size(); i++)
			{
				fout << str[i] << std::endl;
			}
			fout.close();
			std::cout << "\n\n\tИстория сохранена";
		}
		catch (const std::exception&)
		{
			std::cout << "\n\tФайл недоступен!";
		}

	}

};

History list;

class Menu
{
	Math task;
	char ch;

public:
	void SetCh(char c)
	{
		ch = c;
	}
	char GetCh()
	{
		return ch;
	}

	void MainMenu()
	{
		system("cls");
		std::cout
			<< "+*-_-*+\t\tИмбовый Калькулятор\t\t+*-_-*+\n\n"
			<< "\ta - Математические действия\n\n"
			<< "\th - История"
			<< "\tq - Выход\n";
		SetCh(_getch());
		MainSwitch();
	}
	void MainSwitch()
	{
		switch (GetCh())
		{
		case'a':
			TaskMenu();
			break;
		case'h':
			HistoryMenu();
			break;
		case'q':
			exit(0);
			break;
		default:
			MainMenu();
			break;
		}
	}

	void TaskMenu()
	{
		system("cls");
		std::cout
			<< "+*-_-*+\t\tИмбовый Калькулятор\t\t+*-_-*+\n\n"
			<< "\tВыберите действие: \n\n"
			<< "\ta - Сложение\n"
			<< "\ts - Вычитание\n"
			<< "\tm - Умножение\n"
			<< "\td - Деление\n\n"
			<< "\tq - Назад\n";
		SetCh(_getch());
		TaskSwitch();
	}
	void TaskSwitch()
	{
		switch (GetCh())
		{
		case'a':
			f = add;
			Add();
			break;
		case's':
			f = sub;
			Sub();
			break;
		case'm':
			f = mul;
			Mul();
			break;
		case'd':
			f = div;
			Div();
			break;
		case'q':
			MainMenu();
			break;
		default:
			TaskMenu();
			break;
		};
	}

	void HistoryMenu()
	{
		system("cls");
		std::cout
			<< "+*-_-*+\t\tИстория операций\t\t\t+*-_-*+\n\n"
			<< "\ts - Сохранить историю в файл\n\n"
			<< "\tw - Показать историю"
			<< "\tq - Назад\n";
		SetCh(_getch());
		HistorySwitch();
	}
	void HistorySwitch()
	{
		switch (GetCh())
		{
		case's':
			list.Save();
			HistoryMenu();
			break;
		case'w':
			list.Show();
			ListMenu();
			SetCh(_getch());
			break;
		case'q':
			MainMenu();
			break;
		default:
			HistoryMenu();
			break;
		}
	}

	void OffMenu()
	{
		switch (f)
		{
		case add:	std::cout << "\n\n\n\n\n\nЧтобы СКЛАДЫВАТЬ ЕЩЕ\n";
			break;
		case sub:	std::cout << "\n\n\n\n\n\nЧтобы ВЫЧИТАТЬ ЕЩЕ\n";
			break;
		case mul:	std::cout << "\n\n\n\n\n\nЧтобы УМНОЖАТЬ ЕЩЕ\n";
			break;
		case div:	std::cout << "\n\n\n\n\n\nЧтобы ДЕЛИТЬ ЕЩЕ\n";
			break;
		}
		std::cout
			<< "...нажмите любую клавишу\n\n"
			<< "\tq - Назад";
		SetCh(_getch());
	}
	void ListMenu()
	{
		std::cout
			<< "\n\n\td - Очистить историю\n\n"
			<< "\tq - Назад";
		SetCh(_getch());
		ListSwitch();
	}
	void ListSwitch()
	{
		switch (GetCh())
		{
		case 'd':
			list.Clear();
			list.Show();
			ListMenu();
			break;
		case 'q':
			HistoryMenu();
			break;
		default:
			list.Show();
			ListMenu();
			break;
		}
	}

	void Add()
	{
		list.SetSign('+');
		do
		{
			system("cls");
			std::cout
				<< "\tСложение.\n"
				<< " После ввода числа нажмите Enter: \n\n";
			task.Add();
			list.Push(list.SetStr(list.GetSign(), task.GetA(), task.GetB(), task.GetAns()));
			OffMenu();
		} while (GetCh() != 'q');

		TaskMenu();
	}
	void Sub()
	{
		list.SetSign('-');
		do
		{
			system("cls");
			std::cout
				<< "\tРазность.\n"
				<< " После ввода числа нажмите Enter: \n\n";
			task.Sub();
			list.Push(list.SetStr(list.GetSign(), task.GetA(), task.GetB(), task.GetAns()));
			OffMenu();
		} while (GetCh() != 'q');

		TaskMenu();
	}
	void Mul()
	{
		list.SetSign('*');
		do
		{
			system("cls");
			std::cout
				<< "\tУмножение.\n"
				<< " После ввода числа нажмите Enter: \n\n";
			task.Mul();
			list.Push(list.SetStr(list.GetSign(), task.GetA(), task.GetB(), task.GetAns()));
			OffMenu();
		} while (GetCh() != 'q');

		TaskMenu();
	}
	void Div()
	{
		list.SetSign('/');
		do
		{
			system("cls");
			std::cout
				<< "\tДеление.\n"
				<< " После ввода числа нажмите Enter: \n\n";
			task.Div();
			list.Push(list.SetStr(list.GetSign(), task.GetA(), task.GetB(), task.GetAns()));
			OffMenu();
		} while (GetCh() != 'q');

		TaskMenu();
	}

	enum Task { add, sub, mul, div };
	int f;
};

Menu program;

int main()
{
	SetConsoleOutputCP(1251);

	program.MainMenu();
}