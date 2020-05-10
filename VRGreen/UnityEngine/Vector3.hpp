#pragma once
#include <cstdint>

namespace UnityEngine
{
	struct  Vector3_Nig
	{
	public:
		// System.Single UnityEngine.Vector3::x
		float x;
		// System.Single UnityEngine.Vector3::y
		float y;
		// System.Single UnityEngine.Vector3::z
		float z;

	public:
		static int32_t get_offset_of_x_0();
		float get_x_0() const;
		float* get_address_of_x_0();
		void set_x_0(float value);

		static int32_t get_offset_of_y_1();
		float get_y_1() const;
		float* get_address_of_y_1();
		void set_y_1(float value);

		static int32_t get_offset_of_z_2();
		float get_z_2() const;
		float* get_address_of_z_2();
		void set_z_2(float value);
	};

	struct Vector3
	{
		float x;
		float y;
		float z;
	};

}