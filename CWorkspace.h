#pragma once
#include "CLink.h"
#include "CDataChain.h"
class CWorkspace {
public:
	CWorkspace(CDataChain& data);
	~CWorkspace(void);

	const char* GetChainString();
	void Init(int nDepth, int nLength); 
	void Init_by_PI(int nLength);
	bool Save(string& sFilepath);
	bool Load(string& sFilepath);
	int Find(const char* sSubStr, int nPos = 0);
	bool AddLink(int nStartPos, int nLength, CLink* pLink);
	bool RemoveLink(int nPosInList);
	bool GetAllLinks(LinksArray& aLinks);
	void ShowAllLinks();
	bool AddURL(const char* sSubStr, const char* sURL);
	bool AddPerson(const char* sSubStr, int nGroup, const char* sName);
	bool TestPosition(int nPos, LinksArray& aNearestLinks);
	bool TestInterval(int nStartPos, int nEndPos, LinksArray& aNearestLinks);
private:
	CDataPi m_refPI;
	CDataChain& m_refChain;
	LinksArray m_aLinks;
};