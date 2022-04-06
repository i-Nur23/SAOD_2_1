#include <iostream>
#include <locale>
#include <set>

using namespace std;

void PrintArray(int*, int);

int* CreateArray(int volume)
{
    int* array = new int[volume];
    for (int i = 0; i < volume; i++)
    {
        array[i] = rand();
    }
    PrintArray(array, volume);
    return array;
}

void PrintArray(int* array, int volume)
{
    for (int i = 0; i < volume; i++)
    {
        cout << array[i] << " ";
    }
}

void SortBubble(int* array, int volume, int& countCompares, int& countExchanges)
{
    int temp; 
    countCompares = countExchanges = 0;
    for (int i = 1; i < volume; i++)
    {
        int j = volume - 1;
        while (j >= i)
        {
            if (array[j - 1] > array[j])
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
                countExchanges++;
            }
            j--;
            countCompares++;
        }
    }

    PrintArray(array, volume);
}

void SortChoice(int* array, int volume, int& countCompares, int& countExchanges)
{
    int temp;
    countCompares = countExchanges = 0;
    for (int i = 0; i < volume - 1; i++)
    {
        int k = i; temp = array[i];
        for (int j = i+1; j < volume; j++)
        {
            if (array[j] < temp)
            {
                k = j; temp = array[j];
            }
            countCompares++;
        }
        countExchanges++;
        array[k] = array[i]; array[i] = temp;
    }

    PrintArray(array, volume);
}

void SortInsert(int* array, int volume, int &countCompares, int &countExchanges)
{
    int temp;
    countCompares = countExchanges = 0;
    for (int i = 1; i < volume; i++)
    {
        temp = array[i]; int j = i - 1;
        while (j >= 0 && temp < array[j])
        {
            countCompares++;
            countExchanges++;
            array[j + 1] = array[j];
            j--;
        }
        countCompares++;
        array[j + 1] = temp;
    }

    PrintArray(array, volume);
}

int CheckedInput(int begin, int end) // Ввод целочисленного значения с проверкой
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Вводите данные корректно: ";
            continue;
        }
        cin.ignore(32767, '\n');
        if (choice < begin || choice > end)
        {
            cout << "Вводите данные корректно: ";
            continue;
        }
        break;
    }
    return choice;
}

int CheckedInput() // Ввод целочисленного значения с проверкой
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Вводите данные корректно: ";
            continue;
        }
        cin.ignore(32767, '\n');
        break;
    }
    return choice;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    bool work = true;
    int choice;
    int volume{ 0 };
    cout << "Введите объём массива (до 10000): "; volume = CheckedInput(1, 10000);
    int* array = CreateArray(volume);
    int* arrCopy = new int[volume];
    while (work)
    {
        cout << "\nВыбор метода сортировки:\n1 - Сортировка обменом (метод пузырька)\n2 - Сортировка выбором\n3 - Сортировка вставками\n4 - Завершение работы\n";
        cout << "Действие: "; choice = CheckedInput(1, 4);
        int countCompares{ 0 }, countExchanges{ 0 };
        switch (choice)
        {
        case 1:
            cout << "Отсортированный массив: \n";
            memcpy(arrCopy, array, sizeof(int)*volume);
            SortBubble(arrCopy, volume, countCompares, countExchanges);
            cout << "\nЧисло сравнении: " << countCompares << endl;
            cout << "Число перестановок: " << countExchanges;
            cout << "\n\n";
            break;
        case 2:
            cout << "Отсортированный массив: \n";
            memcpy(arrCopy, array, sizeof(int) * volume);
            SortChoice(arrCopy, volume, countCompares, countExchanges);
            cout << "\nЧисло сравнении: " << countCompares << endl;
            cout << "Число перестановок: " << countExchanges;
            cout << "\n\n";
            cout << "\n\n";
            break;
        case 3:
            cout << "Отсортированный массив: \n";
            memcpy(arrCopy, array, sizeof(int) * volume);
            SortInsert(arrCopy, volume, countCompares, countExchanges);
            cout << "\nЧисло сравнении: " << countCompares << endl;
            cout << "Число перестановок: " << countExchanges;
            cout << "\n\n";
            break;
        case 4:
            delete[] array;
            delete[] arrCopy;
            work = false;
            break;
        default:
            break;
        }
        
    }
}
