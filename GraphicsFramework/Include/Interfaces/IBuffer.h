#pragma once

namespace GFW
{
	/**
	 * \brief Bits that describe the intended usage for a buffer. All bits describe interactions between the client(CPU) and the server(GPU). They have no effect on server to server interactions.
	 * The STATIC bit is valid when used alone. When the READ, WRITE or READ_WRITE bits are set either ONCE, PER_FRAME or PER_DRAW must also be set.
	 */
	enum BufferUsageBits
	{
		BUFFER_USAGE_STATIC = 1/*Bit to set when intending to send data once or not at all and then not interact with it again until it's destroyed.*/,
		BUFFER_USAGE_READ = BUFFER_USAGE_STATIC << 1/*Bit to set when intending to read from the buffer.*/,
		BUFFER_USAGE_WRITE = BUFFER_USAGE_READ << 1/*Bit to set when intending to write to the buffer.*/,
		BUFFER_USAGE_READ_WRITE = BUFFER_USAGE_READ | BUFFER_USAGE_WRITE/*Bit to set when intending to both read and write to the buffer. The same as setting both bits individualy.*/,
		BUFFER_USAGE_ONCE = BUFFER_USAGE_WRITE << 1/*Bit to set when intending to interact with the buffer once or at very large intervals.*/,
		BUFFER_USAGE_PER_FRAME = BUFFER_USAGE_ONCE << 1/*Bit to set when intending to interact with the buffer (almost) every frame.*/,
		BUFFER_USAGE_PER_DRAW = BUFFER_USAGE_PER_FRAME << 1/*Bit to set when intending to interact with the buffer multiple times per frame.*/,
	};

	/**
	 * \brief Interface for API specific buffer class.
	 */
	class IBuffer
	{
	public:
		virtual ~IBuffer() = default;

		/**
		 * \brief Function to create a buffer without data.
		 * \param size The size of the buffer to allocate.
		 * \param usageBits Bits that describe how the buffer is intended to be used. BufferUsageBits
		 */

		virtual void Create(unsigned size, int usageBits) = 0;
		/**
		 * \brief Function to create a buffer and set the initial data.
		 * \param size The size of the buffer to allocate.
		 * \param data The data to copy into the buffer.
		 * \param usageBits Bits that describe how the buffer is intended to be used. BufferUsageBits
		 */
		virtual void Create(unsigned size, const void* data, int usageBits) = 0;

		/**
		 * \brief Function to write or update the data in the buffer.
		 * \param offset The offset to where to start writing in the buffer.
		 * \param size The amount of bytes that needs to be written to the buffer.
		 * \param data The data that needs to be written to the buffer.
		 */
		virtual void Write(unsigned offset, unsigned size, const void* data) = 0;

		/**
		 * \brief Function to read data from the buffer.
		 * \param offset The offset to where to start reading from in the buffer.
		 * \param size The amount of bytes to read from the buffer.
		 * \param data Pointer to an output buffer. Must already be allocated and must be atleast @size bytes in size.
		 */
		virtual void Read(unsigned offset, unsigned size, void* data) = 0;

		/**
		* \brief Function to clear the entire buffer to 0.
		*/
		virtual void Clear() = 0;

		/**
		 * \brief Function to clear the entire buffer to the specified 4 byte pattern.
		 * \param pattern 4 byte pattern to fill the buffer with.
		 */
		virtual void Clear(const void* pattern) = 0;
	};
}
