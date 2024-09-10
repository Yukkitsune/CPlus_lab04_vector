#include <iostream>
#include <string>
#include <vector>

struct Address { // Определяем структуру адреса жителя
    std::string street;
    int num_House;
    int num_Flat;
};
struct Citizen { // Определяем структуру информации о жителе
    std::string fio;
    Address adr;
    char sex;
    int age;
};

int main()
{   
    setlocale(LC_ALL, "Russian"); // Русский язык в консоли
    int n; // Количество жителей
    std::cout << "Введите количество жителей: ";
    std::cin >> n;
    std::vector <Citizen> vec(n); // Вектор, с помощью которого будем описывать каждого жителя
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Житель номер: " << i + 1;
        std::cout << std::endl << "FIO: ";
        std::cin.ignore(); // После предыдущего ввода в буфере остается символ '\n', его игнорируем
        std::getline(std::cin, vec[i].fio); // Заполнем поле fio
        std::cout << "Address: ";
        std::cout << std::endl << "Street: "; 
        std::getline(std::cin, vec[i].adr.street); // Заполнем поле street, ссылаясь на структуру Address
        std::cout << "House: ";
        std::cin >> vec[i].adr.num_House; // Заполнем поле House
        std::cout << "Flat: ";
        std::cin >> vec[i].adr.num_Flat; // Заполнем поле Flat
        std::cout << "Sex: ";
        std::cin.ignore(); // После предыдущего ввода в буфере остается символ '\n', его игнорируем
        std::cin >> vec[i].sex; // Заполнем поле sex
        std::cout << "Age: ";
        std::cin >> vec[i].age; // Заполнем поле age
    }
    for (size_t i = 0; i < n;++i) { // Выводим информацию о каждом жителе
        std::cout << "FIO: " <<  vec[i].fio << " " << "Street: " << vec[i].adr.street << " " << "House: " <<
            vec[i].adr.num_House << " " << "Flat: " << vec[i].adr.num_Flat << " " << "Sex: " <<
            vec[i].sex << " " << "Age: " << vec[i].age << std::endl;
    }
    std::string StreetName; 
    std::cout << std::endl << "Street Name: ";
    std::cin.ignore(); // После предыдущего ввода в буфере остается символ '\n', его игнорируем
    std::getline(std::cin, StreetName); // Вводим улицу, на которой ищем
    std::string HouseName;
    std::cout << std::endl << "House Number: ";
    std::cin.ignore(); // После предыдущего ввода в буфере остается символ '\n', его игнорируем
    std::getline(std::cin, HouseName); // Вводим дом, в котором ищем
    int count = 0; // Количество детей от 1 до 5 лет в доме
    for (size_t i = 0; i < n;++i) { // В цикле ищем детей от 1 до 5 лет в доме на улице и инкрементируем count
        if (StreetName == vec[i].adr.street) {
            if (vec[i].age > 1 && vec[i].age < 5) count++;
        }
    }
    if (count) std::cout << "Number of children = " << count << std::endl; //Вывод количества детей, если их не 0 или сообщение о том, что их нет
    else std::cout << "Not Found" << std::endl;
    system("pause");
    return 0;

}
