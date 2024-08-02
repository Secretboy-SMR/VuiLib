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
 * \file vObject.h
 * \brief The base class object for the drawable class in VUILib
 */

#pragma once

#include <include/base/object/vObjectProperty.h>
#include <include/renderer/vRenderTarget.h>
#include <include/renderer/vSurface.h>
#include <include/base/vBase.h>

/**
 * The base class object for the drawable class in VUILib
 * Every object that is drawable in the user interface should inherit this class
 * to ensure that it can join the message loop correctly
 */
class VObject {
public:
	VObject() = default;

public:
	/**
	 * When the control received the repaint message, the virtual function will
	 * be called for drawing
	 * @param Surface The surface will be created by the parent class and provide it
	 * to this sub object.
	 */
	virtual void OnPaint(const sk_sp<VSurface> &Surface) = 0;

public:
	/**
	 * Get the property by the specified name
	 * @param Name The name of the property
	 * @return The reference of the property instance
	 */
	VObjectProperty& GetProperty(const std::string &Name);

public:
	/**
	 * The virtual function that to be called when the property was changed
	 */
	virtual void OnPropertyChange() {

	}

protected:
	/**
	 * Add a property to the object
	 * @tparam Type The type of the target value
	 * @param Name The property name
	 * @param Pointer The pointer referred to the pointer
	 */
	template<class Type>
		requires std::is_base_of_v<VPropertyValueBase, Type>
	void RegisterProperty(const std::string &Name, const std::unique_ptr<Type> &Pointer) {
		return RegisterProperty(Name, std::unique_ptr<VPropertyValueBase>(Pointer.get()));
	}
	/**
	 * Add a property to the object
	 * @param Name The property name
	 * @param Pointer The pointer referred to the pointer
	 */
	void RegisterProperty(const std::string &Name, const std::unique_ptr<VPropertyValueBase> &Pointer);

protected:
	VPropertyList _propertyList;
};