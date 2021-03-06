/******************************************************************
    @name		AtmosFEAR 2 Library - Sound
    @author 	Rexhunter99
    @date		12th June 2019
    @version	2
*/
#ifndef LIBAF2_SOUND_H
#define LIBAF2_SOUND_H

#include <cstdint>
#include <string>
#include <vector>


namespace libAF2 {

/***************************************************************************
	@var enableExceptions
	@namespace libAF2
	Setting this to true will allow FileLoader static methods to throw C++
	exceptions
	@todo: Implement exceptions
*/
extern bool enableExceptions;

class Sound
{
public:

	Sound();
	Sound( const Sound& sound );
	~Sound();

	Sound& operator= (const Sound& sound);


	const uint32_t	getVersion() const { return this->version; }

	std::string	getName() const;
	void		setName( const std::string& name );

	/***************************************************************************
		@fn getWaveDataCopy()
		@return vector<int16_t> Vector of 16-bit integers
		Returns a copy of the internal wavelet data that the user must safely free.
		You can use std::unique_ptr to ensure no memory leaks occur.
	*/
	std::vector<int16_t> getWaveData();

	/***************************************************************************
		@fn getWaveData()
		@return int8_t* Pointer to an array of bytes
		This is an 'unsafe' method as it returns the pointer that is used internally
		inside the class, any changes made to the pointer's memory are reflected in the
		class.
	*/
	std::vector<int16_t>& getWaveDataInternal();

	/***************************************************************************
		@fn getBitDepth()
		@return uint32_t The bit-depth of the wavelet data
	*/
	uint16_t getBitDepth() const;

	/***************************************************************************
		@fn getChannels()
		@return uint16_t The number of channels the wavelet data has
	*/
	uint16_t getChannels() const;

	/***************************************************************************
		@fn getLength()
		@return uint32_t Get the length of the wavelet data
	*/
	uint32_t getLength() const;

	/***************************************************************************
		@fn getFrequency()
		@return uint32_t Get the playrate frequency
	*/
	uint32_t getFrequency() const;

	/***************************************************************************
		@fn setWaveData( bitdepth, channels, length, frequency, bits )
		@param bitdepth The bitdepth of the wavelet data
		@param channels The number of audio channels the wavelet data has
		@param length The length of the wavelet data in bytes
		@param frequency The frequency the wavelet data plays at
		@param bits A pointer to the wavelet data
		Copies the values data in <bits> with the properties from the other params
		to the internal wavelet data array.
	*/
	void setWaveData( uint16_t bitdepth, uint16_t channels, uint32_t length, uint32_t frequency, std::vector<int16_t>& bits );


private:

	const uint32_t		version = 2;
	std::string			m_name;
	std::vector<int16_t>m_data;
	uint16_t			m_bitdepth;
	uint16_t			m_channels;
	uint32_t			m_length;
	uint32_t			m_frequency;
};


}; //namespace libAF2


#endif // LIBAF2_SOUND_H

