
// TestImGuiView.h: CTestImGuiView 클래스의 인터페이스
//

#pragma once

class CTestImGuiView : public CView
{
protected: // serialization에서만 만들어집니다.
	CTestImGuiView() noexcept;
	DECLARE_DYNCREATE(CTestImGuiView)
// 특성입니다.
public:
	CTestImGuiDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CTestImGuiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // TestImGuiView.cpp의 디버그 버전
inline CTestImGuiDoc* CTestImGuiView::GetDocument() const
   { return reinterpret_cast<CTestImGuiDoc*>(m_pDocument); }
#endif

