#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <ddkernel.h>
#include <kernelspecs.h>

#include <tchar.h>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	TCHAR File[256] = { 0 };

	OPENFILENAME Box;
	Box.lStructSize = sizeof(OPENFILENAME);
	Box.hwndOwner = NULL;
	Box.hInstance = NULL;
	Box.lpstrFilter = NULL;
	Box.lpstrCustomFilter = NULL;
	Box.nMaxCustFilter = NULL;
	Box.nFilterIndex = 0;
	Box.lpstrFile = &File[0];
	Box.nMaxFile = 256;
	Box.lpstrFileTitle = NULL;
	Box.nMaxFileTitle = NULL;
	Box.lpstrInitialDir = NULL;
	Box.lpstrTitle = NULL;
	Box.Flags = OFN_EXPLORER;
	Box.nFileOffset = 0;
	Box.nFileExtension = 0;
	Box.lpstrDefExt = NULL;
	Box.lCustData = NULL;
	Box.lpfnHook = NULL;
	Box.lpTemplateName = NULL;

	GetOpenFileName(&Box);//необходимо указать положение файла git-cmd.exe

	string s;
	//LPTSTR szCmdlin = _tcsdup(TEXT("C: \\ Git \\git-cmd.exe "));
	LPTSTR sk = _tcsdup(TEXT("cd C:\\1\\preact & git tag>st2.txt"));
	CreateProcess(Box.lpstrFile, sk, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	ifstream fin;
	fin.open("C:\\1\\preact\\st2.txt");
	string cy = "%";
	ofstream fo;
	fo.open("C:\\1\\preact\\s3.hml");
	fo << "<root>\r\n";
	fin >> s;
	while (!fin.eof()) {
		string s3 = "cd C:\\1\\preact & git show -s -";
		s3 = s3 + "-format=" + '\u0022' + cy + "ad";
		s3 = s3 + '\u0022' + " " + s + " >ss.txt";
		int j = s3.length();
		TCHAR* pBuffer = new TCHAR[j];

		for (int i = 0; i < j; i++) {
			pBuffer[i] = (char)s3[i];
		}
		CreateProcess(Box.lpstrFile, pBuffer, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		ifstream fin2;
		fin2.open("C:\\1\\preact\\ss.txt");
		string s2;
		fo << "<tag name=";
		fo << '\u0022';
		fo << s + '\u0022' + " date=" + '\u0022';
		fin2 >> s2;
		fo << s2 << " ";
		fin2 >> s2;
		fo << s2 << " ";
		fin2 >> s2;
		fo << s2 << " ";
		fin2 >> s2;
		fin2 >> s;
		fo << s << " ";
		fo << s2;
		fo << '\u0022';
		fo << '/';
		fo << '>';
		fo << "\r\n";
		fin2.close();
		fin >> s;
	}
	fo << '<';
	fo << '/';
	fo << "root>";
	fo.close();
	fin.close();
	return 0;
}
