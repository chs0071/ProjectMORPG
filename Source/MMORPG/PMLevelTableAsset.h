#pragma once

enum class ELevelName : uint8;
class UDataTable;

class MMORPG_API FPMLevelTableAsset : public FGCObject
{
public:
	FPMLevelTableAsset(UDataTable* InUDataTable);
	
	TSoftObjectPtr<UWorld> GetLevelPath(ELevelName InLevelName);
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

private:
	UDataTable* DataTable;
};
