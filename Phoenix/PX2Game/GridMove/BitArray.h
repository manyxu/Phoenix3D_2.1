
#ifndef __BITARRAY_H__
#define __BITARRAY_H__

namespace GridMove
{
	class BitArray1D
	{
	public:
		BitArray1D( int len ) : m_NumBits(len)
		{
			m_BufLen = (m_NumBits+31)/32;
			m_pData = new unsigned int[m_BufLen];
		}
		~BitArray1D()
		{
			delete[] m_pData;
		}
		void Clear()
		{
			memset( m_pData, 0, m_BufLen*4 );
		}
		int GetBit( int i )
		{
			return (m_pData[i>>5] >> (i&31)) & 1;
		}
		void SetBit( int i, int bit )
		{
			unsigned int &data = m_pData[i>>5];
			int ibit = i&31;
			data = (data & ~(1<<ibit)) | (bit<<ibit);
		}

	private:
		unsigned int *m_pData;
		int m_NumBits;
		int m_BufLen;
	};

	class BitArray2D
	{
	public:
		BitArray2D( int nbitx, int nbity ) : m_nBitX(nbitx), m_nBitY(nbity), m_BitArray(nbitx*nbity)
		{
		}
		~BitArray2D()
		{
		}
		void Clear()
		{
			m_BitArray.Clear();
		}
		int GetBit( int x, int y )
		{
			return m_BitArray.GetBit( y*m_nBitX+x );
		}
		void SetBit( int x, int y, int bit )
		{
			m_BitArray.SetBit( y*m_nBitX+x, bit );
		}

		int GetWidth(){ return m_nBitX; }
		int GetHeight(){ return m_nBitY; }

	private:
		BitArray1D m_BitArray;
		int m_nBitX, m_nBitY;
	};
}

#endif