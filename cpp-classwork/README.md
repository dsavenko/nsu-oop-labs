# Задачи для очной работы по курсу ООП (C++), ФИТ НГУ, 2 курс

## Тема 1. Введение

Выполните [задачу 0](https://docs.google.com/document/d/16jJOQ2EGlAvqq2sUJdwXgaQYUivRX50o-vSxLPpC2ck/edit?tab=t.0) из практических задач на сайте [НГУ ООП](https://sites.google.com/site/nguoop/%D0%BF%D1%80%D0%B0%D0%BA%D1%82%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%B5-%D0%B7%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F-%D1%81?authuser=0)

## Тема 2. Классы

Реализуйте класс-обёртку для массива строк переменной длины со следующими методами:

```C++
class Array {
public:

    // конструктор
    Array();

    // деструктор
    ~Array();

    // получить текущий размер
    std::size_t size() const;

    // очистка, после неё текущий размер = 0
    void clear();

    // положить значение по данному индексу. Если индекс больше или равен текущему размеру, увеличить размер
    void put(std::size_t index, std::string value);

    // получить значение по индексу. Если индекс больше или равен текущему размеру, вернуть пустую строку
    std::string get(std::size_t index);

private:
    std::string* data_;
    std::size_t size_;
}
```


