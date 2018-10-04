
// readImageView.h : interface of the CreadImageView class
//

#pragma once


class CreadImageView : public CView
{
protected: // create from serialization only
	CreadImageView();
	DECLARE_DYNCREATE(CreadImageView)

// Attributes
public:
	CreadImageDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CreadImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditGammaCorrection();
};

#ifndef _DEBUG  // debug version in readImageView.cpp
inline CreadImageDoc* CreadImageView::GetDocument() const
   { return reinterpret_cast<CreadImageDoc*>(m_pDocument); }
#endif

