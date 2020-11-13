#include "CWorkspace.cpp"
using namespace std;

int main(){
	CDataSimple data;
	data.Generate(2, 5);
	CWorkspace ws(data);
	string a = "text.txt";
	ws.Save(a);
	return 0;
}