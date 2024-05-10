#include <iostream>

int input_check_int(std::string text)
{
	while (true)                                                           // цикл продолжается до тех пор, пока 
	{                                                                      // пользователь не введёт корректное значение
		std::cout << text;
		int a;
		std::cin >> a;

		if (std::cin.fail() || a < 1 || a > 3)                             // если предыдущее извлечение оказалось неудачным,
		{
			std::cerr << " Invalid value entered!\n Try again!\n";
			std::cin.clear();                                              // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');                                  // и удаляем значения предыдущего ввода из входного буфера
		}
		else                                                               // если всё хорошо, то возвращаем a
			return a;
	}
}

char input_check_char()
{
	while (true)
	{
		std::cout << " Enter a character: ";
		char b;
		std::cin >> b;

		if (b != 'X' && b != 'O')                                          // если предыдущее извлечение оказалось неудачным,
		{
			std::cerr << " Invalid value entered!\n Try again!\n";
			std::cin.clear();                                              // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');                                  // и удаляем значения предыдущего ввода из входного буфера
		}
		else                                                               // если всё хорошо, то возвращаем a
			return b;
	}
}


int main()
{
	system("color 80");

	char c[3][3]{ {' ', ' ', ' '},
				  {' ', ' ', ' '},
				  {' ', ' ', ' '} };

	bool b[3][3]{ {true,true,true},
		          {true,true,true},
		          {true,true,true} };

	/*int i = 0;
	int j = 0;*/

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j < 2)std::cout << i + 1 << '.' << j + 1 << '|';
			else std::cout << i + 1 << '.' << j + 1 << ' ' << '\n';
		}
		if (i < 2)std::cout << "--------------" << std::endl;
	}
	std::cout << std::endl;

	int sum = 0;                                                                // Что-бы цикл начался присваиваем значение 0

	while (sum != 9 && (c[0][0] + c[0][1] + c[0][2] != 'X' * 3 && c[0][0] + c[0][1] + c[0][2] != 'O' * 3) &&
		               (c[1][0] + c[1][1] + c[1][2] != 'X' * 3 && c[1][0] + c[1][1] + c[1][2] != 'O' * 3) &&
		               (c[2][0] + c[2][1] + c[2][2] != 'X' * 3 && c[2][0] + c[2][1] + c[2][2] != 'O' * 3) && 
		               (c[0][0] + c[1][0] + c[2][0] != 'X' * 3 && c[0][0] + c[1][0] + c[2][0] != 'O' * 3) &&
		               (c[0][1] + c[1][1] + c[2][1] != 'X' * 3 && c[0][1] + c[1][1] + c[2][1] != 'O' * 3) &&
		               (c[0][2] + c[1][2] + c[2][2] != 'X' * 3 && c[0][2] + c[1][2] + c[2][2] != 'O' * 3) &&
		               (c[0][0] + c[1][1] + c[2][2] != 'X' * 3 && c[0][0] + c[1][1] + c[2][2] != 'O' * 3) &&
		               (c[2][0] + c[1][1] + c[0][2] != 'X' * 3 && c[2][0] + c[1][1] + c[0][2] != 'O' * 3))
	{
		sum = 9;                                                                // Что-бы цикл работал пока не заполнены все ячейки присваиваем 9
		while (true)
		{
			int x = input_check_int(" Enter coordinate 'x': ");
			int y = input_check_int(" Enter coordinate 'y': ");

			if (b[x - 1][y - 1] != true)
			{
				std::cerr << " The field is already occupied!\n Try again!";
				std::cin.clear();                                              // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n');                                  // и удаляем значения предыдущего ввода из входного буфера
			}
			else
			{
				char ch = input_check_char();
				c[x - 1][y - 1] = ch;
				b[x - 1][y - 1] -= 1;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (b[i][j] != true)
				{
					if (j < 2) std::cout << "  " << c[i][j] << " |";
					else std::cout << "  " << c[i][j] << '\n';
				}
				else
				{
					if (j < 2)std::cout << ' ' << i + 1 << '.' << j + 1 << '|';
					else std::cout << ' ' << i + 1 << '.' << j + 1 << ' ' << '\n';
				}
				sum = sum - b[i][j];
			}
			if (i < 2)std::cout << "--------------" << std::endl;
		}
		std::cout << std::endl;
	}
	system("color A4");

	std::cout << " Game over!" << std::endl;

	system("pause>nul");
	return 0;
}