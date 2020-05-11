#pragma once

#include "Color.hpp"
#include "VRC/Player.h"
#include "UnityEngine/Component.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Quaternion.hpp"


namespace VRC::SDKBase
{
	struct VRCPlayerApi : UnityEngine::Component 
	{ 
		NOIMPLEMENT(VRCPlayerApi); 
	
		static VRCPlayerApi* GetCurrentVRCPlayerApi();

		int PlayerId();

		UnityEngine::Vector3* GetPosition();

		UnityEngine::Quaternion* GetRotation();

		static void TeleportTo(VRC::SDKBase::VRCPlayerApi* who, VRC::SDKBase::VRCPlayerApi* to);

		void TeleportTo(VRC::SDKBase::VRCPlayerApi* player);

		void SetRunSpeed(float speed = 4);

		void SetWalkSpeed(float speed = 4);

		void SetJumpImpulse(float impulse = 3);

		void SetNamePlateColor(UnityEngine::Color* col);

		void SetMuteStatus(bool canSpeak, bool canHear);
	};

	

	
}