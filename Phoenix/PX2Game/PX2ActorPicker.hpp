/*
*
* 文件名称	：	PX2ActorPicker.hpp
*
*/

#ifndef PX2ACTORPICKER_HPP
#define PX2ACTORPICKER_HPP

#include "PX2GamePre.hpp"
#include "PX2ActorPickRecord.hpp"

namespace PX2
{

	class Scene;

	/// 角色选择器类
	/** 
	* 线的表现形式为P + t*D，P是线原点，D是单位长度的方向向量，t是方向上的
	* 缩放参数，在区间[tmin,tmax]内，tmin < tmax。P和D必须是世界坐标系里的值。
	* 不同类型参数选择，决定线的类型。
	* 直线line:		tmin = -Mathf::MAX_REAL, tmax = Mathf::MAX_REAL
	* 射线ray：		tmin = 0, tmax = Mathf::MAX_REAL
	* 线段segment：	tmin = 0, tmax > 0
	*/
	class ActorPicker
	{
	public:
		ActorPicker ();

		/// 执行检测，将记录保存到Records中。
		/**
		* 调用此函数自动清空纪录数组。如果先前记录集里就有信息，你必须先保存。
		*/
		void Execute (Scene* scene, const APoint& origin, 
			const AVector& direction, float tmin, float tmax);

		/// 返回绝对值T最接近0的角色记录
		/**
		* 如果Records为空，返回无效值。
		*/
		const ActorPickRecord &GetClosestToZero () const;

		std::vector<ActorPickRecord> Records;

	private:
		APoint mOrigin;
		AVector mDirection;
		float mTMin, mTMax;

		// 当Records没有元素时，这个表示无效的成员会被Get*函数返回。
		static const ActorPickRecord msInvalid;
	};

}

#endif