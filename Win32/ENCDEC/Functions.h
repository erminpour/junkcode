

/////////////////////////////ENCRYPT/DECRYPT///////////////////////////////////
//																			 //
//																			 //
//					THIS IS A SIMPLE ENCRYPTION/DECRYPTION					 //
//					WRITTEN USING THE WINDOWS API AND C/C++. 				 //
//																			 //
//					AUTHOR: VICTOR HUGO CASTRO								 //
//																			 //
//																			 //
///////////////////////////////////////////////////////////////////////////////





#ifndef FUNCTIONS_H
#define FUNCTIONS_H

////////////////////////////////INCLUDE FILES////////////////////////////////
#include "Main.h"
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<time.h>
#include<io.h>
////////////////////////////////INCLUDE FILES////////////////////////////////


////////////////////////////////START ENCRYPT////////////////////////////////

void Encrypt()
{
	
	///////////////////////////GET STRINGS FROM EDIT BOXES///////////////////////////
	GetDlgItemText(hWnd,ID_E1,InFile,_MAX_PATH);
	
	GetDlgItemText(hWnd,ID_E2,OutFile,_MAX_PATH);
	
	GetDlgItemText(hWnd,ID_E3,Key,_MAX_PATH);
	///////////////////////////GET STRINGS FROM EDIT BOXES///////////////////////////


	///////////////////////////EDIT BOX & FILE ERROR CHECK///////////////////////////
	if(false==strcmpi(InFile,OutFile)||false==strcmpi(InFile,Key)||false==strcmpi(OutFile,Key))
	{
		MessageBox(hWnd,"Files Must Not Be Equal!!!","E    R    R    O    R",MB_ICONEXCLAMATION);
	}
	
	else if(false==strcmpi(InFile,"")||false==strcmpi(Key,"")||false==strcmpi(OutFile,""))
	{

	MessageBox(hWnd,"You Must Specify A File!!!","E    R    R    O    R",MB_ICONEXCLAMATION);
	}
	
	else if((_access(InFile,0)==-1))
	{
		MessageBox(hWnd,"InFile Must Exist!!!","E    R    R    O    R",MB_ICONEXCLAMATION);
	}
	///////////////////////////EDIT BOX & FILE ERROR CHECK///////////////////////////
	
	
	else
	{
	

		
		
	///////////////////////////GENERAL DATA TYPES///////////////////////////
	int count;
	int index=0;
	int *Matrix;
	Matrix = new int[MAX];
	///////////////////////////GENERAL DATA TYPES///////////////////////////


	///////////////////////////FSTREAM VARIABLES & OPENING///////////////////////////
	fstream KeyFile1;
	FILE *in,*out;

	KeyFile1.open(Key,ios::out);
	
	in=fopen(InFile,"rb");
	out=fopen(OutFile,"wb");
	///////////////////////////FSTREAM VARIABLES & OPENING///////////////////////////
	
	

	
	
	///////////////////////////POPULATE MATRIX///////////////////////////
	srand(time(NULL));
	
	for(index=0;index<MAX;index++)
		{
			Matrix[index]=rand()%63000000;
			KeyFile1<<Matrix[index]<<endl;
		}
	///////////////////////////POPULATE MATRIX///////////////////////////	
	

	
	
	///////////////////////////ENCRYPTION LOOP///////////////////////////
	while((count = getc(in)) != EOF)
    {
		
		for(index=0;index<MAX;index++)
		{
			count = (count^Matrix[index]);
		
		}
		
		putc(count,out);
	}
	///////////////////////////ENCRYPTION LOOP///////////////////////////
		
	
	///////////////////////////CLOSE FILES///////////////////////////
	fclose(in);
	fclose(out);
	KeyFile1.close();
	
	delete [] Matrix;
	///////////////////////////CLOSE FILES///////////////////////////
	
	
	///////////////////////////CONFIRMATION MESSAGE BOX///////////////////////////
	
	MessageBox(hWnd,"Encryption Was Made and Files Were Closed","S  U  C  C  E  S  S",MB_ICONINFORMATION);
	
	///////////////////////////CONFIRMATION MESSAGE BOX///////////////////////////
	
	
	}//End else


}
////////////////////////////////END ENCRYPT////////////////////////////////


////////////////////////////////START DECRYPT////////////////////////////////

void Decrypt()
{

	///////////////////////////GET STRINGS FROM EDIT BOXES///////////////////////////
	GetDlgItemText(hWnd,ID_E1,InFile,_MAX_PATH);
	
	GetDlgItemText(hWnd,ID_E2,OutFile,_MAX_PATH);
	
	GetDlgItemText(hWnd,ID_E3,Key,_MAX_PATH);
	///////////////////////////GET STRINGS FROM EDIT BOXES///////////////////////////


	///////////////////////////EDIT BOX & FILE ERROR CHECK///////////////////////////
	if(false==strcmpi(InFile,OutFile)||false==strcmpi(InFile,Key)||false==strcmpi(OutFile,Key))
	{
		MessageBox(hWnd,"Files Must Not Be Equal!!!","E    R    R    O    R",MB_ICONEXCLAMATION);
	}
	
	else if(false==strcmpi(InFile,"")||false==strcmpi(Key,"")||false==strcmpi(OutFile,""))
	{

	MessageBox(hWnd,"You Must Specify A File!!!","E    R    R    O    R",MB_ICONEXCLAMATION);
	}
	
	else if((_access(InFile,0)==-1)||(_access(Key,0)==-1))
	{
		MessageBox(hWnd,"InFile And Key Must Exist!!!","E    R    R    O    R",MB_ICONEXCLAMATION);
	}
	///////////////////////////EDIT BOX & FILE ERROR CHECK///////////////////////////

	else
	{

	///////////////////////////GENERAL DATA TYPES///////////////////////////
	int count;
	int index=0;
	int *Matrix;
	Matrix = new int[MAX];
	///////////////////////////GENERAL DATA TYPES///////////////////////////


	///////////////////////////FSTREAM VARIABLES & OPENING///////////////////////////
	fstream KeyFile1;
	FILE *in,*out;

	KeyFile1.open(Key,ios::in);
	
	in=fopen(InFile,"rb");
	out=fopen(OutFile,"wb");
	///////////////////////////FSTREAM VARIABLES & OPENING///////////////////////////
		
	
	
	///////////////////////////POPULATE MATRIX///////////////////////////
	srand(time(NULL));
	
	for(index=0;index<MAX;index++)
		{
			
			KeyFile1>>Matrix[index];
			
		}
	///////////////////////////POPULATE MATRIX///////////////////////////

	
	
	///////////////////////////DECRYPTION LOOP///////////////////////////
	while((count = getc(in)) != EOF)
    {
		
		for(index=0;index<MAX;index++)
		{
			count = (count^Matrix[index]);
		}
		

		putc(count,out);
		   
	}
	///////////////////////////DECRYPTION LOOP///////////////////////////

	
	///////////////////////////CLOSE FSTREAMS///////////////////////////
	fclose(in);
	fclose(out);

	KeyFile1.close();
	
	delete [] Matrix;
	///////////////////////////CLOSE FSTREAMS///////////////////////////
	
	
	///////////////////////////CONFIRMATION MESSAGE BOX///////////////////////////
	
	MessageBox(hWnd,"Decryption Was Made and Files Were Closed","S  U  C  C  E  S  S",MB_ICONINFORMATION);
	
	///////////////////////////CONFIRMATION MESSAGE BOX///////////////////////////
	
	}//End else
	
}

////////////////////////////////END DECRYPT////////////////////////////////



////////////////////////////////START APP_INIT////////////////////////////////
void App_Init(void)
{
		ofn.lStructSize       = sizeof (OPENFILENAME);
		ofn.hwndOwner         = hWnd;
		ofn.hInstance         = NULL;
		ofn.lpstrFilter       = "All Files (*.*)\0*.*\0\0";
		ofn.lpstrCustomFilter = NULL;
		ofn.nMaxCustFilter    = 0;
		ofn.nFilterIndex      = 0;
		ofn.lpstrFile         = szFilePath;
		ofn.nMaxFile          = _MAX_PATH;
		ofn.lpstrFileTitle    = szFileTitle;
		ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT;
		ofn.lpstrInitialDir   = NULL;
		ofn.lpstrTitle        = TEXT("Choose A File To Be Encrypted");
		ofn.Flags             = OFN_FILEMUSTEXIST;
		ofn.nFileOffset       = 0;
		ofn.nFileExtension    = 0;
		ofn.lpstrDefExt       = NULL;
		ofn.lCustData         = 0L; 
		ofn.lpfnHook          = NULL;
		ofn.lpTemplateName    = NULL;
}
	
////////////////////////////////END APP_INIT////////////////////////////////


////////////////////////////////START GETFILES////////////////////////////////

bool GetFiles(void)
{
		szFilePath[0] = '\0';
		szFileTitle[0] = '\0';

		GetOpenFileName(&ofn);

		if(szFilePath[0] == '\0')
			return(false);
		else
			{
				strcpy(szPath, szFilePath);
				return(true);
			}

}

////////////////////////////////END GETFILES////////////////////////////////



////////////////////////////////START SPLASH////////////////////////////////

void splash(HINSTANCE &hInstance)
{
	hbitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP));
    SPL = CreateWindowEx(WS_EX_TOPMOST,"STATIC", "SPLASH", WS_BORDER | SS_BITMAP|WS_POPUP,rc.left-70,rc.top-30,0,0,0,0,hInstance,0);
    SendMessage(SPL, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbitmap);
    ShowWindow(SPL, SW_SHOW);
    UpdateWindow(SPL);
}


////////////////////////////////END SPLASH////////////////////////////////


////////////////////////////////START SPLASHTIMER////////////////////////////////
void splashTimer(void)
{
	SetTimer(hWnd,1,1500,NULL);
}

////////////////////////////////END SPLASHTIMER////////////////////////////////



////////////////////////////////START INFILEOPEN////////////////////////////////

void InFileOpen(void)
{
	if(GetFiles())
	{
										
		SetWindowText(E1, szPath);

		strcpy(szFilePathOut,szPath);
		strcat(szFilePathOut, ".enc");
							
		SetWindowText(E2, szFilePathOut);
										
		strcpy(szFilePathOut2,szPath);
		strcat(szFilePathOut2, ".key");

											
		SetWindowText(E3, szFilePathOut2);

		}
}

////////////////////////////////END INFILEOPEN////////////////////////////////


////////////////////////////////START OUTFILEOPEN////////////////////////////////
void OutFileOpen(void)
{
	if(GetFiles())
	{
		SetWindowText(E2,szPath);
	}
}

////////////////////////////////END OUTFILEOPEN////////////////////////////////


////////////////////////////////START KEYFILEOPEN////////////////////////////////
void KeyFileOpen(void)
{
	if(GetFiles())
	{
		SetWindowText(E3, szPath);
	}
}

////////////////////////////////END KEYFILEOPEN////////////////////////////////



////////////////////////////////START EXIT////////////////////////////////

void Exit(void)
{
	int response;
					
	response=MessageBox(hWnd,"Are You Sure You Want to Exit???","Exit",MB_YESNO|MB_ICONEXCLAMATION);
	
	if(response==IDYES)
	{
		PostQuitMessage(0);
	}
}

////////////////////////////////END EXIT////////////////////////////////


#endif