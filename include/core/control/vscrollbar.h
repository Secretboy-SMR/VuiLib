// License(MIT)
// Athuor: Margoo
#pragma once

#include "vdragcontrolbase.h"
#include "vpushbutton.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

enum class VDragTowardsMode {
	Vertical,
	Horizontal
};

class VCircleScrollBarButton : public VDragControlBaseOnPushButton {
private:
	VRect			 DraggedRange;
	VDragTowardsMode DragTowardsMode;
	bool			 Draggable = true;

private:
	void UserOnDrag(const int &MouseX, const int &MouseY);

public:
	VCircleScrollBarButton(const VDragTowardsMode &DragTowards, VUIObject *Parent);
	VCircleScrollBarButton(const VDragTowardsMode &DragTowards, const int &Width, const int &Height, VUIObject *Parent);

public:
	void LostMouseFocus() override;

public:
	void SetDraggable(const bool &DraggableStatus);

public:
	void OnPaint(VCanvasPainter *Painter) override;

public:
	void SetDragRange(const VRect &Range);

public:
	void MouseLeftClicked(const VMouseClickedFlag &ClickedFlag) override;
	void OnMessage(VMessage *Message) override;
};

class VSliderHorizontal : public VUIObject {
private:
	VSliderTheme *Theme;

	VCircleScrollBarButton *SliderButton;
	double					SliderPercent = 0.f;
	bool					Draggable	  = true;

private:
	inline int GetSliderButtonX() const;
	inline int GetSliderButtonY() const;

	inline int GetUnselectedAreaX() const;
	inline int GetUnselectedAreaWidth() const;
	inline int GetSelectedAreaWidth() const;

private:
	void SliderButtonDraged(const int &, const int &);

protected:
	void OnMessage(VMessage *Message) override;

public:
	VCircleScrollBarButton *GetScrollBarButtonInstance();

public:
	VSignal<const double &> ValueChanged;

public:
	VSliderHorizontal(VUIObject *Parent);
	VSliderHorizontal(const int &Width, VUIObject *Parent);
	~VSliderHorizontal();

public:
	void OnPaint(VCanvasPainter *Painter) override;

public:
	void Move(const int &X, const int &Y) override;
	void Resize(const int &Width, const int &Height) override;

public:
	void SetDraggable(const bool &DraggableStatus);

public:
	double GetValue() const;
	void   SetValue(const double &Value);

public:
	VSliderTheme *GetTheme();
};
class VSliderVertical : public VUIObject {
private:
	VSliderTheme *Theme;

	VCircleScrollBarButton *SliderButton;
	double					SliderPercent = 0.f;
	bool					Draggable	  = true;

private:
	inline int GetSliderButtonX() const;
	inline int GetSliderButtonY() const;

	inline int GetUnselectedAreaY() const;
	inline int GetUnselectedAreaHeight() const;
	inline int GetSelectedAreaHeight() const;

private:
	void SliderButtonDraged(const int &, const int &);

protected:
	void OnMessage(VMessage *Message) override;

public:
	VCircleScrollBarButton *GetScrollBarButtonInstance();

public:
	VSignal<const double &> ValueChanged;

public:
	VSliderVertical(VUIObject *Parent);
	VSliderVertical(const int &Height, VUIObject *Parent);
	~VSliderVertical();

public:
	void OnPaint(VCanvasPainter *Painter) override;

public:
	void Move(const int &X, const int &Y) override;
	void Resize(const int &Width, const int &Height) override;

public:
	double GetValue() const;
	void   SetValue(const double &Value);

public:
	void SetDraggable(const bool &DraggableStatus);

public:
	VSliderTheme *GetTheme();
};

} // namespace Core

VLIB_END_NAMESPACE