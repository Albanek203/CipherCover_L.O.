#include <iostream>
#include <string> 

using namespace std;
class CDataChain {
public:
	CDataChain(void) {}
	virtual ~CDataChain(void) {}
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	virtual int Find(const char* sSubStr, int nPos = 0) = 0;
	virtual const char* GetFullString() = 0;
	virtual void Assignment(string str) = 0;
protected:
	string m_sChain;
};

class CDataSimple : public CDataChain {
public:
	void Generate(int nDepth, int nMaxLength = 0) override {
		string gen = "";
		for (int iter = 0; iter <= nDepth; iter++) {
			if (size(gen) > nMaxLength) { break; }
			gen += to_string(iter);
		}
		m_sChain += gen + "\n";
	}
	const char* GetFullString() override { return m_sChain.c_str(); }
	void Assignment(string str) override { m_sChain = str; }
	int Find(const char* sSubStr, int nPos = 0) override {
		string Sub = m_sChain;
		Sub.erase(0, nPos);
		if (Sub.find(sSubStr)) { return Sub.rfind(sSubStr) + nPos; }
		else { return -1; }
	}
};