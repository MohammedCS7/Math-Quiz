#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

enum enOperations { Add = 1, Substract = 2, Multiply = 3, Divide = 4, Mixed = 5 };

enum enDifficulty { Easy = 1, Mid = 2, Hard = 3, Mix = 4 };


struct stQuestion
{
    int number1;
    int number2;
    int correctAnswer;
    int playerAnswer;
    bool isCorrect;
    enOperations operation;
    enDifficulty difficulty;
};

struct stQuiz
{
    stQuestion questionList[100];
    int correctAnswers=0;
    int wrongAnswers=0;
    int quizNumber;
    enOperations opType;
    enDifficulty diffLevel;
    bool isPass;
};

int ReadNumberInRange(string message,int from, int to)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number < from || number > to);

    return number;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int ReadNumberOfQuestion()
{
    int number;
    cout << "Enter Number of Quiz : " << endl;
    cin >> number;
    return number;
}

float ReadAnswer()
{
    float answer;
    cin >> answer;
    return answer;
}

char GetOperationChar(enOperations op)
{
    char ops[4] = { '+','-','*','/' };
    return ops[op - 1];
}

char PlayAgain()
{
    char choice;
    cout << "Do you want to play again ? Y/N : ";
    cin >> choice;
    return choice;
}

string GetDifficulty(enDifficulty diffi)
{
    string diff[4] = { "Easy","Mid","Hard","Mix" };
    return diff[diffi - 1];
}

string GetOperationType(enOperations op)
{
    string ope[5] = { "Add","Substract","Multiply","Divide","Mix"};
    return ope[op - 1];
}

string GetFinalResult(bool pass)
{
    if (pass)
    {
        return "\t\tFinal Result is PASS : )";
        
    }
    else
    {

        return "\t\tFinal Result is FAIL : (";

    }
}


enOperations ReadOperation()
{
    return  (enOperations)ReadNumberInRange("[1] Add, [2] Substract, [3] Multi, [4] Divide, [5] Mix : ", 1, 5);
}

enDifficulty ReadDifficulty()
{
    return (enDifficulty)ReadNumberInRange("[1] Easy, [2] Mid, [3] Hard, [4] Mix : ", 1, 4);
}

int GetResult(int number1,int number2,enOperations operation)
{
    
    int result = 0;

    switch (operation)
    {
        case enOperations::Add:
            result = number1 + number2;
        break;
        case enOperations::Substract:
            result = number1 - number2;
        break;
    case enOperations::Multiply:
        result = number1 * number2;
        break;
    case enOperations::Divide:
        if (number2 == 0)
            result = 0;
        else
            result = number1 / number2;
        break;
    }
    return result;
}

enDifficulty GetDiff(short choice)
{
    return (enDifficulty)choice;
}

enOperations GetOpe(short choice)
{
    return (enOperations)choice;
}

stQuestion GenerateQuestion(enDifficulty level,enOperations operation)
{
    stQuestion question;
    question.difficulty = level;
    question.operation = operation;

    if (question.difficulty == enDifficulty::Mix)
    {
        level = GetDiff(RandomNumber(1, 3));
    }
    if (question.operation == enOperations::Mixed)
    {
        operation = GetOpe(RandomNumber(1, 4));
    }

    switch (level)
    {
    case enDifficulty::Easy:
        do
        {
            question.number1 = RandomNumber(1, 10);
            question.number2 = RandomNumber(1, 10);
            question.correctAnswer = GetResult(question.number1, question.number2, operation);
        } while (operation == enOperations::Divide && question.number1 % question.number2 != 0);
        question.operation = operation;
        break;
    case enDifficulty::Mid:
        do
        {
            question.number1 = RandomNumber(10, 50);
            question.number2 = RandomNumber(10, 50);
            question.correctAnswer = GetResult(question.number1, question.number2, operation);
        } while (operation == enOperations::Divide && question.number1 % question.number2 != 0);
        question.operation = operation;
        break;
    case enDifficulty::Hard:
        do
        {
            question.number1 = RandomNumber(50, 99);
            question.number2 = RandomNumber(50, 99);
            question.correctAnswer = GetResult(question.number1, question.number2, operation);
        } while (operation == enOperations::Divide && question.number1 % question.number2 != 0);
        question.operation = operation;
        break;
    }
    return question;
}

void PrintQuestion(stQuiz quiz, short quisNum)
{
    cout << "\n\nQuestion [" << quisNum + 1 << "/" << quiz.quizNumber << "]\n" << endl;
    cout << quiz.questionList[quisNum].number1 << endl;
    cout << quiz.questionList[quisNum].number2 << " " << GetOperationChar(quiz.questionList[quisNum].operation) << endl;
    cout << "________________\n\n";
}


void PrintFinalResult(stQuiz quiz)
{
    cout << "\n----------------------------------------------------\n";
    cout << GetFinalResult(quiz.isPass);
    cout << "\n----------------------------------------------------\n";
    cout << "\nNumber of Questions     : " << quiz.quizNumber << endl;
    cout << "Questions Level         : " << GetDifficulty(quiz.diffLevel) << endl;
    cout << "Operation Type          : " << GetOperationType(quiz.opType) << endl;
    cout << "Number of Right Answers : " << quiz.correctAnswers << endl;
    cout << "Number of Wrong Answers : " << quiz.wrongAnswers << endl;
    cout << "\n----------------------------------------------------\n";
}

void ChangeScreenToCorrect()
{
    system("color 2F");
}

void ChangeScreenToWrong()
{
    cout << "\a";
    system("color 4F");
}

void ChangeScreenToStart()
{
    system("cls");
    system("color 0F");
}


bool CorrectQuestion(stQuestion& quiz)
{
    if (quiz.playerAnswer == quiz.correctAnswer)
    {
        quiz.isCorrect = true;
        cout << "Right Answer :-)" << endl;
        return true;
    }
    else
    {
        quiz.isCorrect = false;
        cout << "The Right Answer is : " << quiz.correctAnswer << endl;
        return false;
    }
}

void GenerateQuestions(stQuiz& quiz)
{
        for (int i = 0; i < quiz.quizNumber; i++)
        {
            quiz.questionList[i] = GenerateQuestion(quiz.diffLevel,quiz.opType);
        }
}

void AskAndCorrectQuestions(stQuiz& quiz)
{
    for (int question = 0; question < quiz.quizNumber; question++)
    {
        PrintQuestion(quiz, question);
        quiz.questionList[question].playerAnswer = ReadAnswer();
        if (CorrectQuestion(quiz.questionList[question]))
        {
            quiz.correctAnswers++;
            ChangeScreenToCorrect();
        }
        else
        {
            quiz.wrongAnswers++;
            ChangeScreenToWrong();
        }
    }
    quiz.isPass = (quiz.correctAnswers >= quiz.wrongAnswers);
}

void MathGame()
{

    stQuiz quiz;

    quiz.quizNumber = ReadNumberOfQuestion();
    quiz.diffLevel = ReadDifficulty();
    quiz.opType = ReadOperation();

    GenerateQuestions(quiz);

    AskAndCorrectQuestions(quiz);

    PrintFinalResult(quiz);

}

void PlayMathGame()
{
    char again;
    do
    {
        ChangeScreenToStart();
        MathGame();
        again = PlayAgain();
    } while (again == 'Y' || again == 'y');
    
}

int main()
{
    srand((unsigned)time(NULL));

    PlayMathGame();

    return 0;
}
