#include "RelationshipsSubsystem.h"

void URelationshipsSubsystem::ResetRelationships()
{
    Affinity.Reset();
}

FString URelationshipsSubsystem::MakeKey(const FName& A, const FName& B) const
{
    const FString As = A.ToString();
    const FString Bs = B.ToString();
    return As <= Bs ? (As + TEXT("|") + Bs) : (Bs + TEXT("|") + As);
}

float URelationshipsSubsystem::GetAffinity(const FName& A, const FName& B) const
{
    const FString Key = MakeKey(A, B);
    if (const float* Val = Affinity.Find(Key))
    {
        return *Val;
    }
    return 0.0f;
}

void URelationshipsSubsystem::SetAffinity(const FName& A, const FName& B, float Value)
{
    const FString Key = MakeKey(A, B);
    Affinity.Add(Key, FMath::Clamp(Value, -100.0f, 100.0f));
}

float URelationshipsSubsystem::ModifyAffinity(const FName& A, const FName& B, float Delta)
{
    const FString Key = MakeKey(A, B);
    const float NewVal = FMath::Clamp(GetAffinity(A, B) + Delta, -100.0f, 100.0f);
    Affinity.Add(Key, NewVal);
    return NewVal;
}

TMap<FName, float> URelationshipsSubsystem::GetRelationsFor(const FName& A) const
{
    TMap<FName, float> Out;
    const FString AStr = A.ToString();
    for (const auto& P : Affinity)
    {
        const FString& Key = P.Key;
        float Val = P.Value;
        FString Left, Right;
        if (Key.Split(TEXT("|"), &Left, &Right))
        {
            if (Left == AStr)
            {
                Out.Add(FName(*Right), Val);
            }
            else if (Right == AStr)
            {
                Out.Add(FName(*Left), Val);
            }
        }
    }
    return Out;
}
