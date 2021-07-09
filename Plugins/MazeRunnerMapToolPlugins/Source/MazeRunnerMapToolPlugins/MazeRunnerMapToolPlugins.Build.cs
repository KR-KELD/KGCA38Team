// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MazeRunnerMapToolPlugins : ModuleRules
{
	public MazeRunnerMapToolPlugins(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"MazeRunnerMapToolPlugins/Public",
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                "MazeRunnerMapToolPlugins/Private",
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UMG",
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UMG",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
