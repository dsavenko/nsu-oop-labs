
# Тема 13. Паттерны проектирования

**Общие условия:**

1. Все задачи ниже предполагают модификацию кода вашего [Стекового калькулятора](<../java-tasks/Task 2 - Stack Calculator.md>).
2. По желанию вместо изменения стекового калькулятора вы можете изменить любую другую задачу, применив любой из перечисленных ниже паттернов.
3. Выберите тот паттерн проектирования, который вы еще не реализовывали.

## Задача 1. Абстрактная фабрика (Abstract factory)

Команды в стековом калькуляторе создаются при помощи паттерна “Фабричный метод”. Измените его на использование паттерна "Абстрактная фабрика". Главное отличие абстрактной фабрики от фабричного метода в том, что у фабрики есть отдельный интерфейс и несколько реализаций, которые создают отличающиеся наборы объектов. Обычно у абстрактной фабрики также несколько создающих методов (создатьОбъектА, создатьОбъектБ, и т.д.). Для выполнения задания сделайте следующее:
1. выделите интерфейс фабрики
2. добавьте в него метод создания контекста. Если у вас нет выделенного класса контекста, добавьте метод создания стека
3. сделайте 2 реализации фабрики — одна та, что была раньше (создает команды и контекст/стек как раньше), а вторая будет вместо создания конкретных команд создавать заглушки, которые просто пишут на экран "вызвана команда такая-то", но ничего не делают, и создавать пустой контекст/стек (можете воспользоваться `Collections.emptyList`).

## Задача 2. Приспособленец (Flyweight)

Сделайте так, чтобы все бинарные арифметические операции (`+`, `-`, `*`, `/`) выполнял единственный объект одного класса (“приспособленец”, реализует интерфейс команды). Ваша фабрика (класс, реализующий паттерн “фабричный метод”) создает такой объект в конструкторе. Когда у нее просят создать одну из арифметических команд, она вместо создания нового объекта берет объект-приспособленец, устанавливает у него свойство какую операцию выполнить следующей, и возвращает этот объект. Остальная программа должна работать как прежде, изменения должны коснуться только кода фабрики.

## Задача 3. Стратегия (Strategy)

Сделайте так, чтобы все бинарные арифметические операции (`+`, `-`, `*`, `/`) выполнял один класс `BinaryOperation`. В конструкторе он будет принимать интерфейс `Strategy`, имеющий метод `double execute(double a, double b)`, и вызывать его для двух элементов стека. У этого интерфейса будут реализации для всех бинарных операций. На запрос конкретной бинарной операции фабричный метод будет возвращать экземпляр `BinaryOperation` с нужной стратегией.

## Задача 4. Компоновщик (Composite)

Сделайте новую команду-композит, которую можно вызывать так: `COMPOSITE COMMAND1 COMMAND2 ...` (например, `COMPOSITE * PRINT`). Выполнение этой команды заключается в том, что она последовательно выполняет все переданные в нее команды.

За исключением новой команды изменения в коде должны затронуть только фабричный метод, остальной код не должен меняться.

## Задача 5. Декоратор (Decorator, Wrapper)

Cоздайте новый класс команды-декоратора, которая будет принимать другую команду, выполнять ее, и сохранять в файл состояние стека и переменных до и после выполнения этой команды, а также саму команду с ее аргументами. Декорировать можно любую команду, для этого надо написать перед ней слово `LOG`.
Например, `LOG DEFINE a 4`, `LOG SQRT`, `LOG PUSH 4`. При этом команды без `LOG` тоже работают как раньше. За исключением новой команды изменения в коде должны затронуть только фабричный метод, остальной код не должен меняться.

## Задача 6. Заместитель (Proxy)

Выделите интерфейс вашей фабрики и напишите две ее реализации. Одна старая (обычная), а другая — кэширующий прокси. Эта реализация получает в конструкторе экземпляр другой реализации (по интерфейсу). Когда вызывается ее метод создания команды, она проверяет, создавала ли ранее такую команду. Если нет, то она переадресует вызов создания команды той фабрике, которую получила в конструкторе, после чего сохраняет созданный объект и возвращает его. Если да, то она возвращает ранее созданный объект, не обращаясь к оригинальной фабрике.

Код остальной программы должен единообразно работать как с обычной фабрикой, так и со связкой кэширующий_прокси(обычная_фабрика).