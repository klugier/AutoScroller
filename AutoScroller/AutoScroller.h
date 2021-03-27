#ifndef _AutoScroller_AutoScroller_h_
#define _AutoScroller_AutoScroller_h_

#include <CtrlLib/CtrlLib.h>

namespace Upp
{
	class AutoScroller : public ParentCtrl
	{
	public:
		AutoScroller();
		
	public:
		void Layout() override;
		void MouseWheel(Point, int zdelta, dword) override;
		
	public:
		void EnableScroll(bool b = true);
		void DisableScroll()         { EnableScroll(false); }
		bool IsScrollEnabled() const { return scroll.x.IsEnabled() || scroll.y.IsEnabled(); }
	
		void AddPane(Ctrl& c, Size sz) { ClearPane(); pane = &c; Add(c); scroll.SetTotal(sz); }
		void AddPane(Ctrl& c)          { AddPane(c, c.GetSize()); }
		
		Ctrl* GetPane() const        { return pane; }
		bool HasPane() const         { return pane; }
		void ClearPane()             { if(pane) { pane->Remove(); pane = nullptr; } }
	
		void Scroll(const Point& p);
		void OnScroll();
	
	public:
		Event<> WhenScrolled;
		ScrollBars scroll;
	
	protected:
		Ptr<Ctrl> pane;
	};
}

#endif
