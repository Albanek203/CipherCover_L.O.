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
void ShowAllLinks(CWorkspace& ws){
	ws.ShowAllLinks();
}

void Find(CWorkspace& ws) {
	int nPos;
	string str;
	cout << "Enter the ribbon we are looking for:";
	cin >> str;
	cout << "Indicate from which position we will start searching:";
	cin >> nPos;
	int temp = ws.Find(str.c_str(), nPos);
	if (temp == -1) { cout << "Unfortunately, there is no such tape"; }
	else { cout << "The tape at position " << temp << " is required"; }
}

int main(){
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Show links", ShowAllLinks);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);
	mgr.RegisterCommand("Find", Find);
	mgr.Run();
	return 0;

}