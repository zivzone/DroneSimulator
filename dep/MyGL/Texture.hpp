#pragma once
#include <string>
#include <GL/glew.h>
#include <vector>

namespace MyGL
{
	class Texture
	{
	private:
		GLuint id;
		GLenum textureType;
		int imageWidth, imageHeight;
		unsigned char *imageData;
		bool generated = false;
		void loadImageFile(const std::string &file);
		void freeImageArray();
	public:
		void Load2d(const std::string &file);
		void Load2dArray(const std::string &file, int depth);
		void LoadCubemap(const std::vector<std::string> &faces);
		void SetParameters(GLenum min_filter, GLenum mag_filter, GLenum wrap_filter);
		void BuildMipmap();
		void Bind();
		void Unbind();
		GLuint GetId() const;
		~Texture();
	};
}
