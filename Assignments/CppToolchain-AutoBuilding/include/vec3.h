// =================
//
// A simple CG program for loading and displaying polygon mesh
//
// Author: Hongzheng Chen
//
// =================

#ifndef VEC3_H
#define VEC3_H

template <class T>
class vec3
{
public:
	vec3() : x(0), y(0), z(0) {}
	vec3(const T px, const T py, const T pz)
	{
		set(px, py, pz);
	}
	vec3(const vec3<T> &v)
	{
		set(v.x, v.y, v.z);
	}
	void set(const vec3<T> &v)
	{
		set(v.x, v.y, v.z);
	}
	void set(const T px, const T py, const T pz)
	{
		this->x = px;
		this->y = py;
		this->z = pz;
	}
	T x, y, z;
};

#endif // VEC3_H