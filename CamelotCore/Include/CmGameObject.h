#pragma once

#include "CmPrerequisites.h"
#include "CmIReflectable.h"

namespace CamelotFramework
{
	class CM_EXPORT GameObject : public IReflectable
	{
	public:
		virtual ~GameObject() 
		{ }

		/************************************************************************/
		/* 								RTTI		                     		*/
		/************************************************************************/
	public:
		friend class GameObjectRTTI;
		static RTTITypeBase* getRTTIStatic();
		virtual RTTITypeBase* getRTTI() const;
	};
}

#include "CmGameObjectHandle.h"

namespace CamelotFramework
{
	// Game object handles
	typedef GameObjectHandle<GameObject> HGameObject;
	typedef GameObjectHandle<SceneObject> HSceneObject;
	typedef GameObjectHandle<Component> HComponent;
}