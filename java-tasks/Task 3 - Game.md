
# Задача 3. Игра

Напишите небольшую игру с графическим интерфейсом. На выбор предлагаются следующие жанры и примеры (но вы ими не ограничены):

1. Фиксированный шутер наподобие [Space Invaders](https://ru.wikipedia.org/wiki/Space_Invaders).
2. Скролл-шутер (вертикальный или горизонтальный), пример: [Gradius](https://ru.wikipedia.org/wiki/Gradius).
3. Лабиринт, пример: [Pac-Man](https://ru.wikipedia.org/wiki/Pac-Man), [Bomberman](https://ru.wikipedia.org/wiki/Bomberman_(%D0%B8%D0%B3%D1%80%D0%B0,_1983)), ["Танчики"](https://ru.wikipedia.org/wiki/Battle_City).
4. Ваш вариант.

Игры, которые делать нельзя:
1. Змейка.

Вы можете сделать ту же игру, которую делали [на С++](<../cpp-tasks/Task 3 - Terminal-Based Game.md>), либо выбрать другую, но в любом случае должны выполняться следующие условия:

1. Есть управляемый игроком персонаж и другие объекты, с которыми он взаимодействует (враги, стены, пули, и т.д.).
2. Игра в реальном времени: даже если игрок ничего не делает, на экране что-то происходит (летят пули, двигаются враги, и т.д.).
3. Есть система подсчета очков: количество убитых врагов, собранных предметов и т.д.
4. Должно быть условие окончания игры (проигрыша и/или выигрыша), например столкновение с врагом, уменьшение здоровья до 0, сбор всех предметов на экране, и т.д.

**Технические условия:**

1. Игра с графическим интерфейсом. Вы можете выбрать любую библиотеку для GUI, но рекомендуется использовать Swing (классы из пакета `javax.swing`).
2. Достаточно схематичной "графики": цветные прямоугольники, круги и т.д.
3. Должно быть как минимум 3 различных игровых объекта (например, "игрок", "враг", "пуля").
4. Все игровые объекты должны быть собраны в одну иерархию классов с единым корнем.
5. Поведение игровых объектов должно быть инкапсулировано в их классах. Игровой движок должен единообразно работать со всеми объектами. Желательно избегать явных проверок на тип объекта, вместо этого разное поведение разных объектов должно реализовываться средствами ООП.
6. Код должен быть организован в соответствии с шаблоном проектирования [MVC](https://ru.wikipedia.org/wiki/Model-View-Controller). Должны быть явно выделенные уровни модели, контроллера и представления.
7. Необходимо реализовать два различных представления (view либо связки view/controller), с использованием разных библиотек. Второе представление может быть текстовым, либо использовать другую библиотеку для GUI. **Важно!** При этом модель используется одна и та же.

## Рекомендации и примеры

Пример простой игры, реализованной в концепции MVC, находится вот тут: [mvc-swing-game](../java-examples/mvc-swing).

Для реализации UI можно воспользоваться следующими фреймворками:
1. AWT/Swing (считаются за один)
2. JavaFX
3. SWT
4. [libGDX](https://libgdx.com/) - полноценный фреймворк для создания игр на Java. Подойдет тем, кому интересен геймдев. *Может* потребовать больше времени на освоение, чем другие варианты.
5. [Lanterna](https://github.com/mabe02/lanterna) - библиотека для управления терминалом наподобие curses, позволяет сделать полноценную консольную вьюху. В этом случае ваша консольная версия может очень сильно напоминать ту игру, что была в 1-м семестре. *Возможно,* этот вариант позволит сэкономить время и переиспользовать опыт прошлого семестра.

## Дополнительно

Дополнительные возможности, предлагаемые для реализации:

1. Ведение таблицы рекордов (по очкам), возможность её просмотра из игры.
2. Сохранение и загрузка игры.
3. Более продвинутая графика: картинки вместо геометрических фигур, спрайтовая анимация и т.д.
4. Более продвинутый искусственный интеллект врагов.
5. Звуки и/или музыка.
6. Ваши идеи?

## Возможное упрощение условий

Если вы не чувствуете в себе сил (или у вас не хватает времени) в полной мере реализовать обязательные условия задачи, предлагаю следующее упрощение: второе представление (пункт 5 тех.условий) сделать неполноценным. Например, это может быть текстовый интерфейс на основе `System.out / System.in`, который позволяет только посмотреть таблицу рекордов и список "сейвов", очистить рекорды, удалить "сейвы", но не позволяет играть в саму игру. Несмотря на неполноценность, данное представление также должно работать через основную модель игры.
