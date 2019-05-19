#include <string>
#include "TDataCom.h"
#include "TDateValue.h"

using namespace std;

typedef string TKey;
typedef int TValue;

struct TRecord {
	TKey key;  //����
	TValue val; // ��������(����� ��� ������������� ������)
};

class TTable : public TDataCom {
protected:
	int DataCount; // ���������� ������� � �������
	int Efficiency; // ���������� ������������� ���������� ��������
public:
	TTable() { DataCount = 0; Efficiency = 0; } // �����������
		virtual ~TTable() {}; // ����������
		// �������������� ������
	int GetDataCount() const { return DataCount; } // �-�� �������
	int GetEfficiency() const { return Efficiency; } // �������������
	int IsEmpty() const { return DataCount == 0; } //�����?
	virtual int IsFull() const = 0; // ���������?
	// ������
	//virtual string GetKey(void) const = 0;
	//virtual PTDatValue GetValuePTR(void) const = 0;
	// �������� ������
	virtual PTDatValue FindRecord(string k) = 0; // ����� ������
	virtual void InsRecord(TRecord rec) = 0; // ��������
	virtual void DelRecord(string k) = 0; // ������� ������
	// ���������
	virtual int Reset(void) = 0; // ���������� �� ������ ������
	virtual int IsTabEnded(void) const = 0; // ������� ���������?
	virtual int GoNext(void) = 0; // ������� � ��������� ������
	// (=1 ����� ���������� ��� ��������� ������ �������)
	virtual TRecord GetCurr() const = 0;

	void Print() {
		for (Reset(); !IsTabEnded(); GoNext())
		{
			cout << GetCurr().key << "  -  " << GetCurr().val << endl;
		}
	}

	// ������ �� �����
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
