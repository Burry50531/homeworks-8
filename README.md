Лабораторна робота №8 — Операційні системи

 Опис

Цей репозиторій містить приклади програм з лабораторної роботи №8 з дисципліни "Операційні системи".

Атомарний обмін вмістом двох файлів без створення тимчасових. Використовується `renameat2()` з прапором `RENAME_EXCHANGE`.

 `partial_write_pipe.c`

Демонстрація часткового запису в pipe при використанні неблокуючого режиму (O_NONBLOCK). Пояснює, чому `write()` може повернути менше байтів, ніж запитувалось.

 `file_seek_read.c`

Використання `lseek()` для встановлення позиції в файлі і подальшого читання певної кількості байтів.

`qsort_worst_case.c`

Генерація найгірших вхідних даних для `qsort()`. Тестування продуктивності та перевірка коректності сортування.

`fork_example.c`

Програма демонструє створення нового процесу за допомогою `fork()` і пояснює, як відрізнити батьківський та дочірній процеси.

Запуск

Для компіляції та запуску використовуйте:

gcc -o atomic_swap atomic_swap.c
./atomic_swap

gcc -o partial_write_pipe partial_write_pipe.c
./partial_write_pipe

gcc -o file_seek_read file_seek_read.c
./file_seek_read

gcc -o qsort_worst_case qsort_worst_case.c
./qsort_worst_case

gcc -o fork_example fork_example.c
./fork_example
