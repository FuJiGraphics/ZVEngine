
// TestImGuiView.cpp: CTestImGuiView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TestImGui.h"
#endif

#include "TestImGuiDoc.h"
#include "TestImGuiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestImGuiView

IMPLEMENT_DYNCREATE(CTestImGuiView, CView)

BEGIN_MESSAGE_MAP(CTestImGuiView, CView)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTestImGuiView 생성/소멸

CTestImGuiView::CTestImGuiView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CTestImGuiView::~CTestImGuiView()
{
}

BOOL CTestImGuiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);

}

// CTestImGuiView 그리기

void CTestImGuiView::OnDraw(CDC* /*pDC*/)
{
	CTestImGuiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

}


// CTestImGuiView 진단

#ifdef _DEBUG
void CTestImGuiView::AssertValid() const
{
	CView::AssertValid();
}

void CTestImGuiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestImGuiDoc* CTestImGuiView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestImGuiDoc)));
	return (CTestImGuiDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestImGuiView 메시지 처리기


void CTestImGuiView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

}