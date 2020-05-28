#pragma once

#include <stdint.h>

struct crc32
{
	uint32_t table[256];

	crc32()
	{
		generate_table();
	}

	void generate_table()
	{
		uint32_t polynomial = 0xEDB88320;
		for (uint32_t i = 0; i < 256; i++)
		{
			uint32_t c = i;
			for (size_t j = 0; j < 8; j++)
			{
				if (c & 1)
				{
					c = polynomial ^ (c >> 1);
				}
				else
				{
					c >>= 1;
				}
			}
			table[i] = c;
		}
	}

	uint32_t calc(const void* buf, size_t len, uint32_t c = 0)
	{
		const uint8_t* u = static_cast<const uint8_t*>(buf);
		for (size_t i = 0; i < len; ++i)
		{
			c = table[(c ^ u[i]) & 0xFF] ^ (c >> 8);
		}
		return c ^ 0xFFFFFFFF;
	}
};
