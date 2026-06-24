#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

enum enOperations { Add = 1, Substract = 2, Multiply = 3, Divide = 4, Mixed = 5 };

enum enDifficulty { Easy = 1, Mid = 2, Hard = 3, Mix = 4 };

enum enResult { Pass = 1 , Fail = 2};

struct stQuiz
{
    int number1;
    int number2;
    int result;
    enOperations operation;
    enDifficulty difficulty;
};

struct stResults
{
    int correct=0;
    int wrong=0;
    enResult result;
    int quizNumber;
    enOperations opType;
    enDifficulty diffLevel;
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

int ReadNumberOfQuiz()
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

string GetDifficulty(stResults res)
{
    string diff[4] = { "Easy","Mid","Hard","Mix" };
    return diff[res.diffLevel - 1];
}

string GetOperationType(stResults res)
{
    string diff[5] = { "Add","Substract","Multiply","Divide","Mix"};
    return diff[res.opType - 1];
}

string GetFinalResult(stResults res)
{
    if (res.result == enResult::Pass)
    {
        return "\t\tFinal Result is PASS : )";
        
    }
    else
    {

        return "\t\tFinal Result is FAIL : (";

    }
}

bool isCorrect(float answer, stQuiz quiz)
{
    return answer == quiz.result;
}

enOperations ReadOperation()
{
    return  (enOperations)ReadNumberInRange("[1] Add, [2] Substract, [3] Multi, [4] Divide, [5] Mix : ", 1, 5);
}

enDifficulty ReadDifficulty()
{
    return (enDifficulty)ReadNumberInRange("[1] Easy, [2] Mid, [3] Hard, [4] Mix : ", 1, 4);
}

int GetResult(stQuiz quiz)
{
    
    int number1 = quiz.number1;
    int number2 = quiz.number2;

    int result = 0;

    switch (quiz.operation)
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

void FillAnswers(stQuiz quizes[100], short numOfQuiz)
{
    for (short i = 0; i < numOfQuiz; i++)
    {
        quizes[i].result = GetResult(quizes[i]);
    }
}

enDifficulty GetDiff(short choice)
{
    return (enDifficulty)choice;
}

enOperations GetOpe(short choice)
{
    return (enOperations)choice;
}

enResult PassOrFail(stResults results)
{
    if (results.correct >= results.wrong)
        return enResult::Pass;
    else
        return enResult::Fail;
}

stQuiz GenerateQuiz(enDifficulty level,enOperations operation)
{
    stQuiz quiz;
    quiz.difficulty = level;
    quiz.operation = operation;

    if (quiz.difficulty == enDifficulty::Mix)
    {
        level = GetDiff(RandomNumber(1, 3));
    }
    if (quiz.operation == enOperations::Mixed)
    {
        operation = GetOpe(RandomNumber(1, 4));
    }

    switch (level)
    {
    case enDifficulty::Easy:
        do
        {
            quiz.number1 = RandomNumber(1, 10);
            quiz.number2 = RandomNumber(1, 10);
        } while (operation == enOperations::Divide && quiz.number1 % quiz.number2 != 0);
        quiz.operation = operation;
        break;
    case enDifficulty::Mid:
        do
        {
            quiz.number1 = RandomNumber(10, 50);
            quiz.number2 = RandomNumber(10, 50);
        } while (operation == enOperations::Divide && quiz.number1 % quiz.number2 != 0);
        quiz.operation = operation;
        break;
    case enDifficulty::Hard:
        do
        {
            quiz.number1 = RandomNumber(50, 99);
            quiz.number2 = RandomNumber(50, 99);
        } while (operation == enOperations::Divide && quiz.number1 % quiz.number2 != 0);
        quiz.operation = operation;
        break;
    }
    return quiz;
}

stQuiz ReadQuizInfo()
{
    stQuiz quiz;
    quiz.difficulty = ReadDifficulty();
    quiz.operation = ReadOperation();
    return quiz;
}

stResults ReadResultsInfo(stQuiz quiz,short numOfQuiz)
{
    stResults results;

    results.opType = quiz.operation;
    results.diffLevel = quiz.difficulty;
    results.quizNumber = numOfQuiz;

    return results;
}

void GenerateQuestions(stQuiz arr[100], short quizNum,stQuiz info)
{
        for (int i = 0; i < quizNum; i++)
        {
            arr[i] = GenerateQuiz(info.difficulty,info.operation);
        }
    
}

void PrintQuiz(stQuiz quiz,short quizNum,short allQuiz)
{
    cout << "\n\nQuestion [" << quizNum << "/" << allQuiz << "]\n" << endl;
    cout << quiz.number1 << endl;
    cout << quiz.number2 << " " << GetOperationChar(quiz.operation) << endl;
    cout << "________________\n\n";
}

void PrintFinalResult(stResults result)
{
        cout << "\n----------------------------------------------------\n";
        cout << GetFinalResult(result);
        cout << "\n----------------------------------------------------\n";
}

void PrintResults(stResults res)
{
    cout << "\nNumber of Questions     : " << res.quizNumber << endl;
    cout << "Questions Level         : " << GetDifficulty(res) << endl;
    cout << "Operation Type          : " << GetOperationType(res) << endl;
    cout << "Number of Right Answers : " << res.correct << endl;
    cout << "Number of Wrong Answers : " << res.wrong << endl;
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

void CheckWin(stResults results)
{
    if (results.result == enResult::Pass)
    {
        ChangeScreenToCorrect();
    }
    else
    {
        ChangeScreenToWrong();
    }
}

stResults PlayGame(short numOfQuiz)
{
    stResults results;
    stQuiz quiz;
    
    int correct = 0, wrong = 0;

    quiz = ReadQuizInfo();

    results = ReadResultsInfo(quiz, numOfQuiz);

    stQuiz quizes[100];

    GenerateQuestions(quizes, numOfQuiz, quiz);

    FillAnswers(quizes, numOfQuiz);

    for (short quizNum = 1; quizNum <= numOfQuiz; quizNum++)
    {
        
        quiz = quizes[quizNum-1];
        PrintQuiz(quiz, quizNum, numOfQuiz);
        
        

        float answer = ReadAnswer();
        if (isCorrect(answer, quiz))
        {
            ChangeScreenToCorrect();
            cout << "Right Answer :)";
            correct++;
        }

        else
        {
            ChangeScreenToWrong();
            cout << "The correct answer is : " << quiz.result << endl;
            wrong++;
        }
        
    }
    
    results.correct = correct;
    results.wrong = wrong;
    results.result = PassOrFail(results);

    return results;

}

void TheGame()
{
    char again;
    do
    {
        ChangeScreenToStart();
        stResults results = PlayGame(ReadNumberOfQuiz());
        PrintFinalResult(results);
        PrintResults(results);
        CheckWin(results);
        again = PlayAgain();
    } while (again == 'Y' || again == 'y');
    
}

int main()
{
    srand((unsigned)time(NULL));

    TheGame();

    return 0;
}
