#define TabMaxSize 25
#include <string>
#include "TDateValue.h"
#include "TTable.h"

using namespace std;
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
class TArrayTable : public TTable {
protected:
	PTTabRecord *mas; // ������ ��� ������� �������
	int TabSize; // ����. ����.���������� ������� � �������
	int CurrPos; // ����� ������� ������ (��������� � 0)
public:
	TArrayTable(int Size = TabMaxSize)
	{
		TabSize = Size;
		CurrPos = -1;
		mas = new TRecord[TabSize];
	} // �����������
	~TArrayTable() {}; // ����������
	// �������������� ������
	
		virtual int IsFull() const; // ���������?
	int GetTabSize() const; // �-�� �������
	// ������
	virtual string GetKey(void) const;
	virtual PTDatValue GetValuePTR(void) const;
	virtual string GetKey(TDataPos mode) const;
	virtual PTDatValue GetValuePTR(TDataPos mode) const;
	// �������� ������
	virtual PTDatValue FindRecord(string k) = 0; // ����� ������
	virtual void InsRecord(string k, PTDatValue pVal) = 0; // ��������
	virtual void DelRecord(string k) = 0; // ������� ������
	//���������
	virtual int Reset(void); // ���������� �� ������ ������
	virtual int IsTabEnded(void) const; // ������� ���������?
	virtual int GoNext(void); // ������� � ��������� ������
	//(=1 ����� ���������� ��� ��������� ������ �������)
	virtual int SetCurrentPos(int pos);// ���������� ������� ������
	int GetCurrentPos(void) const; //�������� ����� ������� ������
	friend class TSortTable;
	friend class TTabRecord;
};