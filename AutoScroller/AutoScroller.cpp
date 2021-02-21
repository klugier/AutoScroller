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
	if (!HasPane()) {
		return;
	}
	Rect _r = pane->GetRect();
	Rect r(-p, _r.GetSize());
	pane->SetRect(r);
	WhenScrolled();
}

void AutoScroller::OnScroll()
{
	Scroll(scroll.Get());
}

void AutoScroller::Layout()
{
	Size psz = GetSize();
	scroll.SetPage(psz);
	if (!HasPane()) {
		return;
	}
	Size tsz = pane->GetSize();
	scroll.SetTotal(tsz);
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
