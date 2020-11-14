#include "CWorkspace.cpp"
#include "CDlgCommand.cpp"
using namespace std;

#define EXTENSION() (".txt")

void Init(CWorkspace& ws) {
	int Depth, Lengh;
	cout << "Enter Depth:";
	cin >> Depth;
	cout << "Enter Lengh:";
	ws.Init(Depth, Lengh);
}
void Save(CWorkspace& ws) {
	string name_file;
	cout << "Enter a name for the file where the data will be stored:";
	cin >> name_file;
	name_file += EXTENSION();
	cout << ws.Save(name_file)<<endl;
}
void Load(CWorkspace& ws) {
	string name_file;
	cout << "Enter the name of the file from which the data will be downloaded:";
	cin >> name_file;
	name_file += EXTENSION();
	cout << ws.Load(name_file) << endl;
}
void ShowFullSequence(CWorkspace& ws) {
	cout << ws.GetChainString() << endl;
}

int main(){
	/*CDataSimple data;
	data.Generate(2, 5);
	CWorkspace ws(data);
	string a = "text.txt";
	ws.Save(a);
	return 0;*/
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