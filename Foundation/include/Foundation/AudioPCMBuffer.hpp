#ifndef Foundation_AudioPCMBuffer_hpp
#define Foundation_AudioPCMBuffer_hpp

#include <string>
#include "noncopyable.hpp"
#include "AudioFormat.hpp"
#include "defs.hpp"

namespace ks
{
	class Foundation_API AudioPCMBuffer : public noncopyable
	{
	private:
		AudioFormat _audioFormat;
		unsigned int _frameCapacity;
		unsigned char** _channelData = nullptr;

	protected:
		AudioPCMBuffer();

	public:
		AudioPCMBuffer(const AudioFormat format, const unsigned int frameCapacity);
		~AudioPCMBuffer();

		AudioFormat audioFormat() const noexcept;
		unsigned int frameCapacity() const noexcept;
		unsigned int bytesPerSample() const noexcept;
		unsigned int bytesDataSizePerChannel() const noexcept;
		unsigned int bytesDataSize() const noexcept;
		unsigned int samplesPerChannel() const noexcept;
		unsigned int samples() const noexcept;

		float **floatChannelData() noexcept;
		short **int16ChannelData() noexcept;
		unsigned short **uint16ChannelData() noexcept;
		unsigned char ** channelData() noexcept;

		const float * const *immutableFloatChannelData() const noexcept;
		const unsigned char * const * immutableChannelData() const noexcept;

		void setZero() noexcept;
	};

}

#endif // Foundation_AudioPCMBuffer_hpp