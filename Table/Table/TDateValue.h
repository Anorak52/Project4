typedef TDatValue* PTDatValue;
class TDatValue {
public:
	virtual TDatValue * GetCopy() = 0; // �������� �����
	~TDatValue() {}
};