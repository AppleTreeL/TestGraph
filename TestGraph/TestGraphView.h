
// TestGraphView.h : CTestGraphView ��Ľӿ�
//

#pragma once


class CTestGraphView : public CView
{
protected: // �������л�����
	CTestGraphView();
	DECLARE_DYNCREATE(CTestGraphView)

// ����
public:
	CTestGraphDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	void DrawTaiJiFish(CDC* pDC);
	virtual ~CTestGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TestGraphView.cpp �еĵ��԰汾
inline CTestGraphDoc* CTestGraphView::GetDocument() const
   { return reinterpret_cast<CTestGraphDoc*>(m_pDocument); }
#endif

