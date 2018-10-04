
// readImageDoc.cpp : implementation of the CreadImageDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "readImage.h"
#endif

#include "readImageDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CreadImageDoc

IMPLEMENT_DYNCREATE(CreadImageDoc, CDocument)

BEGIN_MESSAGE_MAP(CreadImageDoc, CDocument)
END_MESSAGE_MAP()


// CreadImageDoc construction/destruction

CreadImageDoc::CreadImageDoc()
{
	// TODO: add one-time construction code here

}

CreadImageDoc::~CreadImageDoc()
{
}

BOOL CreadImageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	rows=0;
	columns=0;

	gamma = 2.5;
	factor = 1;

	return TRUE;
}



// CreadImageDoc serialization

void CreadImageDoc::Serialize(CArchive& ar)
{
	CString line,token;
	int pos;

	if (ar.IsStoring())
	{
		// TODO: add storing code here
		CalcGammaCorrection();
		CString output;
		output.Append("P2\n");
		output.AppendFormat("%d ", columns);
		output.AppendFormat("%d\n", rows);
		output.Append("255\n");
		int count = 0;
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				if (count < 17) {
					output.AppendFormat("%d ", newImg[x][y]);
				}
				else {
					output.Append("\n");
					count++;
				}
			}
		}
		
		ar.WriteString(output);

	}
	else
	{
		// TODO: add loading code here
		ar.ReadString(line);
		if (line.Left(2) != "P2")
		{
			AfxMessageBox("Unsupported format!");
			return;
		}

		ar.ReadString(line);
		while( line.Left(1) == "#") ar.ReadString(line);
		
		line.TrimLeft(_T(" "));
		pos = 0;

		token = line.Tokenize(_T(" "), pos);
		columns = _ttoi(token);

		token = line.Tokenize(_T(" "), pos);
		rows = _ttoi(token);

		ar.ReadString(line); line.Trim(" "); pos = 0;//255
		ar.ReadString(line); line.Trim(" "); pos = 0;
		
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < columns; x++)
			{
				if(pos >= line.GetLength())
				{
					ar.ReadString(line);
					line.Trim(" "); 
					pos = 0;
				}
				token = line.Tokenize(_T(" "), pos);			
				img[x][y] = _ttoi(token);
				newImg[x][y] = _ttoi(token);
			}
		}

	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CreadImageDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CreadImageDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CreadImageDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CreadImageDoc diagnostics

#ifdef _DEBUG
void CreadImageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CreadImageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CreadImageDoc commands


void CreadImageDoc::CalcGammaCorrection()
{
	double gCorrection = 1 / gamma;

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			short int gl = img[x][y];
			short int res = factor*255.0*pow(gl / 255.0, gCorrection);
			newImg[x][y] = res;
		}
	}
}
