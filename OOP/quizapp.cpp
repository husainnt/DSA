#include <iostream>
#include <string.h>

using namespace std;

class Quiz
{
private:
    string questions[5];
    string options[5][3];
    int correctAnswers[5];
    int totalAttempted;
    int totalCorrect;
    int totalIncorrect;

public:
    Quiz()
    {
        totalAttempted = 0;
        totalCorrect = 0;
        totalIncorrect = 0;

        questions[0] = "What is the largest planet in our solar system?";
        questions[1] = "Who is known as the father of computer science?";
        questions[2] = "Which country is famous for its tulips?";
        questions[3] = "What is the capital of Japan?";
        questions[4] = "Which element has the chemical symbol 'Fe'?";

        options[0][0] = "Jupiter";
        options[0][1] = "Saturn";
        options[0][2] = "Neptune";
        correctAnswers[0] = 0;

        options[1][0] = "Alan Turing";
        options[1][1] = "Charles Babbage";
        options[1][2] = "Ada Lovelace";
        correctAnswers[1] = 0;

        options[2][0] = "Netherlands";
        options[2][1] = "France";
        options[2][2] = "Italy";
        correctAnswers[2] = 0;

        options[3][0] = "Tokyo";
        options[3][1] = "Seoul";
        options[3][2] = "Beijing";
        correctAnswers[3] = 0;

        options[4][0] = "Iron";
        options[4][1] = "Gold";
        options[4][2] = "Silver";
        correctAnswers[4] = 0;
    }

    void displayQuestion(int index)
    {
        cout << questions[index] << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << i + 1 << ". " << options[index][i] << endl;
        }
    }

    void checkAnswer(int index, int answer)
    {
        totalAttempted++;
        if (answer == correctAnswers[index])
        {
            cout << "Correct!" << endl;
            totalCorrect++;
        }
        else
        {
            cout << "Incorrect!" << endl;
            totalIncorrect++;
        }
    }

    void startQuiz()
    {
        cout << "Welcome to the Quiz!" << endl;
        cout << "---------------------" << endl;
        for (int i = 0; i < 5; ++i)
        {
            displayQuestion(i);
            int answer;
            cout << "Enter your answer (1, 2, or 3): ";
            cin >> answer;
            checkAnswer(i, answer - 1);
            cout << endl;
        }
        cout << "Quiz Finished!" << endl;
        cout << "Total questions attempted: " << totalAttempted << endl;
        cout << "Total correct answers: " << totalCorrect << endl;
        cout << "Total incorrect answers: " << totalIncorrect << endl;
    }
};

int main()
{
    Quiz quiz;
    quiz.startQuiz();
    return 0;
}
