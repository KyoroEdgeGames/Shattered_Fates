#include "ClanSubsystem.h"

void UClanSubsystem::SetDataAsset(UClanDataAsset* InAsset)
{
    DataAsset = InAsset;
}

TArray<FClanData> UClanSubsystem::GetAllClans() const
{
    return DataAsset ? DataAsset->Clans : TArray<FClanData>();
}
