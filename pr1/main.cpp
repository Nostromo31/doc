#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include "pr1.h"

using namespace std;

void rus()
{
    setlocale(0, "");
}

void space(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < 75; i++)
    {
        cout << '*';
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl;
    }
}

void vectors()
{
    std::vector<int> arr;
    std::vector<int> arr2 = { 1, 2, 3, 4 };
    std::vector<int> arr3{ 1, 2, 3, 4 }; //то же, что и выше, только так можно делать с С++11
    //cout << arr2[4] << endl << arr3[4] << endl; //если этого эл-а нету, то создатся и сам заполнит нулём

    arr.resize(10); //длина станет 10 элементов, начиная с нулевого и до 9-го

    //arr[7] = 7; //без проверки диапозона
    //arr.at(8) = 8;//с ней
    //в любом случае, при arrsize = 0 => программа аварийно завершится, ведь нету ни 7-го, ни восьмого элемента вектора
    //но если через .at() идти, то программа скажет, что причиной аварии стал выход за диапазон
    // а вот если через resize пойти, то все отлично будет.
    //вывод- вектор умный, но не сымый умный. Работает с памятью автоматичеси, но не совсем.


    cout << endl << arr.size() << endl;
    for (int i = 0; i < int(arr.size()); i++) //size выдает размер массива с типом данных unsigned long, а для сравнения
    { //лучше использовать одинаковые типы, потому преобразую его в int
        cout << endl << "[" << i << "]: " << arr[i] << endl;
    }

    cout << endl;

    for (auto const& element : arr) std::cout << element << ' '; //нашел это в интернетах, оно работает, но я не понимаю как

    cout << endl; //разобрал это в интернете

    for (auto& element : arr) element++; //пробую поменять каждый элемент

    cout << endl;

    for (auto const& element : arr) std::cout << element << ' ';

    cout << endl << endl; //в интернетах нашел, как это работает и разобрал. До C++11 так не работало

    for (const auto& i : arr) cout << *(arr.end() - i) << "\n";//должно в обратную сторону считать. Но нет. Логику автора понял
    cout << endl; //Но почему не работает и как исправить - не понимаю

    /*vector<vector <double>> arr3 =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    for (auto a : arr3)
    {

    }*/

}

void iters()
{
    vector<int> arr{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //указатели в качестве итераторов
    auto begin{ &arr[0] };
    auto end{ begin + arr.size() };
    for (auto ptr{ begin }; ptr != end; ++ptr) //если вместо ++ptr написать ptr++, то ничего не поменяется
    {
        cout << ptr << ' ';
    }
    space(2);
    //теперь к самим итераторам
    auto begin2{ arr.begin() }; //есть вариант с std::begin(arr), однако, выдаст то же самое. Вопрос: в чем разница?
    auto end2{ arr.end() };

    for (auto p{ begin2 }; p != end2; ++p)//внутри фигурных скобок auto p{begin2} можно проводить операции.
    { //при +2 начнет выводить со второго элемента, а при -2 выведет 2 элемента с
        cout <<* p << ' '; //мусором (у меня вывело 49 0) и затем выведет массив до точки остановки.
    }
    space(2);
    arr.resize(5);
    for (int i : arr)
    {
        cout << i << ' ';
    }
    space(2);
    vector<int> v{ 1, 2, 3, 4, 5 };
    auto b{ v.begin() };

    for (int i : v) cout << i << ' ';
    cout << endl;
    b++;
    cout << *b << endl;

    /*v.erase(b); //удаляем указанный элемент и делаем b инвалидируемым итератором для этого и следующих элементов
    cout <<  *b << endl; // а что выведет? (Выведет 3)
    ++b; //неопределенное поведение
    cout << *b << endl; // и тут тоже (выведет 4)*/
    //отсюда вопрос: почему инвалидация происходит, если выводит все верно? Может только в этом простом случае все верно
    //проверил на платформе W10 в MVS 2019, тут появляется ошибка, связанная с нарушением доступа чтения
    //"_Mycont было nullptr."
    for (int i : v) cout << i << ' ';
    space(2);


}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

void qsort_f()
{
    //int arr2[] = {5, 3, 13, 22, 12, 1, 6, 0, 4, 33}; //только так работает с qsort
    vector<int> arr2{ 5, 3, 13, 22, 12, 1, 6, 0, 4, 33 };
    //qsort(arr2, 10, sizeof(int), compare);
    sort(arr2.begin(), arr2.end());

    for (int i : arr2)
    {
        cout << i << ' ';
    }

    space(2);
}

void maps()
{
    map <string, int> SwordDamage =
    {
        {"Cooper Sword", 10},
        {"Steel Sword", 20},
        {"Silver Sword", 25}
    };

    map<string, int> ::iterator mpiter = SwordDamage.begin();
    for (int i = 0; mpiter != SwordDamage.end(); mpiter++ ,i++)
    {
        cout << i+1 << ") Weapon: " << mpiter->first << ", damage: " << mpiter->second << endl;//выводит в таком порядке: Cooper Sword -> Silver Sword -> Steel Sword. Сортировка? А как без нее?
    }
    /*for (int i = 0; mpiter != SwordDamage.end(); mpiter++, i++ + )
    {
        cout << i+1 <<") Weapon: " << mpiter <<", damage: " << mpiter
    }*/
}


void ins()
{
    string sString("bbb");
    cout << sString << std::endl;

    sString.insert(2, std::string("mmm"));
    cout << sString << std::endl;

    sString.insert(5, "aaa");
    cout << sString << endl;

    vector<int> aarr{ 1, 2, 3 };
    aarr.insert(aarr.begin(), 5);//c aarr.front() не хочет работать
    for (auto a : aarr)
    {
        cout << a << ' ';
    }
    cout << endl;

    copy(aarr.begin(), aarr.end(), ostream_iterator<int>(cout, " ")); //тип авто не разрешен; для работы
}                                                                     //ostream_iterator нужен #include <iterator>

void stl()
{
    int myArray[] = { 4, 23, -4, 0, 21, 12 };

    cout << "Вывели массив на экран с помощью copy(): ";
    copy(myArray, myArray + 6, ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(myArray, myArray + 6, ostream_iterator<int>(cout, " "));
}

void vec2()
{
    vector<string>vec2{ {'a','b','c','d'}, // явно инициализировали
                      {'e','f','g','h'},
                      {'i','j','k','l'} };

    cout << "size " << vec2.size() << endl; // lenght не выведет; size 3

    for (int y = 0; y < vec2.size(); ++y)
    {
        for (int x = 0; x < vec2[y].length(); ++x)//len 4
        {
            cout << vec2[y][x] << ends;
        }
        cout << endl;
    }

    vector<string>vecStr2;//просто объявили
    vecStr2.push_back("abcd"); //push.back() просто докидывает строку
    vecStr2.push_back("efgh");
    vecStr2.push_back("ijkl");
    cout << endl;

    cout << "size " << vecStr2.size() << endl;//size 3

    cout << "vecStr2 contains: \n";
    for (int y = 0; y < vecStr2.size(); ++y)
    {
        for (int x = 0; x < vecStr2[y].length(); ++x) //до х < 4
        {
            cout << vecStr2[y][x] << ends;
        }
        cout << endl;
    }
}

void rem()
{
    std::string str1 = "Text with some   spaces";
    str1.erase(std::remove(str1.begin(), str1.end(), ' '),
        str1.end());
    std::cout << str1 << '\n';

    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(),
        str2.end(),
        [](unsigned char x) {return std::isspace(x); }),
        str2.end());
    std::cout << str2 << '\n';
}


class hero
{
    private:
        string race, attribute, name, preset, skill, perk;
        int start_health, start_stamina, age, strenght, perception, endurance, charisma, intelligence, agility, luck, unarmed_combat, blades, pistols, blunt, engineering, science, computers, rifles, shotguns, big_guns, stealth,
            rhetoric;
        //vector<pair<string, int>> attributes; //attribute[i].first << ' ' << attribute[i].second
        //vector<pair<string, int>> skills;
    public:
        void setinfo()
        {
            cout << "Choose your race from available races: " << endl << "Human" << endl << "Insectoid" << endl << "Apex" << endl << "Avian" << endl << "Ratling" << endl;
            cout << "Amphibian" << endl << "Orc" << endl << "Goblin" << endl << "Dwarf" << endl << "Gnome" << endl << "Mushroom" << endl << "Golem" << endl << "Minotaur" << endl << endl << "Your choice is: ";
            cin >> race;
            cout << endl << "You choosed " << race << ", congrutulations!" << endl;
        }
        void getinfo()
        {
            space(1);
            cout << "Name: " << name << endl;
            cout << "Race: " << race << endl;
            cout << "Age: " << age << endl << endl;
            cout << "Preset: " << preset << endl << endl;
            cout << "Specs: " << endl;
            cout << "Strenght: " << strenght << endl << "Perception: " << perception << endl << "Endurance: " << endurance << "Charisma: " << charisma << endl;
            cout << "Intelligence: " << intelligence << endl << "Agility: " << agility << endl << "Luck: " << luck << endl << endl;
            cout << "Skills: " << endl << "Unarmed combat: " << unarmed_combat << endl << "Blades: " << blades << endl << "Pistols: " << pistols << endl << "Blunt: " << blunt << endl;
            cout << "Engineering: " << engineering << endl << "Science: " << endl << "Computers: " << computers << "Rifles: " << rifles << endl << "Shotguns: " << shotguns << endl;
            cout << "Big guns: " << big_guns << endl << "Stealth: " << stealth << endl << "Rhetoric: " << rhetoric << endl;
            space(1);
        }
        void setage(int hero_age)
        {
            age = hero_age;
        }
};

void clwork()
{
    hero me;
    me.setinfo();
    int age;
    cout << endl << "Your age is: ";
    cin >> age;
    me.setage(age);
    cout << "Your age is " << age;
    if (age < 30) cout << ". You are young.";
    else if ((age > 30) && (age < 50)) cout << ". You are middle age.";
    else if ((age > 50) && (age < 75)) cout << ". You are almost old.";
    else if ((age > 75) && (age < 100)) cout << ". You are old";
    else cout << ". You are elder creature!" << endl;
    space(1);
    me.getinfo();
}

int main()
{
    rus();

    cout << "Hello World!" << endl;

    //vectors();

    //space(5);

    //iters();

    //space(5);

    //qsort_f();

    //space(5);

    //ins();

    //space(5);

    //stl();

    //space(5);

    //vec2();

    //space(5);

    //maps();

    //space(5);

    //rem();

    //space(5);

    //clwork();

    //space(5);

    pr1 clpr;
    clpr.hello();

    return 0;
}
//pr1.cpp
