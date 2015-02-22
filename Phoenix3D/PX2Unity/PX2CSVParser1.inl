// PX2CSVParser1.inl

//----------------------------------------------------------------------------
// TableItem
//----------------------------------------------------------------------------
inline bool CSVParser1::TableItem::IsValid() const
{
	return mItemString[0]!=0;
}
//----------------------------------------------------------------------------
inline CSVParser1::TableItem::operator const char* () const
{
	return mItemString; 
}
//----------------------------------------------------------------------------
inline std::string CSVParser1::TableItem::String() const 
{ 
	return std::string(mItemString); 
}
//----------------------------------------------------------------------------
inline const char* CSVParser1::TableItem::Str() const  
{
	return mItemString; 
}
//----------------------------------------------------------------------------
inline bool CSVParser1::TableItem::Bool() const  
{
	return atoi(mItemString)!=0; 
}
//----------------------------------------------------------------------------
inline char CSVParser1::TableItem::Char() const 
{
	return (char)mItemString[0];
}
//----------------------------------------------------------------------------
inline unsigned char CSVParser1::TableItem::UChar() const
{
	return (unsigned char)atoi(mItemString); 
}
//----------------------------------------------------------------------------
inline unsigned char CSVParser1::TableItem::Byte() const 
{
	return (unsigned char)atoi(mItemString); 
}
//----------------------------------------------------------------------------
inline short CSVParser1::TableItem::Short() const 
{
	return (short)atoi(mItemString);
}
//----------------------------------------------------------------------------
inline unsigned short CSVParser1::TableItem::UShort() const
{
	return (unsigned short)atoi(mItemString); 
}
//----------------------------------------------------------------------------
inline unsigned short CSVParser1::TableItem::Word() const  
{
	return (unsigned short)atoi(mItemString); 
}
//----------------------------------------------------------------------------
inline int CSVParser1::TableItem::Int() const   
{
	return atoi(mItemString); 
}
//----------------------------------------------------------------------------
inline unsigned int CSVParser1::TableItem::UInt() const 
{
	return (unsigned int)atoi(mItemString); 
}
//----------------------------------------------------------------------------
inline long CSVParser1::TableItem::Long() const   
{
	return atol(mItemString); 
}
//----------------------------------------------------------------------------
inline long CSVParser1::TableItem::ULong() const
{
	return (unsigned long)atol(mItemString); 
}
//----------------------------------------------------------------------------
inline unsigned long CSVParser1::TableItem::DWord() const
{
	return (unsigned long)atol(mItemString); 
}
//----------------------------------------------------------------------------
inline float CSVParser1::TableItem::Float() const
{
	return (float)atof(mItemString); 
}
//----------------------------------------------------------------------------
inline double CSVParser1::TableItem::Double() const
{
	return atof(mItemString); 
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// TableLine
//----------------------------------------------------------------------------
inline const CSVParser1::TableItem CSVParser1::TableLine::operator[](int index) const
{
	return TableItem(mTable->GetString(mLineIdx, index));
}
//----------------------------------------------------------------------------
inline const CSVParser1::TableItem CSVParser1::TableLine::operator[] (
	const char* szIdx) const
{
	return TableItem(mTable->GetString(mLineIdx, szIdx));
}
//----------------------------------------------------------------------------
inline void CSVParser1::TableLine::SetLine (CSVParser1* pTable, int iLineIdx) 
{ 
	mTable = pTable; 
	mLineIdx = iLineIdx;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CSVParser1
//----------------------------------------------------------------------------
inline bool CSVParser1::IsLoaded() 
{
	return mContent != 0; 
}
//----------------------------------------------------------------------------
inline const CSVParser1::TableLine& CSVParser1::operator[](int index) const
{
	return mLines[index]; 
}
//----------------------------------------------------------------------------
inline int CSVParser1::GetNumLines() 
{
	return mNumLines; 
}
//----------------------------------------------------------------------------
inline int CSVParser1::GetNumCols() 
{
	return mNumCols; 
}
//----------------------------------------------------------------------------
inline void CSVParser1::SetTitleLine(int index) 
{
	mTitleLine=index; 
}
//----------------------------------------------------------------------------
inline int CSVParser1::GetTitleLine()    
{
	return mTitleLine; 
}
//----------------------------------------------------------------------------
inline void CSVParser1::SetTitleCol(int index) 
{
	mTitleCol=index;
}
//----------------------------------------------------------------------------
inline int CSVParser1::GetTitleCol() 
{
	return mTitleCol;
}
//----------------------------------------------------------------------------