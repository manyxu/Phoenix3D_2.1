/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill_QueryRange.cpp
*
*/

#include "PX2Skill.hpp"
#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool Skill::IsInRadiusLength (const Character *target)
{
	if (!target)
		return false;

	const APoint &selfPos = mCharacter->GetPosition();
	float selfRadiusLength = mCharacter->GetSelfRadius() + GetMRadiusLength();

	const APoint &targetPos = target->GetPosition();
	float targetRadius = target->GetSelfRadius();

	AVector dir = targetPos - selfPos;
	float dirLength = dir.Length();

	if (dirLength <= (selfRadiusLength + targetRadius))
		return true;

	return false;
}
//----------------------------------------------------------------------------
bool Skill::IsInTrigerDistance (const Character *target)
{
	if (!target)
		return false;

	const APoint &selfPos = mCharacter->GetPosition();
	const APoint &targetPos = target->GetPosition();
	
	AVector dir = targetPos - selfPos;
	float distance = dir.Length();

	if (distance <= (GetMTrigerDistance()+target->GetSelfRadius()))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Skill::IsInRange(const APoint &fromPos, float fromLength,
	float fromWidth, const AVector &fromFaceDir, float fromDegree, 
	const APoint &targetPos, float targetRadius, ShapeType type, bool doBoxRolate)
{
	AVector normalFace = fromFaceDir;
	normalFace.Normalize();

	float lengthMinus = fromLength - targetRadius;

	if (type == ST_BOX)
	{
		if (!doBoxRolate)
		{
			normalFace = AVector::UNIT_X;
		}

		return IsInBoxRange(fromPos, normalFace, fromLength, fromWidth,
			targetPos, targetRadius);
	}
	else if (type == ST_SPHERE)
	{
		if (lengthMinus <= fromLength)
			return true;
	}
	else if (type ==  ST_FAN)
	{
		if (lengthMinus <= fromLength)
		{
			return IsInFanRange(fromPos, normalFace, 
				fromDegree*Mathf::DEG_TO_RAD, targetPos);
		}
	}

	return false;
}
//----------------------------------------------------------------------------
bool Skill::IsInBoxRange (const APoint &center, const AVector &dir,
	float length, float width, const APoint &point, float targetRadius)
{
	AVector pcDir = point - center;	
	float lineLength = pcDir.Dot(dir);

	if (lineLength <= (length+targetRadius))
	{
		float dist = pcDir.Length();
		float halfWidth = width/2.0f;

		if ((dist*dist-lineLength*lineLength) <= halfWidth*halfWidth)
		{
			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
bool Skill::IsInFanRange (const APoint &center, const AVector &dir,
	float radian, const APoint &point)
{
	AVector pcDir = point - center;
	pcDir.Normalize();

	float cosVal = pcDir.Dot(dir);

	return Mathf::ACos(cosVal) <= radian/2.0f;
}
//----------------------------------------------------------------------------