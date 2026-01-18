#include "SkillsSubsystem.h"

void USkillsSubsystem::ResetSkills()
{
    CharacterSkills.Reset();
}

bool USkillsSubsystem::UnlockSkill(const FName& Character, const FName& Skill)
{
    TSet<FName>& SetRef = CharacterSkills.FindOrAdd(Character);
    const bool bAdded = SetRef.Add(Skill) > 0;
    return bAdded;
}

bool USkillsSubsystem::HasSkill(const FName& Character, const FName& Skill) const
{
    if (const TSet<FName>* SetRef = CharacterSkills.Find(Character))
    {
        return SetRef->Contains(Skill);
    }
    return false;
}

TArray<FName> USkillsSubsystem::GetSkills(const FName& Character) const
{
    TArray<FName> Out;
    if (const TSet<FName>* SetRef = CharacterSkills.Find(Character))
    {
        Out = SetRef->Array();
    }
    return Out;
}
