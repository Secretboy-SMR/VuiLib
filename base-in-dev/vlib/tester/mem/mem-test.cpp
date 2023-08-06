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

#include "kernel/mem/vmemory.h"
#include "kernel/mem/vmemrbtree.h"

int mem_test() {
	VMemoryPool							  TestMPool;
	_VMem::VRBTree<int, int, VMemoryPool> Tree(TestMPool);
	Tree.Insert(4, 114514);
	Tree.Insert(9, 8848);
	Tree.Insert(5, 84);
	Tree.Insert(16, 884);
	Tree.Insert(7, 81);
	Tree.Insert(180, 81);
	Tree.Insert(190, 81);
	Tree.Insert(440, 81);
	Tree.Insert(4410, 81);

	Tree.Delete(180);

	printf("%d", Tree.Find(16));

	return 0;
}

int main() {
	return mem_test();
}