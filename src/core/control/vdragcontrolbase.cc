#include "../../../include/core/control/vdragcontrolbase.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

VDragControlBase::VDragControlBase(VUIObject *Parent) : VUIObject(Parent) {
}
void VDragControlBase::MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) {
	switch (ClickedFlag) {
	case VMouseClickedFlag::Down: {
		UserInDrag = true;
		CallWidgetLockFocusID();
		UserStartDrag.Emit();

		break;
	}
	case VMouseClickedFlag::Up: {
		UserInDrag = false;
		CallWidgetUnlockFocusID();

		UserEndDrag.Emit();

		break;
	}
	}
}
void VDragControlBase::OnMessage(Core::VMessage *Message) {
	if (UserInDrag) {
		switch (Message->GetType()) {
		case VMessageType::MouseClickedMessage: {
			VMouseClickedMessage *ClickedMessage = static_cast<VMouseClickedMessage *>(Message);

			if (!ClickedMessage->MousePosition.InsideRectangle(GetRegion()) ||
				(ClickedMessage->ClickedKey == VMouseKeyFlag::Left &&
				 ClickedMessage->ClickedMethod == VMouseClickedFlag::Up)) {
				UserInDrag = false;

				CallWidgetUnlockFocusID();
				CallWidgetSendMessage(Message);

				UserEndDrag.Emit();
			} else {
				MouseDragged.Emit();
			}

			break;
		}
		case VMessageType::MouseMoveMessage: {
			VMouseMoveMessage *MouseMoveMessage = static_cast<VMouseMoveMessage *>(Message);

			MouseDragged.Emit();
			MouseDraggedPosition.Emit(MouseMoveMessage->MousePosition.X, MouseMoveMessage->MousePosition.Y);

			break;
		}
		case VMessageType::KillFocusMessage: {
			UserInDrag = false;
			CallWidgetUnlockFocusID();

			break;
		}
		}
	}
}

VDragControlBaseOnPushButton::VDragControlBaseOnPushButton(VUIObject *Parent) : VPushButton(Parent) {
}
VDragControlBaseOnPushButton::VDragControlBaseOnPushButton(const int &Width, const int &Height, VUIObject *Parent)
	: VPushButton(Width, Height, Parent) {
}
void VDragControlBaseOnPushButton::MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) {
	VPushButton::MouseLeftClicked(ClickedFlag);
	switch (ClickedFlag) {
	case VMouseClickedFlag::Down: {
		UserInDrag = true;
		CallWidgetLockFocusID();

		BeginDrag();

		break;
	}
	case VMouseClickedFlag::Up: {
		UserInDrag = false;
		CallWidgetUnlockFocusID();

		VPushButton::LostMouseFocus();

		EndDrag();

		UserLeftUp.Emit();

		break;
	}
	}
}
void VDragControlBaseOnPushButton::OnMessage(Core::VMessage *Message) {
	if (UserInDrag) {
		switch (Message->GetType()) {
		case VMessageType::MouseClickedMessage: {
			VMouseClickedMessage *ClickedMessage = static_cast<VMouseClickedMessage *>(Message);
			if (!ClickedMessage->MousePosition.InsideRectangle(GetRegion())) {
				UserInDrag = false;
				CallWidgetUnlockFocusID();

				CallWidgetSendMessage(Message);

				VPushButton::LostMouseFocus();

				EndDrag();
			} else if (ClickedMessage->ClickedMethod == VMouseClickedFlag::Up &&
					   ClickedMessage->ClickedKey == VMouseKeyFlag::Left) {
				UserInDrag = false;
				CallWidgetUnlockFocusID();

				CallWidgetSendMessage(Message);

				VPushButton::LostMouseFocus();

				EndDrag();
			} else {
				MouseDragged.Emit(ClickedMessage->MousePosition.X, ClickedMessage->MousePosition.Y);
			}

			break;
		}
		case VMessageType::MouseMoveMessage: {
			VMouseMoveMessage *MouseMoveMessage = static_cast<VMouseMoveMessage *>(Message);
			MouseDragged.Emit(MouseMoveMessage->MousePosition.X, MouseMoveMessage->MousePosition.Y);

			break;
		}
		case VMessageType::KillFocusMessage: {
			UserInDrag = false;
			CallWidgetUnlockFocusID();

			VPushButton::LostMouseFocus();

			EndDrag();

			break;
		}
		}
	}
}

} // namespace Core

VLIB_END_NAMESPACE