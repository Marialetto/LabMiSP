/** @file modTableCipher.h
 *  @author Каратаева М.А.
 *  @version 1.0
 *  @date 21.12.2022
 *  @copyright ИБСТ ПГУ
 *  @brief Класс для (де-)шифрования методом табличной маршрутной перестановки
 */
 
#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

/* @class modTableCipher 
 * @brief Шифрование методом табличной маршрутной перестановки
 * @detalies Для (де-)шифрования используются методы encrypt и decrypt. Ключ устанавливается в конструкторе.
 * @warnings Реализация только для латиского алфавита!
 */
 
class modTableCipher 
{
private:
    int key; 
    /**
     * @brief Метод используемый для (де-)шифрования
     * @param [in] key Текст на английском языке
     */
    string getValidText(const string & s);
     /** 
      * @brief Метод класса, проверяющий текст на валидность
      * @param [in] s Tекст на английском языке
      */
public:
    modTableCipher()=delete; // конструктор без параметра(запрещён)
    modTableCipher(const int& key){};   // конструктор для установки ключа
    string encrypt(const string& open_text);
    /**
     * @brief Зашифрование
     * @param [in] text Открытый текст на английском языке
     * @warnings Текс не должен быть пустой строкой, содержать пробелы. 
     * @return Зашифрованный текст
     * @throw cipher_error Если в качестве текста введена пустая строка
     */
    string decrypt(const string& cipher_text);
     /** 
     * @brief Расшифрование
     * @param [in] text Зашифрованный текст на английском языке
     * @warnings Текс не должен быть пустой строкой и не должен содержать пробелы. 
     * @return Расшифрованный текст
     * @throw cipher_error Если в качестве текста введена пустая строка
     */
};
class cipher_error: public std::invalid_argument
{
public:
	/**
     * @brief Класс для обработки ошибок и исключений 
     * @param [in] what_arg После проверки текста при помощи getValidText, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     * @warnings Текс не должен быть пустой строкой и не должен содержать пробелы.
     */
    explicit cipher_error (const string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
