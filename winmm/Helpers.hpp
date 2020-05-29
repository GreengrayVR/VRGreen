#pragma once

#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "urlmon.lib")

#include <iostream>
#include <urlmon.h>
#include <sstream>
#include <regex>
#include <fstream>
#include <Windows.h>
#include <string>

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



wchar_t* wchar_t_ptr(const char* str)
{
	const char* sz = str;
	std::vector<wchar_t> vec;
	size_t len = strlen(sz);
	vec.resize(len + 1);
	mbstowcs(&vec[0], sz, len);
	return &vec[0];
}

bool fileExists(const char* path)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(wchar_t_ptr(path), &FindFileData);
	int found = handle != INVALID_HANDLE_VALUE;
	if (found)
	{
		//FindClose(&handle); this will crash
		FindClose(handle);
	}
	return found;
}

uint32_t getHash(const char* name)
{
	std::ifstream file;
	file.open(name, std::ios::binary);
	crc32 hasher;
	std::uint32_t crc = 0;
	char buffer[4096];

	while (file.read(buffer, sizeof(buffer)))
	{
		crc = hasher.calc(buffer, sizeof(buffer), crc);
	}

	crc = hasher.calc(buffer, file.gcount(), crc);

	return crc;
}

std::string getVersion()
{
	IStream* stream;
	//Also works with https URL's - unsure about the extent of SSL support though.
	HRESULT result = URLOpenBlockingStream(0, L"http://vrgreen.xyz/client/version", &stream, 0, 0);
	if (result != 0)
	{
		delete stream;
		return nullptr;
	}
	char buffer[100];
	unsigned long bytesRead;
	std::stringstream* ss = new std::stringstream();
	stream->Read(buffer, 100, &bytesRead);
	while (bytesRead > 0U)
	{
		ss->write(buffer, (long long)bytesRead);
		stream->Read(buffer, 100, &bytesRead);
	}
	stream->Release();
	return ss->str();
}

void checkAndDownloadNewVersion()
{
	std::uint32_t crc = 0;

	if (fileExists("VRGreen_update.dll"))
		crc = getHash("VRGreen_update.dll");
	else if (fileExists("VRGreen.dll"))
		crc = getHash("VRGreen.dll");

	std::string version = getVersion();

	if (version != std::to_string(crc))
	{
		MessageBox(GetActiveWindow(), L"Downloading new version\nPlease read the patch notes in the discord\nuwu", L"Update", 0);
		URLDownloadToFile(NULL, L"http://vrgreen.xyz/client/VRGreen.dll", L"VRGreen_update.dll", 0, NULL);
	}

	if (std::to_string(getHash("VRGreen_update.dll")) == version)
		MoveFile(L"VRGreen_update.dll", L"VRGreen.dll");
}
