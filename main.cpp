#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomCard()
{
    return rand() % 10 + 2;
}

int main()
{
    srand(time(0)); // Инициализация генератора случайных чисел
    system("chcp 65001");

    int playerScore = getRandomCard();
    int computerScore = getRandomCard();

    char choice;

    cout << "Уровни сложности: \n 1. Легкий \n 2. Средний \n 3. Сложный \nВыберите уровень игры: ";
    int level;
    cin >> level;
    int c = 0;

    do
    {
        int playerCard = getRandomCard();
        playerScore += playerCard;
        cout << "Вам выпало: " << playerCard << " очков. Ваш счет: " << playerScore << endl;

        if (playerScore == 22 && c == 0)
        {
            cout << "Вы выиграли, поздравляю :) " << endl;
            return 0;
        }
        if (playerScore > 21)
        {
            cout << "Вы проиграли, перебор :( " << endl;
            return 0;
        }
        if (playerScore == 21)
        {
            cout << "Вы выиграли, поздравляю :) " << endl;
            return 0;
        }
        c++;

        cout << "Продолжить игру (y/n)? ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    switch (level)
    {
        case 1: // Уровень "Легкий"
        {
            int chance;
            while (((chance = 21 - computerScore) > 3) && (computerScore < 21))
            {
                int computerCard = getRandomCard();
                computerScore += computerCard;
            }
            break;
        }
        case 2: // Уровень "Средний"
        {
            while (computerScore < 17)
            {
                int computerCard = getRandomCard();
                computerScore += computerCard;
            }
            break;
        }
        case 3: // Уровень "Сложный"
        {
            int chance = 21 - computerScore;
            bool continueTakingCards = true;

            while (continueTakingCards)
            {
                if (computerScore < playerScore && computerScore < 21 && (11 - chance <= 5))
                {
                    int computerCard = getRandomCard();
                    computerScore += computerCard;
                    chance = 21 - computerScore;
                }
                else
                {
                    continueTakingCards = false;
                }
            }
            break;
        }
        default:
            cout << "Некорректный уровень сложности. " << endl;
            return 0;
    }

    if (computerScore > 21)
    {
        cout << "Компьютер набрал больше 21, Вы выиграли :)" << endl;
    }
    else if (playerScore > computerScore)
    {
        cout << "Счет компьютера: " << computerScore << ". Ваш счет: " << playerScore << ". Вы набрали больше и выиграли :)" << endl;
    }
    else if (playerScore < computerScore)
    {
        cout << "Счет компьютера: " << computerScore << ". Ваш счет: " << playerScore << ". Вы набрали меньше и проиграли :(" << endl;
    }
    else
    {
        cout << "Счет компьютера: " << computerScore << ". Ваш счет: " << playerScore << ". Вы выиграли :)" << endl;
    }

    return 0;
}
