#pragma once

#include "DiscordRPC/discord-rpc-master/include/discord_register.h"
#include "DiscordRPC/discord-rpc-master/include/discord_rpc.h"
#include <chrono>
#include <string>
 

class Discord
{
public:
    int imageCounter = 0;

    void Initalize();

    void Update();

    void Shutdown();

    std::string GetLargeImageKey();

private:
    int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
};

