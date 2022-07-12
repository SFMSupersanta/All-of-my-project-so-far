#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
void gamestart()
{
    int key = rand() % 101;
    // cout<<key<<endl;
    cout << "Game is starting\n\nRandom number has been created\nWhat is your guess?\t";
    int guess;
    int score = 9;
    while (true)
    {
        cin >> guess;
        if (guess == key)
        {
            cout << "You got it right!!\nStadistics:\nYou tried " << 10 - score << " times\n"
                 << "finnal score: " << score << "\n";
            if (score <= 0)
            {
                cout << "Gosh, you're really bad at this game";
            }
            else if (score <= 5)
            {
                cout << "Gettin' a hard time there huh";
            }
            else if (score < 9)
            {
                cout << "Great work! Keep it goin!";
            }
            else if (score == 9)
            {
                cout << "Your luck is unmached!!!!! YOU WIN!!!!";
            }
            else
            {
                cout << "The luck is really on your side today as well huh :/";
            }
            break;
        }
        else if (guess > 100)
        {
            cout << "Your guess is bigger than 100. Please choose a number between 0 and 100.\t";
        }
        else if (guess < 0)
        {
            cout << "Your guess is smaller than 0. Please choose a number between 0 and 100.\t";
        }
        else
        {
            score--;
            if (guess < key)
            {
                cout << "Try something bigger.\t";
            }
            else
            {
                cout << "Try a smaller number.\t";
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    int menu;
    do
    {
        cout << "\n\n  \t\tTHE GUESSING GAME\n\n\tstart: 0\tstop: 1\t\trule :2\nChoice: ";
        cin >> menu;
        switch (menu)
        {
        case 0:
            gamestart();
            break;
        case 1:
            cout << "thank you for trying\n";
            break;
        case 2:
            cout << "There is a random number bettwen 0 and 100.\nYou have to guess by typing in the number\nThe console will say \"Try something smaller\" if your guess is too high and oposite\n";
            cout << "Your initial point is 10 and gradually decrease by one every time you guess it wrong. \nThe final score will say how good you are at this game.\nGood luck!";
            break;
        default:
            cout << "please choose by typing zero, one and two";
            break;
        }
    } while (menu != 1);
    return 0;
}
