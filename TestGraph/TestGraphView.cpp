
// TestGraphView.cpp : CTestGraphView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TestGraph.h"
#endif

#include "TestGraphDoc.h"
#include "TestGraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestGraphView

IMPLEMENT_DYNCREATE(CTestGraphView, CView)

BEGIN_MESSAGE_MAP(CTestGraphView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTestGraphView 构造/析构

CTestGraphView::CTestGraphView()
{
	// TODO:  在此处添加构造代码

}

CTestGraphView::~CTestGraphView()
{
}

BOOL CTestGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTestGraphView 绘制

void CTestGraphView::OnDraw(CDC* pDC)
{
	CTestGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	CPen cpen(PS_SOLID, 5, RGB(255, 255, 0));
	CPen* org = pDC->SelectObject(&cpen);
	/*pDC->MoveTo(0, 0);
	pDC->LineTo(0, 30);*/
	CPoint p[7];
	p[0] = CPoint(-350, -100);
	p[1] = CPoint(-250, 100);
	p[2] = CPoint(0, 30);
	p[3] = CPoint(50, -50);
	p[5] = CPoint(350, -20);
	p[6] = CPoint(250, 130);
	double k = (p[3].y - p[2].y) / (p[3].x - p[2].x);
	double x = 90;
	double y = k * (x - p[3].x) + p[3].y;
	p[4] = CPoint(x, y);
	for (int  i = 0; i < 7; i++)
	{
		if (0 == i)
		{
			pDC->MoveTo(p[i]);
		}
		else
		{
			pDC->LineTo(p[i]);
		}
		pDC->Ellipse(p[i].x - 5, p[i].y - 5, p[i].x + 5, p[i].y + 5);
	}
	//设置蓝色笔
	CPen bluePen;
	bluePen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	org = pDC->SelectObject(&bluePen);
	pDC->PolyBezier(p, 7);
	pDC->SelectObject(&org);
}


// CTestGraphView 打印

BOOL CTestGraphView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTestGraphView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CTestGraphView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CTestGraphView 诊断

#ifdef _DEBUG
void CTestGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CTestGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestGraphDoc* CTestGraphView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestGraphDoc)));
	return (CTestGraphDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestGraphView 消息处理程序
