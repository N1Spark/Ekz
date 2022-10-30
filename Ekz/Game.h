#pragma once
#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>

using namespace std;

bool restart_game = true;

class Game
{
	string game_word, temp, letter_temp;
	char letter;
	bool is_right = false, game_win = false;
	int change_to_win = 6;

public:
	void start()
	{
		bool game_start = true;
		fstream in;
		in.open("Answers.txt");
		int random = rand() % 44;
		for (int i = 0; i < random; i++)
		{
			char buf[444];
			in.getline(buf, 444);
			game_word = string(buf);
		}
		letter_temp = ' ';

		temp.resize(game_word.size());
		for (int i = 0; i < game_word.size(); i++)
		{
			temp[i] = '_';
		}

		while (!game_win && !change_to_win == 0)
		{


			for (int i = 0; game_word[i]; i++)
			{
				if (letter == game_word[i] || letter == game_word[i] + 32)
				{
					temp[i] = game_word[i];
					is_right = true;
				}


			}

			if (game_word == temp)
			{
				game_win = true;
				break;
			}

			system("cls");
			cout << "Добро пожаловать в игру \"Виселица\"\nСлово: ";

			for (int i = 0; i < game_word.size(); i++)
			{
				cout << temp[i] << " ";
			}


			if (!game_start)
			{
				for (int i = 1; i <= letter_temp.size(); i++)
				{
					if (letter == letter_temp[i])
					{
						cout << "\nВы уже называли данную букву! Выберите новую.\n";
						is_right = false;
						break;

					}
					else
					{

						if (i == letter_temp.size())
						{

							if (is_right)
							{
								cout << "\nВы верно угадали букву!\n";
								letter_temp += letter;
								letter_temp += (letter - 32);
								is_right = false;
								break;
							}
							else
							{
								cout << "\nВаша буква не верна\n";
								change_to_win--;
								cout << "У вас осталось " << change_to_win << " попыток\n";
								break;

							}
						}
					}

				}
				if (change_to_win == 0)
					break;
			}

			cout << "\nУгадайте букву:";
			cin >> letter;

			game_start = false;
		}


		if (game_win)
		{
			system("cls");
			cout << "Слово = ";
			for (int i = 0; i < game_word.size(); i++)
			{
				cout << temp[i] << " ";
			}

			cout << "\nВы победили!\n";
		}
		else
		{
			system("cls");
			cout << "Слово = ";
			for (int i = 0; i < game_word.size(); i++)
			{
				cout << game_word[i] << " ";
			}

			cout << "\nВы Проиграли!\n";
		}

		char restart;

		cout << "Желаете ли сыграть снова? (Y/N)";

		cin >> restart;
		if (restart == 'N' || restart == 'n')
		{
			restart_game = false;
		}
	}

};