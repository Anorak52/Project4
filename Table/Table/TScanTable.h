#include "TArrayTable.h"

class TScanTable : public TArrayTable {
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {};//конструктор
	// основные методы

	virtual bool Find(TKey _key) {
		for (int i = 0; i < DataCount; i++) {
			Efficiency++;
			if (mas[i].key == _key) {
				CurrPos = i;
				return true;
			}
		}
		CurrPos = DataCount;
		return false;
	}

	virtual void Insert(TRecord rec) {
		if (IsFull()) return;
		if (!Find(rec.key)) {
			mas[CurrPos] = rec;
			DataCount++;
			Efficiency++;
		}
		else
		{
			mas[CurrPos].val++;
		}
	}
	
	virtual void Delete(TKey _key) {
		if (Find(_key)) {
			DataCount--;
			Efficiency++;
			mas[CurrPos] = mas[DataCount];
		}
	}
};