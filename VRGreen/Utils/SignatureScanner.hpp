#pragma once

class PatternScan
{
public:
	PatternScan();
	~PatternScan();

    std::unique_ptr<BYTE[]> Data;
private:



    auto GetOffset(DWORD Offset) const -> DWORD
    {
        auto Buffer{ DWORD(0) };

        memcpy(&Buffer, &Data[Offset], sizeof(DWORD));

        return Buffer;
    }
};

PatternScan::PatternScan()
{
}

PatternScan::~PatternScan()
{
}