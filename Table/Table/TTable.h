#include <string>
#include "TDataCom.h"
#include "TDateValue.h"

using namespace std;

typedef string TKey;
typedef int TValue;

struct TRecord {
	TKey key;  // люч
	TValue val; // значение(число раз встречаемости ключей)
};

class TTable : public TDataCom {
protected:
	int DataCount; // количество записей в таблице
	int Efficiency; // показатель эффективности выполнени€ операции
public:
	TTable() { DataCount = 0; Efficiency = 0; } // конструктор
		virtual ~TTable() {}; // деструктор
		// информационные методы
	int GetDataCount() const { return DataCount; } // к-во записей
	int GetEfficiency() const { return Efficiency; } // эффективность
	int IsEmpty() const { return DataCount == 0; } //пуста?
	virtual int IsFull() const = 0; // заполнена?
	// доступ
	//virtual string GetKey(void) const = 0;
	//virtual PTDatValue GetValuePTR(void) const = 0;
	// основные методы
	virtual PTDatValue FindRecord(string k) = 0; // найти запись
	virtual void InsRecord(TRecord rec) = 0; // вставить
	virtual void DelRecord(string k) = 0; // удалить запись
	// навигаци€
	virtual int Reset(void) = 0; // установить на первую запись
	virtual int IsTabEnded(void) const = 0; // таблица завершена?
	virtual int GoNext(void) = 0; // переход к следующей записи
	// (=1 после применени€ дл€ последней записи таблицы)
	virtual TRecord GetCurr() const = 0;

	void Print() {
		for (Reset(); !IsTabEnded(); GoNext())
		{
			cout << GetCurr().key << "  -  " << GetCurr().val << endl;
		}
	}

	// „тение из файла
	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);

		if (!TxtFile.fail())
		{
			while (!TxtFile.eof()) str += TxtFile.get();
			TxtFile.close();
		}
		else cout << "File does not exist" << endl;

		for (int i = 0; i < str.length(); i++)
		{
			char tmp = str[i];
			if (((int)tmp >= 65) && ((int)tmp <= 90))
			{
				tmp += 32;
			}
			str[i] = tmp;
		}

		string tmp = "";
		TRecord rec;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				rec.key = tmp;
				rec.val = 1;
				InsRecord(rec);
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
	}
};
