#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>

#include <string.h>
#include <cstring>
#include <string>

#include <Windows.h>
#include "TDateValue.h"

using namespace std;

//typedef string TKey // тип ключа записи
// Класс объектов-значений для записей таблицы
typedef TTabRecord* PTTabRecord;
class TTabRecord : public TDatValue {
protected: // поля
	string Key; // ключ записи
	PTDatValue pValue; // указатель на значение
public: // методы
	TTabRecord(string k = "", PTDatValue pVal = NULL);// конструктор
	void SetKey(string k);// установить значение ключа
	string GetKey(void); // получить значение ключа
	void SetValuePtr(PTDatValue p);// установить указатель на данные
	PTDatValue GetValuePTR(void); // получить указатель на данные
	virtual TDatValue * GetCopy(); // изготовить копию
	TTabRecord & operator = (TTabRecord &tr);// присваивание
	virtual int operator == (const TTabRecord &tr); // сравнение =
	virtual int operator < (const TTabRecord &tr); // сравнение «<»
	virtual int operator > (const TTabRecord &tr); // сравнение «>»
   //дружественные классы для различных типов таблиц, см. далее
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
};