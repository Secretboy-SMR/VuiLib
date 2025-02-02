// License(MIT)
// Athuor: Margoo
#pragma once

#include "vpushbutton.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

class VDragControlBase : public VUIObject {
protected:
	bool UserInDrag = false;

public:
	VSignal<>						  UserStartDrag;
	VSignal<>						  MouseDragged;
	VSignal<const int &, const int &> MouseDraggedPosition;
	VSignal<>						  UserEndDrag;

public:
	VDragControlBase(VUIObject *Parent);

public:
	void MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) override;
	void OnMessage(VMessage *Message) override;
};
class VDragControlBaseOnPushButton : public VPushButton {
protected:
	bool UserInDrag = false;

public:
	VSignal<>						  UserStartDrag;
	VSignal<const int &, const int &> MouseDragged;
	VSignal<>						  UserEndDrag;
	VSignal<>						  UserLeftUp;

public:
	virtual void BeginDrag() {
	}
	virtual void EndDrag() {
	}

public:
	VDragControlBaseOnPushButton(VUIObject *Parent);
	VDragControlBaseOnPushButton(const int &Width, const int &Height, VUIObject *Parent);

public:
	void MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) override;
	void OnMessage(VMessage *Message) override;
};

} // namespace Core

VLIB_END_NAMESPACE