#include "../../../include/core/control/vscrollbar.h"

VLIB_BEGIN_NAMESPACE

namespace Core {
VCircleScrollBarButton::VCircleScrollBarButton(const VDragTowardsMode &DragTowards, VUIObject *Parent)
	: VDragControlBaseOnPushButton(Parent) {
	DragTowardsMode = DragTowards;
	MouseDragged.Connect(this, &VCircleScrollBarButton::UserOnDrag);

	Theme = new VCircleScrollBarTheme(*(VCircleScrollBarTheme *)GetTargetTheme(Core::VUIThemeType::VCircleBarButton));
}
VCircleScrollBarButton::VCircleScrollBarButton(const VDragTowardsMode &DragTowards, const int &Width, const int &Height,
											   VUIObject *Parent)
	: VDragControlBaseOnPushButton(Width, Height, Parent) {
	DragTowardsMode = DragTowards;
	MouseDragged.Connect(this, &VCircleScrollBarButton::UserOnDrag);

	Theme = new VCircleScrollBarTheme(*(VCircleScrollBarTheme *)GetTargetTheme(Core::VUIThemeType::VCircleBarButton));
}
void VCircleScrollBarButton::OnPaint(Core::VCanvasPainter *Painter) {
	VSolidBrush BackgroundBrush(Theme->LocalTheme.BackgroundColor, CallWidgetGetRenderHandle());
	VPenBrush	PenBrush(Theme->LocalTheme.BorderColor, CallWidgetGetRenderHandle(), Theme->LocalTheme.BorderThickness);
	VSolidBrush TextBrush(Theme->LocalTheme.TextColor, CallWidgetGetRenderHandle());

	Painter->BeginDraw();

	Painter->FillEllipse({static_cast<int>(Theme->LocalTheme.BorderThickness),
						  static_cast<int>(Theme->LocalTheme.BorderThickness), GetWidth(), GetHeight()},
						 &PenBrush, &BackgroundBrush);

	Painter->EndDraw();
}
void VCircleScrollBarButton::SetDragRange(const VRect &Range) {
	DraggedRange = Range;
}
void VCircleScrollBarButton::LostMouseFocus() {
	if (!UserInDrag) {
		VPushButton::LostMouseFocus();
	}
}
void VCircleScrollBarButton::UserOnDrag(const int &MouseX, const int &MouseY) {
	if (Draggable) {
		switch (DragTowardsMode) {
		case VDragTowardsMode::Vertical: {
			if (MouseY >= DraggedRange.Top && MouseY <= DraggedRange.Bottom) {
				Move(GetX(), MouseY);
			}

			break;
		}
		case VDragTowardsMode::Horizontal: {
			if (MouseX >= DraggedRange.Left && MouseX <= DraggedRange.Right) {
				Move(MouseX, GetY());
			}

			break;
		}
		}
	}
}
void VCircleScrollBarButton::SetDraggable(const bool &DraggableStatus) {
	Draggable = DraggableStatus;
}
void VCircleScrollBarButton::MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) {
	if (Draggable) {
		VDragControlBaseOnPushButton::MouseLeftClicked(ClickedFlag);
	}
}
void VCircleScrollBarButton::OnMessage(VMessage *Message) {
	if (Draggable) {
		VDragControlBaseOnPushButton::OnMessage(Message);
	}
}

void VSliderHorizontal::OnMessage(VMessage *Message) {
	if (Message->GetType() == VMessageType::MouseClickedMessage && Draggable) {
		VMouseClickedMessage *MouseClickedMessage = static_cast<VMouseClickedMessage *>(Message);

		if (MouseClickedMessage->ClickedKey == VMouseKeyFlag::Left &&
			MouseClickedMessage->ClickedMethod == VMouseClickedFlag::Down &&
			MouseClickedMessage->MousePosition.InsideRectangle(GetRegion())) {
			SliderPercent = double(MouseClickedMessage->MousePosition.X - GetX()) / GetWidth();

			SliderButton->Move(MouseClickedMessage->MousePosition.X - SliderButton->GetWidth() / 2,
							   SliderButton->GetY());
			SliderButton->MouseLeftClicked(VMouseClickedFlag::Down);
			ValueChanged.Emit(SliderPercent);
		}
	}
}
VSliderHorizontal::VSliderHorizontal(VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VSliderTheme(*(static_cast<VSliderTheme *>(GetTargetTheme(VUIThemeType::VSlider))));

	SliderButton = new VCircleScrollBarButton(VDragTowardsMode::Horizontal, Parent);
	SliderButton->Resize(18, 18);
	SliderButton->Move(GetSliderButtonX(), GetSliderButtonY());
	SliderButton->SetDragRange({GetX(), GetY(), GetWidth(), GetHeight()});

	SliderButton->MouseDragged.Connect(this, &VSliderHorizontal::SliderButtonDraged);
}
VSliderHorizontal::VSliderHorizontal(const int &Width, VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VSliderTheme(*(static_cast<VSliderTheme *>(GetTargetTheme(VUIThemeType::VSlider))));

	SliderButton = new VCircleScrollBarButton(VDragTowardsMode::Horizontal, Parent);
	SliderButton->Resize(18, 18);
	SliderButton->Move(GetSliderButtonX(), GetSliderButtonY());
	SliderButton->SetDragRange({GetX(), GetY(), GetWidth(), GetHeight()});

	SliderButton->MouseDragged.Connect(this, &VSliderHorizontal::SliderButtonDraged);

	Resize(Width, 4);
}
VSliderHorizontal::~VSliderHorizontal() {
	delete Theme;
}

int VSliderHorizontal::GetSliderButtonX() const {
	if (SliderPercent != 0) {
		return SliderPercent * GetWidth() + GetX() - SliderButton->GetWidth() / 2;
	} else {
		return SliderPercent * GetWidth() + GetX();
	}
}
int VSliderHorizontal::GetSliderButtonY() const {
	return GetY() - 6;
}
VSliderTheme *VSliderHorizontal::GetTheme() {
	return Theme;
}
int VSliderHorizontal::GetSelectedAreaWidth() const {
	return GetWidth() * SliderPercent;
}
int VSliderHorizontal::GetUnselectedAreaWidth() const {
	return GetWidth() - GetSelectedAreaWidth();
}
int VSliderHorizontal::GetUnselectedAreaX() const {
	return GetSelectedAreaWidth();
}
void VSliderHorizontal::SetDraggable(const bool &DraggableStatus) {
	Draggable = DraggableStatus;

	SliderButton->SetDraggable(Draggable);
}
void VSliderHorizontal::OnPaint(VCanvasPainter *Painter) {
	Painter->BeginDraw();

	// Draw Unselected area
	{
		VSolidBrush UnselectBrush(Theme->UnselectedArea.LocalTheme.BackgroundColor, CallWidgetGetRenderHandle());
		VPenBrush	UnselectBorder(Theme->UnselectedArea.LocalTheme.BorderColor, CallWidgetGetRenderHandle(),
								   Theme->UnselectedArea.LocalTheme.BorderThickness);

		Painter->FillRoundedRectangle({0, 0, GetUnselectedAreaX() + GetUnselectedAreaWidth(), 4}, VPoint{4, 4},
									  &UnselectBorder, &UnselectBrush);
	}

	// Draw Selected area
	{
		VSolidBrush SelectBrush(Theme->SelectedArea.LocalTheme.BackgroundColor, CallWidgetGetRenderHandle());
		VPenBrush	SelectBorder(Theme->SelectedArea.LocalTheme.BorderColor, CallWidgetGetRenderHandle(),
								 Theme->SelectedArea.LocalTheme.BorderThickness);

		Painter->FillRoundedRectangle({0, 0, GetSelectedAreaWidth(), 4}, VPoint{4, 4}, &SelectBorder, &SelectBrush);
	}

	Painter->EndDraw();
}
void VSliderHorizontal::Move(const int &X, const int &Y) {
	VUIObject::Move(X, Y);
	SliderButton->Move(GetSliderButtonX(), GetSliderButtonY());
	SliderButton->SetDragRange({GetX(), GetY(), GetX() + GetWidth() - 14, GetY() + GetHeight()});
}
void VSliderHorizontal::SliderButtonDraged(const int &, const int &) {
	SliderPercent = double(SliderButton->GetX() - GetX()) / (GetWidth() - 14);

	ValueChanged.Emit(SliderPercent);

	Update();
}
void VSliderHorizontal::Resize(const int &Width, const int &Height) {
	VUIObject::Resize(Width, 4);
}
double VSliderHorizontal::GetValue() const {
	return SliderPercent;
}
void VSliderHorizontal::SetValue(const double &Value) {
	auto TargetValue = Value >= 1.f ? 1.f : Value;
	TargetValue		 = Value <= 0.f ? 0.f : Value;

	SliderPercent = TargetValue;

	if (SliderPercent != 0) {
		SliderButton->Move(GetX() + GetWidth() * SliderPercent - SliderButton->GetWidth() / 2, SliderButton->GetY());
	} else {
		SliderButton->Move(GetX() + GetWidth(), SliderButton->GetY());
	}

	Update();
}
VCircleScrollBarButton *VSliderHorizontal::GetScrollBarButtonInstance() {
	return SliderButton;
}

VSliderVertical::VSliderVertical(VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VSliderTheme(*(static_cast<VSliderTheme *>(GetTargetTheme(VUIThemeType::VSlider))));

	SliderButton = new VCircleScrollBarButton(VDragTowardsMode::Vertical, Parent);
	SliderButton->Resize(18, 18);
	SliderButton->Move(GetSliderButtonX(), GetSliderButtonY());
	SliderButton->SetDragRange({GetX(), GetY(), GetWidth(), GetHeight()});

	SliderButton->MouseDragged.Connect(this, &VSliderVertical::SliderButtonDraged);
}
VSliderVertical::VSliderVertical(const int &Height, VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VSliderTheme(*(static_cast<VSliderTheme *>(GetTargetTheme(VUIThemeType::VSlider))));

	SliderButton = new VCircleScrollBarButton(VDragTowardsMode::Vertical, Parent);
	SliderButton->Resize(18, 18);
	SliderButton->Move(GetSliderButtonX(), GetSliderButtonY());
	SliderButton->SetDragRange({GetX(), GetY(), GetWidth(), GetHeight()});

	SliderButton->MouseDragged.Connect(this, &VSliderVertical::SliderButtonDraged);

	Resize(4, Height);
}
VSliderVertical::~VSliderVertical() {
	delete Theme;
}

int VSliderVertical::GetSliderButtonX() const {
	return GetX() - 6;
}
int VSliderVertical::GetSliderButtonY() const {
	if (SliderPercent != 0) {
		return SliderPercent * GetHeight() + GetY() - SliderButton->GetHeight() / 2;
	} else {
		return SliderPercent * GetHeight() + GetY();
	}
}
VSliderTheme *VSliderVertical::GetTheme() {
	return Theme;
}
int VSliderVertical::GetSelectedAreaHeight() const {
	return GetHeight() * SliderPercent;
}
int VSliderVertical::GetUnselectedAreaHeight() const {
	return GetHeight() - GetSelectedAreaHeight();
}
int VSliderVertical::GetUnselectedAreaY() const {
	return GetSelectedAreaHeight();
}
void VSliderVertical::SetDraggable(const bool &DraggableStatus) {
	Draggable = DraggableStatus;

	SliderButton->SetDraggable(Draggable);
}
void VSliderVertical::OnPaint(VCanvasPainter *Painter) {
	Painter->BeginDraw();

	// Draw Unselected area
	{
		VSolidBrush UnselectBrush(Theme->UnselectedArea.LocalTheme.BackgroundColor, CallWidgetGetRenderHandle());
		VPenBrush	UnselectBorder(Theme->UnselectedArea.LocalTheme.BorderColor, CallWidgetGetRenderHandle(),
								   Theme->UnselectedArea.LocalTheme.BorderThickness);

		Painter->FillRoundedRectangle({0, 0, 4, GetUnselectedAreaY() + GetUnselectedAreaHeight()}, VPoint{4, 4},
									  &UnselectBorder, &UnselectBrush);
	}

	// Draw Selected area
	{
		VSolidBrush SelectBrush(Theme->SelectedArea.LocalTheme.BackgroundColor, CallWidgetGetRenderHandle());
		VPenBrush	SelectBorder(Theme->SelectedArea.LocalTheme.BorderColor, CallWidgetGetRenderHandle(),
								 Theme->SelectedArea.LocalTheme.BorderThickness);

		Painter->FillRoundedRectangle({0, 0, 4, GetSelectedAreaHeight()}, VPoint{4, 4}, &SelectBorder, &SelectBrush);
	}

	Painter->EndDraw();
}
void VSliderVertical::Move(const int &X, const int &Y) {
	VUIObject::Move(X, Y);
	SliderButton->Move(GetSliderButtonX(), GetSliderButtonY());
	SliderButton->SetDragRange({GetX(), GetY(), GetX() + GetWidth(), GetY() + GetHeight() - 14});
}
void VSliderVertical::SliderButtonDraged(const int &, const int &) {
	SliderPercent = double(SliderButton->GetY() - GetY()) / (GetHeight() - 14);

	ValueChanged.Emit(SliderPercent);

	Update();
}
void VSliderVertical::OnMessage(VMessage *Message) {
	if (Message->GetType() == VMessageType::MouseClickedMessage && Draggable) {
		VMouseClickedMessage *MouseClickedMessage = static_cast<VMouseClickedMessage *>(Message);

		if (MouseClickedMessage->ClickedKey == VMouseKeyFlag::Left &&
			MouseClickedMessage->ClickedMethod == VMouseClickedFlag::Down &&
			MouseClickedMessage->MousePosition.InsideRectangle(GetRegion())) {
			SliderPercent = double(MouseClickedMessage->MousePosition.Y - GetY()) / GetHeight();

			SliderButton->Move(SliderButton->GetX(),
							   MouseClickedMessage->MousePosition.Y - SliderButton->GetHeight() / 2);
			SliderButton->MouseLeftClicked(VMouseClickedFlag::Down);
			ValueChanged.Emit(SliderPercent);
		}
	}
}
void VSliderVertical::Resize(const int &Width, const int &Height) {
	VUIObject::Resize(4, Height);
}
double VSliderVertical::GetValue() const {
	return SliderPercent;
}
void VSliderVertical::SetValue(const double &Value) {
	auto TargetValue = Value >= 1.f ? 1.f : Value;
	TargetValue		 = Value <= 0.f ? 0.f : Value;

	SliderPercent = TargetValue;

	if (SliderPercent != 0) {
		SliderButton->Move(GetX(), SliderButton->GetY() + GetHeight() * SliderPercent - SliderButton->GetHeight() / 2);
	} else {
		SliderButton->Move(GetX(), SliderButton->GetY() + GetHeight());
	}

	Update();
}
VCircleScrollBarButton *VSliderVertical::GetScrollBarButtonInstance() {
	return SliderButton;
}
} // namespace Core

VLIB_END_NAMESPACE