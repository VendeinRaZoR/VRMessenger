﻿# Клиент-мессенджер VRMessenger (2011-2012 годов разработки)

**Краткое описание**

Приложение TCP IPv4 клиента-мессенджера VRMessenger. 

Разрабатывалось в эпоху IM-клиентов ICQ, QIP 2005 и прочих. 
В то время социальные сети не обладали достаточным функционалом,
поэтому все пользовались именно этими клиентами.

Вдохновившись существующими мессенджерами, была предпринята попытка
разработать свой собственный мессенджер в стиле старой Windows
с использованием WinAPI. Работать он должен был, соответственно,
исключительно под Windows.

Реализована простенькая WinAPI GUI-обёртка, которая потом легла 
в основу графического редактора карт высот ByteBlaster.

Всего программа состоит из 3-х диалоговых окон:

1) Окно входа

![image](https://user-images.githubusercontent.com/73369113/152821207-1315bc03-d605-409c-b97c-3594ea9bfbb4.png)

2) Окно настроек

![image](https://user-images.githubusercontent.com/73369113/152821289-330b57c6-8180-42a9-849f-f8b7a4a8a375.png)

3) Окно выбора и поиска пользователя

![image](users.bmp)


**В папке Deploy находятся уже собранные клиент и сервер.**

Алгоритм подключения следующий:

1) Запустить VRMServer (на своей машине или на машине в сети); 
2) На окне входа нажать кнопку "Настройки", откроется окно;
3) Выбрать пункт "Регистрация";
4) Удалить все поля и ввести свои и нажать кнопку "Зарегистрироваться";
5) Если подключения нет, то появится сообщение "Ошибка отправки данных";
6) Выбрать пункт "Подключение";
7) Задать порт и адрес сервера, если VRMServer запущен на машине в сети,
иначе оставить галочку "По Умолчанию";
8) Нажать на "Сохранить изменения", конфигурация запишется в INI файл;
9) Закрыть окно настроек, ввести ранее указанный логин и пароль 
и нажать кнопку "Подлючение";
10) Откроется окно пользователя, отобразится имя пользователя и его статус "В Сети".

Дальнейшая разработка приложения TCP IPv4 клиента VRMessenger была остановлена, 
так как времени уже не особо было и надо было готовиться к ЕГЭ для поступления в 
институт. 

В скором времени актуальность мессенджеров ICQ и QIP пропала, так как на смену им
пришли соцсети, вроде ВК. Поэтому дальнейшая разработка VRMessenger и VRMServer
уже не имеет практического и экономического смыслов.
