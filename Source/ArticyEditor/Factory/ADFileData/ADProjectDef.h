﻿//  
// Copyright (c) Articy Software GmbH & Co. KG. All rights reserved.  
//

#pragma once

#include "CoreMinimal.h"
#include "ADProjectDef.generated.h"

/**
 * 
 */
USTRUCT()
struct ARTICYEDITOR_API FADProjectDef
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category="Project")
	FString Name;
	UPROPERTY(VisibleAnywhere, Category="Project")
	FString DetailName;
	UPROPERTY(VisibleAnywhere, Category="Project")
	FString Guid;
	UPROPERTY(VisibleAnywhere, Category="Project")
	FString TechnicalName;
};
