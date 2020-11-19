#pragma once
#include "CDataChain.h"
class CLink {
public:
	CLink(CDataChain& refChain);
	virtual ~CLink(void) {}
	virtual bool Save(ostream& so);
	virtual bool Load(istream& is);
	void Assignment_nPos_nSize(int nPos, int nSize);
	void Get_nPosAND_nSize();
	int Take_nPos();
protected:
	CDataChain& m_refChain;
	int m_nPos;
	int m_nSize;
};
typedef vector<CLink*> LinksArray;

class CLinkURL : public CLink {
public:
	CLinkURL(CDataChain& refChain);
	virtual ~CLinkURL(void);
	void Add_URL(const char* str);
private:
	string m_sURL;
};
class CLinkPerson : public CLink {
public:
	CLinkPerson(CDataChain& refChain);
	virtual ~CLinkPerson(void);
	void AssigmentGroup(int member);
	void AssigmentName(string name);
private:
	int m_nGroupCode;
	string m_sName;
};