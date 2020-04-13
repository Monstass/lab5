#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;
float made_list(int, list<float>&);
float print_list(int, list<float>&);
float transform_list(int, list<float>&);

int main()
{
    int size;
    list<float> my_list;
    
    while (1)
    {
        cout << "Enter the size of the list: ";
        cin >> size;
        if (size > 0)
        {
            break;
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    srand(time(NULL));
    made_list(size, my_list);
    system("cls");
    cout << "Source list:";
    print_list(size, my_list);
    cout << endl;
    cout << "Trans. list:";
    transform_list(size, my_list);
    print_list(size, my_list);

    return 0;
}

float made_list(int size, list<float>& my_list)
{
    for (int i = 0; i < size * 2; i++)
    {
        my_list.push_back(rand() % 100);  // заполнение 
    }
    return 0;
}

float print_list(int size, list<float>& my_list)
{
    for (list<float>::iterator i = my_list.begin(); i != my_list.end(); i++) // Вывод
    {
        cout << "\t" << *i;
    }
    return 0;
}

float transform_list(int size, list<float>& my_list)
{
    float temp, temp_prev;
    swap(my_list.front(), my_list.back());
    list<float>::iterator it = my_list.begin();
    int i = size - 1;
    advance(it, i);
    temp_prev = *it;
    advance(it, 1);
    temp = *it;
    *it = temp_prev;
    advance(it, -1);
    *it = temp;
    return 0;
}