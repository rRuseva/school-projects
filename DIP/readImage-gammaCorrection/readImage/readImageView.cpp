
// readImageView.cpp : implementation of the CreadImageView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "readImage.h"
#endif

#include "readImageDoc.h"
#include "readImageView.h"

#include "GammaCorrection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CreadImageView

IMPLEMENT_DYNCREATE(CreadImageView, CView)

BEGIN_MESSAGE_MAP(CreadImageView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EDIT_GAMMACORRECTION, &CreadImageView::OnEditGammaCorrection)
END_MESSAGE_MAP()

// CreadImageView construction/destruction

CreadImageView::CreadImageView()
{
	// TODO: add construction code here

}

CreadImageView::~CreadImageView()
{
}

BOOL CreadImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CreadImageView drawing

void CreadImageView::OnDraw(CDC* pDC)
{
	CreadImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOut(0, 10, "Original Image");
	CString str;
	str.Format("Gamma corrected image with gamma = %g and coefficient = %g", pDoc->gamma, pDoc->factor);
	if (pDoc->columns)
		pDC->TextOut(pDoc->columns + 20, 10, str);

	for (int y = 0; y < pDoc->rows; y++){
		for (int x = 0; x < pDoc->columns; x++){
			//draw original image
			short int gl = pDoc->img[x][y];
			pDC->SetPixel(x,y+50,RGB(gl, gl, gl));

			//drawgamma corrected image
			short int px = pDoc->newImg[x][y];
			pDC->SetPixel(x + pDoc->columns + 5, y + 50, RGB(px, px, px));
		}

	}
}

void CreadImageView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CreadImageView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CreadImageView diagnostics

#ifdef _DEBUG
void CreadImageView::AssertValid() const
{
	CView::AssertValid();
}

void CreadImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CreadImageDoc* CreadImageView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CreadImageDoc)));
	return (CreadImageDoc*)m_pDocument;
}
#endif //_DEBUG


// CreadImageView message handlers


void CreadImageView::OnEditGammaCorrection()
{
	// TODO: Add your command handler code here
	CreadImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	GammaCorrection G;
	G.factor = pDoc->factor;
	G.gamma = pDoc->gamma;

	int result = G.DoModal();
	if (result == IDOK)
	{
		pDoc->factor = G.factor;
		pDoc->gamma = G.gamma;

		pDoc->CalcGammaCorrection();
		Invalidate();
	}
}
