#include "../../../include/vml/vmlparser.h"
#include "veditor.h"

VLIB_BEGIN_NAMESPACE

namespace Core {
enum class VBuiltInHightlighterTheme {
	OneDarkPro,
	FleetDark
};

struct VHightlighterTheme {
	Core::VColor SymbolColor;
	Core::VColor BackgroundColor;
	Core::VColor SelectBackgroundColor;
	Core::VColor SelectTextColor;
	Core::VColor KeyWorldColor;
	Core::VColor StringColor;
	Core::VColor LabelColor;
	Core::VColor TypeColor;
	Core::VColor MetaCallColor;
	Core::VColor CommentColor;
	Core::VColor TagColor;
	Core::VColor SubElementColor;
	Core::VColor IgnoreGrayColor;

	Core::VSolidBrush *SymbolBrush;
	Core::VSolidBrush *KeyWorldBrush;
	Core::VSolidBrush *StringBrush;
	Core::VSolidBrush *TypeBrush;
	Core::VSolidBrush *MetaCallBrush;
	Core::VSolidBrush *LabelBrush;
	Core::VSolidBrush *CommentBrush;
	Core::VSolidBrush *TagBrush;
	Core::VSolidBrush *SubElementBrush;
	Core::VSolidBrush *IgnoreGrayBrush;

	VString FontFamily;

	VHightlighterTheme(const VRenderHandle &StaticRenderHandle);
	VHightlighterTheme(const VHightlighterTheme &Theme);
	VHightlighterTheme(const VRenderHandle &StaticRenderHandle, const VBuiltInHightlighterTheme &Theme);

	~VHightlighterTheme();
};

class VBasicHightlighter {
protected:
	VEditor *Editor;

public:
	VBasicHightlighter();

	virtual void CheckInputChar(const wchar_t &NewChar, bool *AllowEditFlag) {
	}
	virtual void NewCharacter(const wchar_t &NewChar) {
	}
	virtual void BeforeChange(const VString &PlainText) {
	}
	virtual void RenderColor(const VString &PlainText) {
	}
	virtual void MouseClicked(const int &TextPosition) {
	}

	virtual void BindEditor(VEditor *TargetEditor);
};

class VVMLHighlighter : public VBasicHightlighter {
private:
	VHightlighterTheme HighlightTheme;

public:
	VVMLHighlighter(VEditor *Editor);
	VVMLHighlighter(const VRenderHandle &StaticRenderHandle);
	VVMLHighlighter(const VRenderHandle &StaticRenderHandle, const VBuiltInHightlighterTheme &Theme);
	VVMLHighlighter(const VHightlighterTheme &Theme);

	void CheckInputChar(const wchar_t &NewChar, bool *AllowEditFlag) override;
	void NewCharacter(const wchar_t &NewChar) override;
	void RenderColor(const VString &PlainText) override;
	void MouseClicked(const int &TextPosition) override;

	void BindEditor(VEditor *TargetEditor) override;

private:
	int CountSpace(VML::VMLNode Node, const int &PreSpaceCount = 0);

private:
	VBasicTimer DoubleClickTimer;
};
class VVSSHighlighter : public VBasicHightlighter {
private:
	VHightlighterTheme HighlightTheme;

public:
	VVSSHighlighter(VEditor *Editor);
	VVSSHighlighter(const VRenderHandle &StaticRenderHandle);
	VVSSHighlighter(const VRenderHandle &StaticRenderHandle, const VBuiltInHightlighterTheme &Theme);
	VVSSHighlighter(const VHightlighterTheme &Theme);

	void CheckInputChar(const wchar_t &NewChar, bool *AllowEditFlag) override;
	void NewCharacter(const wchar_t &NewChar) override;
	void RenderColor(const VString &PlainText) override;
	void MouseClicked(const int &TextPosition) override;

	void BindEditor(VEditor *TargetEditor) override;

private:
	VBasicTimer DoubleClickTimer;
};
} // namespace Core

VLIB_END_NAMESPACE