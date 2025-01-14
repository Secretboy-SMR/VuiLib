#include "../../../include/core/control/vimagelabel.h"

VLIB_BEGIN_NAMESPACE

namespace Core {

VImageLabel::VImageLabel(VUIObject *Parent) : VUIObject(Parent) {
	Theme		 = new VImageLabelTheme;
	Theme->Image = nullptr;
}
VImageLabel::VImageLabel(const int &Width, const int &Height, Core::VUIObject *Parent) : VUIObject(Parent) {
	Theme		 = new VImageLabelTheme;
	Theme->Image = nullptr;

	Resize(Width, Height);
}
VImageLabel::VImageLabel(const int &Width, const int &Height, VImage *Image, VUIObject *Parent) : VUIObject(Parent) {
	Theme = new VImageLabelTheme;

	if (Image != nullptr) {
		Theme->Image = new VImage(*Image);
	} else {
		Theme->Image = nullptr;
	}

	Resize(Width, Height);
}
VImageLabel::VImageLabel(const int &Width, const int &Height, const VString &ImagePath, VUIObject *Parent)
	: VUIObject(Parent) {
	Theme		 = new VImageLabelTheme;
	Theme->Image = new VImage(ImagePath.CStyleString(), CallWidgetGetStaticRenderHandle());

	Resize(Width, Height);
}
VImageLabel::~VImageLabel() {
	delete Theme;
}

VImageLabelTheme *VImageLabel::GetTheme() {
	return Theme;
}

void VImageLabel::OnPaint(VCanvasPainter *Painter) {
	Painter->BeginDraw();

	if (Theme->Image) {
		if (Theme->BorderRadius.X == Theme->BorderRadius.Y && Theme->BorderRadius.X == 0) {
			Painter->DrawImage(
				VRect{
					0,
					0,
					static_cast<int>(GetRegion().GetWidth()),
					static_cast<int>(GetRegion().GetHeight()),
				},
				Theme->Image,
				VRect{
					0,
					0,
					static_cast<int>(Theme->Image->GetDirectXObject()->GetSize().width),
					static_cast<int>(Theme->Image->GetDirectXObject()->GetSize().height),
				},
				1.f);
		} else if (GetRegion().GetWidth() == Theme->Image->GetDirectXObject()->GetSize().width &&
				   GetRegion().GetHeight() == Theme->Image->GetDirectXObject()->GetSize().height) {
			VBitmapBrush BitmapBrush(Theme->Image, CallWidgetGetRenderHandle());

			Painter->SolidRoundedRectangle(
				VRect{
					0,
					0,
					static_cast<int>(GetRegion().GetWidth()),
					static_cast<int>(GetRegion().GetHeight()),
				},
				Theme->BorderRadius, &BitmapBrush);
		} else {
			VCanvasPainter ScaleCanvas(GetRegion().GetWidth(), GetRegion().GetHeight(), CallWidgetGetRenderHandle());
			ScaleCanvas.BeginDraw();
			ScaleCanvas.DrawImage(
				VRect{
					0,
					0,
					static_cast<int>(GetRegion().GetWidth()),
					static_cast<int>(GetRegion().GetHeight()),
				},
				Theme->Image,
				VRect{
					0,
					0,
					static_cast<int>(Theme->Image->GetDirectXObject()->GetSize().width),
					static_cast<int>(Theme->Image->GetDirectXObject()->GetSize().height),
				},
				1.f);
			ScaleCanvas.EndDraw();

			ID2D1BitmapRenderTarget *ScaleCanvasDXObject = ScaleCanvas.GetDXObject();
			ID2D1Bitmap				*D2DBitmap;
			ScaleCanvasDXObject->GetBitmap(&D2DBitmap);
			VBitmapBrush BitmapBrush(D2DBitmap, CallWidgetGetRenderHandle());

			Painter->SolidRoundedRectangle(
				VRect{
					0,
					0,
					static_cast<int>(GetRegion().GetWidth()),
					static_cast<int>(GetRegion().GetHeight()),
				},
				Theme->BorderRadius, &BitmapBrush);

			D2DBitmap->Release();
		}
	}

	Painter->EndDraw();
}

void VImageLabel::ResizeByImage() {
	if (Theme->Image != nullptr) {
		Resize(Theme->Image->GetWidth(), Theme->Image->GetHeight());
	}
}
void VImageLabel::SetBorderRadius(const VPoint &Radius) {
	Theme->BorderRadius = Radius;

	Update();
}
VImage *VImageLabel::GetImage() {
	return Theme->Image;
}
void VImageLabel::SetLockStatus(const bool &Status) {
	LockHeight = Status;
}
void VImageLabel::Resize(const int &Width, const int &Height) {
	if (LockHeight) {
		VUIObject::Resize(Height, Height);
	} else {
		VUIObject::Resize(Width, Height);
	}
}
void VImageLabel::SetImage(VImage *Image) {
	if (Image != nullptr) {
		if (Theme->Image != nullptr) {
			*(Theme->Image) = *Image;
		} else {
			Theme->Image = new VImage(*Image);
		}
	}
}

} // namespace Core

VLIB_END_NAMESPACE