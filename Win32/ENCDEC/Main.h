

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




#ifndef MAIN_H
#define MAIN_H

////////////////////////////////INCLUDE FILES////////////////////////////////
#include<windows.h>
#include<string.h>
#include<stdio.h>
////////////////////////////////INCLUDE FILES////////////////////////////////


////////////////////////////////PROC////////////////////////////////

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);


LRESULT CALLBACK DlgPasswordProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);


LRESULT CALLBACK DlgAboutProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
////////////////////////////////PROC////////////////////////////////


////////////////////////////////DEFINES////////////////////////////////
#define ID_ABOUT		100
#define ID_DEC			101
#define ID_E1			102
#define ID_E2			103
#define ID_E3			104
#define ID_ENC			105
#define ID_INF			106
#define ID_KEY			107
#define ID_OUF			108
#define IDB_BITMAP		109
#define IDI_ICON		110
#define IDM_EXIT		111
#define IDR_MENU1		112
#define IDD_PASSWORD	113
#define IDC_PASSWORD	114
#define IDD_ABOUT		115
#define MAX				512
////////////////////////////////DEFINES////////////////////////////////


////////////////////////////////HWND'S////////////////////////////////
HWND ABOUT	=	NULL;
HWND DEC	=	NULL;
HWND DLG	=	NULL;
HWND E1		=	NULL;
HWND E2		=	NULL;
HWND E3		=	NULL;
HWND ENC	=	NULL;
HWND hWnd	=	NULL;
HWND INF	=	NULL;
HWND INF2	=	NULL;
HWND KEY	=	NULL;
HWND KEY2	=	NULL;
HWND OUF	=	NULL;
HWND OUF2	=	NULL;
HWND SPL	=	NULL;
////////////////////////////////HWND'S////////////////////////////////


////////////////////////////////CHARACTER FILE STRINGS////////////////////////////////
char szFilePath[_MAX_PATH];
char szFilePathOut[_MAX_PATH];
char szFilePathOut2[_MAX_PATH];
char szFileTitle[_MAX_FNAME + _MAX_EXT];
char szPath[_MAX_PATH];
char InFile[_MAX_PATH];
char OutFile[_MAX_PATH];			
char Key[_MAX_PATH];			
////////////////////////////////CHARACTER FILE STRINGS////////////////////////////////


////////////////////////////////MISC////////////////////////////////

HBITMAP hbitmap;
HINSTANCE hInst;
OPENFILENAME ofn;
MSG Msg;
bool CorrectPassword = false;

////////////////////////////////MISC////////////////////////////////


////////////////////////////////SCREEN RESOLUTION////////////////////////////////

int iSw = (WORD)GetSystemMetrics(SM_CXSCREEN);       // WIDTH
int iSh = (WORD)GetSystemMetrics(SM_CYSCREEN);       // HEIGHT

////////////////////////////////SCREEN RESOLUTION////////////////////////////////
  

////////////////////////////////CENTER SCREEN RECT////////////////////////////////

RECT rc = { (iSw - 450)/2, (iSh - 450)/2, 450,450 };

////////////////////////////////CENTER SCREEN RECT////////////////////////////////



////////////////////////////////FUNCTIONS////////////////////////////////

void Encrypt();

void Decrypt();

void App_Init(void);

bool GetFiles(void);

void splash(HINSTANCE &hInstance);

void splashTimer(void);

void InFileOpen(void);

void OutFileOpen(void);

void KeyFileOpen(void);

void Exit(void);

////////////////////////////////FUNCTIONS////////////////////////////////



#endif

