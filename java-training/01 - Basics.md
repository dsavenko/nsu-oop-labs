
# Тема 1. Основы Java

**Общие условия**

Создать пакет с именем `ru.nsu.<ваша фамилия>.basics.task<номер задачи>`. Создать два подпакета — `ui` и `model`. 

## Задача 1.

Model: интерфейс `Printer` c методом `void print(int n)`, две реализации — одна пишет в консоль "hello" `N+k` раз, другая — "bye" `N+k` раз, где `k` — случайное число от `-N+1` до `N`. Фабрика `PrinterFactory` с методом `Printer createPrinter(String name)`, которая создает конкретный принтер. 

UI: с консоли запрашиваем у пользователя строку — название принтера, и число N. С помощью фабрики создаем принтер и вызываем у него `print(N)`.
Сделать так, чтобы конкретные классы-реализации интерфейсов нельзя было напрямую инстанциировать из UI, только через фабрику.

## Задача 2.

Model: интерфейс `Reader` c методом `int readInt()`, интерфейс `Writer` c методом `void write(int n)`, класс, реализующий оба интерфейса, в котором `readInt` читает число с консоли (запрашивает у пользователя), `write(int n)` печатает на консоль N раз одно случайное слово из фиксированного набора (не меньше 3 слов в наборе). Фабрика `IOFactory` с методами `Reader createReader()` и `Writer createWriter()`, оба возвращают экземпляр(ы) одного и того же класса. 

UI: С помощью фабрики создаем `Reader` и `Writer`, вызываем `readInt`, потом `write`.

Сделать так, чтобы конкретный класс-реализацию интерфейсов нельзя было напрямую инстанциировать из UI, только через фабрику.

## Задача 3.

Model: класс `Parent` с конструктором, принимающим `String`, и методом `void print()`, печатающим эту строку. Класс `Child`, наследующийся от `Parent`, с конструктором, принимающим `int N`, передающим в конструктор родителя строку `Child_<k>`, где `k` - случайное число от `-100` до `100`, и переопределенным методом `print()`, который вызывает метод `print` родителя `N` раз. 

UI: с консоли запрашиваем у пользователя число `N`. Создаем экземпляр `Child`. Зовем у него `print`. 

Сделать так, чтобы `Parent` нельзя было напрямую инстанциировать из `UI`, только `Child`.

## Задача 4.

Model: сделайте интерфейсы `Minner` с методом `int min()` и `Maxer` с методом `int max()`. А также абстрактный класс `RandomArray`, который реализует оба интерфейса, но не реализует их методы. У класса есть поле типа массив интов. Конструктор, который принимает аргумент `int N`, инициализирует это поле массивом длины `N`, который заполняется случайными числами в диапазоне от `-1000` до `1000`. Сделайте класс `Child`, который наследуется от `RandomArray` и реализует методы `min` и `max`. Также в классе `RandomArray` сделайте статический метод `RandomArray RandomArray.create(int N)`, который возвращает экземпляр `Child`.

UI: с консоли запрашиваем у пользователя число `N`. Получаем `RandomArray` через `RandomArray.create(N)`. Печатаем на консоль результаты вызова `min()` и `max()`

Сделать так, чтобы `Child` нельзя было напрямую инстанциировать из UI, только через `RandomArray.create`.

## Задача 5.

Model: создать интерфейс `Printer` с одним методом `void print()`. Создать класс `StringPrinterFactory`, который в конструкторе принимает массив строк, и имеет один метод `Printer createPrinter()`. Этот метод возвращает `PrinterImpl` — внутренний приватный класс, реализующий интерфейс `Printer`, который в методе `print`выводит случайную строку из массива строк, переданного в конструктор `StringPrinterFactory`. `PrinterImpl` не содержит никаких полей, только реализацию метода интерфейса.

UI: запросить у пользователя число `N`. Создать массив длины `N`, запросить у пользователя `N` строк, заполнить ими массив. Запросить у пользователя число `K`. Создать `StringPrinterFactory` и получить у нее экземпляр `Printer`. `K` раз вызвать у него метод `print`.

## Задача 6.

Model: интерфейс `NumberGenerator` с методом `long getNumber()`. Его реализация, которая возвращает число в диапазоне от `0` до некоторого предела (задается в конструкторе). Интерфейс `PrimeChecker` с методом `boolean isPrime(long n)`. Его реализация, которая возвращает `true` тогда, когда переданное число — простое. Также класс-фабрика с двумя методами: `NumberGenerator createNumberGenerator(long maxN)` и `PrimeChecker createPrimeChecker()`.

UI: запросить у пользователя числа `N` и `K`. С помощью фабрики создать экземпляры `NumberGenerator` с `MaxN=N` и `PrimeChecker`. `К` раз получить у генератора число, проверить, является ли оно простым, и вывести на консоль число и сообщение, простое ли оно.

Сделать так, чтобы реализации интерфейсов нельзя было напрямую инстанциировать из UI, только через фабрику.

## Задача 7.

Model: интерфейс `ArrayModifier` с методом `int[] modify(int k, int[] a)`. Его реализация, которая возвращает копию массива с удаленным элементом с индексом `k`. Также класс-фабрика с методом `ArrayModifier createArrayModifier()`.

UI: Получить `ArrayModifier` через фабрику. Запросить числа числа `k` и `n`. Создать массив случайных чисел из диапазона `-100` до `100` длины `n`. Удалять из него k-й элемент. Распечатать оба массива.

Сделать так, чтобы реализации интерфейса нельзя было напрямую инстанциировать из UI, только через фабрику.

## Задача 8.

Model: интерфейс `ArrayModifier` с методом `int[] modify(int k, int[] a)`. Его реализация, которая возвращает копию массива с дублированным элементом с индексом `k` (то есть в позицию `k+1` вставляется элемент из позиции `k`, а элементы правее него сдвигаются на 1 позицию, длина массива увеличивается на 1). Также класс-фабрика с методом `ArrayModifier createArrayModifier()`.

UI: Получить `ArrayModifier` через фабрику. Запросить числа числа `k` и `n`. Создать массив случайных чисел из диапазона `-100` до `100` длины `n`. Дублировать k-й элемент. Распечатать оба массива.

Сделать так, чтобы реализации интерфейса нельзя было напрямую инстанциировать из UI, только через фабрику.

## Задача 9. Паттерн проектирования "Стратегия".

Вместо подпакета `model` будет подпакет `widgets`.

Widgets: интерфейс `LinePrinter` c методом `void printLine(int n)`. Две реализации — одна печатает `n` звездочек (символ `*`), вторая — 2 звездочки и n-2 пробелов между ними (1 звездочку, если n<2). Класс `Diamond`, который получает в конструкторе экземпляр `LinePrinter` и использует его для печати ромба построчно. Также фабрика с двумя методами `LinePrinter createFilledLinePrinter()` и `LinePrinter createEmptyLinePrinter()`.

UI: запрашиваем у пользователя число `n` - высоту ромба. С помощью класса `Diamond` с нужным `LinePrinter` печатаем 2 ромба — заполненный и пустой. Для n=3 должно получиться что-то вроде
```
 *
***
 * 
 *
* *
 * 
```

Сделать так, чтобы реализации были недоступны из UI, только интерфейсы, фабрика и класс `Diamond`.
