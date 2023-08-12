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

#pragma once

#include "kernel/mem/vconstantpool.h"
#include "kernel/mem/vmemory.h"
#include "kernel/mem/vmemrbtree.h"
#include "kernel/mem/vpointer.h"
#include <kernel/container/vdeque.h>

template <typename T>
class MyInitializerList {
public:
	MyInitializerList(const T *begin, const T *end) : data(begin), size(end - begin) {
	}

	const T *begin() const {
		return data;
	}
	const T *end() const {
		return data + size;
	}

private:
	const T *data;
	size_t	 size;
};

template <typename T>
void processInitializerList(const MyInitializerList<T> &list) {
}

int mem_test() {
	VMemoryPool B;

	VDeque<int> TestDeque(
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27}, B);

	for (auto &a : TestDeque) {
		printf("%d ", a);
	}

	return 0;
}

int main() {
	return mem_test();
}