#pragma once

#include "../control/vabstractbutton.h"
#include "../uibasic/vtimer.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

enum class VScrollerButtonType {
	Vertical,
	Horizontal
};

class VScrollerPushButton : public VAbstractButton {
private:
	bool				ScrollerInDragging = false;
	VScrollerButtonType ScrollerType	   = VScrollerButtonType::Vertical;

	int ScrollerMaxValue  = 0;
	int ScrollerMiniValue = 0;

	VPoint ScrollerDragOriginPoint;

public:
	VSignal<> ScrollerOnTrigger;
	VSignal<> OnMouseFocus;
	VSignal<> LoseMouseFocus;

public:
	void MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) override;
	void OnMessage(VMessage *Message) override;

public:
	void SetMaxValue(const int &TargetValue);
	void SetMiniValue(const int &TargetValue);

	void SetScrollerType(const VScrollerButtonType &TargetType);

private:
	VViewScrollerButtonTheme *Theme;

	VBasicTimer				AnimationFrameTimer;
	VAnimationInterpolator *Interpolator;

	VLabelStatusTheme OldTheme;
	VLabelStatusTheme TargetTheme;

	bool InAnimation = false;

public:
	VRect GetRegion() override;

public:
	void LeftClickedDown() override;
	void LeftClickedUp() override;
	void GotMouseFocus() override;
	void LostMouseFocus() override;

public:
	void OnPaint(VCanvasPainter *Painter) override;
	void CheckFrame() override;

public:
	VViewScrollerButtonTheme *GetTheme();

public:
	VScrollerPushButton(VUIObject *Parent, const VScrollerButtonType &ScrollerType = VScrollerButtonType::Vertical);
};

class VScrollerVertical : public VAbstractButton {
private:
	int ScrollerViewHeight = 0;

private:
	VViewScrollerTheme *Theme;

	VBasicTimer				AnimationFrameTimer;
	VAnimationInterpolator *Interpolator;

	VLabelStatusTheme OldTheme;
	VLabelStatusTheme TargetTheme;

	bool InAnimation  = false;
	bool OnMouseHover = false;

private:
	VScrollerPushButton *ScrollerButton;

private:
	void InitViewButton();
	void ResetViewButton();

private:
	void ScrollerValueOnChange();

public:
	VSignal<const double &> ValueOnChange;
	double					GetValue() const;

public:
	VRect GetRegion() override;

public:
	void OnMessage(VMessage *Message) override;

private:
	void SwitchDraggingStatusAnimation();
	void TurnToNormalStatusAnimation();
	void GotMouseFocus() override;
	void LostMouseFocus() override;

public:
	void OnPaint(VCanvasPainter *Painter) override;
	void CheckFrame() override;

public:
	void SetViewHeight(const int &Height);
	void SetViewPercent(const double &ViewPercent);
	void SetViewPoint(const int &TargetPoint);

public:
	void Resize(const int &Width, const int &Height) override;

public:
	VViewScrollerTheme	*GetTheme();
	VScrollerPushButton *GetScrollerButtonInstance();

public:
	VScrollerVertical(VUIObject *Parent);
	VScrollerVertical(const int &Width, const int &Height, VUIObject *Parent);
	VScrollerVertical(const int &Width, const int &Height, const int &ViewHeight, VUIObject *Parent);
};

class VScrollerHorizontal : public VAbstractButton {
private:
	int ScrollerViewWidth = 0;

private:
	VViewScrollerTheme *Theme;

	VBasicTimer				AnimationFrameTimer;
	VAnimationInterpolator *Interpolator;

	VLabelStatusTheme OldTheme;
	VLabelStatusTheme TargetTheme;

	bool InAnimation  = false;
	bool OnMouseHover = false;

private:
	VScrollerPushButton *ScrollerButton;

private:
	void InitViewButton();
	void ResetViewButton();

private:
	void ScrollerValueOnChange();

public:
	VSignal<const double &> ValueOnChange;
	double					GetValue() const;

public:
	VRect GetRegion() override;

public:
	void OnMessage(VMessage *Message) override;

private:
	void SwitchDraggingStatusAnimation();
	void TurnToNormalStatusAnimation();
	void GotMouseFocus() override;
	void LostMouseFocus() override;

public:
	void OnPaint(VCanvasPainter *Painter) override;
	void CheckFrame() override;

public:
	void SetViewWidth(const int &Width);
	void SetViewPercent(const double &ViewPercent);
	void SetViewPoint(const int &TargetPoint);

public:
	void Resize(const int &Width, const int &Height) override;

public:
	VViewScrollerTheme	*GetTheme();
	VScrollerPushButton *GetScrollerButtonInstance();

public:
	VScrollerHorizontal(VUIObject *Parent);
	VScrollerHorizontal(const int &Width, const int &Height, VUIObject *Parent);
	VScrollerHorizontal(const int &Width, const int &Height, const int &ViewHeight, VUIObject *Parent);
};

} // namespace Core

VLIB_END_NAMESPACE