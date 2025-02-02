#include "../../../include/core/control/vblurlabel.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

VBlurLabel::VBlurLabel(VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VBlurLabelTheme(*(static_cast<VBlurLabelTheme *>(GetTargetTheme(VUIThemeType::VBlurLabel))));
}
VBlurLabel::~VBlurLabel() {
	delete Theme;
}
bool VBlurLabel::RendBlurCanvas(VCanvasPainter *Painter, VUIObject *Object) {
	if ((Object->GetWidth() == 0 && Object->GetHeight() == 0) || Object->GetCanvas() == nullptr) {
		return false;
	}

	VCanvasPainter ChildCanvas(Object->GetWidth(), Object->GetHeight(), CallWidgetGetRenderHandle());
	ChildCanvas.BeginDraw();
	ChildCanvas.Clear(VColor::FromBYTERGBA(0, 0, 0, 0));

	Object->OnPaint(&ChildCanvas);

	auto ObjectChildLayout = Object->GetChildLayout();

	for (auto ChildObject = ObjectChildLayout.begin(); ChildObject != ObjectChildLayout.end(); ++ChildObject) {
		if (Object == this) {
			return true;
		}

		if (RendBlurCanvas(&ChildCanvas, *ChildObject)) {
			Painter->DrawCanvas(Object->GetRegion(), &ChildCanvas, {0, 0, Object->GetWidth(), Object->GetHeight()},
								1.f);

			return true;
		}
	}

	ChildCanvas.EndDraw();

	Painter->DrawCanvas(Object->GetRegion(), &ChildCanvas, {0, 0, Object->GetWidth(), Object->GetHeight()},
						Object->GetTransparency());

	return false;
}
VBlurLabel::VBlurLabel(const int &Width, const int &Height, VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VBlurLabelTheme(*(static_cast<VBlurLabelTheme *>(GetTargetTheme(VUIThemeType::VBlurLabel))));

	Resize(Width, Height);
}
VBlurLabel::VBlurLabel(const int &Width, const int &Height, const int &Radius, VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VBlurLabelTheme(*(static_cast<VBlurLabelTheme *>(GetTargetTheme(VUIThemeType::VBlurLabel))));

	Resize(Width, Height);

	Theme->BlurRadius = Radius;
}

void VBlurLabel::OnPaint(Core::VCanvasPainter *Painter) {
	VImage BlurImage(GetWidth(), GetHeight(), VSF_ALPHA_MODE_PREMULTIPLIED, CallWidgetGetRenderHandle());

	D2D1_POINT_2U SourcePoint = {0, 0};
	D2D1_RECT_U	  RectArea	  = {static_cast<unsigned int>(GetOriginX()), static_cast<unsigned int>(GetOriginY()),
								 static_cast<unsigned int>(GetOriginX()) + static_cast<unsigned int>(GetWidth()),
								 static_cast<unsigned int>(GetHeight()) + static_cast<unsigned int>(GetOriginY())};

	BlurImage.GetDirectXObject()->CopyFromRenderTarget(&SourcePoint, GetParent()->GetCanvas()->GetDXObject(),
													   &RectArea);
	BlurImage.ApplyGassBlur(Theme->BlurRadius, CallWidgetGetRenderHandle());

	VSolidBrush	 SolidBrush(Theme->MixedColor, CallWidgetGetRenderHandle());
	VBitmapBrush BitmapBrush(&BlurImage, CallWidgetGetRenderHandle());

	Painter->BeginDraw();
	Painter->Clear(VColor(0.f, 0.f, 0.f, 0.f));

	Painter->SolidRoundedRectangle({0, 0, GetWidth(), GetHeight()}, Theme->BorderRadius, &BitmapBrush);
	Painter->SolidRoundedRectangle({0, 0, GetWidth(), GetHeight()}, Theme->BorderRadius, &SolidBrush);

	Painter->EndDraw();
}
VBlurLabelTheme *VBlurLabel::GetTheme() {
	return Theme;
}

} // namespace Core

VLIB_END_NAMESPACE