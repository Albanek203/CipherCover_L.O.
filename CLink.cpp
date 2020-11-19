#include "CLink.h"
class CLink {
public:
	CLink(CDataChain& refChain) :m_refChain(refChain) {}
	virtual ~CLink(void) {}
	virtual bool Save(ostream& so) {
		so << "Size:" << m_nSize << " Pos:" << m_nPos;
		return true;
	}
	virtual bool Load(istream& is) { 
		string arr,value = "";
		int i = 5;
		getline(is, arr);		
		while (arr[i] != ' ') { value += arr[i]; i++; }
		m_nSize = stoi(value.c_str());
		value = "";
		arr.erase(0, i + 5);
		i = 0;
		while (isdigit(arr[i])) { value += arr[i]; i++; }
		m_nPos = stoi(value.c_str());
		return true;
	}

	void Assignment_nPos_nSize(int nPos,int nSize) {
		m_nPos = nPos;
		m_nSize = nSize;
	}
	void Get_nPosAND_nSize() {
		cout << "Size:" << m_nSize << " Pos:" << m_nPos<< endl;
	}
	int Take_nPos() { return m_nPos; }
protected:
	CDataChain& m_refChain;
	int m_nPos;
	int m_nSize;
};
typedef vector<CLink*> LinksArray;

class CLinkURL : public CLink {
public:
	CLinkURL(CDataChain& refChain) :CLink(refChain) {}
	virtual ~CLinkURL(void) {}
	void Add_URL(const char* str) { m_sURL = str; }
private:
	string m_sURL;
};
class CLinkPerson : public CLink {
public:
	CLinkPerson(CDataChain& refChain) :CLink(refChain) {}
	virtual ~CLinkPerson(void) {}
	void AssigmentGroup(int member) { m_nGroupCode = member; }
	void AssigmentName(string name) { m_sName = name; }
private:
	int m_nGroupCode;
	string m_sName;

};