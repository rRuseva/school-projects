#pragma once


// GammaCorrecDialog dialog

class GammaCorrection : public CDialogEx
{
	DECLARE_DYNAMIC(GammaCorrection)

public:
	GammaCorrection(CWnd* pParent = NULL);   // standard constructor
	virtual ~GammaCorrection();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMMA_CORREC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	double gamma;
	double factor;
};
