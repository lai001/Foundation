#include "PixelBufferPool.hpp"
#include <assert.h>

namespace ks
{
	PixelBufferPool::PixelBufferPool(const unsigned int width,
		const unsigned int height,
		const unsigned int maxNum,
		const PixelBuffer::FormatType formatType)
		:width(width), height(height), maxNum(maxNum), formatType(formatType), cursor(0)
	{
		assert(maxNum > 0);
		pixelBuffers.resize(maxNum);

		for (int i = 0; i < maxNum; i++)
		{
			pixelBuffers[i] = new PixelBuffer(width, height, formatType);
		}
	}

	PixelBufferPool::~PixelBufferPool()
	{
		for (int i = 0; i < maxNum; i++)
		{
			delete pixelBuffers[i];
		}
		pixelBuffers.clear();
	}

	PixelBuffer * PixelBufferPool::pixelBuffer()
	{
		PixelBuffer* pixelBuffer = pixelBuffers[cursor];
		cursor = cursor + 1;
		cursor = cursor % maxNum;
		return pixelBuffer;
	}
}