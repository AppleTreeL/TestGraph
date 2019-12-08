
// TestGraphView.h : CTestGraphView 类的接口
//

#pragma once


class CTestGraphView : public CView
{
protected: // 仅从序列化创建
	CTestGraphView();
	DECLARE_DYNCREATE(CTestGraphView)

// 特性
public:
	CTestGraphDoc* GetDocument() const;

// 操作
public:
	//TODO

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	void DrawTaiJiFish(CDC* pDC);
	virtual ~CTestGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TestGraphView.cpp 中的调试版本
inline CTestGraphDoc* CTestGraphView::GetDocument() const
   { return reinterpret_cast<CTestGraphDoc*>(m_pDocument); }
#endif

