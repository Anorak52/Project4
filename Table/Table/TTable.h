#include <string>
#include "TDataCom.h"
#include "TDateValue.h"

using namespace std;

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
	virtual string GetKey(void) const = 0;
	virtual PTDatValue GetValuePTR(void) const = 0;
	// �������� ������
	virtual PTDatValue FindRecord(string k) = 0; // ����� ������
	virtual void InsRecord(string k, PTDatValue pVal) = 0; // ��������
	virtual void DelRecord(string k) = 0; // ������� ������
	// ���������
	virtual int Reset(void) = 0; // ���������� �� ������ ������
	virtual int IsTabEnded(void) const = 0; // ������� ���������?
	virtual int GoNext(void) = 0; // ������� � ��������� ������
	// (=1 ����� ���������� ��� ��������� ������ �������)
};
