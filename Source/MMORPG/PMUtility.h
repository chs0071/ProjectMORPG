#pragma once

template<class T>
FString EnumToString(const FString& InEnumName, T InEnumValue)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *InEnumName, true);
	if(EnumPtr)
		return EnumPtr->GetNameStringByIndex((int32)InEnumValue);
	return TEXT("Invalid");
}
#define ENUM_TO_STRING(EnumName, EnumValue) EnumToString<EnumName>(#EnumName, EnumValue)
#define EMPTY_STRING TEXT("")