// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Homework2 : ModuleRules
{
	public Homework2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
