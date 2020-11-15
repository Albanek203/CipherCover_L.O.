#include "CDataChain.cpp"
#include <vector>
class CLink {
public:
	CLink(CDataChain& refChain) :m_refChain(refChain) {}
	/*virtual ~CLink(void);*/

	////Пробує прив"язати об"єкт до підстрічки у послідовності
	//bool Attach(const char* sSubStr);

	////Форматований вивід на консоль
	//virtual void Output(ostream& os);

	virtual bool Save(ostream& so) {
		so << "Size:" << m_nSize << "\nPos:" << m_nPos;
		return 0;
	}

	//Зчитує об"єкт із вхідного потоку
	virtual bool Load(istream& is) {}

	void Assignment_nPos_nSize(int nPos,int nSize) {
		m_nPos = nPos;
		m_nSize = nSize;
	}
protected:
	//Посилання на контейнер з повною послідовністю
	CDataChain& m_refChain;
	//Позиція початку у повній послідовності
	int m_nPos;
	//Довжина підстрічки, до якої прив"язується об"єкт
	int m_nSize;
};typedef vector<CLink*> LinksArray;