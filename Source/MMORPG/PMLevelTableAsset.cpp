#include "PMLevelTableAsset.h"
#include "PMLevelTable.h"
#include "PMUtility.h"
#include "Engine/DataTable.h"

FPMLevelTableAsset::FPMLevelTableAsset(UDataTable* InUDataTable)
	: DataTable(InUDataTable)
{
	//DataTable->AddToRoot();
}

TSoftObjectPtr<UWorld> FPMLevelTableAsset::GetLevelPath(ELevelName InLevelName)
{
	FName LevelName = FName(ENUM_TO_STRING(ELevelName, InLevelName));
	FPMLevelTable* LocalLevelTable = DataTable->FindRow<FPMLevelTable>(LevelName, EMPTY_STRING);
	if (LocalLevelTable)
		return LocalLevelTable->LevelReference;
	return nullptr;
}

void FPMLevelTableAsset::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(DataTable);
}
