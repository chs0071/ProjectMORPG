#include "PMAssetManager.h"
#include "Engine/DataTable.h"
#include "PMLevelTableAsset.h"
#include "PMLevelTable.h"
#include "PMUtility.h"

void FPMAssetManager::Initialize()
{
	LoadLevelTable();
}

FString FPMAssetManager::LoadLevel(ELevelName InLevelName)
{
	TSoftObjectPtr<UWorld> LocalLevelPath = LevelTableAsset->GetLevelPath(InLevelName);
	if (LocalLevelPath.IsNull() == false)
		return LocalLevelPath.ToString();
	return EMPTY_STRING;
}

UDataTable* FPMAssetManager::LoadTable(const FString& InTableName)
{
	UObject* LoadUObject = StaticLoadObject(UDataTable::StaticClass(), nullptr, *InTableName);
	if (IsValid(LoadUObject))
		return Cast<UDataTable>(LoadUObject);
	return nullptr;
}

void FPMAssetManager::LoadLevelTable()
{
	UDataTable* DataTable = LoadTable(TEXT("/Game/Table/LevelDataTable.LevelDataTable"));
	if (IsValid(DataTable))
	{
		LevelTableAsset = MakeShareable(new FPMLevelTableAsset(DataTable));
	}
}