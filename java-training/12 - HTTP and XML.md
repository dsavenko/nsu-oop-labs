
# Тема 12. Работа с HTTP(S) и XML

**Общие условия**

1. Создайте Maven-проект с `groupId = ru.nsu.<ваша фамилия>.http.task<номер задачи>` и `artifactId = main`.
2. Для работы с HTTP(S) воспользуйтесь классом `java.net.URL` и его методом `openConnection`. Для парсинга XML используйте класс `javax.xml.parsers.DocumentBuilder`.

Пример работы с `URL`:
```java
URL url = new URL(/*...something...*/);
URLConnection conn = url.openConnection();
try (InputStream input = conn.getInputStream()) {
    // do what you need to do
}
```

Пример работы с `DocumentBuilder`:
```java
DocumentBuilder builder = DocumentBuilderFactory.newDefaultInstance().newDocumentBuilder();
Document doc = builder.parse(/*...some input here...*/);
NodeList items = doc.getElementsByTagName(/*...tag name you need...*/);
// see NodeList javadoc on what to do next
```

## Задача 1. Тривиальная читалка RSS

Выведите на консоль список лучших публикаций на [Хабре](https://habr.com/ru/feed/) за сутки, для каждой публикации выведите название, автора и ссылку. Информация о лучших публикациях доступна в основанном на XML формате RSS по ссылке: [https://habr.com/ru/rss/best/daily/](https://habr.com/ru/rss/best/daily/).

Можете заменить Хабр на любой другой RSS-источник.
