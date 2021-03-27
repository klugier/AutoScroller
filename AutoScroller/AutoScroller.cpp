#ifndef _AutoScroller_AutoScroller_hpp_
#define _AutoScroller_AutoScroller_hpp_

#include "AutoScroller.h"

using namespace Upp;

constexpr int LINE_WIDTH  = 12;
constexpr int LINE_HEIGHT = 12;

AutoScroller::AutoScroller()
{
	AddFrame(scroll);
	scroll.AutoHide();
	scroll.WhenScroll = [=] { OnScroll(); };
	scroll.SetLine(DPI(LINE_WIDTH, LINE_HEIGHT));
}

void AutoScroller::Scroll(const Point& p)
{
	if (HasPane()) {
		Rect _r = pane->GetRect();
		Rect r(-p, _r.GetSize());
		pane->SetRect(r);
		WhenScrolled();
	}
}

void AutoScroller::OnScroll()
{
	Scroll(scroll.Get());
}

void AutoScroller::Layout()
{
	Size psz = scroll.GetReducedViewSize();
	scroll.SetPage(psz);
}

void AutoScroller::MouseWheel(Point, int zdelta, dword)
{
	scroll.WheelY(zdelta);
}

void AutoScroller::EnableScroll(bool b)
{
	scroll.x.Enable(b);
	scroll.y.Enable(b);
}

#endif
