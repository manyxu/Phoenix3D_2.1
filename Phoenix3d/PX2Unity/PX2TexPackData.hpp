/*
*
* 文件名称	：	PX2TexPackData.hpp
*
*/

#ifndef PX2TEXPACKDATA_HPP
#define PX2TEXPACKDATA_HPP

#include "PX2UnityPre.hpp"

namespace PX2
{

	class TexPackElement
	{
	public:
		TexPackElement ();
		~TexPackElement ();

		bool IsValid () const;

		// X  => sprite x pos in texture
		// Y  => sprite y pos in texture
		// W  => sprite width (may be trimmed)
		// H  => sprite height (may be trimmed)
		// OX => sprite's x-corner offset (only available if trimmed)
		// OY => sprite's y-corner offset (only available if trimmed)
		// OW => sprite's original width (only available if trimmed)
		// OH => sprite's original height (only available if trimmed)
		// Rolated => 'y' only set if sprite is rotated

		int X;
		int Y;
		int W;
		int H;
		int OX;
		int OY;
		int OW;
		int OH;
		bool Rolated;
		int TexWidth;
		int TexHeight;
		std::string ElementName;
		std::string ImagePathFull;
	};

	class TexPack
	{
	public:
		TexPack ();
		~TexPack ();

		bool IsValid () const;

		std::string ImageFullPath;
		std::string ImagePath;
		int Width;
		int Height;
		bool IsHasUpdate; // 是否有更新

		std::vector<TexPackElement> Elements;
	};

#include "PX2TexPackData.inl"

}

#endif