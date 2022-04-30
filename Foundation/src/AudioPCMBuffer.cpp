#include "AudioPCMBuffer.hpp"
#include <assert.h>

namespace ks
{
	AudioPCMBuffer::AudioPCMBuffer()
	{
	}

	AudioPCMBuffer::AudioPCMBuffer(const AudioFormat format, const unsigned int frameCapacity)
		: _audioFormat(format), _frameCapacity(frameCapacity)
	{

		if (format.isNonInterleaved())
		{
			_channelData = new uint8_t *[format.channelsPerFrame];
			for (int i = 0; i < format.channelsPerFrame; i++)
			{
				int size = bytesDataSizePerChannel();
				_channelData[i] = new uint8_t[size];
				memset(_channelData[i], 0, size);
			}
		}
		else
		{
			_channelData = new uint8_t *[1];
			int size = bytesDataSizePerChannel();
			_channelData[0] = new uint8_t[size];
			memset(_channelData[0], 0, size);
		}
	}

	AudioPCMBuffer::~AudioPCMBuffer()
	{
		if (_audioFormat.isNonInterleaved())
		{
			for (int i = 0; i < _audioFormat.channelsPerFrame; i++)
			{
				if (_channelData[i])
				{
					delete[] _channelData[i];
				}
			}
			delete[] _channelData;
		}
		else
		{
			delete[] _channelData[0];
			delete[] _channelData;
		}
	}

	AudioFormat AudioPCMBuffer::audioFormat() const noexcept
	{
		return _audioFormat;
	}

	unsigned int AudioPCMBuffer::frameCapacity() const noexcept
	{
		return _frameCapacity;
	}

	unsigned int AudioPCMBuffer::bytesPerSample() const noexcept
	{
		return _audioFormat.bytesPerSample();
	}

	float **AudioPCMBuffer::floatChannelData() noexcept
	{
		return reinterpret_cast<float **>(_channelData);
	}

	short **AudioPCMBuffer::int16ChannelData() noexcept
	{
		return reinterpret_cast<short **>(_channelData);
	}

	unsigned short **AudioPCMBuffer::uint16ChannelData() noexcept
	{
		return reinterpret_cast<unsigned short **>(_channelData);
	}

	unsigned char ** AudioPCMBuffer::channelData() noexcept
	{
		return _channelData;
	}

	const float * const * AudioPCMBuffer::immutableFloatChannelData() const noexcept
	{
		return reinterpret_cast<const float * const *>(_channelData);
	}

	const unsigned char * const * AudioPCMBuffer::immutableChannelData() const noexcept
	{
		return _channelData;
	}

	void AudioPCMBuffer::setZero() noexcept
	{
		
		bool isNonInterleaved = audioFormat().formatFlags.isContains(AudioFormatFlag::isNonInterleaved);

		if (isNonInterleaved)
		{
			for (int i = 0; i < audioFormat().channelsPerFrame; i++)
			{
				memset(channelData()[i], 0, bytesDataSizePerChannel());
			}
		}
		else
		{
			memset(channelData()[0], 0, bytesDataSizePerChannel());
		}
	}

	unsigned int AudioPCMBuffer::bytesDataSizePerChannel() const noexcept
	{
		return _audioFormat.bytesPerFrame * _frameCapacity;
	}

	unsigned int AudioPCMBuffer::bytesDataSize() const noexcept
	{
		bool isNonInterleaved = audioFormat().formatFlags.isContains(AudioFormatFlag::isNonInterleaved);

		if (isNonInterleaved)
		{
			return bytesDataSizePerChannel() * audioFormat().channelsPerFrame;
		}
		else
		{
			return bytesDataSizePerChannel();
		}
	}

	unsigned int AudioPCMBuffer::samplesPerChannel() const noexcept
	{
		bool isNonInterleaved = audioFormat().formatFlags.isContains(AudioFormatFlag::isNonInterleaved);
		if (isNonInterleaved)
		{
			return _frameCapacity;
		}
		else
		{
			return _frameCapacity * audioFormat().channelsPerFrame;
		}
	}

	unsigned int AudioPCMBuffer::samples() const noexcept
	{
		return _frameCapacity * audioFormat().channelsPerFrame;
	}

}