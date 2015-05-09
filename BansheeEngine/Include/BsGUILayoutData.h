#pragma once

#include "BsPrerequisites.h"
#include "BsRect2I.h"

namespace BansheeEngine
{
	/**
	 * @brief	Contains all attributes that are output by GUI layouts and
	 *			assigned to GUI elements. This includes element position,
	 *			size and depth.
	 */
	struct BS_EXPORT GUILayoutData
	{
		GUILayoutData()
			:depthRangeMin(-1), depthRangeMax(-1), depth(0)
		{ 
			setPanelDepth(0);
		}

		/**
		 * @brief	Set widget part of element depth. (Most significant part)
		 */
		void setWidgetDepth(UINT8 depth)
		{
			UINT32 shiftedDepth = depth << 24;

			depth = shiftedDepth | (depth & 0x00FFFFFF);
		}

		/**
		 * @brief	Set panel part of element depth. Less significant than widget
		 *			depth but more than custom element depth.
		 */
		void setPanelDepth(INT16 depth)
		{
			UINT32 signedDepth = ((INT32)depth + 32768) << 8;

			depth = signedDepth | (depth & 0xFF0000FF);;
		}


		/**
		 * @brief	Retrieve widget part of element depth. (Most significant part)
		 */
		UINT8 getWidgetDepth() const
		{
			return (depth >> 24) & 0xFF;
		}

		/**
		 * @brief	Retrieve panel part of element depth. Less significant than widget
		 *			depth but more than custom element depth.
		 */
		INT16 getPanelDepth() const
		{
			return (((INT32)depth >> 8) & 0xFFFF) - 32768;
		}

		/**
		 * @brief	Returns a clip rectangle that is relative to the current bounds.
		 */
		Rect2I getLocalClipRect() const
		{
			Rect2I localClipRect = clipRect;
			localClipRect.x -= area.x;
			localClipRect.y -= area.y;

			return localClipRect;
		}

		Rect2I area;
		Rect2I clipRect;
		UINT32 depth;
		UINT16 depthRangeMin;
		UINT16 depthRangeMax;
	};
}