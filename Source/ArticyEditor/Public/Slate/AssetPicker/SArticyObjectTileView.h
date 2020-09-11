//  
// Copyright (c) articy Software GmbH & Co. KG. All rights reserved.  
//

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Widgets/SCompoundWidget.h"
#include "ArticyObject.h"
#include "Widgets/Layout/SBorder.h"
#include "ArticyBaseTypes.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Text/STextBlock.h"


/**
 *  REFERENCE: SAssetViewItem, which is the normal asset selection widget in a picker
 */
class ARTICYEDITOR_API SArticyObjectTileView : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SArticyObjectTileView) 
		: _LabelVisibility(EVisibility::Visible)
		, _OnMouseDoubleClick()
		, _ThumbnailSize(FVector2D(48.f, 48.f))	
		, _ThumbnailPadding(FMargin(2.f))
	{}
		SLATE_ATTRIBUTE(FArticyId, ObjectToDisplay)
		SLATE_ATTRIBUTE(EVisibility, LabelVisibility)
	    SLATE_EVENT(FPointerEventHandler, OnMouseDoubleClick)
		SLATE_ARGUMENT(FVector2D, ThumbnailSize)
		SLATE_ARGUMENT(FMargin, ThumbnailPadding)
	SLATE_END_ARGS()

/**
 * Construct this widget
 *
 * @param	InArgs	The declaration data for this widget
 */
	void Construct(const FArguments& InArgs);
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:
	TAttribute<FArticyId> ArticyIdAttribute;
	mutable FArticyId CachedArticyId;
	mutable TWeakObjectPtr<UArticyObject> CachedArticyObject;
	
	TSharedPtr<SImage> PreviewImage;
	TSharedPtr<STextBlock> DisplayNameTextBlock;
	TSharedPtr<SBorder> WidgetContainerBorder;

	mutable FSlateBrush PreviewBrush;
	const FSlateBrush* TypeImage = nullptr;
	TSharedPtr<FTextBlockStyle> EntityNameTextStyle;
	FVector2D ThumbnailSize;
	FMargin ThumbnailPadding;
	TAttribute<EVisibility> LabelVisibility;
	bool bHasPreviewImage = false;
	
private:
	void UpdateDisplayedArticyObject();
	
	virtual FText OnGetEntityName() const;
	virtual const FSlateBrush* OnGetEntityImage() const;
	EVisibility OnHasPreviewImage() const;
	virtual FSlateColor OnGetArticyObjectColor() const;
	const FSlateBrush* GetTypeImage() const;
};
