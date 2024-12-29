class CfgPatches
{
	class DynamicEventFramework_Medicine
	{
		units[]=
		{
		"AdderallAutoInjector_DEF",
		"AdderallBottle_DEF",
        "DexamphetamineBagIV_DEF",
        "PrimobolanAutoInjector_DEF",
		"VomitulinTablets_DEF"
		};

		requiredVersion=0.1;
		requiredAddons[]= { "DZ_Gear_Medical" };
	};
};

class CfgMods
{
	class DynamicEventFramework_Medicine
	{
		dir = "DynamicEventFramework";
		type = "mod";
		dependencies[] = {"World", "Game", "Mission"};
		class defs
		{
			//class gameScriptModule //TODO configs 
			//{
			//	value = "";
			//	files[] = {"DynamicEventFramework/def_medical/Scripts/3_Game"};
			//};

			class worldScriptModule
			{
				value = "";
				files[] = {"DynamicEventFramework/def_medical/Scripts/4_World"};
			};

			//class missionScriptModule //TODO RPCs
			//{
			//	value = "";
			//	files[] = {"DynamicEventFramework/def_medical/Scripts/5_Mission"};
			//};
		};
	};
};

class CfgVehicles
{
    class SalineBagIV;
	class Epinephrine;
	class VitaminBottle;
	class PainkillerTablets;

	class AdderallAutoInjector_DEF : Epinephrine
    {
        scope=2;
		displayName="$STR_AdderallAutoInjector0";
		descriptionShort="$STR_AdderallAutoInjector1";
		
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[]=
		{
			"\DynamicEventFramework\def_medical\data\medicine\adderallautoinjector_ca.paa"
		};
    };

	class AdderallBottle_DEF : VitaminBottle
    {
        scope=2;
		displayName="$STR_AdderallBottle0";
		descriptionShort="$STR_AdderallBottle1";
		
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[]=
		{
			"\DynamicEventFramework\def_medical\data\medicine\adderall_bottle_co.paa"
		};
		
		canBeSplit=1;
		varQuantityInit=10;
		varQuantityMax=10;
		
		class Medicine
		{
			prevention=0;
			treatment=0;
			diseaseExit=0;
		};
    };

    class DexamphetamineBagIV_DEF : SalineBagIV
    {
        scope=2;
		displayName="$STR_Dexamphetamine0";
		descriptionShort="$STR_Dexamphetamine1";
		
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[]=
		{
			"\DynamicEventFramework\def_medical\data\medicine\dexamphetamine_bag_ca.paa"
		};
    };

	class PrimobolanAutoInjector_DEF : Epinephrine
    {
        scope=2;
		displayName="$STR_PrimobolanAutoInjector0";
		descriptionShort="$STR_PrimobolanAutoInjector1";
		
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[]=
		{
			"\DynamicEventFramework\def_medical\data\medicine\primobolanautoinjector_ca.paa"
		};
    };
	
	class VomitulinTablets_DEF : PainkillerTablets
    {
        scope=2;
		displayName="$STR_VomitulinTablets0";
		descriptionShort="$STR_VomitulinTablets1";
		
		hiddenSelections[] = {"camoground", "zbytek"};
		hiddenSelectionsTextures[]=
		{
			"\DynamicEventFramework\def_medical\data\medicine\vomitulintablets_co.paa",
			"\DynamicEventFramework\def_medical\data\medicine\vomitulintablets_co.paa"
		};
    };
};