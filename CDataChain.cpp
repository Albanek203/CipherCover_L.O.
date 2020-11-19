#include <iostream>
#include <string> 
#include <fstream>
#include <iomanip>
using namespace std;
class CDataChain {
public:
	CDataChain(void) {}
	virtual ~CDataChain(void) {}
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
	void Generate(int nDepth, int nMaxLength = 0) override {
		string gen = "";
		for (int iter = 0; iter <= nDepth; iter++) {
			if (size(gen) > nMaxLength) { break; }
			gen += to_string(iter);
		}
		m_sChain = gen + "\n";
	}
	const char* GetFullString() override { return m_sChain.c_str(); }
	void Assignment(string str) override { m_sChain = str; }
	int Find(const char* sSubStr, int nPos = 0) override {
		string Sub = m_sChain;
		Sub.erase(0, nPos);
		if (Sub.find(sSubStr)) { return Sub.rfind(sSubStr) + nPos; }
		else { return -1; }
	}
	size_t GetLength() override { return size(m_sChain); }
};

class CDataPi :public CDataChain {
public:
	void Generate(int nDepth, int nMaxLenght = 0) override {
		ifstream temp_r;
		ofstream temp_w;
		string str;
		temp_w.open("temp.txt");
		temp_w << setprecision(nMaxLenght) << 4. * atan(1.);
		temp_w.close();
		temp_r.open("temp.txt");
		getline(temp_r, str);
		temp_r.close();
		remove("temp.txt");
		str.erase(str.find('.'), 1);
		m_sChain = str + "\n";
	}
};