#include <iostream>
#include <string> 

using namespace std;
class CDataChain {
public:
	//CDataChain(void);
	//virtual ~CDataChain(void);
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;

	//повертає довжину згенерованої послідовності цифр.
	//virtual size_t GetLength();

	////повертає позицію входження підстрічки sSubStr починаючи із nPos.
	//// -1, якщо підстрічки не знайдено
	//virtual int Find(const char* sSubStr, int nPos = 0);

	////повертає підстрічку починаючи із nPos довжиною nLength. або до кінця послідовності
	//virtual string GetSubStr(int nPos, int nLength = -1);

	//повертає всю згенеровану послідовність цифр
	virtual const char* GetFullString() = 0;
	virtual void Assignment(string str) = 0;
protected:
	string m_sChain;
};

class CDataSimple : public CDataChain {
public:
	void Generate(int nDepth, int nMaxLength = 0) override {
		for (int iter = 0; iter <= nDepth; iter++) {
			if (size(m_sChain) >= nMaxLength) { break; }
			m_sChain += to_string(iter);
		}
	}
	const char* GetFullString() override { return m_sChain.c_str(); }
	void Assignment(string str) { m_sChain = str; }
};