
// laba2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Claba2App:
// Сведения о реализации этого класса: laba2.cpp
//

class Claba2App : public CWinApp
{
public:
	Claba2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Claba2App theApp;
