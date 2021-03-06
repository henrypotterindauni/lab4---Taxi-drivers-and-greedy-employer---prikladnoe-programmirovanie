#include <iostream>
int N;  //количество сотрудников

int price[2][1000];    //массив, отвечающий за номер такси и его тариф (цену за один километр)

int path_distance[2][1000];     //массив, отвечающий за номер сотрудника и расстояние от работы до дома

int addit_array[3][1000];   //массив, отвечающий за вывод номера сотрудника, номер такси и его итоговой цены


using   namespace std;


int sorting_dist(int    path_distance[2][1000], int N)

{

    for (int s = 0; s < N - 1; s++)

    {
        for (int i = 0; i < N - 1; i++) 

        {
            if (path_distance[2][i] >= path_distance[2][i + 1])
            
            {
                
                swap(path_distance[2][i], path_distance[2][i + 1]);
                
                swap(path_distance[1][i], path_distance[1][i + 1]);
            
            }
        
        }
    
    }
    
    return 0;

}


int sorting_price(int   price[2][1000], int N)  //сортировка массива по убыванию

{
    
    for (int s = 0; s < N - 1; s++) {
        
        for (int i = 0; i < N - 1; i++) {
        
            if (price[2][i] <= price[2][i + 1])
            
            {
            
                swap(price[2][i], price[2][i + 1]);
                
                swap(price[1][i], price[1][i + 1]);
            
            }
        
        }
    
    }
    
    return 0;

}


int data_entry_dist(int path_distance[2][1000], int N)   //заполнения массива информацией

{

    for (int i = 0; i < N; i++)

    {

        cout << "\nВведите длину пути сотрудника № " << i + 1 << " целым положительным числом (в км):   ";

        cin >> path_distance[2][i]; //длина пути   

        if (path_distance[2][i] < 0)

        {

            cout << "\nВведите положительную целую величину. Длина пути сотрудника:    ";

            cin >> path_distance[2][i];

        }

        path_distance[1][i] = i + 1;    //номер сотрудника

    }

    return 0;

}


int data_entry_price(int    price[2][1000], int N)  //заполнения массива информацией

{

    for (int i = 0; i < N; i++)

    {

        cout << "\nВведите тариф за проезд одного километра в такси № " << i + 1 << ":  ";

        cin >> price[2][i];     //тариф таксиста

        if (price[2][i] < 0)

        {

            cout << "\nТариф не может быть отрицательным. Введите положительную целую величину. Тариф за проезд одного километра: ";

            cin >> price[2][i];

        }
  
        price[1][i] = i + 1;    //номер такси
    
    }
    
    return 0;

}


int price_calcul(int    price[2][1000], int path_distance[2][1000], int  addit_array[3][1000], int N)

{

    for (int f = 0; f < N; f++)    //цикл для присвоения значений в массив addit_array

    {

        addit_array[3][f] = path_distance[2][f] * price[2][f];

        addit_array[2][f] = price[1][f];

        addit_array[1][f] = path_distance[1][f];

    }


    for (int s = 0; s < N - 1; s++)    //востоновления порядка сотрудников
    
    {
    
        for (int i = 0; i < N - 1; i++)
        
        {
        
            if (addit_array[1][i] > addit_array[1][i + 1])
            
            {
            
                swap(addit_array[1][i], addit_array[1][i + 1]);
                
                swap(addit_array[2][i], addit_array[2][i + 1]);
                
                swap(addit_array[3][i], addit_array[3][i + 1]);
            
            }

        }
    
    }


    
    for (int d = 0; d < N; d++)
    
    cout << "\nСотрудник №" << addit_array[1][d] << " сядет в такси №" << addit_array[2][d] << " и стоимость проезда будет равна = " << addit_array[3][d] << "." << endl;
    
    cout << "\n--------------------------------------------------------------------------------\n";
    
        return 0;

}


int main()
{
    
    setlocale(LC_ALL, "Russian");
    
    cout << "\nВведите количество сотрудников, для которых нужно вызвать такси:   ";
    
    cin >> N;
    
    cout << "\n--------------------------------------------------------------------------------\n";
    
    data_entry_dist(path_distance, N);
    
    cout << "\n--------------------------------------------------------------------------------\n";
    
    sorting_dist(path_distance, N);
    
    data_entry_price(price, N);
    
    sorting_price(price, N);
    
    cout << "\n--------------------------------------------------------------------------------\n";
    
    price_calcul(price, path_distance, addit_array, N);
    
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
