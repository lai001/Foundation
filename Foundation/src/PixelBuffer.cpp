#include "PixelBuffer.hpp"
#include <unordered_map>
#include <algorithm>
#include <assert.h>

namespace ks
{
	PixelBuffer::PixelBuffer(const int width, const int height, const PixelBuffer::FormatType type, unsigned char* data[maxPlanes], const unsigned int planes)
		: _width(width), _height(height), _type(type)
	{
		for (unsigned int i = 0; i < maxPlanes; i++)
		{
			_data[i] = nullptr;
		}
		for (unsigned int i = 0; i < std::min(planes, maxPlanes); i++)
		{
			_data[i] = data[i];
		}
	}

	PixelBuffer::PixelBuffer(const int width, const int height, const PixelBuffer::FormatType type)
		: _width(width), _height(height), _type(type)
	{
		for (unsigned int i = 0; i < maxPlanes; i++)
		{
			_data[i] = nullptr;
		}
		if (type == FormatType::yuv420p)
		{
			_data[0] = new unsigned char[width];
			_data[1] = new unsigned char[std::ceil(width / 2.0)];
			_data[2] = new unsigned char[std::ceil(width / 2.0)];
		}
		else
		{
			_data[0] = new unsigned char[PixelBuffer::getBytesCount(width, height, type)];
		}
	}

	PixelBuffer::~PixelBuffer()
	{
		for (unsigned int i = 0; i < maxPlanes; i++)
		{
			if (_data[i])
			{
				delete _data[i];
			}
		}
	}

	unsigned int PixelBuffer::getBytesCount(const int width, const int height, const PixelBuffer::FormatType type) noexcept
	{
		std::unordered_map<PixelBuffer::FormatType, unsigned int> available;
		available[PixelBuffer::FormatType::rgb8] = 1;
		available[PixelBuffer::FormatType::rgba8] = 1;
		available[PixelBuffer::FormatType::bgra8] = 1;
		available[PixelBuffer::FormatType::bgr8] = 1;
		available[PixelBuffer::FormatType::gray8] = 1;
		assert(available.find(type) != available.end());
		return width * height * getChannels(type);
	}

	int PixelBuffer::getWidth() const noexcept
	{
		return _width;
	}

	int PixelBuffer::getHeight() const noexcept
	{
		return _height;
	}

	const unsigned char* const *  PixelBuffer::getImmutableData() const noexcept
	{
		return _data;
	}

	unsigned char** PixelBuffer::getMutableData() noexcept
	{
		return _data;
	}

	PixelBuffer::FormatType PixelBuffer::getType() const noexcept
	{
		return _type;
	}

	unsigned int PixelBuffer::getChannels() const noexcept
	{
		return getChannels(_type);
	}

	unsigned int PixelBuffer::getChannels(const PixelBuffer::FormatType type) noexcept
	{
		std::unordered_map<PixelBuffer::FormatType, unsigned int> channels;
		channels[PixelBuffer::FormatType::rgb8] = 3;
		channels[PixelBuffer::FormatType::rgba8] = 4;
		channels[PixelBuffer::FormatType::bgra8] = 4;
		channels[PixelBuffer::FormatType::bgr8] = 4;
		channels[PixelBuffer::FormatType::yuv420p] = 3;
		channels[PixelBuffer::FormatType::gray8] = 1;
		assert(channels.find(type) != channels.end());
		return channels[type];
	}
}