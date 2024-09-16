/*
 * Copyright (c) 2023~Now Margoo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file vRichTextRenderer.h
 * \brief The HTML AST based rich text renderer in VUILib
 */

#pragma once

#include <include/base/geometry/vRect.h>
#include <include/parser/html/vHTMLAST.h>
#include <include/renderer/vRendererBase.h>

/**
 * The rich text renderer in VUILib
 */
class VRichTextRenderer {
public:
	/**
	 * Construct the rich text renderer with the HTML AST
	 * @param AST The HTML AST tree of the rich text
	 */
	explicit VRichTextRenderer(VHTMLAST *AST);

public:
	/**
	 * Render the rich text on the canvas
	 * @param Canvas The reference of the canvas
	 * @param Bound The bound of the text area
	 */
	void Render(SkCanvas *Canvas, const VRect &Bound);

private:
	/**
	 * Render the node on the specified position
	 * @param Node The AST node to be rendered
	 * @param Canvas The target canvas to be rendered on
	 * @param Bound The bound of the text area
	 * @param X The specified X position
	 * @param Y The specified Y position
	 * @param Size The text size
	 * @param EnglishFont The English font style
	 * @param OtherFont The other font style
	 * @param Color The text color
	 * @param LineCount The count of the paragraph
	 * @return The new marching position
	 */
	std::tuple<SkScalar, SkScalar, int> RenderNode(VHTMLASTNode *Node, SkCanvas *Canvas, const VRect &Bound,
											  const SkScalar &X, const SkScalar &Y, const SkScalar &Size,
											  SkFont &EnglishFont, SkFont &OtherFont, const SkColor &Color,
											  const int &LineCount);

private:
	/**
	 * Calculating the parameter which will be used in rendering process
	 */
	std::tuple<SkScalar, std::optional<int>> CalculatingRendering(VHTMLASTNode *Node, const VRect &Bound,
																  const SkScalar &X, const SkScalar &Y,
																  const SkScalar &Size, SkFont &EnglishFont,
																  SkFont &OtherFont, const SkScalar &MaxHeight);

private:
	/**
	 * Init the renderer default font set
	 */
	void InitFontSet();

private:
	VHTMLAST *_ast;

private:
	int _lineSpacing;
	int _wordSpacing;

private:
	std::vector<int> _lineWidths;
	std::vector<int> _lineHeights;

private:
	sk_sp<SkTypeface> _otherTypeFace;
	sk_sp<SkTypeface> _englishTypeFace;
	SkFont			  _englishFont;
	SkFont			  _otherFont;

private:
	static constexpr SkScalar _H1Size = 40;
	static constexpr SkScalar _H2Size = 32;
	static constexpr SkScalar _H3Size = 26;
	static constexpr SkScalar _H4Size = 18;
};