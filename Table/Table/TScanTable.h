#include "TArrayTable.h"

class TScanTable : public TArrayTable {
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {};//конструктор
	// основные методы
	virtual PTDatValue FindRecord(string k);//найти запись
	virtual void InsRecord(string k, PTDatValue pVal);//вставить
	virtual void DelRecord(string k);//удалить запись
};