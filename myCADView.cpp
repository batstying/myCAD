// myCADView.cpp : implementation of the CMyCADView class
//

#include "stdafx.h"
#include "myCAD.h"

#include "myCADDoc.h"
#include "myCADView.h"
#include "PenWidth.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMyCADApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyCADView

IMPLEMENT_DYNCREATE(CMyCADView, CView)

BEGIN_MESSAGE_MAP(CMyCADView, CView)
	//{{AFX_MSG_MAP(CMyCADView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_LINE, OnLine)
	ON_COMMAND(IDM_RECTANGLE, OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, OnEllipse)
	ON_COMMAND(IDM_PENWidth, OnPENWidth)
	ON_COMMAND(IDM_PEN_SOLID, OnPenSolid)
	ON_COMMAND(IDM_PEN_NULL, OnPenNull)
	ON_COMMAND(IDM_PEN_DOT, OnPenDot)
	ON_UPDATE_COMMAND_UI(IDM_PEN_SOLID, OnUpdatePenSolid)
	ON_UPDATE_COMMAND_UI(IDM_PEN_NULL, OnUpdatePenNull)
	ON_UPDATE_COMMAND_UI(IDM_PEN_DOT, OnUpdatePenDot)
	ON_COMMAND(IDM_PEN_DASH, OnPenDash)
	ON_UPDATE_COMMAND_UI(IDM_PEN_DASH, OnUpdatePenDash)
	ON_COMMAND(IDM_PENCOLOR, OnPencolor)
	ON_COMMAND(IDM_BRUSHCOLOR, OnBrushcolor)
	ON_COMMAND(IDM_BRU_SOLID, OnBruSolid)
	ON_UPDATE_COMMAND_UI(IDM_BRU_SOLID, OnUpdateBruSolid)
	ON_COMMAND(IDM_BRU_PATTERN, OnBruPattern)
	ON_UPDATE_COMMAND_UI(IDM_BRU_PATTERN, OnUpdateBruPattern)
	ON_COMMAND(IDM_BRU_NULL, OnBruNull)
	ON_UPDATE_COMMAND_UI(IDM_BRU_NULL, OnUpdateBruNull)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCADView construction/destruction

CMyCADView::CMyCADView()
{
	// TODO: add construction code here

    m_isDraw = FALSE;
    m_hCur   = NULL;
    m_pShape = NULL;
    m_pFactory = NULL;

    InitPenAndBrush();
}

CMyCADView::~CMyCADView()
{
    CMyCADDoc* pDoc = GetDocument();
    IShape* pShape;

    if (m_pFactory != NULL)
    {
        delete m_pFactory;
        m_pFactory = NULL;
    } 

    POSITION pos = pDoc->m_pShapeLst.GetHeadPosition();
    
    while(pos)
    {
        pShape = pDoc->m_pShapeLst.GetNext(pos);     
        ASSERT(pShape != NULL);
        delete pShape;
        pShape = NULL;
    }

}

void CMyCADView::InitPenAndBrush()
{
    //��ʼ����������
    m_penColor   = RGB(0,0,0);
    m_nWidth = 1;
    m_nPenIndex = PS_SOLID;

    m_nPenStyle = 0;
    
    //��ʼ��ˢ������
    m_logBrush.lbColor = RGB(255,255,255);
    m_logBrush.lbStyle = BS_HOLLOW;
    m_logBrush.lbHatch = HS_VERTICAL;
}

BOOL CMyCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyCADView drawing

void CMyCADView::OnDraw(CDC* pDC)
{
	CMyCADDoc* pDoc = GetDocument();
//     CLine line;
//     CRectangle rectangel;
    IShape* pShape = NULL;

	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    /*
    ˫�����ͼ������ػ������ʱ����ʾ��˸���⣩
    1������һ���ڴ�DC��������ʾDC
    2������һ������Ļ��ʾ���ݵ�λͼ
    3���ڴ�dc����λͼ
    4������bmpλͼ��ɫΪ��ʾ����ɫ
    5�����ڴ��л�ͼ
    6����BitBlt���ڴ�DC�е�bmp������ʾDC��
    �൱��ֻ��һ�Σ����ԾͲ�������˸�������ˡ�    
    */

    CDC dcMemory;//�ڴ�DC
    CBitmap MemBitmap;//λͼ

    dcMemory.CreateCompatibleDC(pDC);//�ڴ�DC������ʾDC

    CRect rc;
    GetClientRect(&rc);
    //����һ������Ļ��ʾ���ݵ�λͼ
    MemBitmap.CreateCompatibleBitmap(pDC,rc.Width(),rc.Height());
     
    //�ڴ�dc����λͼ��λͼ���൱�ڻ���
    CBitmap* pOldBitmap = dcMemory.SelectObject(&MemBitmap);

    //����bmpλͼ��ɫΪ��ʾ����ɫ
    dcMemory.FillSolidRect(0,0,rc.Width(),rc.Height(),RGB(255,255,255));

    //���л�ͼ���������ڴ��н���
    POSITION pos = pDoc->m_pShapeLst.GetHeadPosition();

    while(pos)
    {
       //line = pDoc->m_LineLst.GetNext(pos);
       //line.OnDraw(&dcMemory);
//         rectangel = pDoc->m_RectangleLst.GetNext(pos);
//         rectangel.OnDraw(&dcMemory);
        pShape = pDoc->m_pShapeLst.GetNext(pos);

        ASSERT(pShape != NULL);
        pShape->OnDraw(&dcMemory);
    }

    if (m_pShape != NULL)
    {
        m_pShape->OnDraw(&dcMemory);
    }
    
  
    //����֮����BitBltһ����������Ļ��
    int isSucess = pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &dcMemory, 
        0, 0, SRCCOPY);
    
    if (isSucess == 0)
    {
        return ;
    }
}

/////////////////////////////////////////////////////////////////////////////
// CMyCADView printing

BOOL CMyCADView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyCADView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyCADView diagnostics

#ifdef _DEBUG
void CMyCADView::AssertValid() const
{
	CView::AssertValid();
}

void CMyCADView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCADDoc* CMyCADView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCADDoc)));
	return (CMyCADDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCADView message handlers

//�޸�ע�ᴰ����Ĺ������
void CMyCADView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
    DWORD dwErr;

    m_hCur = ::LoadCursor(NULL,MAKEINTRESOURCE(IDC_CROSS));

    //dwErr = GetLastError();

    if (m_hCur == NULL)
    {
        return;
    }

    dwErr = ::SetClassLong(GetSafeHwnd(),GCL_HCURSOR,(long)m_hCur);

    if (dwErr == 0)
    {
        return;
    }	
}

void CMyCADView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

    if (m_isDraw)
    {
         CClientDC dc(this);

         if (m_pShape != NULL)
         {
            m_pShape->OnMouseMove(nFlags,point);
         }
                  
         OnDraw(&dc);
    }
    
    CView::OnMouseMove(nFlags, point);
}

void CMyCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    
    SetCapture();
    m_isDraw = TRUE;

    if (m_pFactory != NULL)
    {
        m_pShape = m_pFactory->CreateShape();
    }
    
    if (m_pShape != NULL)
    {
        m_pShape->setBrush(&m_logBrush);
        m_pShape->setPen(m_nPenIndex,m_nWidth,m_penColor);
        m_pShape->OnLButtonDown(nFlags,point);
    }
    
	
	CView::OnLButtonDown(nFlags, point);
}

void CMyCADView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	
    m_isDraw = FALSE;

    if (m_pShape != NULL)
    {
        m_pShape->OnLButtonUp(nFlags,point);
    }
    
    ReleaseCapture();
    
    CMyCADDoc* pDoc = GetDocument();   

    if (m_pShape != NULL)
    {
        pDoc->m_pShapeLst.AddTail(m_pShape);
    }
    
    CClientDC dc(this);
    OnDraw(&dc);
    
	CView::OnLButtonUp(nFlags, point);
}

void CMyCADView::OnLine() 
{
    if (m_pFactory != NULL)
    {
        delete m_pFactory;
        m_pFactory = NULL;
    }

    InitPenAndBrush();
    m_pFactory = new CLineFactory();
}

void CMyCADView::OnRectangle() 
{
    if (m_pFactory != NULL)
    {
        delete m_pFactory;
        m_pFactory = NULL;
    }

    InitPenAndBrush();
	m_pFactory = new CRectFactroy();
}

void CMyCADView::OnEllipse() 
{
    if (m_pFactory != NULL)
    {
        delete m_pFactory;
        m_pFactory = NULL;
    }
    
    InitPenAndBrush();
	m_pFactory = new CEllFactroy();	
	
}

void CMyCADView::OnPENWidth() 
{
	// TODO: Add your command handler code here

    CPenWidth dlg;

    dlg.m_nWidth = m_nWidth;
    UpdateData(FALSE);
    
    if (dlg.DoModal() == IDOK)
    {
        UpdateData(TRUE);
        m_nWidth = dlg.m_nWidth;
    }

}

void CMyCADView::OnPenSolid() 
{
	// TODO: Add your command handler code here
	m_nPenStyle = 0;
    m_nPenIndex = PS_SOLID;
}

void CMyCADView::OnPenDot() 
{
	// TODO: Add your command handler code here
	m_nPenStyle = 1;
    m_nPenIndex = PS_DOT;
}

void CMyCADView::OnPenDash() 
{
    // TODO: Add your command handler code here
    m_nPenStyle = 2;
    m_nPenIndex = PS_DASH;    
}

void CMyCADView::OnPenNull() 
{
    // TODO: Add your command handler code here
    m_nPenStyle = 3;
    m_nPenIndex = PS_NULL;
}

void CMyCADView::OnUpdatePenSolid(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio( 0 == m_nPenStyle );
}

void CMyCADView::OnUpdatePenDot(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio( 1 == m_nPenStyle );
}

void CMyCADView::OnUpdatePenDash(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio( 2 == m_nPenStyle );
}

void CMyCADView::OnUpdatePenNull(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->SetRadio( 3 == m_nPenStyle );
}

void CMyCADView::OnPencolor() 
{
    CColorDialog dlg;
       
    if (dlg.DoModal() == IDOK)
    {
        m_penColor = dlg.GetColor();
    }	
}

void CMyCADView::OnBrushcolor() 
{
    CColorDialog dlg;
    
    if (dlg.DoModal() == IDOK)
    {
        m_logBrush.lbColor = dlg.GetColor();
    }	
}

void CMyCADView::OnBruSolid() 
{
	// TODO: Add your command handler code here
    m_nBruStyle = 0;
    m_logBrush.lbStyle = BS_SOLID;
}

void CMyCADView::OnUpdateBruSolid(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio( 0 == m_nBruStyle );
}

void CMyCADView::OnBruPattern() 
{
	// TODO: Add your command handler code here
    m_nBruStyle = 1;
    m_logBrush.lbStyle = BS_PATTERN;	
}

void CMyCADView::OnUpdateBruPattern(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    pCmdUI->SetRadio( 1 == m_nBruStyle );
	
}

void CMyCADView::OnBruNull() 
{
	// TODO: Add your command handler code here
    m_nBruStyle = 2;
    m_logBrush.lbStyle = BS_NULL;	
}

void CMyCADView::OnUpdateBruNull(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    pCmdUI->SetRadio( 2 == m_nBruStyle );
	
}
