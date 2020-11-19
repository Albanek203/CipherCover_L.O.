#pragma once
#include <iostream>
#include <string> 
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class CDataChain {
public:
	CDataChain(void);
	virtual ~CDataChain(void);
	virtual size_t GetLength() = 0;
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	virtual int Find(const char* sSubStr, int nPos = 0) = 0;
	virtual const char* GetFullString() = 0;
	virtual void Assignment(string str) = 0;
protected:
	string m_sChain;
};

class CDataSimple : public CDataChain {
public:
	void Generate(int nDepth, int nMaxLength = 0);
	const char* GetFullString();
	void Assignment(string str);
	int Find(const char* sSubStr, int nPos = 0);
	size_t GetLength();
};

class CDataPi :public CDataChain {
public:
	void Generate(int nDepth, int nMaxLenght = 0);
};