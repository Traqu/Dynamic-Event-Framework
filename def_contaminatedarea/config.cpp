class CfgPatches
{
	class DynamicEventFramework_ContaminatedArea
	{
		units[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class DynamicEventFramework_ContaminatedArea
	{
		dir = "DynamicEventFramework";
		type = "mod";
		author = "Traqu";
		authorID = "76561198066157113";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DynamicEventFramework/def_contaminatedarea/Scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class ContaminatedArea_Static;
	class DEF_ContaminatedArea_DE: ContaminatedArea_Static
	{
		scope=1;
		storageCategory=4;
	};
	class DEF_ContaminatedArea_Shipwreck_DE: DEF_ContaminatedArea_DE{};
	class DEF_ContaminatedArea_ShipwreckSmall_DE: DEF_ContaminatedArea_DE{};
};