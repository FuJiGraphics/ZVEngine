#include <iostream>
#include <string>
#include <Windows.h>

FILE *gnucmd;


void cmd(const std::string &cmdstr);

// Load DLL
typedef int(*FPADD)(int, int);
FPADD add;

HMODULE hDLL;
void LoadDLL(const std::string& path)
{

	char currentDirectory[260];
	GetCurrentDirectoryA(260, currentDirectory);
	std::string ppath = currentDirectory;
	ppath += "\\";
	ppath += path;
	hDLL = LoadLibraryA((ppath).c_str());
	add = (FPADD)GetProcAddress(hDLL, "add");
}


int main()
{
	//  -shared -lstdc++ -o layer.dll Layer.cpp -Wl,--output-def,Layer.def,--out-implib,Layer.a\n

	//std::string c = std::string("..\\Vendor\\mingw\\bin\\g++ -c");
	//gnucmd = _popen(c.c_str(), "w");
	//while (true)
	//{
	//	// std::cin.ignore(5, '\n');
	//	c = std::string("-shared -lstdc++ -o layer.dll Layer.cpp -Wl,--output-def,Layer.def,--out-implib,Layer.a");
	//	cmd(c);
	//	system("pause");
	//}
	//
	//_pclose(gnucmd);
	LoadDLL("layer.dll");
	std::cout << add(3, 2) << std::endl;
	system("pause");
}


void cmd(const std::string &cmdstr)
{
	fputs((cmdstr + "\n").c_str(), gnucmd);
	fflush(gnucmd);
}