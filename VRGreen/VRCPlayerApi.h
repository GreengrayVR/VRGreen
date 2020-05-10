#pragma once

#include "Color.hpp"
#include "VRC/Player.h"
#include "UnityEngine/Component.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Quaternion.hpp"
//namespace VRC
//{
//	struct Player { void CurrentPlayer(); };
//}

namespace VRC::SDKBase
{
	struct VRCPlayerApi : UnityEngine::Component 
	{ 
		NOIMPLEMENT(VRCPlayerApi); 
	
		static VRCPlayerApi* GetCurrentVRCPlayerApi();

		inline int PlayerId();

		inline UnityEngine::Vector3* GetPosition();

		inline UnityEngine::Quaternion* GetRotation();

		inline static void TeleportTo(VRC::SDKBase::VRCPlayerApi* who, VRC::SDKBase::VRCPlayerApi* to);

		void TeleportTo(VRC::SDKBase::VRCPlayerApi* player);

		void SetRunSpeed(float speed = 4);

		void SetWalkSpeed(float speed = 4);

		void SetJumpImpulse(float impulse = 3);

		// RVA: 0x15FDA40 Offset: 0x15FCC40 VA: 0x1815FDA40
		void SetNamePlateColor(UnityEngine::Color* col);

		void SetMuteStatus(bool canSpeak, bool canHear);
	};

	

	
}