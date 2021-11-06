#pragma once

class FPMLevelTableAsset;
class UDataTable;
enum class ELevelName : uint8;

class FPMAssetManager
{
public:
	void Initialize();

	FString LoadLevel(ELevelName InLevelName);
private:
	void LoadLevelTable();
	UDataTable* LoadTable(const FString& InTableName);
	
	TSharedPtr<FPMLevelTableAsset> LevelTableAsset;
};
