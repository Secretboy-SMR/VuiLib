#pragma warning(disable : 26495)

#include "../../../include/core/render/vwrite.h"

VLIB_BEGIN_NAMESPACE

namespace Core {
VFont::VFont(const VFont &FontObject) {
	auto Widget		   = FontObject.GetTextWeightStyle();
	auto Family		   = FontObject.GetFamilyName();
	auto Style		   = FontObject.GetTextFontStyle();
	auto Stretch	   = FontObject.GetFontStretchStyle();
	auto Locale		   = FontObject.GetLocaleName();
	auto Size		   = FontObject.GetTextSize();
	auto TextAlignment = FontObject.TextFormat->GetTextAlignment();
	auto LineAlignment = FontObject.TextFormat->GetParagraphAlignment();

	VLIB_REPORT_IF_FAILED_INFO(VDirectXWriteFactory.GetInstance()->CreateTextFormat(
								   Family.CStyleString(), nullptr, (DWRITE_FONT_WEIGHT)Widget, (DWRITE_FONT_STYLE)Style,
								   (DWRITE_FONT_STRETCH)Stretch, Size, Locale.CStyleString(), &TextFormat),
							   L"Failed to create IDWriteTextFormat object");

	TextFormat->SetTextAlignment(TextAlignment);
	TextFormat->SetParagraphAlignment(LineAlignment);
}
VFont::VFont(const VString &FamilyName, const FontWeight &TextWidget, const FontStyle &TextStyle,
			 const FontStretch &TextStretch, const float &TextSize, const VString &Local) {
	VLIB_REPORT_IF_FAILED_INFO(VDirectXWriteFactory.GetInstance()->CreateTextFormat(
								   FamilyName.CStyleString(), nullptr, (DWRITE_FONT_WEIGHT)TextWidget,
								   (DWRITE_FONT_STYLE)TextStyle, (DWRITE_FONT_STRETCH)TextStretch, TextSize,
								   Local.CStyleString(), &TextFormat),
							   L"Failed to create IDWriteTextFormat object");
}
VFont::~VFont() {
	TextFormat.ReleaseAndGetAddressOf();
}
void VFont::SetLineAlignment(const VFontAlignment &Alignment) {
	TextFormat->SetTextAlignment(Alignment);
}
void VFont::SetParagraphAlignment(const VFontParagraphAlignment &Alignment) {
	TextFormat->SetParagraphAlignment(Alignment);
}
void VFont::SetFamilyName(const VString &FontFamilyName) {
	auto Widget		   = GetTextWeightStyle();
	auto Style		   = GetTextFontStyle();
	auto Stretch	   = GetFontStretchStyle();
	auto Size		   = GetTextSize();
	auto Locale		   = GetLocaleName();
	auto TextAlignment = TextFormat->GetTextAlignment();
	auto LineAlignment = TextFormat->GetParagraphAlignment();

	TextFormat.ReleaseAndGetAddressOf();

	VLIB_REPORT_IF_FAILED_INFO(VDirectXWriteFactory.GetInstance()->CreateTextFormat(
								   FontFamilyName.CStyleString(), nullptr, (DWRITE_FONT_WEIGHT)Widget,
								   (DWRITE_FONT_STYLE)Style, (DWRITE_FONT_STRETCH)Stretch, Size, Locale.CStyleString(),
								   &TextFormat),
							   L"Failed to create IDWriteTextFormat object");

	TextFormat->SetTextAlignment(TextAlignment);
	TextFormat->SetParagraphAlignment(LineAlignment);
}
VString VFont::GetFamilyName() const {
	WCHAR FamilyName[LF_FACESIZE];
	TextFormat->GetFontFamilyName(FamilyName, LF_FACESIZE);

	return FamilyName;
}
VString VFont::GetLocaleName() const {
	wchar_t *LocaleCache = new wchar_t[TextFormat->GetLocaleNameLength() + 1];
	TextFormat->GetLocaleName(LocaleCache, TextFormat->GetLocaleNameLength() + 1);

	VLIB_CHECK_REPORT(LocaleCache == nullptr, L"Get font locale name failed!");

	const VString Locale(LocaleCache);

	delete LocaleCache;

	return Locale;
}

VFont::FontWeight VFont::GetTextWeightStyle() const {
	return (FontWeight)TextFormat->GetFontWeight();
}
VFont::FontStyle VFont::GetTextFontStyle() const {
	return (FontStyle)TextFormat->GetFontStyle();
}
VFont::FontStretch VFont::GetFontStretchStyle() const {
	return (FontStretch)TextFormat->GetFontStretch();
}
void VFont::SetTextSize(const int &Size) {
	auto Widget		   = GetTextWeightStyle();
	auto Family		   = GetFamilyName();
	auto Style		   = GetTextFontStyle();
	auto Stretch	   = GetFontStretchStyle();
	auto Locale		   = GetLocaleName();
	auto TextAlignment = TextFormat->GetTextAlignment();
	auto LineAlignment = TextFormat->GetParagraphAlignment();

	TextFormat.ReleaseAndGetAddressOf();

	VLIB_REPORT_IF_FAILED_INFO(VDirectXWriteFactory.GetInstance()->CreateTextFormat(
								   Family.CStyleString(), nullptr, (DWRITE_FONT_WEIGHT)Widget, (DWRITE_FONT_STYLE)Style,
								   (DWRITE_FONT_STRETCH)Stretch, Size, Locale.CStyleString(), &TextFormat),
							   L"Failed to create IDWriteTextFormat object");

	TextFormat->SetTextAlignment(TextAlignment);
	TextFormat->SetParagraphAlignment(LineAlignment);
}
void VFont::SetTextWidget(const int &Widget) {
	auto Family		   = GetFamilyName();
	auto Style		   = GetTextFontStyle();
	auto Stretch	   = GetFontStretchStyle();
	auto Locale		   = GetLocaleName();
	auto Size		   = GetTextSize();
	auto TextAlignment = TextFormat->GetTextAlignment();
	auto LineAlignment = TextFormat->GetParagraphAlignment();

	TextFormat.ReleaseAndGetAddressOf();

	VLIB_REPORT_IF_FAILED_INFO(VDirectXWriteFactory.GetInstance()->CreateTextFormat(
								   Family.CStyleString(), nullptr, (DWRITE_FONT_WEIGHT)Widget, (DWRITE_FONT_STYLE)Style,
								   (DWRITE_FONT_STRETCH)Stretch, Size, Locale.CStyleString(), &TextFormat),
							   L"Failed to create IDWriteTextFormat object");

	TextFormat->SetTextAlignment(TextAlignment);
	TextFormat->SetParagraphAlignment(LineAlignment);
}
int VFont::GetTextSize() const {
	return TextFormat->GetFontSize();
}
} // namespace Core

VLIB_END_NAMESPACE