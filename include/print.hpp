#include <string>
#include <fstream>
#include <iostream>
/*!
	\brief Функция копирования
	\param[in] text Копирование текстовой строки
	\param[out] out Вывод текстовой строки на экран
	
	Данная функция копирует текстовую строку и выводит её на экран для контроля.
	
	Код функции выглядит следующим образом:
	\code
		void print(const std::string& text, std::ostream& out = std::cout);
	\endcode
*/
void print(const std::string& text, std::ostream& out = std::cout);
/*!
	\brief Функция копирования
	\param[in] text Копирование текстовой строки
	\param[out] out Вывод текстовой строки на экран
	
	Данная функция копирует текстовую строку и выводит её на экран для контроля.
	
	Код функции выглядит следующим образом:
	\code
		void print(const std::string& text, std::ofstream& out);
	\endcode
*/
void print(const std::string& text, std::ofstream& out);
