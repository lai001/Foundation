#ifndef Foundation_PixelBufferPool_hpp
#define Foundation_PixelBufferPool_hpp

#include <vector>
#include "noncopyable.hpp"
#include "PixelBuffer.hpp"

namespace ks
{
	class PixelBufferPool : public noncopyable
	{
	private:
		std::vector<PixelBuffer*> pixelBuffers;
		unsigned int width;
		unsigned int height;
		unsigned int maxNum;
		PixelBuffer::FormatType formatType;
		unsigned int cursor;
	public:
		PixelBufferPool(const unsigned int width,
			const unsigned int height, 
			const unsigned int maxNum,
			const PixelBuffer::FormatType formatType);
		~PixelBufferPool();

		PixelBuffer* pixelBuffer();
	};
}

#endif // Foundation_PixelBufferPool_hpp