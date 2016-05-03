


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

////////////////////////////////INCLUDE FILES////////////////////////////////
#include"Main.h"
#include"Functions.h"
////////////////////////////////INCLUDE FILES////////////////////////////////





////////////////////////////////START WINMAIN////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow)
{
  
	
	DialogBox(hInst, MAKEINTRESOURCE(IDD_PASSWORD), NULL, (DLGPROC)DlgPasswordProc );
	
	if(!CorrectPassword) return false;

	splash(hInstance);
	
	App_Init();
	
////////////////////////////////FILL WINDOW CLASS////////////////////////////////
		
  //DECLARE WINDOW CLASS
	WNDCLASS wndWc;
  
	wndWc.style = CS_OWNDC |CS_HREDRAW | CS_VREDRAW;
	wndWc.lpfnWndProc = (WNDPROC) WndProc;
	wndWc.cbClsExtra = 0;
	wndWc.cbWndExtra = 0;
	wndWc.hInstance =hInstance;
	wndWc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON));
	wndWc.hCursor = LoadCursor(0, IDC_ARROW);
	wndWc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndWc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wndWc.lpszClassName = "EncDec";

	//REGISTER WINDOW CLASS
	RegisterClass(&wndWc);
	
////////////////////////////////FILL WINDOW CLASS////////////////////////////////
  
 
////////////////////////////////CREATE MAIN WINDOW////////////////////////////////
  
	hWnd = CreateWindow("EncDec", "E N C R Y P T  /  D E C R Y P T",WS_OVERLAPPEDWINDOW,rc.left,rc.top, 450,300,NULL, NULL, hInst, NULL);
  
	//SHOW WINDOW
	ShowWindow(hWnd, SW_SHOW);
	
////////////////////////////////CREATE MAIN WINDOW////////////////////////////////
 
	
	//SPLASH TIMER
	splashTimer();
  


////////////////////////////////MAIN LOOP////////////////////////////////  
	while(GetMessage(&Msg,NULL,0,0))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
////////////////////////////////MAIN LOOP//////////////////////////////// 



	//RELEASE WINDOW
	DestroyWindow(hWnd);


  
  return Msg.wParam;
}

////////////////////////////////END WINMAIN////////////////////////////////


////////////////////////////////START WNDPROC////////////////////////////////

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)

{

  switch(Msg)
  {
	
////////////////////////////////WM_CREATE////////////////////////////////
	case WM_CREATE:
		{	
			
		ENC		=	CreateWindow("Button","E    N    C    R    Y    P    T",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,2,220,215,25,hWnd,(HMENU)ID_ENC,hInst,0);
		
		DEC		=	CreateWindow("Button","D    E    C    R    Y    P    T",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,225,220,215,25,hWnd,(HMENU)ID_DEC,hInst,0);

		KEY		=	CreateWindow("Button","Key...",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,20,150,60,22,hWnd,(HMENU)ID_KEY,hInst,0);

		KEY2	=	CreateWindow("Button","Key...",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,360,150,60,22,hWnd,(HMENU)ID_KEY,hInst,0);

		INF		=	CreateWindow("Button","InFile...",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,20,40,60,22,hWnd,(HMENU)ID_INF,hInst,0);

		INF2	=	CreateWindow("Button","InFile...",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,360,40,60,22,hWnd,(HMENU)ID_INF,hInst,0);
		
		OUF		=	CreateWindow("Button","OutFile...",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,20,95,60,22,hWnd,(HMENU)ID_OUF,hInst,0);

		OUF2	=	CreateWindow("Button","OutFile...",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,360,95,60,22,hWnd,(HMENU)ID_OUF,hInst,0);

		E1		=	CreateWindow("Edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER ,85,40,270,22,hWnd,(HMENU)ID_E1,hInst,0);
		
		E2		=	CreateWindow("Edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER ,85,95,270,22,hWnd,(HMENU)ID_E2,hInst,0);

		E3		=	CreateWindow("Edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER ,85,150,270,22,hWnd,(HMENU)ID_E3,hInst,0);

		break;
		}
////////////////////////////////WM_CREATE////////////////////////////////

////////////////////////////////WM_COMMAND////////////////////////////////
  
	case WM_COMMAND:
		{
			
			switch(HIWORD(wParam))
			
				{
			
				case BN_CLICKED:
				
					switch(LOWORD(wParam))
				
						{
				
						case ID_ENC:
					
						{
						
							Encrypt();
							break;
						}
				
						case ID_DEC:
						
						{
							Decrypt();	
							break;
						}
				
				
						case ID_INF:
						
						{
							InFileOpen();			
							break;
						}
				
						case ID_OUF:
						
						{
							OutFileOpen();
							break;
						}
			
						case ID_KEY:
						{
							KeyFileOpen();
							break;
						}
				
						case ID_ABOUT:
						{
							DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUT), NULL, (DLGPROC)DlgAboutProc );
							break;
						}
				
						case IDM_EXIT:
						{
							Exit();
							break;	
						}

					
						}//switch(LOWORD(wParam))
				
					}//switch(HIWORD(wParam))
				break;
			}
	
////////////////////////////////WM_COMMAND////////////////////////////////	
	

////////////////////////////////WM_DESTROY//////////////////////////////// 	

	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

////////////////////////////////WM_DESTROY//////////////////////////////// 

		
////////////////////////////////WM_KEYDOWN////////////////////////////////  
  
	case WM_KEYDOWN:
		{

			switch (wParam)
				{
					case VK_ESCAPE:
					{
					PostQuitMessage(0);
					break;
					}
				}
		break;
		}
	
////////////////////////////////WM_KEYDOWN//////////////////////////////// 
  
	
	
////////////////////////////////WM_TIMER//////////////////////////////// 	
	
	case WM_TIMER:
		{
    		ShowWindow(SPL,SW_HIDE);
			KillTimer(hWnd,1);
			break;
		}
	
////////////////////////////////WM_TIMER//////////////////////////////// 
	
	
	
	}//switch(Msg)

 

  return DefWindowProc(hWnd,Msg,wParam,lParam);

}

////////////////////////////////END WNDPROC////////////////////////////////


////////////////////////////////START DLGPROC////////////////////////////////

LRESULT CALLBACK DlgPasswordProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	char Password[25]={0};							

    switch( message )										
    {
		case WM_INITDIALOG:											

			

            return TRUE;

		case WM_COMMAND:									
            
			switch( LOWORD( wParam ) )						
            {    
				case IDOK:									
					{


					GetDlgItemText(hwnd, IDC_PASSWORD, Password, 25);
															
															
					if(!strcmp(Password, "Password") || !strcmp(Password, "password"))
					{						
						CorrectPassword = true;			
						EndDialog( hwnd, FALSE );			
					}
					else 
					{										
						MessageBox(hwnd, "InValid password!(The Password is 'password')", "E    R    R    O    R    !", MB_OK);
					}										

					return TRUE;							
					}
				case IDCANCEL:								
					{
					int response;
					
					response=MessageBox(hwnd, "Are You Sure?", "E    R    R    O    R    !?!", MB_YESNO);
					
					if(response==IDYES)
					{
					EndDialog( hwnd, FALSE );				
					}
					return TRUE;						
					}
			}
            break;

        case WM_CLOSE:										
			{
			EndDialog( hwnd, FALSE );						
            
			break;
			}
		case WM_DESTROY:									
			
			break;											
    }

    return FALSE;											
}

////////////////////////////////END DLGPROC////////////////////////////////


////////////////////////////////START DLGABOUTPROC////////////////////////////////

LRESULT CALLBACK DlgAboutProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		
		case WM_INITDIALOG:											

			return TRUE;
	
	
		case WM_COMMAND:
			{
				switch( LOWORD( wParam ) )
				{
				case IDOK:
					EndDialog(hwnd,FALSE);
				}
			break;
			}
		
		
		case WM_DESTROY:									
			
			break;
		
		case IDOK:
			{
				EndDialog(hwnd,FALSE);
				return TRUE;
			}
	}


return FALSE;
}

////////////////////////////////END DLGABOUTPROC////////////////////////////////