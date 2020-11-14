#include <iostream>
#include <string>
#include "CDlgCommand.cpp"
using namespace std;

#define EXTENSION (".txt")

void Init(CWorkspace& ws) {
	int Depth, Lengh;
	cout << "Enter Depth:";
	cin >> Depth;
	cout << "Enter Lengh:";
	cin >> Lengh;
	ws.Init(Depth, Lengh);
}
void Save(CWorkspace& ws) {
	string name_file;
	cout << "Enter a name for the file where the data will be stored:";
	cin >> name_file;
	name_file += EXTENSION;
	if (ws.Save(name_file)) { cout << "Ok!"; }
	else { cout << "Error"; }
}
void Load(CWorkspace& ws) {
	string name_file;
	cout << "Enter the name of the file from which the data will be downloaded:";
	cin >> name_file;
	name_file += EXTENSION;
	if (ws.Load(name_file)) { cout << "Ok!"; }
}
void ShowFullSequence(CWorkspace& ws) {
	cout << ws.GetChainString() << endl;
}

int main(){
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);
	mgr.Run();
	return 0;

}