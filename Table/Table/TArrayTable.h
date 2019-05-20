#define TabMaxSize 25
#include <string>
#include "TDateValue.h"
#include "TTable.h"

using namespace std;
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
class TArrayTable : public TTable {
protected:
	PTTabRecord * mas;// память для записей таблицы
	int TabSize; // макс. возм.количество записей в таблице
	int CurrPos; // номер текущей записи (нумерация с 0)
public:
	TArrayTable(int Size = TabMaxSize) // конструктор
	{
		mas = new PTTabRecord[Size];
		for (int i = 0; i < Size; i++) mas[i] = NULL;
		TabSize = Size; DataCount = CurrPos = 0;
	}
	~TArrayTable() {}; // деструктор
	// информационные методы
	
		virtual int IsFull() const; // заполнена?
	int GetTabSize() const; // к-во записей
	// доступ
	virtual TKey GetKey(void) const { return GetKey(CURRENT_POS); }
	virtual PTDatValue GetValuePTR(void) const { return GetValuePTR(CURRENT_POS); }
	virtual TKey GetKey(TDataPos mode) const;
	virtual PTDatValue GetValuePTR(TDataPos mode) const; // указатель на значение
	// основные методы
	virtual PTDatValue FindRecord(string k) = 0; // найти запись
	virtual void InsRecord(string k, PTDatValue pVal) = 0; // вставить
	virtual void DelRecord(string k) = 0; // удалить запись
	//навигация
	virtual int Reset(void); // установить на первую запись
	virtual int IsTabEnded(void) const; // таблица завершена?
	virtual int GoNext(void); // переход к следующей записи
	//(=1 после применения для последней записи таблицы)
	virtual int SetCurrentPos(int pos);// установить текущую запись
	int GetCurrentPos(void) const; //получить номер текущей записи

	friend class TSortTable;
	friend class TTabRecord;
};