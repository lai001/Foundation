#ifndef Foundation_AudioFormat_hpp
#define Foundation_AudioFormat_hpp
#include <string>
#include "defs.hpp"
#include "BitFlag.hpp"

namespace ks
{
	enum class AudioFormatIdentifiersType
	{
		pcm
	};

	enum class AudioSampleType
	{
		uint16,
		uint32,
		sint16,
		sint32,
		float32,
		float64
	};

	std::string Foundation_API AudioSampleTypeToString(const AudioSampleType type) noexcept;

	struct Foundation_API AudioFormatFlag : public ks::BitFlag<int, AudioFormatFlag>
	{
		explicit AudioFormatFlag(int v = 0) :ks::BitFlag<int,  AudioFormatFlag>(v) { }
		static const AudioFormatFlag isFloat;
		static const AudioFormatFlag isSignedInteger;
		static const AudioFormatFlag isNonInterleaved;
		static const AudioFormatFlag isBigEndian;
	};

	struct Foundation_API AudioFormat
	{
		double                     sampleRate;
		AudioFormatIdentifiersType formatType;
		AudioFormatFlag            formatFlags = AudioFormatFlag(0);
		unsigned int               bytesPerPacket;
		unsigned int               framesPerPacket;
		unsigned int               bytesPerFrame;
		unsigned int               channelsPerFrame;
		unsigned int               bitsPerChannel;

		bool operator==(const AudioFormat &format) const noexcept;

		AudioSampleType getSampleType() const noexcept;

		int bytesPerSample() const noexcept;
		bool isNonInterleaved() const noexcept;
		bool isFloat() const noexcept;
		bool isSignedInteger() const noexcept;
	};
}

#endif // Foundation_AudioFormat_hpp