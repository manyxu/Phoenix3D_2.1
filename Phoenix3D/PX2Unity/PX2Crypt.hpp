/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Crypt.hpp
*
*/

#ifndef PX2CRYPT_HPP
#define PX2CRYPT_HPP

namespace PX2
{
	
	class Crypt
	{
	public:
		Crypt ();
		~Crypt ();

		static bool Encrypt(unsigned char *source, unsigned char *destination, 
			unsigned long length);
		static bool Decrypt(unsigned char *source, unsigned char *destination, 
			unsigned long length);
	};

}

#endif