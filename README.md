[![C++](https://img.shields.io/badge/C++-f06529)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Boost tests](https://img.shields.io/badge/Boost_test-f0db4f)](https://www.boost.org/)

# C++ _ boost test _ project

## Задание

- Посмотреть задание [link](./task/)

## Установка и запуск программы в Linux

1) При первом запуске запускаем команду ```make dir``` для создания папок build

2) Запускаем проект: ```make run```

## Установка и запуск тестов "Boost test"

1) Переходим в папку tests

2) Запускаем через Python Conan venv
    
    ```$conan install /home/eduard/Projects/iu7/TESTS_v1/lab1/conanfile.txt -of /home/eduard/Projects/iu7/TESTS_v1/lab1/build-conan --build=missing```

    Поменяйте пути выше

4) Запустить тесты находясь в папке tests: 

    ```./load.sh all```

    Тесты запустятся в рандомном порядке на 4 потоках