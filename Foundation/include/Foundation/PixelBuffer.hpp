#ifndef PIXELBUFFER_HPP
#define PIXELBUFFER_HPP

#include <memory>
#include "defs.hpp"
#include "noncopyable.hpp"

namespace ks
{
	class Foundation_API PixelBuffer : public boost::noncopyable
	{

	public:
		enum class FormatType
		{
			rgba8,
			rgb8,
			bgra8,
			bgr8,
			gray8,
			yuv420p
		};
		constexpr static unsigned int maxPlanes = 8;

	private:
		int _width;
		int _height;
		unsigned char* _data[maxPlanes];
		PixelBuffer::FormatType _type;

	public:
		explicit PixelBuffer(const int width, const int height, const PixelBuffer::FormatType type, unsigned char* data[maxPlanes], const unsigned int planes);
		explicit PixelBuffer(const int width, const int height, const PixelBuffer::FormatType type);
		~PixelBuffer();

		static unsigned int getBytesCount(const int width, const int height, const PixelBuffer::FormatType type) noexcept;

		int getWidth() const noexcept;
		int getHeight() const noexcept;
		const unsigned char* const * getImmutableData() const noexcept;
		unsigned char** getMutableData() noexcept;
		PixelBuffer::FormatType getType() const noexcept;
		unsigned int getChannels() const noexcept;
		static unsigned int getChannels(const PixelBuffer::FormatType type) noexcept;
	};
}

#endif // !PIXELBUFFER_HPP