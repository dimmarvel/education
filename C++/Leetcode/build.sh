#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Ошибка: Укажите .cpp файл для компиляции"
    echo "Пример использования: ./bush.sh file.cpp"
    exit 1
fi

source_file="$1"

if [ ! -f "$source_file" ]; then
    echo "Ошибка: Файл '$source_file' не найден"
    exit 1
fi

output_name="${source_file%.cpp}"

g++ -std=c++20 -g -Wall -Wextra -pedantic -o "$output_name" "$source_file"

if [ $? -eq 0 ]; then
    echo "✓ Компиляция успешна"
    echo "Исполняемый файл: $output_name"
else
    echo "✗ Ошибка компиляции"
    exit 1
fi