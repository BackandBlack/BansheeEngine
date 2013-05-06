#pragma once

#include "CmPrerequisites.h"
#include "CmIReflectable.h"

namespace CamelotFramework
{
	class CM_EXPORT ImportOptions : public IReflectable
	{
	public:
		virtual ~ImportOptions() {}

		/************************************************************************/
		/* 								SERIALIZATION                      		*/
		/************************************************************************/
	public:
		friend class ImportOptionsRTTI;
		static RTTITypeBase* getRTTIStatic();
		virtual RTTITypeBase* getRTTI() const;
	};
}