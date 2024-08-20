class CfgPatches
{
	class DynamicEventFramework_Medicine
	{
		units[]=
		{
            "DexamphetamineBagIV_DEF"
        };
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class DynamicEventFramework_Medicine
	{
		dir = "DynamicEventFramework";
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DynamicEventFramework/def_medical/Scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
    class SalineBagIV;

    class DexamphetamineBagIV_DEF : SalineBagIV
    {
        scope=2;
		displayName="$STR_Dexamphetamine0";
		descriptionShort="$STR_Dexamphetamine1";
		
       // model="\DynamicEventFramework\def_medical\data\medicine\dexamphetamine.p3d";
		hiddenSelectionsTextures[]=
		{
			"\DynamicEventFramework\def_medical\data\medicine\dexamphetamine_bag_ca.paa"
		};
    };
};