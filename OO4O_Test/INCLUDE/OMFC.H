/* Copyright (c) 2003, Oracle Corporation.  All rights reserved.  */

/*
    This source code is provided as a debugging aid for developers
    who have purchased Oracle Objects for OLE    .  Please see the
    provided help file for documentation of these classes.

*/

/*
    Oracle Objects for OLE    
    C++ classes for bound Widget support
    MFC version
    
    CREATED    ********   11/22/94

*/

#ifndef OMFC_ORACLE
#define OMFC_ORACLE

#ifndef OBOUND_ORACLE
#include "obound.h"
#endif

#define OBOUND_READONLY   TRUE
#define OBOUND_READWRITE  FALSE

//-----------------------------
// OMFCBound: a derived OBound class for MFC

class OMFCBound : public OBound
{
public:
    OMFCBound(void);
    ~OMFCBound(void);
    
protected:
    oresult Subclass(CWnd *bwnd, CWnd *wnd, int itemid);
    BOOL IsBound(void) {return m_isbound;}
    BOOL   m_isbound;
};


//-----------------------------
// OBoundEdit: a bound edit control

class OBoundEdit : public CEdit, public OMFCBound
{
// Construction
public:
	OBoundEdit();
   
    // declarations of methods so that compiler won't implement these (which would be wrong)
    // at present we don't implement these either...
    OBoundEdit(const OBoundEdit &other);  // copy constructor
    OBoundEdit &operator=(const OBoundEdit &other);  // overloaded assignment

    oresult BindToControl(CWnd *wnd, int itemid) {return Subclass(this, wnd, itemid);}
    oresult SetProperty(BOOL mode=OBOUND_READWRITE);

// Implementation
public:
	virtual ~OBoundEdit();

protected:
	// Generated message map functions
	//{{AFX_MSG(OBoundEdit)
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    oresult Refresh(const OValue &val); 
    oresult SaveChange(void);
    BOOL    m_mode;    // readonly/readwrite mode
};


/////////////////////////////////////////////////////////////////////////////
// OBoundStatic: a bound static control

class OBoundStatic : public CStatic, public OMFCBound
{
// Construction
public:
	OBoundStatic();

    // declarations of methods so that compiler won't implement these (which would be wrong)
    // at present we don't implement these either...
    OBoundStatic(const OBoundStatic &other);  // copy constructor
    OBoundStatic &operator=(const OBoundStatic &other);  // overloaded assignment

    oresult BindToControl(CWnd *wnd, int itemid) {return Subclass(this, wnd, itemid);}

// Operations
public:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(OBoundStatic)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~OBoundStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(OBoundStatic)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    oresult Refresh(const OValue &val); 
    oresult SaveChange(void) {return OSUCCESS;}
};

//----------------------------
// OBoundCheckBox: a bound checkbox control

class OBoundCheckBox : public CButton, public OMFCBound
{
// Construction
public:
	OBoundCheckBox();

    OBoundCheckBox(const OBoundCheckBox &other);  // copy constructor
    OBoundCheckBox &operator=(const OBoundCheckBox &other);  // overloaded assignment

    oresult BindToControl(CWnd *wnd, int itemid) {return Subclass(this, wnd, itemid);}
    oresult SetProperty(const OValue &onvalue, const OValue &offvalue, BOOL mode=OBOUND_READWRITE); 

// Operations
public:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(OBoundCheckBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~OBoundCheckBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(OBoundCheckBox)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    oresult Refresh(const OValue &val); 
    oresult SaveChange(void);
    BOOL    m_mode;             // readonly/readwrite mode
    BOOL    m_tristate;         // tri-state flag
    OValue  m_onvalue;          // represented value when checked
    OValue  m_offvalue;         // represented value when unchecked
    OValue  m_curvalue;   
};


// button list element structure
struct buttonlist
{
  void    *button;   // derived c++ radio button pointer
  OValue  *value;           // value for this button
  int itemid;               // button id in the parent's window
  buttonlist  *next;        // pointer to the next button list element
};  

//---------------------------------
// OBoundGroupButton: a bound radio button group control

class OBoundGroupButton : public OMFCBound
{
// Construction
public:
	OBoundGroupButton();

    OBoundGroupButton(const OBoundGroupButton &other);  // copy constructor
    OBoundGroupButton &operator=(const OBoundGroupButton &other);  // overloaded assignment

    oresult BindToControl(CWnd *wnd, int itemid);
    oresult SetProperty(int itemid, const OValue &value, BOOL mode=OBOUND_READWRITE);
// Operations
public:

	virtual ~OBoundGroupButton();
    
    // for internal use (don't call)
    void ButtonChanged(void *button);

private:
    oresult Refresh(const OValue &val); 
    oresult SaveChange(void);
    BOOL    m_mode;         // readonly/readwrite mode
    buttonlist *m_head;     // head of buttonlist
    buttonlist *m_tail;     // tail of buttonlist
    buttonlist *m_current;  // currently checked radio button
};

//----------------------------
// OBoundSlider: a bound scrollbar + static control

class OBoundSlider : public CWnd, public OMFCBound
{
// Construction
public:
	OBoundSlider();

    OBoundSlider(const OBoundSlider &other);  // copy constructor
    OBoundSlider &operator=(const OBoundSlider &other);  // overloaded assignment

    oresult BindToControl(CWnd *wnd, int scrollbarid, int staticid);
    oresult SetProperty(const OValue &min, const OValue &max, BOOL mode=OBOUND_READWRITE);

// Operations
public:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(OBoundSlider)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~OBoundSlider();

	// Generated message map functions
protected:
	//{{AFX_MSG(OBoundSlider)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
    oresult Refresh(const OValue &val); 
    oresult SaveChange(void);
    BOOL    m_mode;                     // readonly/readwrite mode
    void   *m_scrollbar;           // embedded derived scrollbar object
    CStatic m_static;                   // embedded static object
    int     m_minvalue;                 // minimum value
    int     m_maxvalue;                 // maximum value
    int     m_currentvalue;             // current value
};

#endif
