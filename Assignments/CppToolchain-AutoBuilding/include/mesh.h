// =================
//
// A simple CG program for loading and displaying polygon mesh
//
// Author: Hongzheng Chen
//
// =================

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <GL/glut.h>
#include <vec3.h>
using namespace std;

class Mesh
{
public:
	Mesh(): fmode(0) {}

	bool loadOBJ(const char *path);
	bool loadPLY(const char *path);
	bool loadOFF(const char *path);

	vector< vec3<GLfloat> > vertices;
	vector< vec3<GLint> > faces;
	int fmode;
};

#endif // MESH_H