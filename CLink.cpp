#include "CDataChain.cpp"
#include <vector>
class CLink {
public:
	CLink(CDataChain& refChain) :m_refChain(refChain) {}
	/*virtual ~CLink(void);*/

	////����� ����"����� ��"��� �� �������� � �����������
	//bool Attach(const char* sSubStr);

	////������������ ���� �� �������
	//virtual void Output(ostream& os);

	virtual bool Save(ostream& so) {
		so << "Size:" << m_nSize << " Pos:" << m_nPos;
		return true;
	}

	//����� ��"��� �� �������� ������
	virtual bool Load(istream& is) { return true; }

	void Assignment_nPos_nSize(int nPos,int nSize) {
		m_nPos = nPos;
		m_nSize = nSize;
	}
	void Get_nPosAND_nSize() {
		cout << "Size: " << m_nSize << " Pos: " << m_nPos;
	}
protected:
	//��������� �� ��������� � ������ �����������
	CDataChain& m_refChain;
	//������� ������� � ����� �����������
	int m_nPos;
	//������� ��������, �� ��� ����"������� ��"���
	int m_nSize;
};
typedef vector<CLink*> LinksArray;