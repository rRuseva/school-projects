// GammaCorrection.cpp : implementation file
//

#include "stdafx.h"
#include "readImage.h"
#include "GammaCorrection.h"
#include "afxdialogex.h"


// GammaCorrection dialog

IMPLEMENT_DYNAMIC(GammaCorrection, CDialogEx)

GammaCorrection::GammaCorrection(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GAMMA_CORREC, pParent)
	, gamma()
	, factor()
{
	
}

GammaCorrection::~GammaCorrection()
{
	gamma ;
	factor;
}

void GammaCorrection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_GAMMA, gamma);
	DDV_MinMaxDouble(pDX, gamma, 0.1, 9.99);
	DDX_Text(pDX, IDC_EDIT_FACTOR, factor);
	DDV_MinMaxDouble(pDX, factor, 0, 100);
}

BOOL GammaCorrection::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  
}

BEGIN_MESSAGE_MAP(GammaCorrection, CDialogEx)
END_MESSAGE_MAP()


