#include "AudioFormat.hpp"
#include <assert.h>
#include <unordered_map>

namespace ks
{
	const AudioFormatFlag AudioFormatFlag::isFloat = AudioFormatFlag(1 << 1);
	const AudioFormatFlag AudioFormatFlag::isSignedInteger = AudioFormatFlag(1 << 2);
	const AudioFormatFlag AudioFormatFlag::isNonInterleaved = AudioFormatFlag(1 << 3);
	const AudioFormatFlag AudioFormatFlag::isBigEndian = AudioFormatFlag(1 << 4);

	bool AudioFormat::operator==(const AudioFormat & format) const noexcept
	{
		if (sampleRate != format.sampleRate)
		{
			return false;
		}
		if (formatType != format.formatType)
		{
			return false;
		}
		if (formatFlags != format.formatFlags)
		{
			return false;
		}
		if (bytesPerPacket != format.bytesPerPacket)
		{
			return false;
		}
		if (framesPerPacket != format.framesPerPacket)
		{
			return false;
		}
		if (bytesPerFrame != format.bytesPerFrame)
		{
			return false;
		}
		if (channelsPerFrame != format.channelsPerFrame)
		{
			return false;
		}
		if (bitsPerChannel != format.bitsPerChannel)
		{
			return false;
		}
		return true;
	}

	AudioSampleType AudioFormat::getSampleType() const noexcept
	{
		assert(bitsPerChannel == 16 || bitsPerChannel == 32 || bitsPerChannel == 64);
		if (isFloat())
		{
			return bitsPerChannel == 32 ? AudioSampleType::float32 : AudioSampleType::float64;
		}
		if (isSignedInteger())
		{
			return bitsPerChannel == 16 ? AudioSampleType::sint16 : AudioSampleType::sint32;
		}
		return bitsPerChannel == 16 ? AudioSampleType::uint16 : AudioSampleType::uint32;
	}

	int AudioFormat::bytesPerSample() const noexcept
	{
		return bitsPerChannel / 8;
	}

	bool AudioFormat::isNonInterleaved() const noexcept
	{
		return formatFlags.isContains(AudioFormatFlag::isNonInterleaved);
	}

	bool AudioFormat::isFloat() const noexcept
	{
		return formatFlags.isContains(AudioFormatFlag::isFloat);
	}

	bool AudioFormat::isSignedInteger() const noexcept
	{
		return formatFlags.isContains(AudioFormatFlag::isSignedInteger);
	}

	std::string AudioSampleTypeToString(const AudioSampleType type) noexcept
	{
		std::unordered_map<AudioSampleType, std::string> table;
		table[AudioSampleType::uint16] = "uint16";
		table[AudioSampleType::uint32] = "uint32";
		table[AudioSampleType::sint16] = "sint16";
		table[AudioSampleType::sint32] = "sint32";
		table[AudioSampleType::float32] = "float32";
		table[AudioSampleType::float64] = "float64";
		assert(table.find(type) != table.end());
		return table[type];
	}
}