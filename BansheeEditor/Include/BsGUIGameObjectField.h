#pragma once

#include "BsEditorPrerequisites.h"
#include "BsGUIElementContainer.h"

namespace BansheeEditor
{
	class BS_ED_EXPORT GUIGameObjectField : public BS::GUIElementContainer
	{
		struct PrivatelyConstruct {};

	public:
		static const CM::String& getGUITypeName();

		static GUIGameObjectField* create(const BS::GUIContent& labelContent, CM::UINT32 labelWidth, const BS::GUIOptions& layoutOptions, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const BS::GUIContent& labelContent, const BS::GUIOptions& layoutOptions, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const CM::HString& labelText, CM::UINT32 labelWidth, const BS::GUIOptions& layoutOptions, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const CM::HString& labelText, const BS::GUIOptions& layoutOptions, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const BS::GUIOptions& layoutOptions, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const BS::GUIContent& labelContent, CM::UINT32 labelWidth, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const BS::GUIContent& labelContent, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const CM::HString& labelText, CM::UINT32 labelWidth, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const CM::HString& labelText, 
			const CM::String& labelStyle = CM::StringUtil::BLANK, const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		static GUIGameObjectField* create(const CM::String& dropButtonStyle = CM::StringUtil::BLANK,
			const CM::String& clearButtonStyle = CM::StringUtil::BLANK);

		GUIGameObjectField(const PrivatelyConstruct& dummy, const BS::GUIContent& labelContent, 
			CM::UINT32 labelWidth, const CM::String& labelStyle, const CM::String& dropButtonStyle,
			const CM::String& clearButtonStyle, const BS::GUILayoutOptions& layoutOptions, bool withLabel);

		CM::HGameObject getValue() const;
		void setValue(const CM::HGameObject& value);

		void _updateLayoutInternal(CM::INT32 x, CM::INT32 y, CM::UINT32 width, CM::UINT32 height,
			CM::RectI clipRect, CM::UINT8 widgetDepth, CM::UINT16 areaDepth);

		CM::Vector2I _getOptimalSize() const;
	private:
		virtual ~GUIGameObjectField();

		void dataDropped(void* data);

	private:
		static const CM::UINT32 DEFAULT_LABEL_WIDTH;
		static const CM::String DROP_BUTTON_STYLE;
		static const CM::String CLEAR_BUTTON_STYLE;

		BS::GUILayout* mLayout;
		BS::GUILabel* mLabel;
		GUIDropButton* mDropButton;
		BS::GUIButton* mClearButton;

		CM::UINT64 mInstanceId;
	};
}