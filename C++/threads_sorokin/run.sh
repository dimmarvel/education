#!/bin/bash

if [[ "$#" -ne 1 ]]; then
    echo "[!] Использование: $0 <имя_программы_без_cpp>"
    echo "[i] Пример: для thread.cpp → '$0 thread'"
    exit 1
fi

TARGET="$1"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"

mkdir -p "${BUILD_DIR}" || { echo "[X] Ошибка создания ${BUILD_DIR}"; exit 2; }
cd "${BUILD_DIR}" || { echo "[X] Не удалось войти в ${BUILD_DIR}"; exit 3; }

echo "[+] Конфигурируем проект..."
cmake .. || { echo "[X] Ошибка CMake"; exit 4; }

echo ""
echo "[+] Компилируем '${TARGET}'..."
if ! make --silent "${TARGET}"; then
    echo -e "\n[X] Ошибка компиляции '${TARGET}'"
    
    echo -e "\n[i] Доступные цели:"
    grep 'add_executable(' "${SCRIPT_DIR}/CMakeLists.txt" | awk '{print $2}' || true
    
    echo -e "\n[i] Фактические CPP-файлы:"
    find "${SCRIPT_DIR}" -maxdepth 1 -name '*.cpp' -exec basename {} \; || true
    
    exit 5
fi;

echo -e "\n\033[32m[✓] Успешная компиляция!\033[0m\n"

executable="${BUILD_DIR}/${TARGET}"
if [[ -x "$executable" ]]; then
    echo "[>] Запускаем программу:"
    "${executable}"
else
    echo "[X] Исполняемый файл не найден: $executable"
    exit 6
fi
