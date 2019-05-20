#include "TScanTable.h"
#include "TTabRecord.h"
#include "TDateValue.h"

enum TSortMethod { INSERT_SORT, MERGE_SORT, QUIQ_SORT };
class TSortTable : public TScanTable {
protected:
	TSortMethod SortMethod; // метод сортировки
	void SortData(void); // сортировка данных
	void InsertSort(PTTabRecord *pMem, int DataCount); // метод вставок
	void MergeSort(PTTabRecord *pMem, int DataCount); // метод слияния
	void MergeSorter(PTTabRecord * &pData, PTTabRecord * &pBuff, int Size);
	void MergeData(PTTabRecord *&pData, PTTabRecord *&pBuff, int n1, int n2);
	void QuiqSort(PTTabRecord *pMem, int DataCount); // быстрая сортировка
	void QuiqSplit(PTTabRecord *pData, int Size, int &Pivot);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) {};// конструктор
	TSortTable(const TScanTable &tab); // из просматриваемой таблицы
	TSortTable & operator=(const TScanTable &tab); // присваивание
	TSortMethod GetSortMethod(void); // получить метод сортировки
	void SetSortMethod(TSortMethod sm);// установить метод сортировки
	// основные методы
	virtual PTDatValue FindRecord(string k); // найти запись
		virtual void InsRecord(string k, PTDatValue pVal); // вставить
	virtual void DelRecord(string k); // удалить запись
};
