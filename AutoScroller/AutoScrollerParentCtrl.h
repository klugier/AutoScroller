#ifndef _AutoScroller_AutoScroller_h_
#define _AutoScroller_AutoScroller_h_

#include <CtrlLib/CtrlLib.h>

namespace Upp
{
	template<class C = ParentCtrl>
	class AutoScroller : public C
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
	
		void AddPane(Ctrl& c)        { ClearPane(); pane = &c; C::Add(c); }
		Ctrl* GetPane() const        { return pane; }
		bool HasPane() const         { return (~pane != nullptr); }
		void ClearPane()             { if(! ~pane) return; pane->Remove(); pane = nullptr; }
	
		void Scroll(const Point& p);
		void OnScroll();
	
		Event<> WhenScrolled;
		ScrollBars scroll;
	
	protected:
		Ptr<Ctrl> pane;
	};
}

#endif
