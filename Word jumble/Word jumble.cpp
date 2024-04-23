#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    system("chcp 1251");
    srand(time(NULL));
    cout << "Расставьте правильно буквы!"<<endl;
    cout << "Введите <подсказка> если хотите подсказку."<<endl;
    cout << "Введите <ответ> если сдаётесь." << endl;
    
    string words_base[5][2] = { {"слово","В названии игры проверь!"},
        {"клавиатура","С помощью чего ты напишешь ответ?"},
        {"автобус","Там много бабушек днём."},
        {"мясорубка","Что-то делает с мясом."},
        {"игра","Это что?"} };
    int words_number = rand()%5;
    string theword = words_base[words_number][0];
    for (int i = 0;i < theword.size();++i) {
        int t = rand() % theword.size();
        if (i != t) {
            char s = theword[t];
            theword[t] = theword[i];
            theword[i] = s;
        }
    }
    cout << "Угадай: "<<theword<<"\t-\t";
    
    cin >> theword;
    if (theword == "подсказка") {
        cout << words_base[words_number][1]<<endl;
        cin >> theword;
    }
    if (theword == "ответ") {
        cout << words_base[words_number][0]<<endl;
    }
    if (theword == words_base[words_number][0]) {
        cout << "Вы абсолютно правы!";
    }
    else {
        cout << "В следующий раз повезёт!";
    }

}

