#pragma once
#include "Engine/DataTable.h"
#include "PMLevelTable.generated.h"

UENUM(BlueprintType)
enum class ELevelName : uint8
{
	Title,
	Field,
};

USTRUCT()
struct MMORPG_API FPMLevelTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> LevelReference;
};
