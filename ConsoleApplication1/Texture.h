#pragma once
#ifndef __TEXTURE__
#define __TEXTURE__

#include <GL/glut.h>
#include <iostream>
#include <stdio.h>

class Texture {
public: 
	inline Texture(){}

	inline ~Texture(){}

	static GLuint loadBMP_custom(const char *imagepath) {
		unsigned char header[54];
		unsigned int dataPos;
		unsigned int width, height;
		unsigned int imageSize;

		unsigned char *data;

		FILE * file = fopen(imagepath, "rb");
		if (!file) {
			printf("Image could not be opened!\n");
			return 0;
		}
		if (fread(header, 1, 54, file) != 54) {
			printf("Not a correct BMP file!\n");
			return false;
		}
		if (header[0] != 'B' || header[1] != 'M') {
			printf("Not a correct BMP file\n");
			return 0;
		}
		dataPos = *(int*)&(header[0x0A]);
		imageSize = *(int*)&(header[0x22]);
		width = *(int*)&(header[0x12]);
		height = *(int*)&(header[0x16]);

		if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
		if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

											 // Create a buffer
		data = new unsigned char[imageSize];

		// Read the actual data from the file into the buffer
		size_t a;
		if ((a = fread(data, 1, imageSize, file)) != imageSize)
			std::cout << a << " " << imageSize << " The Image could not be loaded" << std::endl;
		//Everything is in memory now, the file can be closed
		fclose(file);


		// Create one OpenGL texture
		GLuint textureID;

		glGenTextures(1, &textureID);

		// "Bind" the newly created texture : all future texture functions will modify this texture
		glBindTexture(GL_TEXTURE_2D, textureID);

		// Give the image to OpenGL
//#ifdef __linux__
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//#else
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
//#endif

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		std::cout << "LOAD SUCCESS" << std::endl;
		return textureID;
	}

};
#endif
