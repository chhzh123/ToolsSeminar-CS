// =================
//
// A simple CG program for loading and displaying polygon mesh
//
// Author: Hongzheng Chen
//
// =================

#include <mesh.h>

// The following function is partly referenced from
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
bool Mesh::loadOBJ(const char *path)
{

	fmode = 1;

	printf("Loading OBJ file %s...\n", path);

	FILE *file = fopen(path, "r");
	if (file == NULL)
	{
		printf("Error: No this file!\n");
		getchar();
		return false;
	}

	while (1)
	{

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		if (strcmp(lineHeader, "v") == 0)
		{
			vec3<GLfloat> vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			vec3<GLint> face;
			int matches = fscanf(file, "%d %d %d\n", &face.x, &face.y, &face.z);
			if (matches != 3)
			{
				printf("Error: File parser!\n");
				fclose(file);
				return false;
			}
			faces.push_back(face);
		}
		else
		{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
	}
	fclose(file);
	printf("Finish loading obj file.\n");
	return true;
}

bool Mesh::loadPLY(const char *path)
{

	fmode = 2;

	printf("Loading PLY file %s...\n", path);

	FILE *file = fopen(path, "r");
	if (file == NULL)
	{
		printf("Error: No this file!\n");
		getchar();
		return false;
	}

	int vertex_num, face_num;

	while (1)
	{

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		if (strcmp(lineHeader, "element") == 0)
		{
			int num;
			char str[20];
			fscanf(file, "%s %d\n", str, &num);
			if (strcmp(str, "vertex") == 0)
			{
				vertex_num = num;
				printf("# Vertex: %d\n", vertex_num);
			}
			else if (strcmp(str, "face") == 0)
			{
				face_num = num;
				printf("# Face: %d\n", face_num);
			}
		}
		else if (strcmp(lineHeader, "end_header") == 0)
		{
			break;
		}
	}

	// read vertices
	for (int i = 0; i < vertex_num; ++i)
	{
		vec3<GLfloat> vertex;
		fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
		vertices.push_back(vertex);
	}
	// read faces
	for (int i = 0; i < face_num; ++i)
	{
		vec3<GLint> face;
		int num;
		int matches = fscanf(file, "%d %d %d %d\n", &num, &face.x, &face.y, &face.z);
		faces.push_back(face);
	}
	fclose(file);
	printf("Finish loading ply file.\n");
	return true;
}

bool Mesh::loadOFF(const char *path)
{

	fmode = 3;

	printf("Loading OFF file %s...\n", path);

	FILE *file = fopen(path, "r");
	if (file == NULL)
	{
		printf("Error: No this file!\n");
		getchar();
		return false;
	}

	int vertex_num, face_num, n;

	char lineHeader[128];
	fscanf(file, "%s", lineHeader);
	fscanf(file, "%d %d %d", &vertex_num, &face_num, &n);

	// read vertices
	for (int i = 0; i < vertex_num; ++i)
	{
		vec3<GLfloat> vertex;
		fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
		vertices.push_back(vertex);
	}
	// read faces
	for (int i = 0; i < face_num; ++i)
	{
		vec3<GLint> face;
		int num;
		int matches = fscanf(file, "%d %d %d %d\n", &num, &face.x, &face.y, &face.z);
		faces.push_back(face);
	}
	fclose(file);
	printf("Finish loading off file.\n");
	return true;
}